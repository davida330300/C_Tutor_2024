#include <stdio.h>

const int MAX_BUF=10000000;

int main()
{
    char buf[MAX_BUF];
    int idx;
    for( idx = 0 ; idx < MAX_BUF ; idx++ )
      buf[idx]=10;
}

// segmentation fault