#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 1000 

void findDuplicates(int arr[], int size) {
    bool visited[MAX_SIZE] = {false}; 
    printf("Duplicate values:\n");
    for (int i = 0; i < size; i++) {
        if (visited[arr[i]]) {
            printf("%d\n", arr[i]);
        } else {
            visited[arr[i]] = true;
        }
    }
}

int main() {
    int arr[] = {4, 2, 7, 2, 9, 4, 7, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    findDuplicates(arr, size);

    return 0;
}
