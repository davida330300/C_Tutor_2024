
#include <stdio.h>

#define MAX_NAME_LEN 16
#define MAX_ROUTE_LEN 16
#define N_ROUTES 16

// Enum defining priority
enum priority {
    PRIME,
    PRIME_URGENT,
    URGENT,
    REGULAR
};

// Struct representing a package
struct package {
    int id;                                     //  4
    int order_id;                               //  4
    char dest[MAX_NAME_LEN];                    //  1*16
    enum priority priority;                     //  4
    float value;                                //  4
    float weight;                               //  4
    char routine[N_ROUTES][MAX_ROUTE_LEN];      // 256
};

int main() {
    // Output the size of the struct package
    printf("Size of struct package: %zu bytes\n", sizeof(struct package));
    printf("Size of struct enum: %zu bytes\n", sizeof(float));
    return 0;
}