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
    // Read lines from standard input and encrypt each line
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), stdin) != NULL)
    {
        encrypt(buffer, 3);    // Encrypt with a key of 3
        fputs(buffer, stdout); // Write the encrypted line to standard output
    }

    printf("\nEncryption completed successfully.\n");

    return 0;
}
