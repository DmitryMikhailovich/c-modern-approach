/* Sorts an array of integers using Quicksort algorithm */
#include <stdio.h>

#define N 10

void quicksort(int a[], int *low, int *high);
int *split(int a[], int *low, int *high);

int main(void)
{
    int a[N], i, *low = &a[0], *high = &a[N-1];
    printf("Enter %d numbers to be sorted: ", N);
    for(i = 0; i < N; i++)
        scanf("%d", &a[i]);
    
    quicksort(a, low, high);
    printf("In sorted order: ");
    for(i = 0; i < N; i++)
        printf(" %3d", a[i]);
    printf("\n");
    
    return 0;
}

void quicksort(int a[], int *low, int *high)
{
    int *middle;
    if(low >= high) return;
    middle = split(a, low, high);
    quicksort(a, low, middle - 1);
    quicksort(a, middle + 1, high);
}

int *split(int a[], int *low, int *high)
{
    int *middle;
    int part_element = *low;

    for(;;) {
        while (low < high && part_element <= *high)
            high--;
        if(low >= high) break;
        *low = *high;
        low++;
        while(low < high && *low <= part_element)
            low++;
        if(low >= high) break;
        *high = *low;
        high--;
    }
    *high = part_element;
    middle = high;
    return middle;
}

