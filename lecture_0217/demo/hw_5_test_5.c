#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NAME_LEN 16
#define MAX_ROUTE_LEN 16
#define N_ROUTES 16
#define NUM_PACKAGES 10

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

    // Open the binary file for reading and writing
    FILE *file = fopen("packages.bin", "r+b");

    if (file == NULL) {
        perror("Error opening file");
        return 1;  // Return an error code
    }

    // Seek to the beginning of the file
    if (fseek(file, 0, SEEK_SET) != 0) {
        perror("Error seeking in file");
        fclose(file);
        return 1;
    }

    // Search for the first package with id equal to -1
    struct package currentPackage;
    int packageIndex = -1;
    for (int i = 0; i < NUM_PACKAGES; ++i) {
        fread(&currentPackage, sizeof(struct package), 1, file);
        printf("%d\n", currentPackage.id);
        if (currentPackage.id == -1) {
            printf("found! %d\n", i);
            packageIndex = i;
            break;
        }

        // Move the file pointer back to the beginning of the current package
        fseek(file, -sizeof(struct package), SEEK_CUR);
    }

    if (packageIndex != -1) {
        // Create a new random package
        struct package newPackage;
        newPackage.id = 999;  // Replace with your desired ID or generate dynamically
        newPackage.order_id = rand();  // Random order ID
        getRandomString(newPackage.dest, MAX_NAME_LEN);
        newPackage.priority = getRandomPriority();
        newPackage.value = (float)rand() / RAND_MAX * 100.0;  // Random float value between 0 and 100
        newPackage.weight = (float)rand() / RAND_MAX * 10.0;   // Random float weight between 0 and 10

        // Initialize routine with random strings
        for (int i = 0; i < N_ROUTES; ++i) {
            getRandomString(newPackage.routine[i], MAX_ROUTE_LEN);
        }

        // Write the new package to the file at the found index
        fseek(file, packageIndex * sizeof(struct package), SEEK_SET);
        if (fwrite(&newPackage, sizeof(struct package), 1, file) != 1) {
            perror("Error writing to file");
            fclose(file);
            return 1;
        }

        printf("Found and overwritten the package with id -1 at position %d in packages.bin.\n", packageIndex);
    } else {
        printf("No package with id -1 found in packages.bin.\n");
    }

    // Close the file
    fclose(file);

    return 0;
}
