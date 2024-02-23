//Write menu-driven program in c to input 1D dynamic array and perform following operations:
//a.Linear search for an element.
//b.Inserting an element at specified position.
//c.Deleting an element from the specified position.
//d.Reversing the array.
//e.Updating the array , multiply the odd-indexed elements by 2 and adding 5 to all the elements at even index.

#include <stdio.h>
#include <stdlib.h>

void display_arr(int arr[], int s) {
    printf("Array: ");
    for (int i = 0; i < s; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int linear_Search(int arr[], int s, int k) {
    for (int i = 0; i < s; ++i) {
        if (arr[i] == k) {
            return i; 
        }
    }
    return -1; 
}

void inserting_ele(int arr[], int *s, int pos, int ele) {
    if (pos < 0 || pos > *s) {
        printf("Invalid position for insertion.\n");
        return;
    }
    for (int i = *s; i > pos; --i) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = ele;
    (*s)++;
}

void deleting_ele(int arr[], int *s, int pos) {
    if (pos < 0 || pos >= *s) {
        printf("Invalid position for deletion.\n");
        return;
    }
    for (int i = pos; i < *s - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    (*s)--;
}

void reversing_arr(int arr[], int s) {
    int temp;
    for (int i = 0; i < s / 2; ++i) {
        temp = arr[i];
        arr[i] = arr[s - i - 1];
        arr[s - i - 1] = temp;
    }
}

void updating_arr(int arr[], int s) {
    for (int i = 0; i < s; ++i) {
        if (i % 2 == 0) { 
            arr[i] += 5;
        } else { 
            arr[i] *= 2;
        }
    }
}

int main() {
    int s;
    printf("Enter the size of the array: ");
    scanf("%d", &s);

    int *arr = (int *)malloc(s * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < s; ++i) {
        scanf("%d", &arr[i]);
    }

    int i;
    do {
        printf("\nMenu:\n");
        printf("1. Linear search for an element\n");
        printf("2. Insert an element at specified position\n");
        printf("3. Delete an element from specified position\n");
        printf("4. Reverse the array\n");
        printf("5. Update the array\n");
        printf("6. Display the array\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &i);

        switch (i) {
            case 1: {
                int k, pos;
                printf("Enter the element to search: ");
                scanf("%d", &k);
                pos = linear_Search(arr, s, k);
                if (pos != -1)
                    printf("Element found at index: %d\n", pos);
                else
                    printf("Element not found\n");
                break;
            }
            case 2: {
                int pos, ele;
                printf("Enter the position to insert: ");
                scanf("%d", &pos);
                printf("Enter the element to insert: ");
                scanf("%d", &ele);
                inserting_ele(arr, &s, pos, ele);
                break;
            }
            case 3: {
                int pos;
                printf("Enter the position to delete: ");
                scanf("%d", &pos);
                deleting_ele(arr, &s, pos);
                break;
            }
            case 4:
                reversing_arr(arr, s);
                printf("Array reversed.\n");
                break;
            case 5:
                updating_arr(arr, s);
                printf("Array updated.\n");
                break;
            case 6:
                display_arr(arr, s);
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (i != 7);

    free(arr); 
    return 0;
}
