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
        return 1;  // Return an errr code
    }

    // Seek to the beginning of the 5th package
    long offset = sizeof(struct package) * 4;  // 5th package (0-based index)
    if (fseek(file, offset, SEEK_SET) != 0) {
        perror("Error seeking in file");
        fclose(file);
        return 1;
    }

    // Create a new random package
    struct package newPackage;
    newPackage.id = -1;  // Replace with your desired ID or generate dynamically
    newPackage.order_id = rand();  // Random order ID
    getRandomString(newPackage.dest, MAX_NAME_LEN);
    newPackage.priority = getRandomPriority();
    newPackage.value = (float)rand() / RAND_MAX * 100.0;  // Random float value between 0 and 100
    newPackage.weight = (float)rand() / RAND_MAX * 10.0;   // Random float weight between 0 and 10

    // Initialize routine with random strings
    for (int i = 0; i < N_ROUTES; ++i) {
        getRandomString(newPackage.routine[i], MAX_ROUTE_LEN);
    }

    // Write the new package to the file
    if (fwrite(&newPackage, sizeof(struct package), 1, file) != 1) {
        perror("Error writing to file");
        fclose(file);
        return 1;
    }

    // Close the file
    fclose(file);

    printf("New package written to the 5th position in packages.bin.\n");

    return 0;
}

// for(){
// if(package.route[i][j] != '.' && j == MAX_ROUTE_LEN-1){
//     // len = MAX_ROUTE_LEN;
//     // break;
// }else if(package.route[i][j] == '.'){
//     // len = j;
//     // dbreak;
// // }else if(package.route[i][j] != '.' && j != MAX_ROUTE_LEN-1){
// //     j++
// // }
// }

// max_route_len = rout_len