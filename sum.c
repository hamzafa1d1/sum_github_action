#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int sum(int a, int b) {
    return a + b;
}

bool run_test(FILE *file, int test_case_num) {
    int a, b, expected, result;

    // Read inputs (a, b) and the expected result
    if (fscanf(file, "%d %d %d", &a, &b, &expected) != 3) {
        printf("Test case %d: Error reading dataset file\n", test_case_num);
        return false;
    }

    // Calculate sum
    result = sum(a, b);

    // Compare result with expected output
    if (result == expected) {
        printf("Test case %d: Passed (%d + %d = %d)\n", test_case_num, a, b, result);
        return true;
    } else {
        printf("Test case %d: Failed (%d + %d = %d, expected %d)\n", test_case_num, a, b, result, expected);
        return false;
    }
}

int main() {
    FILE *file = fopen("dataset.txt", "r");
    if (file == NULL) {
        perror("Error opening dataset file");
        return 1;
    }

    int test_case_num = 0;
    int passed = 0, failed = 0;

    printf("Running tests...\n");

    while (!feof(file)) {
        test_case_num++;
        if (run_test(file, test_case_num)) {
            passed++;
        } else {
            failed++;
        }
    }

    fclose(file);

    printf("\nTotal tests: %d | Passed: %d | Failed: %d\n", passed + failed, passed, failed);

    return (failed == 0) ? 0 : 1; // Return non-zero exit code if any test failed
}
