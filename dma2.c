#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    // Allocate memory for 100 floating-point num
    float *num = (float *)calloc(100, sizeof(float));
    if (num == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input n floating-point num into allocated memory
    printf("Enter the number of floating-point num you want to input (less than 100): ");
    scanf("%d", &n);

    if (n > 100 || n <= 0) {
        printf("Invalid input! Please enter a number less than 100 and greater than 0.\n");
        free(num);
        return 1;
    }

    printf("Enter %d floating-point num: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &num[i]);
    }

    // Find the maximum and minimum values
    float max1 = num[0], min1 = num[0];
    for (int i = 1; i < n; i++) {
        if (num[i] > max1) {
            max1 = num[i];
        }
        if (num[i] < min1) {
            min1 = num[i];
        }
    }

    // Initialize second maximum and second minimum
    float max2 = (max1 == num[0]) ? num[1] : num[0];
    float min2 = (min1 == num[0]) ? num[1] : num[0];

    // Find the second maximum and second minimum
    for (int i = 0; i < n; i++) {
        if (num[i] != max1 && num[i] > max2) {
            max2 = num[i];
        }
        if (num[i] != min1 && num[i] < min2) {
            min2 = num[i];
        }
    }

    // Print the second maximum and second minimum
    printf("Second maximum: %.2f\n", max2);
    printf("Second minimum: %.2f\n", min2);

    // Free the allocated memory
    free(num);

    return 0;
}
