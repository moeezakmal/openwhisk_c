#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10000
#define COLS 1000

int main() {
    

    clock_t start = clock();

    // Allocate memory for the 2D array
    int **array = malloc(ROWS * sizeof(int *));
    if (array == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < ROWS; i++) {
        array[i] = malloc(COLS * sizeof(int));
        if (array[i] == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }
    }

    //clock_t start = clock();

    // Multiple loops that access the array sequentially
    for (int loop = 0; loop < 500; loop++) { // Repeat 500 times
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                array[i][j] = i + j + loop; // Sequential access
            }
        }
    }

    //double runtime = (double)(clock() - start) / CLOCKS_PER_SEC;
    //printf("{ \"runtime\": \"%f seconds\" }\n", runtime);

    // Free the 2D array
    for (int i = 0; i < ROWS; i++) {
        free(array[i]);
    }
    free(array);

    double runtime = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("{ \"runtime\": \"%f seconds\" }\n", runtime);

    return 0;
}

