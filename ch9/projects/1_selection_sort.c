#include <stdio.h>

void selection_sort(int a[], int n);

int main(void) 
{
    int n;
    printf("Enter array_length: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter array of %d integers: ", n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    selection_sort(a, n);
    printf("Sorted array bo selection sort: ");
    for(int i = 0; i < n; i++)
        printf(" %3d", a[i]);
    printf("\n");
    return 0;
}

void selection_sort(int a[], int n) 
{
    int tmp, max_i, max = a[0];
    for(int i = 1; i < n; i++)
        if(a[i] > max) {
            max = a[i];
            max_i = i;
        }

    tmp = a[n-1];
    a[n-1] = max;
    a[max_i] = tmp;
    if(n > 1) 
        selection_sort(a, n-1);
}    
