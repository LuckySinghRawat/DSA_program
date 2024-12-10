#include <stdio.h>

void countFrequency(int arr[], int size) {
    int frequency[size];
    
    for (int i = 0; i < size; i++) {
        frequency[i] = -1;
    }
    
    for (int i = 0; i < size; i++) {
        if (frequency[i] != -1) {
            continue;
        }
        
        int count = 1;
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
                frequency[j] = 0;
            }
        }
        frequency[i] = count;
    }
    
    printf("Element | Frequency\n");
    for (int i = 0; i < size; i++) {
        if (frequency[i] != 0) {
            printf("%d       | %d\n", arr[i], frequency[i]);
        }
    }
}

int main() {
    int array[] = {1,4,1,5,2,3,1,0,6,2,1};
    int size = sizeof(array) / sizeof(array[0]);
    
    countFrequency(array, size);
    
    return 0;
}
