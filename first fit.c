/*

Enter the number of blocks: 6
Enter the sizes of blocks: 100 300 250 200 450 600
Enter the number of processes: 4
Enter the sizes of processes: 110 88 312 350

*/

#include<stdio.h>

void firstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    
    for(int i = 0; i < n; i++) {
        allocation[i] = -1;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }
    
    printf("\nProcess No.\tProcess Size\t\tBlock no.\n");
    for (int i = 0; i < n; i++) {
        printf(" %i\t\t\t", i+1);
        printf("%i\t\t\t", processSize[i]);
        if (allocation[i] != -1) {
            printf("%i", allocation[i] + 1);
        } else {
            printf("Not Allocated");
        }
        printf("\n");
    }
}

int main() {
    int m, n;
    
    printf("Enter the number of blocks: ");
    scanf("%d", &m);
    
    
    int blockSize[m];
    printf("Enter the sizes of blocks: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &blockSize[i]);
    }
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    int processSize[n];
    
    
    printf("Enter the sizes of processes: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &processSize[i]);
    }
    
    firstFit(blockSize, m, processSize, n);

    return 0;
}
