#include <stdio.h>
#include "object.h"

int main(void)
{
    void *a = new_o(object, 4, 5);
    int c; 
    void *cp = & c;
    printf("Size of int is %ld and of object - %ld\n",
            sizeof(int), get_size_o(object)); 
    printf("a is %d\n",
            get_a(a));
    delete_o(a);
    return 0;
}
