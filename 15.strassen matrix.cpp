#include <stdio.h>
#include <stdlib.h>

// Function to add two matrices
void add(int n, int **A, int **B, int **C) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to subtract two matrices
void subtract(int n, int **A, int **B, int **C) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Function to multiply two matrices using Strassen's algorithm
void strassen(int n, int **A, int **B, int **C) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = n / 2;
    int **A11, **A12, **A21, **A22;
    int **B11, **B12, **B21, **B22;
    int **C11, **C12, **C21, **C22;
    int **P1, **P2, **P3, **P4, **P5, **P6, **P7;
    int **temp1, **temp2;

    // Allocate memory for submatrices
    A11 = (int **)malloc(newSize * sizeof(int *));
    A12 = (int **)malloc(newSize * sizeof(int *));
    A21 = (int **)malloc(newSize * sizeof(int *));
    A22 = (int **)malloc(newSize * sizeof(int *));
    B11 = (int **)malloc(newSize * sizeof(int *));
    B12 = (int **)malloc(newSize * sizeof(int *));
    B21 = (int **)malloc(newSize * sizeof(int *));
    B22 = (int **)malloc(newSize * sizeof(int *));
    C11 = (int **)malloc(newSize * sizeof(int *));
    C12 = (int **)malloc(newSize * sizeof(int *));
    C21 = (int **)malloc(newSize * sizeof(int *));
    C22 = (int **)malloc(newSize * sizeof(int *));
    P1 = (int **)malloc(newSize * sizeof(int *));
    P2 = (int **)malloc(newSize * sizeof(int *));
    P3 = (int **)malloc(newSize * sizeof(int *));
    P4 = (int **)malloc(newSize * sizeof(int *));
    P5 = (int **)malloc(newSize * sizeof(int *));
    P6 = (int **)malloc(newSize * sizeof(int *));
    P7 = (int **)malloc(newSize * sizeof(int *));
    temp1 = (int **)malloc(newSize * sizeof(int *));
    temp2 = (int **)malloc(newSize * sizeof(int *));
    for (int i = 0; i < newSize; i++) {
        A11[i] = (int *)malloc(newSize * sizeof(int));
        A12[i] = (int *)malloc(newSize * sizeof(int));
        A21[i] = (int *)malloc(newSize * sizeof(int));
        A22[i] = (int *)malloc(newSize * sizeof(int));
        B11[i] = (int *)malloc(newSize * sizeof(int));
        B12[i] = (int *)malloc(newSize * sizeof(int));
        B21[i] = (int *)malloc(newSize * sizeof(int));
        B22[i] = (int *)malloc(newSize * sizeof(int));
        C11[i] = (int *)malloc(newSize * sizeof(int));
        C12[i] = (int *)malloc(newSize * sizeof(int));
        C21[i] = (int *)malloc(newSize * sizeof(int));
        C22[i] = (int *)malloc(newSize * sizeof(int));
        P1[i] = (int *)malloc(newSize * sizeof(int));
        P2[i] = (int *)malloc(newSize * sizeof(int));
        P3[i] = (int *)malloc(newSize * sizeof(int));
        P4[i] = (int *)malloc(newSize * sizeof(int));
        P5[i] = (int *)malloc(newSize * sizeof(int));
        P6[i] = (int *)malloc(newSize * sizeof(int));
        P7[i] = (int *)malloc(newSize * sizeof(int));
        temp1[i] = (int *)malloc(newSize * sizeof(int));
        temp2[i] = (int *)malloc(newSize * sizeof(int));
    }

    // Divide matrices into submatrices
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // Calculate intermediate matrices
    add(newSize, A11, A22, temp1);
    add(newSize, B11, B22, temp2);
    strassen(newSize, temp1, temp2, P1);

    add(newSize, A21, A22, temp1);
    strassen(newSize, temp1, B11, P2);

    subtract(newSize, B12, B22, temp1);
    strassen(newSize, A11, temp1, P3);

    subtract(newSize, B21, B11, temp1);
    strassen(newSize, A22, temp1, P4);

    add(newSize, A11, A12, temp1);
    strassen(newSize, temp1, B22, P5);

    subtract(newSize, A21, A11, temp1);
    add(newSize, B11, B12, temp2);
    strassen(newSize, temp1, temp2, P6);

    subtract(newSize, A12, A22, temp1);
    add(newSize, B21, B22, temp2);
    strassen(newSize, temp1, temp2, P7);

    // Calculate result submatrices
    add(newSize, P1, P4, temp1);
    subtract(newSize, temp1, P5, temp2);
    add(newSize, temp2);
