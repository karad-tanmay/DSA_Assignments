#include <stdio.h>

int main1(){
    int x = 10;
    float k = 1.01;
    printf("This is x: %d\n", x);
    return 0;
}

/*
* line 1 - keyword -> function -> delim -> spdelim ->NULL -
* line 2 - keyw -> identifier -> assign -> integer -> spdelim -> NULL; - 0.4
* line 3 - keyw -> identifier -> assign -> fraction -> spdelim -> NULL; - 1.0
* line 4 - func -> delim -> string -> delim -> identifier -> delim -> spdelim -> NULL - 1.0
*/

int main2(){
    float k = 69.69;
    // int y = 69;
    printf("This is y: %d\n", y);
    return 0;
}

/*
* line 1 - keyword -> function -> delim -> spdelim ->NULL - 0.8 
* line 2 - keyw -> identifier -> assign -> fraction -> spdelim -> NULL; - 1.0 
* line 3 - keyw -> identifier -> assign -> integer -> spdelim -> NULL; - 1.0
* line 4 - func -> delim -> string -> delim -> identifier -> delim -> spdelim -> NULL - 1.0
*/


