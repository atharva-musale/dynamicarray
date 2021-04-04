#include <stdio.h>
#include <stdlib.h>
#include "DYNAMIC.h"

int main()
{
    int i,choice, val,m;
    i= 1;

    dyarr d;
    d = init(d);

    printf("-------------- DYNAMIC ARRAY ---------------- \n");

    while(i == 1)
    {
        printf("Enter: \n");
        printf("1. to add input to array.\n");
        printf("2. to display the array.\n");
        printf("3. to find max element of array.\n");
        printf("4. to remove an element from array.\n");
        printf("5. to exit.\n");
        printf("Your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter value: ");
                    scanf("%d", &val);
                    d = addElement(d, val);
                    break;
            case 2: printArray(d);
                    break;
            case 3: m = maxElement(d);
                    printf("Max element: %d \n", d.ptr[m]);
                    break;
            case 4: printf("Enter value: ");
                    scanf("%d", &val);
                    d = removeElement(d, val);
                    break;
            case 5: i = 0;
                    destroy(d);
                    break;
        }

        printf("\n ------------------------------------ \n");

    }
    return 0;
}
