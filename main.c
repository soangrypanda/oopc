#include <stdio.h>
#include "object.h"

int main(void)
{
    void *a = new_o(object, 4, 5);
    
    printf("Size of int is %ld and of object - %ld\n",
            sizeof(int), get_size_o(object)); 

    return 0;
}
