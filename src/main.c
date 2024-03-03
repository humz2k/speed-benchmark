#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "int_sum.h"

int main(int argc, char **argv){
    assert(argc == 2);
    int n = atoi(argv[1]);
    printf("sum(0->%d) = %d\n",n,run_int_sum(n));
    return 0;
}
