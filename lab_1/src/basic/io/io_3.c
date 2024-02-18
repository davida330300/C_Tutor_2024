#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 50

int main() {
    FILE* madlibFile = fopen("madlib.txt", "r+");

    if (madlibFile == NULL) {
        fprintf(stderr, "Error opening madlib.txt\n");
        exit(EXIT_FAILURE);
    }

    // Read and print the original story
    char buffer[MAX_LENGTH];
    while (fgets(buffer, MAX_LENGTH, madlibFile) != NULL) {
        printf("%s", buffer);
    }

    // Move to the beginning of the file
    rewind(madlibFile);

    // Replace placeholders with user input
    // Use fseek to move to specific positions in the file

    // Print the modified story
    rewind(madlibFile);
    printf("\nModified Story:\n");
    while (fgets(buffer, MAX_LENGTH, madlibFile) != NULL) {
        printf("%s", buffer);
    }

    fclose(madlibFile);

    return 0;
}
