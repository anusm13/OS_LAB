#include <stdio.h>

#define MAX 10

int main() {

    int n, hungry, pos[MAX];
    int choice;

    printf("Enter total number of philosophers: ");
    scanf("%d", &n);

    printf("How many are hungry: ");
    scanf("%d", &hungry);

    for (int i = 0; i < hungry; i++) {
        printf("Enter philosopher %d position (1-%d): ", i + 1, n);
        scanf("%d", &pos[i]);
    }

    do {

        printf("\n1. One can eat at a time\n");
        printf("2. Two can eat at a time\n");
        printf("3. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:

            printf("\nOnly one philosopher can eat at a time\n");

            for (int i = 0; i < hungry; i++) {
                printf("P%d is waiting\n", pos[i]);
            }

            for (int i = 0; i < hungry; i++) {
                printf("P%d is eating\n", pos[i]);
                printf("P%d finished eating\n", pos[i]);
            }

            break;

        case 2: {

            int eating[MAX] = {0};

            printf("\nTwo philosophers can eat simultaneously\n");

            for (int i = 0; i < hungry; i++) {

                int left = (pos[i] == 1) ? n : pos[i] - 1;
                int right = (pos[i] == n) ? 1 : pos[i] + 1;

                int canEat = 1;

                for (int j = 0; j < hungry; j++) {

                    if (eating[j]) {

                        if (pos[j] == left || pos[j] == right) {
                            canEat = 0;
                            break;
                        }
                    }
                }

                if (canEat) {
                    eating[i] = 1;
                    printf("P%d is eating\n", pos[i]);
                }
                else {
                    printf("P%d is waiting\n", pos[i]);
                }
            }

            for (int i = 0; i < hungry; i++) {
                if (eating[i]) {
                    printf("P%d finished eating\n", pos[i]);
                }
            }

            break;
        }

        case 3:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice\n");
        }

    } while (choice != 3);

    return 0;
}
