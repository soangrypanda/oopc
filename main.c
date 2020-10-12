#include <stdio.h>
#include "object.h"

int main(void)
{
    void *a = new_o(object);
    void *b = copy_o(a);
    print_o(a);
    if(a != b)
        fputs("a and b are different!\n", stdout);
    printf("%lu\n",  get_size_o(a));
    delete_o(&a);
    delete_o(&b);
    print_o(a);
    return 0;
}
