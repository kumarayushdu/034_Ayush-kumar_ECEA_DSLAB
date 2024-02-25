#include <stdio.h>

// Iterative Binary Search
int binarySearchIterative(int arr[], int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        // Check if x is present at mid
        if (arr[mid] == x)
            return mid;
        
        // If x greater, ignore left half
        if (arr[mid] < x)
            left = mid + 1;
        
        // If x is smaller, ignore right half
        else
            right = mid - 1;
    }
    
    // If we reach here, then the element was not present
    return -1;
}

// Recursive Binary Search
int binarySearchRecursive(int arr[], int left, int right, int x) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
        
        // If the element is present at the middle
        if (arr[mid] == x)
            return mid;
        
        // If the element is smaller than mid, then it's in the left subarray
        if (arr[mid] > x)
            return binarySearchRecursive(arr, left, mid - 1, x);
        
        // Else, the element can only be present in the right subarray
        return binarySearchRecursive(arr, mid + 1, right, x);
    }
    
    // If the element is not present in the array
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    
    // Iterative binary search
    int resultIterative = binarySearchIterative(arr, 0, n - 1, x);
    if (resultIterative == -1)
        printf("Element is not present in array (Iterative)\n");
    else
        printf("Element is present at index %d (Iterative)\n", resultIterative);
    
    // Recursive binary search
    int resultRecursive = binarySearchRecursive(arr, 0, n - 1, x);
    if (resultRecursive == -1)
        printf("Element is not present in array (Recursive)\n");
    else
        printf("Element is present at index %d (Recursive)\n", resultRecursive);
    
    return 0;
}
