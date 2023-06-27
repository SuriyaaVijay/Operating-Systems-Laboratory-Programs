#include <stdio.h>
int isPresent(int *arr, int num, int present_index) {
    int index = -1;
    for (int i = present_index; i >= 0; i--)
        if (arr[i] == num) {
            index = i;
            break;
        }
    return index;
}
int findLRUIndex(int *arr, int *frame_arr, int request_num, int frame_size, int present_index) {
    int prev_temp, prev=999;
    for (int i = 0; i < frame_size; i++) {
        prev_temp = isPresent(arr, frame_arr[i], present_index);
        if(prev_temp < prev)
            prev = prev_temp;
    }
    for(int i = 0; i < frame_size; i++) {
        if(arr[prev] == frame_arr[i])
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
    for (int i = 0; i < request_num; i++) {
        if (i < frame_size) {
            frame_arr[i] = arr[i];
            page_fault++;
            for (int j = 0; j < i + 1; j++)
                printf("%d - ", frame_arr[j]);
            printf("\n\n");
        }
        else {
            if (isPresent(frame_arr, arr[i], frame_size-1) == -1) {
                int prev_index = findLRUIndex(arr, frame_arr, request_num, frame_size, i);
                frame_arr[prev_index] = arr[i];
                page_fault++;
                
            }
            for (int j = 0; j < frame_size; j++)
                printf("%d - ", frame_arr[j]);
            printf("\n\n");
        }
    }
    printf("No. of page faults: %d\n", page_fault);
}