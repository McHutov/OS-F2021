#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a,b;
    printf("Enter a and b : ");
    int errFlag = scanf("%d%d", &a, &b);
    
    if (!errFlag) {
        printf("Pls, enter integer!");
        return -1;
    }
    
    printf("A and b before swap:\n");
    printf("A: %d\n", a);
    printf("B: %d\n", b);
    printf("A and b after swap:\n");
    swap(&a, &b);
    printf("A: %d\n", a);
    printf("B: %d\n", b);
}
