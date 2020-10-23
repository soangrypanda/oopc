#include <stdio.h>
#include "object.h"

int main(void)
{
    int i = 13;
    void *ip = &i;
    void *d = new_o(ip);


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

//    delete_o(&ip);
//    copy_o(ip);
//    print_o(ip);
//    add_o(a, ip);
//    sub_o(a, ip);
//    mult_o(a, ip);
//    div_o(a, ip);    
    return 0;
}
