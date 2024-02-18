#include <stdio.h>

int main() {
    // Integer types
    int integerVar = 10;
    char charVar = 'A';
    short shortVar = 32767;
    long longVar = 1234567890;
    long long longLongVar = 1234567890123456789;

    // Floating-point types
    float floatVar = 3.14;
    double doubleVar = 2.71828;
    long double longDoubleVar = 3.141592653589793238;

    // Void type
    void *voidPointer; // A pointer to an unknown type

    // Derived types
    int intArray[5] = {1, 2, 3, 4, 5};
    int *intPointer = &integerVar; // Pointer to an integer
    struct Point {
        int x;
        int y;
    };
    struct Point pointVar = {10, 20};

    union Number {
        int intValue;
        float floatValue;
    };
    union Number numberVar;
    numberVar.intValue = 42;

    enum Days { SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY };
    enum Days today = WEDNESDAY;

    // Printing values
    printf("Integer: %d\n", integerVar);
    printf("Character: %c\n", charVar);
    printf("Short: %hd\n", shortVar);
    printf("Long: %ld\n", longVar);
    printf("Long Long: %lld\n", longLongVar);

    printf("Float: %f\n", floatVar);
    printf("Double: %lf\n", doubleVar);
    printf("Long Double: %Lf\n", longDoubleVar);

    printf("Array: %d\n", intArray[2]);
    printf("Pointer: %d\n", *intPointer);
    printf("Struct: %d, %d\n", pointVar.x, pointVar.y);

    printf("Union: %d\n", numberVar.intValue);
    printf("Enum: %d\n", today);

    return 0;
}
