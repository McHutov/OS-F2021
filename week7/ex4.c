#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void* newRealloc(void *ptr,size_t size) {
    
    void *newArr;
    if(ptr == NULL) {
        newArr = malloc(size);
    } else {
        if (size == 0) {
            free(ptr);
        } else {
            newArr = malloc(size);
            size_t newSize = sizeof(ptr);
            if( newSize > size){
                memcpy(newArr,ptr,newSize);
            } else {
                memcpy(newArr,ptr,size);
            }
        }
    }
    
    free(ptr);
    return newArr;
    
}

int main(){
    
    printf("Enter original array size:");
	int n1=0;
	scanf("%d",&n1);
	//Create a new array of n1 ints
	int* a1 = malloc(n1*sizeof(int));
	int i;
	for(i=0; i<n1; i++){
		//Set each value in a1 to 100
		a1[i]=100;
		
		//Print each element out (to make sure things look right)
		printf("%d ",a1[i]);
	}

	//User specifies the new array size, stored in variable n2.
	printf("\nEnter new array size: ");
	int n2=0;
	scanf("%d",&n2);

	//Dynamically change the array to size n2
	a1 = realloc(a1, n2);

	//If the new array is a larger size, set all new members to 0. Reason: dont want to use uninitialized variables.

	if(n2 > n1) {
	    for(int i = n1; i < n2; i++) {
	        a1[i] = 0;
	    }
	}
	

	for(i=0; i<n2;i++){
		//Print each element out (to make sure things look right)
		printf("%d ",a1[i]);
	}
	printf("\n");
	
	//Done with array now, done with program :D
    free(a1);
	return 0;
}


