#include <stdio.h>

void Change();

/* Given an input of string of English character in terminal,               */  
/* change upper letter to lower letter, and lower letter to upper letter    */  
int main(){
    char str[1000];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    Change(str);

    printf("Converted string: %s\n", str);
    return 0;

}

void Change(char* str) {

    // Your code here...

}




