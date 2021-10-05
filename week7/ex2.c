#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter number of elements:");
    scanf("%d", &n);
    
    int *array = malloc(n*sizeof(int));
    
    for(int i = 0; i < n; i++){
        array[i] = i;
        printf("ptr[%d]=%d\n", i, array[i]);
    }
     
    free(array);
    return 0;
}

