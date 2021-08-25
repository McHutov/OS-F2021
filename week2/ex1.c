#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void) {
    int maxInteger = INT_MAX;
    float maxFloat = FLT_MAX;
    double maxDouble = DBL_MAX;
    
    printf("INT: %d\n", maxInteger);
    printf("FLOAT: %f\n", maxFloat);
    printf("DOUBLE: %f\n", maxDouble);
    printf("\n");
    printf("INT-SIZE: %ld\n", sizeof(maxInteger));
    printf("FLOAT-SIZE: %ld\n", sizeof(maxFloat));
    printf("DOUBLE-SIZE: %ld\n", sizeof(maxDouble));
    
}
