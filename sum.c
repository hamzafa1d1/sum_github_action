#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("dataset.txt", "r");
    if (file == NULL) {
        perror("Error opening dataset file");
        return 1;
    }

    int a, b, expected, result;
    // Read inputs from the first line
    if (fscanf(file, "%d %d", &a, &b) != 2) {
        perror("Error reading input values");
        fclose(file);
        return 1;
    }

    // Read expected output from the second line
    if (fscanf(file, "%d", &expected) != 1) {
        perror("Error reading expected output");
        fclose(file);
        return 1;
    }

    fclose(file);

    // Compute sum
    result = a + b + 1;

    // Validate result
    if (result == expected) {
        printf("Test passed: %d + %d = %d\n", a, b, result);
        return 0;
    } else {
        printf("Test failed: %d + %d = %d, expected %d\n", a, b, result, expected);
        return 1;
    }
}
