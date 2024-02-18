#include <stdbool.h>
#include <stdio.h>
bool is_one(int i) { return i == 1; }
int main()
{
    struct
    {
        signed int a : 1;
    } obj = {
        .a = 1
    };

    puts(is_one(obj.a) ? "one" : "not one");
    return 0;
}

// WTF?