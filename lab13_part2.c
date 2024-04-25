#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_SIZE 10


/*
A Markov chain's transition matrix M has nonnegative real numbers that represent the probabilities of transitioning between states. For each row i in the transition matrix, the sum of all probabilities must be 1. This is because the total probability of transitioning to any state from i must be 100%.

Question 1:
M^k is a Markov chain for any positive integer k because given each row in M sums to 1, the same holds true for M^k.

When you multiply matrices to obtain M^k , you are considering the combined probabilities of transitioning through multiple steps. Since each row of M^k still sums to 1, it maintains the properties of a Markov chain. I show this in my code below.

Question 2:
The (i, j)-entry of M^k computes the probability of transitioning from state i to state j in k steps.
*/


// Function to multiply two double matrices
void multiply_matrices(int n, double A[MAX_SIZE][MAX_SIZE], double B[MAX_SIZE][MAX_SIZE], double result[MAX_SIZE][MAX_SIZE]) {
    // Initialize the result matrix to zero
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = 0;
        }
    }

    // Compute product of A and B
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Function to check if each row in a matrix sums to 1 and is a valid Markov chain
bool is_valid_markov_chain(int n, double matrix[MAX_SIZE][MAX_SIZE]) {
    const double tolerance = 0.0001; // Small error tolerance for floating point errors
    for (int i = 0; i < n; i++) {
        double row_sum = 0.0;
        for (int j = 0; j < n; j++) {
            row_sum += matrix[i][j];
        }
        
        // If any row doesn't sum to 1 then it is invalid
        if (fabs(row_sum - 1.0) > tolerance) {
            return false;
        }
    }
    return true;
}

// Function to compute the power of a double matrix and validate each step to k
void matrix_power_with_validation(int n, double A[MAX_SIZE][MAX_SIZE], int k, double result[MAX_SIZE][MAX_SIZE]) {
    // Start with an identity matrix
    double temp[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                temp[i][j] = 1.0;
            } else {
                temp[i][j] = 0.0;
            }
        }
    }

    // Multiply the matrix k times
    for (int step = 1; step <= k; step++) {
        double new_result[MAX_SIZE][MAX_SIZE];
        multiply_matrices(n, temp, A, new_result);

        // Check if the new matrix is a valid Markov chain
        if (is_valid_markov_chain(n, new_result)) {
            printf("Matrix M^%d is a valid Markov chain.\n", step);
        } else {
            printf("Matrix M^%d is NOT a valid Markov chain.\n", step);
        }

        // Copy new_result into temp for the next iteration
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                temp[x][y] = new_result[x][y];
            }
        }
    }

    // Copy the final result to the output
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = temp[i][j];
        }
    }
}


// Function to print a double matrix
void print_matrix(int n, double matrix[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}


int main() {
    
    int n = 3; // Size of the transition matrix
    int k = 9; // Power to which the matrix will be raised
    
    // Transition matrix for a Markov chain
    double M[MAX_SIZE][MAX_SIZE] = {
        {0.1, 0.6, 0.3}, // Probabilities from state 0 to other states
        {0.5, 0.2, 0.3}, // Probabilities from state 1 to other states
        {0.2, 0.4, 0.4}  // Probabilities from state 2 to other states
    };

    // Create a result matrix to store M^k
    double result[MAX_SIZE][MAX_SIZE];

    // Compute the matrix to the power k with validation after each step 
    matrix_power_with_validation(n, M, k, result);

    // Print the original transition matrix
    printf("Original Transition Matrix:\n");
    print_matrix(n, M);

    // Print the resulting matrix after raising it to the power k
    printf("\nMatrix M^%d:\n", k);
    print_matrix(n, result);

    return 0;
}