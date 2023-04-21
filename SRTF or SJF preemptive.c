#include <stdio.h>

void sjf_preemptive(int at[], int bt[], int n) {
    int ct[n], remaining_bt[n], t = 0, completed = 0, min_bt_index, ft[n], rt[n];

    for (int i = 0; i < n; i++) {
        remaining_bt[i] = bt[i];
    }

    while (completed != n) {
        min_bt_index = -1;
        for (int i = 0; i < n; i++) {
            if (at[i] <= t && remaining_bt[i] > 0) {
                if (min_bt_index == -1 || remaining_bt[i] < remaining_bt[min_bt_index]) {
                    min_bt_index = i;
                }
            }
        }

        if (min_bt_index == -1) {
            t++;
            continue;
        }

        if (remaining_bt[min_bt_index] == bt[min_bt_index]) {
            ft[min_bt_index] = t;
            rt[min_bt_index] = ft[min_bt_index] - at[min_bt_index];
        }

        remaining_bt[min_bt_index]--;
        t++;

        if (remaining_bt[min_bt_index] == 0) {
            completed++;
            ct[min_bt_index] = t;
        }
    }

    int wt[n], tat[n], total_wt = 0, total_tat = 0, total_rt = 0;
    float avg_wt, avg_tat, avg_rt;

    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        total_wt += wt[i];
        total_tat += tat[i];
        total_rt += rt[i];
    }

    avg_wt = (float) total_wt / n;
    avg_tat = (float) total_tat / n;
    avg_rt = (float) total_rt / n;

    printf("\nProcess\tAT\tBT\tFT\tCT\tWT\tTAT\tRT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], ft[i], ct[i], wt[i], tat[i], rt[i]);
    }

    printf("\nAverage turnaround time: %.2f\n", avg_tat);
    printf("Average waiting time: %.2f\n", avg_wt);
    printf("Average response time: %.2f\n", avg_rt);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n];
    printf("Enter the arrival time and burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
    }

    sjf_preemptive(at, bt, n);

    return 0;
}
