#include <stdio.h>
#include <stdlib.h>

void strassen(int **A, int **B, int **C, int n);
void add(int **A, int **B, int **C, int n);
void subtract(int **A, int **B, int **C, int n);
void split(int **P, int **C, int iB, int jB, int n);
void join(int **C, int **P, int iB, int jB, int n);

void strassen(int **A, int **B, int **C, int n) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    } else {
        int **A11, **A12, **A21, **A22;
        int **B11, **B12, **B21, **B22;
        int **C11, **C12, **C21, **C22;
        int **P1, **P2, **P3, **P4, **P5, **P6, **P7;
        int **AResult, **BResult;

        int i, j;
        
        // Memory allocation for matrices
        A11 = (int **)malloc(n/2 * sizeof(int *));
        A12 = (int **)malloc(n/2 * sizeof(int *));
        A21 = (int **)malloc(n/2 * sizeof(int *));
        A22 = (int **)malloc(n/2 * sizeof(int *));
        B11 = (int **)malloc(n/2 * sizeof(int *));
        B12 = (int **)malloc(n/2 * sizeof(int *));
        B21 = (int **)malloc(n/2 * sizeof(int *));
        B22 = (int **)malloc(n/2 * sizeof(int *));
        C11 = (int **)malloc(n/2 * sizeof(int *));
        C12 = (int **)malloc(n/2 * sizeof(int *));
        C21 = (int **)malloc(n/2 * sizeof(int *));
        C22 = (int **)malloc(n/2 * sizeof(int *));
        P1 = (int **)malloc(n/2 * sizeof(int *));
        P2 = (int **)malloc(n/2 * sizeof(int *));
        P3 = (int **)malloc(n/2 * sizeof(int *));
        P4 = (int **)malloc(n/2 * sizeof(int *));
        P5 = (int **)malloc(n/2 * sizeof(int *));
        P6 = (int **)malloc(n/2 * sizeof(int *));
        P7 = (int **)malloc(n/2 * sizeof(int *));
        AResult = (int **)malloc(n/2 * sizeof(int *));
        BResult = (int **)malloc(n/2 * sizeof(int *));
        
        for (i = 0; i < n/2; i++) {
            A11[i] = (int *)malloc(n/2 * sizeof(int));
            A12[i] = (int *)malloc(n/2 * sizeof(int));
            A21[i] = (int *)malloc(n/2 * sizeof(int));
            A22[i] = (int *)malloc(n/2 * sizeof(int));
            B11[i] = (int *)malloc(n/2 * sizeof(int));
            B12[i] = (int *)malloc(n/2 * sizeof(int));
            B21[i] = (int *)malloc(n/2 * sizeof(int));
            B22[i] = (int *)malloc(n/2 * sizeof(int));
            C11[i] = (int *)malloc(n/2 * sizeof(int));
            C12[i] = (int *)malloc(n/2 * sizeof(int));
            C21[i] = (int *)malloc(n/2 * sizeof(int));
            C22[i] = (int *)malloc(n/2 * sizeof(int));
            P1[i] = (int *)malloc(n/2 * sizeof(int));
            P2[i] = (int *)malloc(n/2 * sizeof(int));
            P3[i] = (int *)malloc(n/2 * sizeof(int));
            P4[i] = (int *)malloc(n/2 * sizeof(int));
            P5[i] = (int *)malloc(n/2 * sizeof(int));
            P6[i] = (int *)malloc(n/2 * sizeof(int));
            P7[i] = (int *)malloc(n/2 * sizeof(int));
            AResult[i] = (int *)malloc(n/2 * sizeof(int));
            BResult[i] = (int *)malloc(n/2 * sizeof(int));
        }

        // Splitting A and B into 4 submatrices each
        split(A, A11, 0, 0, n/2);
        split(A, A12, 0, n/2, n/2);
        split(A, A21, n/2, 0, n/2);
        split(A, A22, n/2, n/2, n/2);
        split(B, B11, 0, 0, n/2);
        split(B, B12, 0, n/2, n/2);
        split(B, B21, n/2, 0, n/2);
        split(B, B22, n/2, n/2, n/2);

        // Calculating P1 to P7
        add(A11, A22, AResult, n/2);
        add(B11, B22, BResult, n/2);
        strassen(AResult, BResult, P1, n/2);

        add(A21, A22, AResult, n/2);
        strassen(AResult, B11, P2, n/2);

        subtract(B12, B22, BResult, n/2);
        strassen(A11, BResult, P3, n/2);

        subtract(B21, B11, BResult, n/2);
        strassen(A22, BResult, P4, n/2);

        add(A11, A12, AResult, n/2);
        strassen(AResult, B22, P5, n/2);

        subtract(A21, A11, AResult, n/2);
        add(B11, B12, BResult, n/2);
        strassen(AResult, BResult, P6, n/2);

        subtract(A12, A22, AResult, n/2);
        add(B21, B22, BResult, n/2);
        strassen(AResult, BResult, P7, n/2);

        // Calculating C11, C12, C21, C22
        add(P1, P4, AResult, n/2);
        subtract(AResult, P5, BResult, n/2);
        add(BResult, P7, C11, n/2);

        add(P3, P5, C12, n/2);

        add(P2, P4, C21, n/2);

        add(P1, P3, AResult, n/2);
        subtract(AResult, P2, BResult, n/2);
        add(BResult, P6, C22, n/2);

        // Joining 4 quadrants into result matrix C
        join(C, C11, 0, 0, n/2);
        join(C, C12, 0, n/2, n/2);
        join(C, C21, n/2, 0, n/2);
        join(C, C22, n/2, n/2, n/2);

        // Free memory
        for (i = 0; i < n/2; i++) {
            free(A11[i]);
            free(A12[i]);
            free(A21[i]);
            free(A22[i]);
            free(B11[i]);
            free(B12[i]);
            free(B21[i]);
            free(B22[i]);
            free(C11[i]);
            free(C12[i]);
            free(C21[i]);
            free(C22[i]);
            free(P1[i]);
            free(P2[i]);
            free(P3[i]);
            free(P4[i]);
            free(P5[i]);
            free(P6[i]);
            free(P7[i]);
            free(AResult[i]);
            free(BResult[i]);
        }

//        free(A11);
//        free(A12);
//        free(A21);
//        free(A22);
//        free(B11);
//        free(B12);
//        free(B21);
//        free(B22);
//        free(C11);
//        free(C12);
//        free(C21);
//        free(C22);
//        free(P1);
//        free(P2);
//        free(P3);
//        free(P4);
//        free(P5);
//        free(P6);
//        free(P7);
//        free(AResult);
//        free(BResult);
    }
}

