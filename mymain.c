#include <stdio.h>
#include <stdlib.h> 
#include "mymatrix.h"

void read_mat(mat* matrix);
mat* get_matrix_by_index(int index) ;


mat *MAT_A, *MAT_B, *MAT_C, *MAT_D, *MAT_E, *MAT_F;  

typedef enum {
    ADD, SUB, MUL, MULSKLR, TRANS, STOP
} operations;

int main() {
    int x, mat_choice1, mat_choice2;
    float y; 
    MAT_A = (mat *)malloc(sizeof(mat));
    MAT_B = (mat *)malloc(sizeof(mat));
    MAT_C = (mat *)malloc(sizeof(mat));
    MAT_D = (mat *)malloc(sizeof(mat));
    MAT_E = (mat *)malloc(sizeof(mat));
    MAT_F = (mat *)malloc(sizeof(mat));

    /* Check if memory allocation is successful*/
    if (!MAT_A || !MAT_B || !MAT_C || !MAT_D || !MAT_E || !MAT_F) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    build_mat(MAT_A);
    build_mat(MAT_B);
    build_mat(MAT_C);
    build_mat(MAT_D);
    build_mat(MAT_E);
    build_mat(MAT_F);

    read_mat(MAT_A);
    read_mat(MAT_B);
    read_mat(MAT_C);
    read_mat(MAT_D);

    do {
        printf("Hi, what would you like to do?\n");
        printf("0: Add matrices\n");
        printf("1: Subtract matrices\n");
        printf("2: Multiply matrices\n");
        printf("3: Multiply matrix with scalar\n");
        printf("4: Transpose matrix\n");
        printf("5: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &x);
        if (x >= 0 && x <= 4)
       {
          printf("Choose the first matrix (0-5): ");
          scanf("%d", &mat_choice1);
          printf("Choose the second matrix (0-5): ");
          scanf("%d", &mat_choice2);
          if (mat_choice1 < 0 || mat_choice1 > 5 || mat_choice2 < 0 || mat_choice2 > 5) 
           {
             printf("Invalid matrix choice. Matrix index should be between 0 and 5.\n");
             continue;
           }
       }
       switch (x) 
       {
         case ADD:
            printf("You chose adding matrices\n");
            add_mat(get_matrix_by_index(mat_choice1), get_matrix_by_index(mat_choice2), MAT_F); /* Store result in matrix F*/
            print_mat(MAT_F);
            break;
         case SUB:
            printf("You chose subtracting matrices\n");
            sub_mat(get_matrix_by_index(mat_choice1), get_matrix_by_index(mat_choice2), MAT_F); /* Store result in matrix F*/
            print_mat(MAT_F);
            break;
         case MUL:
            printf("You chose multiplying matrices\n");
            mul_mat(get_matrix_by_index(mat_choice1), get_matrix_by_index(mat_choice2), MAT_F); /* Store result in matrix F*/
            print_mat(MAT_F);
            break;
         case MULSKLR:
            printf("You chose multiplying with scalar\n");
            printf("Enter scalar value: ");
            scanf("%f", &y);
            mul_scalar(get_matrix_by_index(mat_choice1), MAT_F, y); /* Store result in matrix F*/
            print_mat(MAT_F);
            break;
         case TRANS:
            printf("You chose transposing matrix\n");
            trans_mat(get_matrix_by_index(mat_choice1));
            print_mat(get_matrix_by_index(mat_choice1));
            break;
          case STOP:
            printf("You chose to finish the program - thank you :)\n");
            break;
          default:
            printf("Invalid choice\n");
            break;
          }
   } while (x != 5);

    free(MAT_A);
    free(MAT_B);
    free(MAT_C);
    free(MAT_D);
    free(MAT_E);
    free(MAT_F);

    return 0;
}

/* A function to insert the values into the matrix + checks the correctness of the values */
void read_mat(mat* matrix) {
    printf("Please enter a 4x4 matrix values:\n");
    int i, j, result;
    for (i = 0; i < maxlow; i++) {
        for (j = 0; j < maxrow; j++) {
            printf("Please enter number for the row %d and column %d: ", i + 1, j + 1);
            result = scanf("%f", &matrix->data[i][j]);
            if (result == EOF) {
                printf("Sorry, but you entered the enter button - EOF encountered, ERROR input.\n");
                return;
            }
            while (result != 1) {
                printf("Invalid input. Please enter a float value: ");
                while (getchar() != '\n');
                result = scanf("%f", &matrix->data[i][j]);
                if (result == EOF) {
                    printf("Sorry, but you entered the enter button - EOF encountered, ERROR input.\n");
                    return;
                }
            }
        }
    }
}


/*function for selecting the matrix*/
mat* get_matrix_by_index(int index) {
    switch (index) {
    case 0:
        return MAT_A;
    case 1:
        return MAT_B;
    case 2:
        return MAT_C;
    case 3:
        return MAT_D;
    case 4:
        return MAT_E;
    case 5:
        return MAT_F;
    default:
        return NULL;
    }
}
