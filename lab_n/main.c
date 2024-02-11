// main.c

#include <stdio.h>
#include "cal.h"

int main() {
    // Get user input
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    // Call the function from another file
    int result = square(num);

    // Display the result
    printf("Square of %d is %d\n", num, result);

    return 0;
}
