#include <stdio.h>

int largest(int a[], int n);
int average(int a[], int n);
int num_positive(int a[], int n);

int largest(int a[], int n) {
    int largest = a[0];
    for(int i = 1; i < n; i++)
        if(largest < a[i])
            largest = a[i];
    return largest;
}
int average(int a[], int n) {
    int total = 0;
    for(int i = 0; i < n; i++) 
        total += a[i];
    return total / n;
}
int num_positive(int a[], int n) {
    int result = 0;
    for(int i = 0; i < n; i++)
        if(a[i] > 0)
            result++;
    return result;
}


