
/*

	testing inputs:
	
	no. of process : 4
	
	bt for each processes: 8 5 4 10
	
	expected outcome: Average WT: 10.25 || Average TAT: 18.75
*/

#include<stdio.h>

void main() {
    // initialize variables
    int n, i, j, temp, bt[20], wt[20], tat[20];
    float avgwt=0, avgtat=0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // enter burst time for each process
    printf("\nEnter burst time for each process:\n");
    for(i=0; i<n; i++) {
        printf("Process %d: ", i+1);
        scanf("%d", &bt[i]);
    }

    // sort the burst times in ascending order using selection sort
    for(i=0; i<n; i++) {
        for(j=i+1; j<n; j++) {
            if(bt[i] > bt[j]) {
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }

    // calculate waiting time and turnaround time for each process
    wt[0] = 0; // waiting time for first process is always 0
    for(i=1; i<n; i++) {
        wt[i] = 0;
        for(j=0; j<i; j++) {
            wt[i] += bt[j];
        }
    }

    // calculate turnaround time
    for(i=0; i<n; i++) {
        tat[i] = bt[i] + wt[i];
        // calculate average waiting time and average turnaround time
        avgwt += wt[i];
        avgtat += tat[i];
    }

    // calculate average waiting time and average turnaround time
    avgwt /= n;
    avgtat /= n;

    // print results
    printf("\nProcess\tBT\tWT\tTAT\n");
    for(i=0; i<n; i++) {
        printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);
    }
    printf("\nAverage WT: %.2f", avgwt);
    printf("\nAverage TAT: %.2f", avgtat);
}
