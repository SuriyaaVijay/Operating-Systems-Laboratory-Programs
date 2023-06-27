#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int swap(int* num1, int* num2) {
    int temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int findMinIndex(int len, int array[len]) {
    int minIndex = 0, min = array[0];
    for(int i = 1; i < len; i++)
        if(min > array[i]) {
            minIndex = i;
            min = array[i];
        }
    return minIndex;
}

int main() {
    int process_num, present_time, time_quantum, max_time;
    float total_tat = 0, total_wt = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &process_num);
    printf("Enter the time quantum: ");
    scanf("%d", &time_quantum);
    int p[process_num], bt[process_num], at[process_num], ct[process_num], tat[process_num], wt[process_num], rt[process_num], btb[process_num], pnum[process_num];
    for(int i = 0; i < process_num; i++) {
        printf("Enter the priority of process #%d: ", i);
        scanf("%d", &p[i]);
        printf("Enter the arrival time of process #%d: ", i);
        scanf("%d", &at[i]);
        printf("Enter the burst time of process #%d: ", i);
        scanf("%d", &bt[i]);
        pnum[i] = i + 1;
    }
    for(int i = 0; i < process_num; i++) {
        rt[i] = -1;
        btb[i] = bt[i];
    }
    for(int x = 0; x < process_num - 1; x++)
        for(int y = 0; y < process_num - x - 1; y++)
            if(at[y] > at[y + 1]){               
                swap(&at[y], &at[y + 1]);
                swap(&bt[y], &bt[y + 1]);
                swap(&btb[y], &btb[y + 1]);
                swap(&p[y], &p[y + 1]);
                swap(&pnum[y], &pnum[y + 1]);
            }
    for(int x = 0; x < process_num - 1; x++)
        for(int y = 0; y < process_num - x - 1; y++)
            if(bt[y] > bt[y + 1] && at[y] == at[y+1]) {
                swap(&bt[y], &bt[y + 1]);
                swap(&btb[y], &btb[y + 1]);
                swap(&p[y], &p[y + 1]);
                swap(&pnum[y], &pnum[y + 1]);
            }
    printf("Pnum\tP\tAT\tBT\n");
    for(int i = 0; i < process_num; i++) {
        printf("%d\t%d\t%d\t%d\n", i, p[i], at[i], bt[i]);
    }
    present_time = at[0];
    max_time = at[process_num-1];
    for(int i = process_num; i > 0;) {
        int tem = 0;
        for(int j = 0; j < process_num; j++) {
            if(at[j] <= present_time && bt[j] != -1)
                tem++;
        }
        if(tem == 0) {
            if(present_time >= max_time)
                break;
            present_time++;
            continue;
        }
        int temp_at[tem], temp_bt[tem], temp_p[tem], iter = 0;
        for(int j = 0; iter < tem; j++) {
            if(bt[j] == -1)
                continue;
            temp_at[iter] = at[j];
            temp_bt[iter] = bt[j];
            temp_p[iter] = p[j];
            iter++;
        }
        int minIndex = findMinIndex(tem, temp_p);
        for(int j = 0; j < process_num; j++) {
            if(at[j] == temp_at[minIndex] && bt[j] == temp_bt[minIndex] && p[j] == temp_p[minIndex]) {
                if(rt[j] == -1)
                    rt[j] = present_time - at[j];
                if(bt[j] > time_quantum) {
                    present_time += time_quantum;
                    bt[j] -= time_quantum;
                }
                else {
                    present_time += bt[j];
                    ct[j] = present_time;
                    bt[j] = -1;
                }
                if(bt[j] <= 0)
                    bt[j] = -1;
                break;
            }
        }
    }
    printf("\n----After Priority Scheduling Algorithm----\n\nPnum\tP\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for(int i = 0; i < process_num; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - btb[i];
        total_tat += tat[i];
        total_wt += wt[i];
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", pnum[i], p[i], at[i], btb[i], ct[i], tat[i], wt[i], rt[i]);
    }
    float avg_tat = total_tat/process_num, avg_wt = total_wt/process_num;
    printf("\nAverage Turn Around time: %0.2f\nAverage Waiting Time: %0.2f\n", avg_tat, avg_wt);
}