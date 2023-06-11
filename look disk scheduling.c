/*
---  LOOK DISK SCHEDULING ALGORITHM ----

Enter the number of Requests: 7
Enter the Requests sequence: 82 170 43 142 24 16 190
Enter initial head position: 50
Enter total disk size: 200
Enter the head movement direction for high 1 and for low 0: 1

*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int RQ[100], i, j, n, TotalHeadMoment = 0, initial, size, move;
    
    printf(" --- LOOK disk scheduling algorithm --- \n");

    printf("Enter the number of Requests: ");
    scanf("%d", &n);
    printf("Enter the Requests sequence: ");
    for (i = 0; i < n; i++)
        scanf("%d", &RQ[i]);
    printf("Enter initial head position: ");
    scanf("%d", &initial);
    printf("Enter total disk size: ");
    scanf("%d", &size);
    printf("Enter the head movement direction for high 1 and for low 0: ");
    scanf("%d", &move);

    // Logic for LOOK disk scheduling

    /* Logic to sort the request array */
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (RQ[j] > RQ[j + 1]) {
                int temp;
                temp = RQ[j];
                RQ[j] = RQ[j + 1];
                RQ[j + 1] = temp;
            }
        }
    }

    int index;
    for (i = 0; i < n; i++) {
        if (initial < RQ[i]) {
            index = i;
            break;
        }
    }

    printf("\nSeek Sequence is:\n");
    
    // If movement is towards high value
    if (move == 1) {
        for (i = index; i < n; i++) {
            printf("%d -> ", initial);
            TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial);
            initial = RQ[i];
        }
        for (i = index - 1; i >= 0; i--) {
            printf("%d -> ", initial);
            TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial);
            initial = RQ[i];
        }
    }
    // If movement is towards low value
    else {
        for (i = index - 1; i >= 0; i--) {
            printf("%d -> ", initial);
            TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial);
            initial = RQ[i];
        }
        for (i = index; i < n; i++) {
            printf("%d -> ", initial);
            TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial);
            initial = RQ[i];
        }
    }
    
    printf("%d\n", initial);

    printf("\nTotal head movement is %d", TotalHeadMoment);

    return 0;
}
