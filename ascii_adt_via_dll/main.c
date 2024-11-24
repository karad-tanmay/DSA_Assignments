#include <stdio.h>
#include "ascii_adt.h"

int main()
{
    char ch;
    scanf("%c", &ch);
    DLL l;
    init_ASCII(&l);
    ASCII_of(ch, &l);
    traverse(l);
    destroy(&l);
    traverse(l);
    return 0;
}