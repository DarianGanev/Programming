#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ull;

ull reduce(ull arr[], ull arrlen, ull (*ptr)(ull, ull), ull first)
{
    ull result = first;
    for (ull i = 0; i < arrlen; i++)
    {
        result = ptr(result, arr[i]);
    }
    return result;
}

ull add(ull a, ull b)
{
    return a + b;
}

int main()
{
    ull arr[] = {1, 2, 3};
    ull arrlen = sizeof(arr) / sizeof(arr[0]);

    ull result = reduce(arr, arrlen, add, 0);
    printf("Result: %llu\n", result);

    return 0;
}