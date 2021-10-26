#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

struct file{
    int node;
    int num;
    char *char[255];
    int o;
}

void add_file(struct file *f, char *name,  int size) {
    int k = f[size].o;
    int i = 0;
    
    while(name[i] != ' '){
        a[size].char[k] = &name[i];
        ++i;
    }
}
