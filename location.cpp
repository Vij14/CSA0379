#include <stdio.h>

int main() {
    int regNos[] = {1234, 5678, 9012, 3456, 7890};
    int regToSearch = 9012; // Change this to the registration number you want to search for
    int found = -1; // Initialize to -1 to indicate not found

    // Calculate the size of the array
    int size = sizeof(regNos) / sizeof(regNos[0]);

    // Search for the registration number and find its index
    for (int i = 0; i < size; ++i) {
        if (regNos[i] == regToSearch) {
            found = i;
            break;
        }
    }

    // Display the result
    if (found != -1) {
        printf("Registration number %d found at index %d.\n", regToSearch, found);
    } else {
        printf("Registration number %d not found in the array.\n", regToSearch);
    }

    return 0;
}
