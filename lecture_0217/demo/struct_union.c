#include <stdio.h>

// Define a struct
struct MyStruct {
    int a;
    char b;
    float c;
};

// Define a union
union MyUnion {
    int a;
    char b;
    float c;
};

int main() {
    // Create an instance of the struct
    struct MyStruct myStruct;

    // Assign values to the struct members
    myStruct.a = 42;
    myStruct.b = 'X';
    myStruct.c = 3.14;

    // Print values of the struct members
    printf("Struct values:\n");
    printf("a: %d\n", myStruct.a);
    printf("b: %c\n", myStruct.b);
    printf("c: %.2f\n", myStruct.c);

    // Print the size of the struct
    printf("Size of struct: %zu bytes\n", sizeof(struct MyStruct));

    // Create an instance of the union
    union MyUnion myUnion;

    // Assign values to the union members
     myUnion.c = 3.14;
    myUnion.a = 123;
    myUnion.b = 'X';
    //myUnion.c = 3.14;
    
    // Print values of the union members
    printf("\nUnion values:\n");
    printf("a: %d\n", myUnion.a);  // Since it's a union, 'a', 'b', and 'c' share the same memory
    printf("b: %c\n", myUnion.b);
    printf("c: %.2f\n", myUnion.c);
    
    // Print the size of the union
    printf("Size of union: %zu bytes\n", sizeof(union MyUnion));

    return 0;
}
