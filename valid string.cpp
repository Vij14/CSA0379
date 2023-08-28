#include <stdio.h>
#include <stdbool.h>

bool isValidString(const char *str) {
    if (str == NULL) {
        return false; 
    }

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 32 || str[i] > 126) {
            return false; 
        }
    }

    return true;
}

int main() {
    char input1[] = "Hello, world!";
    char input2[] = "helloworld!"; 
    
    if (isValidString(input1)) {
        printf("Input 1 is a valid string.\n");
    } else {
        printf("Input 1 is not a valid string.\n");
    }
    
    if (isValidString(input2)) {
        printf("Input 2 is a valid string.\n");
    } else {
        printf("Input 2 is not a valid string.\n");
    }

    return 0;
}
