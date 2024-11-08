
#include "../include/tree.h"
#include "../include/utilities.h"


int main(int argc, char const *argv[])
{
    
    int array[] = {50, 20, 10, 30, 40, 80, 44, 98, 15, 100, 134, 116, 165, 132, 2, 7, 42};

    size_t len_array = sizeof(array)/sizeof(array[0]);  //start int func, don`t work;
    printf("%d\n", len_array);

    Tree_sort(array, len_array);

    Html_dump(number_of_dumps);

    return 0;
}
