#include <stdio.h>
#include <stdlib.h>
struct QNode {
    int key;
    struct QNode *next;
};
struct Queue {
    struct QNode *front, *rear;
};
struct QNode *newNode(int k) {
    struct QNode *temp = (struct QNode *)malloc(sizeof(struct QNode));
    temp->key = k;
    temp->next = NULL;
    return temp;
}
struct Queue *createQueue() {
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}
void enQueue(struct Queue *q, int k) {
    struct QNode *temp = newNode(k);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}
void deQueue(struct Queue *q) {
    if (q->front == NULL)
        return;
    struct QNode *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
}
int isPresent(int *arr, int num, int present_index, int arr_num) {
    int index = -1;
    for (int i = present_index; i < arr_num; i++) {
        if (arr[i] == num) {
            index = i;
            break;
        }
    }
    return index;
}
int findFirstIndex(int *arr, int *frame_arr, int request_num, int frame_size, int present_index) {
    int prev_temp, prev = -1;
    for (int i = 0; i < frame_size; i++) {
        prev_temp = isPresent(arr, frame_arr[i], present_index, request_num);
        if (prev_temp == -1) {
            prev = prev_temp;
            for (int j = 0; j < request_num; j++) {
                if (arr[j] == frame_arr[i])
                    return j;
            }
        }
        else if (prev_temp > prev)
            prev = prev_temp;
    }
    for (int i = 0; i < frame_size; i++) {
        if (arr[prev] == frame_arr[i])
            return i;
    }
}
int main() {
    int frame_size, request_num, page_fault = 0;
    printf("Enter the size of the frame_size: ");
    scanf("%d", &frame_size);
    printf("Enter the number of requests: ");
    scanf("%d", &request_num);
    int arr[request_num];
    for(int i = 0; i < request_num; i++) {
        printf("Enter request #%d: ", i);
        scanf("%d", &arr[i]);
    }
    int frame_arr[frame_size];
    struct Queue* q = createQueue();
    int frame_arr[frame_size];
    for (int i = 0; i < request_num; i++) {
        if (i < frame_size) {
            frame_arr[i] = arr[i];
            enQueue(q, arr[i]);
            page_fault++;
            for (int j = 0; j < i + 1; j++)
                printf("%d - ", frame_arr[j]);
            printf("\n\n");
        }
        else {
            if (isPresent(frame_arr, arr[i], 0, frame_size) == -1) {
                enQueue(q, arr[i]);
                for(int j = 0; j < frame_size; j++) {
                    if(q->front->key == frame_arr[j]) {
                        printf("Dequed: %d\n", q->front->key);
                        deQueue(q);
                        frame_arr[j] = arr[i];
                        break;
                    }
                }
                page_fault++;
            }
            for (int j = 0; j < frame_size; j++)
                printf("%d - ", frame_arr[j]);
            printf("\n\n");
        }
    }
    printf("No. of page faults: %d\n", page_fault);
}