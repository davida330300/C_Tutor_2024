#include <stdio.h>
#include <stdlib.h>

// Function to encrypt a string by shifting each character by a specified key
void encrypt(char *str, int key)
{
    for (int i = 0; str[i] != '\0'; ++i)
    {
        // Check if the character is an uppercase letter
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = ((str[i] - 'A' + key) % 26) + 'A';
        }
        // Check if the character is a lowercase letter
        else if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = ((str[i] - 'a' + key) % 26) + 'a';
        }
        // Leave non-alphabetic characters unchanged
    }
}

int main()
{
    // Open the input file in read mode
    FILE *inputFile = fopen("input.txt", "r");

    // Check for errors during file opening
    if (inputFile == NULL)
    {
        fprintf(stderr, "Error opening input file.\n");
        exit(EXIT_FAILURE);
    }

    // Open the output file in write mode
    FILE *outputFile = fopen("output.txt", "w");

    // Check for errors during file opening
    if (outputFile == NULL)
    {
        fprintf(stderr, "Error opening output file.\n");
        fclose(inputFile);
        exit(EXIT_FAILURE);
    }

    // Read lines from the input file and encrypt each line
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), inputFile) != NULL)
    {
        encrypt(buffer, 3);        // Encrypt with a key of 3
        fputs(buffer, outputFile); // Write the encrypted line to the output file
    }

    // Close the input and output files
    fclose(inputFile);
    fclose(outputFile);

    printf("Encryption completed successfully.\n");

    return 0;
}
