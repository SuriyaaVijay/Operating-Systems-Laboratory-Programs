#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>
#include<stdbool.h>

int swap(int* num1, int* num2) {
    int temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

struct QNode {
    int at, bt;
    struct QNode* next;
};

struct Queue {
    struct QNode *front, *rear;
};

struct QNode* newNode(int at, int bt)
{
    struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->at = at;
    temp->bt = bt;
    temp->next = NULL;
    return temp;
}

struct Queue* createQueue()
{
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enQueue(struct Queue* q, int at, int bt)
{
    // Create a new LL node
    struct QNode* temp = newNode(at, bt);
 
    // If queue is empty, then new node is front and rear both
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
 
    // Add the new node at the end of queue and change rear
    q->rear->next = temp;
    q->rear = temp;
}
 
// Function to remove a key from given queue q
void deQueue(struct Queue* q)
{
    // If queue is empty, return NULL.
    if (q->front == NULL)
        return;
 
    // Store previous front and move front one node ahead
    struct QNode* temp = q->front;
 
    q->front = q->front->next;
 
    // If front becomes NULL, then change rear also as NULL
    if (q->front == NULL)
        q->rear = NULL;
 
    free(temp);
}

bool isPresent(struct Queue* queue, int at, int bt) {
    struct QNode* temp = queue->front;
    while(temp != NULL) {
        if(temp->at == at && temp->bt == bt)
            return true;
        temp = temp->next;
    }
    return false;
}

void display(struct Queue* queue) {
    struct QNode* temp = queue->front;
    while(temp != NULL) {
        printf("%d\t%d\n", temp->at, temp->bt);
        temp = temp->next;
    }
}

int main() {
    struct Queue* queue = createQueue();
    int process_num, temp, present_time, time_quantum, flag = -1, max_time;
    float total_tat = 0, total_wt = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &process_num);
    printf("Enter the time quantum: ");
    scanf("%d", &time_quantum);
    int bt[process_num], at[process_num], ct[process_num], tat[process_num], wt[process_num], rt[process_num], btb[process_num], pnum[process_num];
    for(int i = 0; i < process_num; i++) {
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
                swap(&pnum[y], &pnum[y + 1]);
            }
    for(int x = 0; x < process_num - 1; x++)
        for(int y = 0; y < process_num - x - 1; y++)
            if(bt[y] > bt[y + 1] && at[y] == at[y+1]) {
                swap(&bt[y], &bt[y + 1]);
                swap(&btb[y], &btb[y + 1]);
                swap(&pnum[y], &pnum[y + 1]);
            }
    printf("Pnum\tAT\tBT\n");
    for(int i = 0; i < process_num; i++)
        printf("%d\t%d\t%d\n", i, at[i], bt[i]);
    present_time = at[0];
    max_time = at[process_num-1];
    for(int i = process_num; i > 0;) { // MAIN LOOP
        int tem = 0;
        for(int j = 0; j < process_num; j++) {
            if(at[j] <= present_time && bt[j] != -1)
                tem++;
        }
        if(tem == 0) {
            if(present_time >= max_time && queue->front == NULL) {
                break;
            }
            present_time++;
            continue;
        }
        int iter = 0;
        for(int j = 0; iter < tem; j++) {
            if(bt[j] == -1)
                continue;
            if(!isPresent(queue, at[j], bt[j])) {
                enQueue(queue, at[j], bt[j]);
            }
            iter++;
        }
        if(flag == 0) {
            int temp_at = queue->front->at;
            int temp_bt = queue->front->bt;
            deQueue(queue);
            enQueue(queue, temp_at, temp_bt);
            flag = -1;
        }
        for(int j = 0; j < process_num; j++) {
            if(queue->front->at == at[j] && queue->front->bt == bt[j]) {
                if(rt[j] == -1)
                    rt[j] = present_time - at[j];
                if(bt[j] > time_quantum) {
                    present_time += time_quantum;
                    bt[j] -= time_quantum;
                    queue->front->bt = bt[j];
                    flag = 0;
                }
                else {
                    present_time += bt[j];
                    ct[j] = present_time;
                    deQueue(queue);
                    bt[j] = -1;
                }
                if(bt[j] <= 0)
                    bt[j] = -1; 
                break;
            }
        }
    }
    printf("\n----After Round Robin Algorithm----\n\nPnum\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for(int i = 0; i < process_num; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - btb[i];
        total_tat += tat[i];
        total_wt += wt[i];
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", pnum[i], at[i], btb[i], ct[i], tat[i], wt[i], rt[i]);
    }
    float avg_tat = total_tat/process_num, avg_wt = total_wt/process_num;
    printf("\nAverage Turn Around time: %0.2f\nAverage Waiting Time: %0.2f\n", avg_tat, avg_wt);
}