#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10


/*
Question 1
A^2 represents the number of paths of length 2 from vertex i to vertex j.

Question 2
A^k represents the number of paths of length k from vertex i to vertex j.
*/

// Function to square an adjacency matrix
void square_matrix(int n, int A[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE]) {
    // Initialize the result matrix to zero
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = 0;
        }
    }

    // Compute A^2 with matrix multiplication
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                result[i][j] += A[i][k] * A[k][j];
            }
        }
    }
}

// Function to multiply 2 matrices
void multiply_matrices(int n, int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE]) {
    // Initialize the result matrix to zero
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = 0;
        }
    }

    // Compute the product of A and B
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Function to compute A^k
void matrix_power(int n, int A[MAX_SIZE][MAX_SIZE], int k, int result[MAX_SIZE][MAX_SIZE]) {
    // Start with an identity matrix
    int temp[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[i][j] = (i == j) ? 1 : 0;
        }
    }

    // Multiply the matrix k times
    for (int i = 0; i < k; i++) {
        int new_result[MAX_SIZE][MAX_SIZE];
        multiply_matrices(n, temp, A, new_result);

        // Copy new result into temp for the next iteration
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                temp[x][y] = new_result[x][y];
            }
        }
    }

    // Copy final result to the output
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = temp[i][j];
        }
    }
}

// Function to print a matrix
void print_matrix(int n, int matrix[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    
    // Walks and Matrix Multiplication
    
    int n = 3; // Size of the matrix (n is the number of vertices)
    int k = 3; // Power to raise matrix

    // Create an adjacency matrix for a directed graph
    int A[MAX_SIZE][MAX_SIZE] = {
        {0, 1, 0}, // Edge from vertex 0 to vertex 1
        {1, 0, 1}, // Edges from vertex 1 to vertices 0 and 2
        {0, 1, 0}  // Edge from vertex 2 to vertex 1
    };

    // Create an adjacency matrix for a directed graph
    int A_k[MAX_SIZE][MAX_SIZE] = {
        {0, 1, 0}, // Edge from vertex 0 to vertex 1
        {1, 0, 1}, // Edges from vertex 1 to vertices 0 and 2
        {0, 1, 0}  // Edge from vertex 2 to vertex 1
    };
    
    // Question 1
    /*
    A^2 represents the number of paths of length 2 from vertex i to vertex j.
    */
    
    // Create a result matrix to store A^2
    int result1[MAX_SIZE][MAX_SIZE];

    // Square the adjacency matrix and compute A^2
    square_matrix(n, A, result1);

    // Print the original adjacency matrix
    printf("Original Adjacency Matrix:\n");
    print_matrix(n, A);

    // Print the squared matrix (A^2)
    printf("\nSquared Matrix (A^2):\n");
    print_matrix(n, result1);
    
    // Question 2
    /*
    A^k represents the number of paths of length k from vertex i to vertex j.
    */
    
    // Create a result matrix to store A^k
    int result2[MAX_SIZE][MAX_SIZE];

    // Compute A^k
    matrix_power(n, A_k, k, result2);

    // Print the original adjacency matrix
    printf("\nOriginal Adjacency Matrix:\n");
    print_matrix(n, A);

    // Print the result of A^k
    printf("\nMatrix A^%d:\n", k);
    print_matrix(n, result2);


    return 0;
}