void add(int **A, int **B, int **C, int n) {
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void subtract(int **A, int **B, int **C, int n) {
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void split(int **P, int **C, int iB, int jB, int n) {
    int i1, j1, i2, j2;
    for (i1 = 0, i2 = iB; i1 < n; i1++, i2++)
        for (j1 = 0, j2 = jB; j1 < n; j1++, j2++)
            C[i1][j1] = P[i2][j2];
}

void join(int **C, int **P, int iB, int jB, int n) {
    int i1, j1, i2, j2;
    for (i1 = 0, i2 = iB; i1 < n; i1++, i2++)
        for (j1 = 0, j2 = jB; j1 < n; j1++, j2++)
            C[i2][j2] = P[i1][j1];
}

int main() {
    int n, i, j;

    printf("Enter size of matrices: ");
    scanf("%d", &n);

    int **A = (int **)malloc(n * sizeof(int *));
    int **B = (int **)malloc(n * sizeof(int *));
    int **C = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        A[i] = (int *)malloc(n * sizeof(int));
        B[i] = (int *)malloc(n * sizeof(int));
        C[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter elements of matrix A:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    printf("Enter elements of matrix B:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &B[i][j]);

    strassen(A, B, C, n);

    printf("Resultant matrix C:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (i = 0; i < n; i++) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);

    return 0;
}

