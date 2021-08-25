#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    printf("Enter string: ");
    gets(str);
    
    for(int i = strlen(str); i >= 0; i--) {
        printf("%c", str[i]);
    }
}
