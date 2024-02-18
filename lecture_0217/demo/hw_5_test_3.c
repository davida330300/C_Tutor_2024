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

    // Seek to the beginning of the 5th package
    long offset = sizeof(struct package) * 4;  // 5th package (0-based index)
    if (fseek(file, offset, SEEK_SET) != 0) {
        perror("Error seeking in file");
        fclose(file);
        return 1;
    }

    // Read the 5th package
    struct package fifthPackage;
    if (fread(&fifthPackage, sizeof(struct package), 1, file) != 1) {
        perror("Error reading from file");
        fclose(file);
        return 1;
    }

    // Close the file
    fclose(file);

    // Print the information of the 5th package
    printf("Package ID: %d\n", fifthPackage.id);
    printf("Order ID: %d\n", fifthPackage.order_id);
    printf("Destination: %s\n", fifthPackage.dest);
    printf("Priority: %d\n", fifthPackage.priority);
    printf("Value: %.2f\n", fifthPackage.value);
    printf("Weight: %.2f\n", fifthPackage.weight);

    printf("Routine:\n");
    for (int i = 0; i < N_ROUTES; ++i) {
        printf("%d: %s\n", i + 1, fifthPackage.routine[i]);
    }

    return 0;
}
