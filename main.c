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

    void * c = add_o(a,b);
    delete_o(&c);
    c = sub_o(a,b);
    delete_o(&c);
    c = mult_o(a,b);
    delete_o(&c);
    c = div_o(a,b);
    delete_o(&c);

    delete_o(&a);
    delete_o(&b);
    return 0;
}
