#include <stdio.h>

int main()
{
    int pages[50], frames[20];
    int n, f, choice;
    int i, j, k;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);
    printf("\nPage Replacement Algorithms \n");
    printf("1. FIFO\n");
    printf("2. LRU\n");
    printf("3. Optimal\n");
    printf("4. Exit\n");

    do
    {
        int pageFaults = 0;

        for(i = 0; i < f; i++)
            frames[i] = -1;


        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                int index = 0, found;

                for(i = 0; i < n; i++)
                {
                    found = 0;

                    for(j = 0; j < f; j++)
                    {
                        if(frames[j] == pages[i])
                        {
                            found = 1;
                            break;
                        }
                    }

                    if(!found)
                    {
                        frames[index] = pages[i];
                        index = (index + 1) % f;
                        pageFaults++;
                    }
                }

                printf("\nFIFO Page Faults = %d\n", pageFaults);
                break;
            }

            case 2:
            {
                int time[20] = {0};
                int counter = 0, found, pos, min;

                for(i = 0; i < n; i++)
                {
                    found = 0;

                    for(j = 0; j < f; j++)
                    {
                        if(frames[j] == pages[i])
                        {
                            found = 1;
                            counter++;
                            time[j] = counter;
                            break;
                        }
                    }

                    if(!found)
                    {
                        pos = 0;
                        min = time[0];

                        for(j = 1; j < f; j++)
                        {
                            if(time[j] < min)
                            {
                                min = time[j];
                                pos = j;
                            }
                        }

                        counter++;
                        frames[pos] = pages[i];
                        time[pos] = counter;
                        pageFaults++;
                    }
                }

                printf("\nLRU Page Faults = %d\n", pageFaults);
                break;
            }

            case 3:
            {
                int found, pos, farthest, future;

                for(i = 0; i < n; i++)
                {
                    found = 0;

                    for(j = 0; j < f; j++)
                    {
                        if(frames[j] == pages[i])
                        {
                            found = 1;
                            break;
                        }
                    }

                    if(!found)
                    {
                        int empty = -1;

                        for(j = 0; j < f; j++)
                        {
                            if(frames[j] == -1)
                            {
                                empty = j;
                                break;
                            }
                        }

                        if(empty != -1)
                        {
                            frames[empty] = pages[i];
                        }
                        else
                        {
                            farthest = -1;
                            pos = -1;

                            for(j = 0; j < f; j++)
                            {
                                future = -1;

                                for(k = i + 1; k < n; k++)
                                {
                                    if(frames[j] == pages[k])
                                    {
                                        future = k;
                                        break;
                                    }
                                }

                                if(future == -1)
                                {
                                    pos = j;
                                    break;
                                }

                                if(future > farthest)
                                {
                                    farthest = future;
                                    pos = j;
                                }
                            }

                            frames[pos] = pages[i];
                        }

                        pageFaults++;
                    }
                }

                printf("\nOptimal Page Faults = %d\n", pageFaults);
                break;
            }

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 4);

    return 0;
}
