#include <stdio.h>

void printDouble(int nums[], int size) {  
    for (int i = 0; i < size; i++) {
        nums[i] *= 2;
    }
}

int main() {
    int nums[] = {10, 6, 22, 40, 1};  
    int size = sizeof(nums) / sizeof(nums[0]);  // Calculate the number of elements

    printDouble(nums, size);

    for (int i = 0; i < size; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}
