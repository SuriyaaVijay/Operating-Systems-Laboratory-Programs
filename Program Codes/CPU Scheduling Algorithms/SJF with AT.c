#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int findMinIndex(int len, int array[len]) {
    int minIndex = 0, min = array[0];
    for(int i = 1; i < len; i++)
        if(min > array[i]) {
            minIndex = i;
            min = array[i];
        }
    return minIndex;
}

int swap(int* num1, int* num2) {
    int temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int main() {
    int process_num, present_time, max_time;
    float total_tat = 0, total_wt = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &process_num);
    int bt[process_num], at[process_num], ct[process_num], tat[process_num], wt[process_num], btb[process_num], pnum[process_num];
    for(int i = 0; i < process_num; i++) {
        printf("Enter the arrival time of process #%d: ", i);
        scanf("%d", &at[i]);
        printf("Enter the burst time of process #%d: ", i);
        scanf("%d", &bt[i]);
        pnum[i] = i + 1;
    }
    for(int i = 0; i < process_num; i++)
        btb[i] = bt[i];
    for(int x = 0; x < process_num - 1; x++)
        for(int y = 0; y < process_num - x - 1; y++)
            if(at[y] > at[y + 1]){
                swap(&at[y], &at[y + 1]);
                swap(&bt[y], &bt[y + 1]);
                swap(&btb[y], &btb[y + 1]);
                swap(&pnum[y], &pnum[y + 1]);
            }
    for(int x = 0; x < process_num - 1; x++)
        for(int y = 0; y < process_num - x - 1; y++)
            if(bt[y] > bt[y + 1] && at[y] == at[y+1]){
                swap(&bt[y], &bt[y + 1]);
                swap(&btb[y], &btb[y + 1]);
                swap(&pnum[y], &pnum[y + 1]);
            }
    printf("Pnum\tAT\tBT\n");
    for(int i = 0; i < process_num; i++)
        printf("%d\t%d\t%d\n", i, at[i], bt[i]);
    present_time = at[0];
    max_time = at[process_num-1];
    for(int i = process_num; i > 0; ) {
        int tem = 0;
        for(int j = 0; j < process_num; j++)
            if(at[j] <= present_time && bt[j] != -1)
                tem++;
        if(tem == 0) {
            if(present_time >= max_time)
                break;
            present_time++;
            continue;
        }
        int temp_at[tem];
        int temp_bt[tem];
        int iter = 0;
        for(int j = 0; iter < tem; j++) {
            if(bt[j] == -1)
                continue;
            temp_at[iter] = at[j];
            temp_bt[iter] = bt[j];
            //printf("%d, %d added to temp\n", temp_at[iter], temp_bt[iter]);
            iter++;
        }
        int minIndex = findMinIndex(tem, temp_bt);
        for(int j = 0; j < process_num; j++) {
            if(at[j] == temp_at[minIndex] && bt[j] == temp_bt[minIndex]) {
                //printf("Process %d has been completed!\n", at[j]);
                present_time += bt[j];
                ct[j] = present_time;
                tat[j] = ct[j] - at[j];
                wt[j] = tat[j] - bt[j];
                //printf("%f TAT and %f WT\n", total_tat, total_wt);
                bt[j] = -1;
                i--;
                break;
            }
        }
    }
    printf("\n----After SJF Algorithm----\n\nPnum\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i = 0; i < process_num; i++) {
        total_tat += tat[i];
        total_wt += wt[i];
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", pnum[i], at[i], btb[i], ct[i], tat[i], wt[i]);
    }
    float avg_tat = total_tat/process_num, avg_wt = total_wt/process_num;
    printf("\nAverage Turn Around time: %0.2f\nAverage Waiting Time: %0.2f\n", avg_tat, avg_wt);
}