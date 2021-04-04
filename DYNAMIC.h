#include <stdio.h>
#include <stdlib.h>

struct dynamicarray
{
    int size;
    int capacity;
    int* ptr;
};

typedef struct dynamicarray dyarr;

dyarr init(dyarr d)
{
    int* p;
    p = (int*)malloc(2 * sizeof(int));
    d.ptr = p;
    d.size = 0;
    d.capacity = 2;
    return d;
}

void destroy(dyarr d)
{
    free(d.ptr);
}


dyarr expandArray(dyarr d)
{
    int i,k;
    k = d.capacity;
    d.capacity = d.capacity *2;
    int *p, *temp;
    temp = d.ptr;
    p = (int*)malloc(d.capacity * sizeof(int));

    for(i= 0; i<k;i++)
    {
        p[i] = temp[i];
    }
    d.ptr = p;
    free(temp);

    return d;
}

dyarr addElement(dyarr d,int val)
{
    if(d.size < d.capacity)
    {
        d.ptr[d.size] = val;
        d.size++;
    }
    else
    {
        d = expandArray(d);
        d.ptr[d.size] = val;
        d.size++;
    }
    printf(" Size = %d", d.size);
    printf(" Capacity = %d", d.capacity);

    return d;
}

void printArray(dyarr d)
{
    int i;
    printf("Array: ");
    for(i= 0; i<d.size; i++)
    {
        printf("%d ",d.ptr[i]);
    }
    printf("\n");
}

int maxElement(dyarr d)
{
    int* temp = d.ptr;
    int max = 0, i, index;
    for(i=0; i<d.size; i++)
    {
        if(max < temp[i])
        {
            max = temp[i];
            index = i;
        }
    }
    return index;
}

int findElement(dyarr d, int val)
{
    int* temp = d.ptr;
    int index, i;
    for(i=0; i<d.size; i++)
    {
        if(val == temp[i])
        {
            index = i;
            return index;
        }
    }
    return -1;
}

dyarr removeElement(dyarr d, int val)
{
    int i;
    int* temp = d.ptr;
    int index = findElement(d,val);
    if(index == -1){ return d; }

    else if(index == d.size-1)
    {
        d.size--;
        return d;
    }
    else{
        for(i = index; i<d.size-1; i++)
        {
            temp[i] = temp[i+1];
        }
        d.size--;
        return d;
    }
}
