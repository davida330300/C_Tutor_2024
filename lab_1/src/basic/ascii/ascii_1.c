#include <stdio.h>

/*  Take a look at ASCII table                                                      */
/*  You can find out that every char is associate with a int value, from 0 ~ 128    */
/*  Write a code to print all the ascii int value, associate with its char          */
/*  You may find out the first 32 char cannot be print, it is fine                  */
int main()
{

    for (int i = 0; i < 128; i++)
    {
        // Your code here...
        printf("ascii %d, %c\n", i, i);
    }
    printf("\n");

    return 0;
}
/*  It seems that, we can CAST int into char..., we can discuss about casting a little more */