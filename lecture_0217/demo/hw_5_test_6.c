#include <stdio.h>

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

int main() {
    // Open the binary file for reading
    FILE *file = fopen("packages.bin", "rb");

    if (file == NULL) {
        perror("Error opening file");
        return 1;  // Return an error code
    }

    // Read and print each package in the file
    struct package currentPackage;
    for (int i = 0; i < NUM_PACKAGES; ++i) {
        // Read the next package from the file
        fread(&currentPackage, sizeof(struct package), 1, file);

        // Print the information of the current package
        printf("Package %d:\n", i + 1);
        printf("  ID: %d\n", currentPackage.id);
        printf("  Order ID: %d\n", currentPackage.order_id);
        printf("  Destination: %s\n", currentPackage.dest);
        printf("  Priority: %d\n", currentPackage.priority);
        printf("  Value: %.2f\n", currentPackage.value);
        printf("  Weight: %.2f\n", currentPackage.weight);

        printf("  Routine:\n");
        for (int j = 0; j < N_ROUTES; ++j) {
            printf("    %d: %s\n", j + 1, currentPackage.routine[j]);
        }
    }

    // Close the file
    fclose(file);

    return 0;
}
