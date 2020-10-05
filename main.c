#include <stdio.h>
#include "object.h"
#include "selectors.h"

int main(int argc, char **argv) 
{
    if(argc < 2) {
        fputs("Arguments less then 2!\n", stderr);
        exit(1);
    }
    int val = strtol(argv[1], 0, 10);  
    void *a = new(object, val); 
    void *b = new(object, 7);
    void *c = add(a, b);
    print(a);
    print(b);
    print(c);
    delete(a);
    delete(b);
    delete(c);
    exit(0);
}
