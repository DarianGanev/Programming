#include <stdio.h>

int compareasc(const void * const a, const void * const b){
    int *p1 = (const int *)a;
    int *p2 = (const int *)b;

    if(*p1 > *p2) return 1;
    if(*p1 < *p2) return -1;

    return 0;
}

int comparedesc(void *a, void *b){
    int *p1 = (const int *)a;
    int *p2 = (const int *)b;

    if(*p1 > *p2) return -1;
    if(*p1 < *p2) return 1;

    return 0;
}

int main(){
    int const a = 0;
    int const b = 12;

    printf("%d, %d\n",compareasc(&a,&b), comparedesc(&a,&b));
}