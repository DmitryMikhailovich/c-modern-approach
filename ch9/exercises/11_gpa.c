#include <stdio.h>

float compute_GPA(char grades[], int n);

float compute_GPA(char grades[], int n) {
    float total = 0.0f;
    for(int i = 0; i < n; i++) {
        switch(grades[i]) {
            case 'A': total += 4; break;
            case 'B': total += 3; break;
            case 'C': total += 2; break;
            case 'D': total += 1; break;
            case 'F': total += 0; break;
        }
    }
    return total / n;
}

