// a program to allocate memory for 500 characters using calloc . Input n characters in allocated memory and sort them in ascending order .display the characters and free the memory .

#include <stdio.h>
#include <stdlib.h>

void sortAscending(char *arr, int n) {
    int i, j;
    char temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    char *c;

    // Allocate memory for 500 c
    c = (char *)calloc(500, sizeof(char));
    if (c == NULL) {
        printf("Memory allocation failed!\n");
        //return 1;
    }

    // Input n c into allocated memory
    printf("Enter the number of c you want to input (maximum 500): ");
    scanf("%d", &n);

    

    printf("Enter %d c: ", n);
    for (int i = 0; i < n; i++) {
        scanf(" %c", &c[i]); // Note the space before %c to consume leading whitespace
    }

    // Sort the c in ascending order
    sortAscending(c, n);

    // Display the sorted c
    printf("Sorted c in ascending order: ");
    for (int i = 0; i < n; i++) {
        printf("%c ", c[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(c);

    return 0;
}
