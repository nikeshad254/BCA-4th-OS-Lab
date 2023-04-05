#include <stdio.h>

typedef struct Process
{
    int processNumber;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
} Process;

void sortProcessesByArrivalTime(Process processes[], int n)
{
    int i, j;
    Process tempProcess;

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (processes[i].arrivalTime > processes[j].arrivalTime)
            {
                tempProcess = processes[i];
                processes[i] = processes[j];
                processes[j] = tempProcess;
            }
        }
    }
}

void calculateCompletionTime(Process processes[], int n)
{
    int i, currentTime = 0;

    for (i = 0; i < n; i++)
    {
        if (currentTime >= processes[i].arrivalTime)
        {
            processes[i].completionTime = currentTime + processes[i].burstTime;
        }
        else
        {
            processes[i].completionTime = processes[i].arrivalTime + processes[i].burstTime;
            currentTime = processes[i].arrivalTime;
        }

        currentTime = processes[i].completionTime;
    }
}

void calculateTurnaroundTime(Process processes[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        processes[i].turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;
    }
}

void calculateWaitingTime(Process processes[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;
    }
}

void displayProcessTable(Process processes[], int n)
{
    int i;

    printf("\n\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", processes[i].processNumber, processes[i].arrivalTime, processes[i].burstTime, processes[i].completionTime, processes[i].turnaroundTime, processes[i].waitingTime);
    }
}

int main()
{
    int n, i;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process processes[n];

    for (i = 0; i < n; i++)
    {
        printf("Enter the arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrivalTime, &processes[i].burstTime);
        processes[i].processNumber = i + 1;
    }

    sortProcessesByArrivalTime(processes, n);
    calculateCompletionTime(processes, n);
    calculateTurnaroundTime(processes, n);
    calculateWaitingTime(processes, n);
    displayProcessTable(processes, n);
    
    
    int ans = 0; 
    for (i = 0; i < n; i++)
    {
        ans += processes[i].turnaroundTime;
    }
    float rem = ans/n;
	printf("\n\nAverage Turn Around Time: %f", rem);
	
	ans = 0;
	for (i = 0; i < n; i++)
    {
        ans += processes[i].waitingTime;
    }
    rem = ans/n;
	printf("\n\nAverage Waiting Time: %f", rem);
    return 0;
}
