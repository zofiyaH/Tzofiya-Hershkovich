
#include "mymatrix.h"

void buildMatrix(mat *matrix) {
    int i, j;
    for (i = 0; i < maxlow; i++)
        for (j = 0; j < maxrow; j++)
            matrix->data[i][j] = 0;
}

/*Function to print matrix*/
void print_mat(mat *matrix) {
    int i, j;
    for (i = 0; i < maxlow; i++) {
        for (j = 0; j < maxrow; j++) {
            printf("%f\t", matrix->data[i][j]);
        }
        printf("\n");
    }
}

/*Function to add two matrices*/
void add_mat(mat *A, mat *B, mat *result) {
    int i, j;
    for (i = 0; i < maxlow; i++)
        for (j = 0; j < maxrow; j++)
            result->data[i][j] = A->data[i][j] + B->data[i][j];
}

/*Function to subtract two matrices*/
void sub_mat(mat *A, mat *B, mat *result) {
    int i, j;
    for (i = 0; i < maxlow; i++)
        for (j = 0; j < maxrow; j++)
            result->data[i][j] = A->data[i][j] - B->data[i][j];
}

/*Function to multiply two matrices*/
void mul_mat(mat *A, mat *B, mat *result) {
    int i, j, k;
    for (i = 0; i < maxlow; i++)
        for (j = 0; j < maxrow; j++)
            for (k = 0; k < maxlow; k++)
                result->data[i][j] += A->data[i][k] * B->data[k][j];
}

/*Function to multiply a matrix by a scalar*/

void mul_scalar(mat *A, mat *result, float a) {
    int i, j;
    for (i = 0; i < maxlow; i++)
        for (j = 0; j < maxrow; j++)
            result->data[i][j] = A->data[i][j] * a;
}

/* Function to transpose a matrix*/
void trans_mat(mat *matrix) {
    mat temp;
    int i, j;
    for (i = 0; i < maxlow; i++) {
        for (j = 0; j < i; j++) {
            temp.data[i][j] = matrix->data[i][j];
            matrix->data[i][j] = matrix->data[j][i];
            matrix->data[j][i] = temp.data[i][j];
        }
    }
}
