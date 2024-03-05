#include <stdio.h>

#define MAX_SIZE 10

// Function to check if a matrix is sparse
int isSparse(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int count_non_zero = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                count_non_zero++;
            }
        }
    }
    // If non-zero elements are less than or equal to half of total elements,
    // then the matrix is considered sparse
    if (count_non_zero <= (rows * cols) / 2) {
        return 1; // Sparse matrix
    } else {
        return 0; // Not a sparse matrix
    }
}

// Function to generate sparse matrix representation
void generateSparseMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int sparse[MAX_SIZE * MAX_SIZE][3]; // Maximum possible non-zero elements in sparse matrix
    int k = 0;
    // Storing non-zero elements and their positions
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];
                k++;
            }
        }
    }
    printf("Sparse matrix representation:\n");
    for (int i = 0; i < k; i++) {
        printf("%d %d %d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int rows, cols;

    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    if (isSparse(matrix, rows, cols)) {
        printf("The given matrix is a sparse matrix.\n");
        generateSparseMatrix(matrix, rows, cols);
    } else {
        printf("The given matrix is not a sparse matrix.\n");
    }

    return 0;
}
