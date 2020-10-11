#include <stdio.h>
#include "object.h"

int main(void)
{
    void *a = new_o(object, 4, 5);
    int c; 
    void *cp = & c;
    printf("Size of int is %ld and of object - %ld\n",
            sizeof(int), get_size_o(object)); 
    printf("Object 1 a is %d\n",
            get_a(a));
    print_o(a); 
    void *b = copy_o(a);
    printf("Object 2 a is %d\n",
            get_a(b));
    print_o(b); 
    if(a != b)
        fputs("a and b are different!\n", stdout);
    
    delete_o(a);
    delete_o(b);
    return 0;
}
