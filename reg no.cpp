#include <stdio.h>

int main() {
    int regNos[] = {1234, 5678, 9012, 3456, 7890};
    int regToSearch = 9012; // Change this to the registration number you want to search for
    int found = 0; // Flag to indicate if the registration number was found

    // Calculate the size of the array
    int size = sizeof(regNos) / sizeof(regNos[0]);

    // Search for the registration number
    for (int i = 0; i < size; ++i) {
        if (regNos[i] == regToSearch) {
            found = 1;
            break;
        }
    }

    // Display the result
    if (found) {
        printf("Registration number %d found in the array.\n", regToSearch);
    } else {
        printf("Registration number %d not found in the array.\n", regToSearch);
    }

    return 0;
}
