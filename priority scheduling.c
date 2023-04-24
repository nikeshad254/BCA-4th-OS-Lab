
/*
	testing inputs:
	
	Process	BT	Priority
		P1	5		1
		P2	7		6
		P3	2		4
		P4	3		5
		
	expected outputs: Average waiting time: 7.25 || Average turnaround time: 11.50

*/

#include<stdio.h>

void main() {
    // initialize variables
    int n, i, j, temp, bt[20], wt[20], tat[20], p[20], pr[20], total_wt=0, total_tat=0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // enter burst time and priority for each process
    printf("\nEnter burst time and priority for each process:\n");
    for(i=0; i<n; i++) {
        printf("Process %d: ", i+1);
        scanf("%d %d", &bt[i], &pr[i]);
        p[i] = i+1;
    }

    // sort the processes by priority using selection sort
    for(i=0; i<n; i++) {
        for(j=i+1; j<n; j++) {
            if(pr[i] < pr[j]) {
                temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
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
        total_wt += wt[i];
    }

    // calculate turnaround time
    for(i=0; i<n; i++) {
        tat[i] = bt[i] + wt[i];
        total_tat += tat[i];
    }

    // calculate average waiting time and turnaround time
    float avg_wt = (float) total_wt / n;
    float avg_tat = (float) total_tat / n;

    // print results
    printf("\n\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for(i=0; i<n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i], bt[i], pr[i], wt[i], tat[i]);
    }
    printf("\nAverage waiting time: %.2f", avg_wt);
    printf("\nAverage turnaround time: %.2f", avg_tat);
}
