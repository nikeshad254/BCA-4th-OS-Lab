/*

-- demo data - code from javatpoint: https://www.javatpoint.com/round-robin-program-in-c
		Process	AT	BT
		P1		0	8
		P2		1	5
		P3		2	10
		P4		3	11				quantum = 6;

	
	ans: ATAT: 14.75, AWT: 23.25; 
*/

#include<stdio.h>

void main() {
	// initlialize the variable name
	int i, NOP, sum=0,count=0, y, quant, wt=0, tat=0, at[10], bt[10], temp[10];
	float avg_wt, avg_tat;
	printf(" Total number of process in the system: ");
	scanf("%d", &NOP);
	y = NOP; // Assign the number of process to variable y

// Use for loop to enter the details of the process like Arrival time and the Burst Time
	for(i=0; i<NOP; i++) {
		printf("Enter the AT and BT for P[%d]: ", i+1);
		scanf("%d %d", &at[i], &bt[i]);
		temp[i] = bt[i]; // store the burst time in temp array
	}
// Accept the Time qunat
	printf("\nEnter the Time Quantum for the process: ");
	scanf("%d", &quant);
// Display the process No, burst time, Turn Around Time and the waiting time
	printf("\n Process No \t\t BT \t\t TAT \t\t WT ");
	for(sum=0, i = 0; y!=0; ) {
		if(temp[i] <= quant && temp[i] > 0) { // define the conditions
			sum = sum + temp[i];
			temp[i] = 0;
			count=1;
		} else if(temp[i] > 0) {
			temp[i] = temp[i] - quant;
			sum = sum + quant;
		}
		if(temp[i]==0 && count==1) {
			y--; //decrement the process no.
			printf("\nProcess No[%d] \t\t %d\t\t\t %d\t\t %d", i+1, bt[i], sum-at[i], sum-at[i]-bt[i]);
			wt = wt+sum-at[i]-bt[i];
			tat = tat+sum-at[i];
			count =0;
		}
		if(i==NOP-1) {
			i=0;
		} else if(at[i+1]<=sum) {
			i++;
		} else {
			i=0;
		}
	}
// represents the average waiting time and Turn Around time
	avg_wt = wt * 1.0/NOP;
	avg_tat = tat * 1.0/NOP;
	printf("\n\n Average Turn Around Time: \t%f", avg_wt);
	printf("\n Average Waiting Time: \t%f", avg_tat);
}