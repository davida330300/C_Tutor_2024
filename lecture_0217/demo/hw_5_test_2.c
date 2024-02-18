#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NAME_LEN 16
#define MAX_ROUTE_LEN 16
#define N_ROUTES 16
#define NUM_PACKAGES 10  // You can change this to the number of packages you want to write

// Enum defining priority
enum priority {
    PRIME,
    PRIME_URGENT,
    URGENT,
    REGULAR
};

// Struct representing a package
struct package {
    int id;
    int order_id;
    char dest[MAX_NAME_LEN];
    enum priority priority;
    float value;
    float weight;
    char routine[N_ROUTES][MAX_ROUTE_LEN];
};

// Function to generate a random priority
enum priority getRandomPriority() {
    return rand() % 4;  // Assumes there are 4 priority levels
}

// Function to generate a random string
void getRandomString(char *str, int len) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    for (int i = 0; i < len - 1; ++i) {
        str[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    str[len - 1] = '\0';  // Null-terminate the string
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Open a binary file for writing
    FILE *file = fopen("packages.bin", "wb");

    if (file == NULL) {
        perror("Error opening file");
        return 1;  // Return an error code
    }

    // Create an array of packages and initialize with random values
    struct package packages[NUM_PACKAGES];

    for (int i = 0; i < NUM_PACKAGES; ++i) {
        packages[i].id = i + 1;  // Assuming unique IDs
        packages[i].order_id = rand();  // Random order ID
        getRandomString(packages[i].dest, MAX_NAME_LEN);
        packages[i].priority = getRandomPriority();
        packages[i].value = (float)rand() / RAND_MAX * 100.0;  // Random float value between 0 and 100
        packages[i].weight = (float)rand() / RAND_MAX * 10.0;   // Random float weight between 0 and 10

        // Initialize routine with random strings
        for (int j = 0; j < N_ROUTES; ++j) {
            getRandomString(packages[i].routine[j], MAX_ROUTE_LEN);
        }
    }

    // Write the array to the binary file
    fwrite(packages, sizeof(struct package), NUM_PACKAGES, file);

    // Close the file
    fclose(file);

    return 0;
}
