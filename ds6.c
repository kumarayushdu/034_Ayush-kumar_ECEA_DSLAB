#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Structure to represent a node in the sparse matrix
struct Node {
    int row, col, value;
    struct Node *next;
};

// Function to create a new node
struct Node* createNode(int row, int col, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

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
struct Node* generateSparseMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    struct Node* head = NULL;
    struct Node* temp = NULL;
    // Storing non-zero elements and their positions
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                struct Node* newNode = createNode(i, j, matrix[i][j]);
                if (head == NULL) {
                    head = newNode;
                    temp = newNode;
                } else {
                    temp->next = newNode;
                    temp = temp->next;
                }
            }
        }
    }
    return head;
}

// Function to display sparse matrix
void displaySparseMatrix(struct Node* head) {
    struct Node* temp = head;
    printf("Sparse matrix representation:\n");
    while (temp != NULL) {
        printf("%d %d %d\n", temp->row, temp->col, temp->value);
        temp = temp->next;
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
        struct Node* sparseMatrix = generateSparseMatrix(matrix, rows, cols);
        displaySparseMatrix(sparseMatrix);
    } else {
        printf("The given matrix is not a sparse matrix.\n");
    }

    return 0;
}
