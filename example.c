#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5000
#define COLS 2000

int main() {
    
    clock_t start = clock();
    
    // Allocate memory for the 2D arrays
    int **array1 = malloc(ROWS * sizeof(int *));
    int **array2 = malloc(ROWS * sizeof(int *));
    if (array1 == NULL || array2 == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < ROWS; i++) {
        array1[i] = malloc(COLS * sizeof(int));
        array2[i] = malloc(COLS * sizeof(int));
        if (array1[i] == NULL || array2[i] == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }
    }

    // Interact the arrays with each other 555 times
    for (int loop = 0; loop < 555; loop++) { // Repeat 555 times
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                array1[i][j] = i + j + loop; // Sequential access
                array2[j][i] = array1[i][j]; // Cache friendly access
            }
        }
    }


    // Free the 2D arrays
    for (int i = 0; i < ROWS; i++) {
        free(array1[i]);
        free(array2[i]);
    }
    free(array1);
    free(array2);

    double runtime = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("{ \"runtime\": \"%f seconds\" }\n", runtime);

    return 0;
}

