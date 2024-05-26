#include <stdio.h>
int *getEvens(int n)
{
    int arr[5];
    int x = 2, i;
    for (i = 0; i < n; i++)
    {
        arr[i] = x;
        x += 2;
    }
    return arr;
}
int main()
{
    int *p;
    p = getEvens(5);
    int i;
    for (i = 0; i < 5; i++)
        printf("%d ", *(p + i));
    printf("\n");
    return 0;
}

/*
Renaissance-ProgrammingPathshala/Live_Class/Debug/test.cpp
*/