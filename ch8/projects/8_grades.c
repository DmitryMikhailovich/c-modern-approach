#include <stdio.h>

int main(void) 
{
    int matrix[5][5];
    int student_totals[5] = {0}, quiz_totals[5] = {0},
        min_score[5] = {0}, max_score[5] = {0};
    int i, j;
    for(i = 0; i < 5; i++) {
        printf("Enter grades for student %d: ", i+1);
        for(j = 0; j < 5; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    //initialize min_score with values from first row
    for(j = 0; j < 5; j++)
        min_score[j] = matrix[0][j];

    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            student_totals[i] += matrix[i][j];
            quiz_totals[j] += matrix[i][j];
            min_score[j] = min_score[j] > matrix[i][j] ? matrix[i][j] : min_score[j];
            max_score[j] = max_score[j] < matrix[i][j] ? matrix[i][j] : max_score[j];
        }
    }
    printf("Total scores for each student:");
    for(i = 0; i< 5; i++)
        printf(" %d", student_totals[i]);
    printf("\nQuiz average scores:");
    for(j = 0; j < 5; j++)
        printf(" %.1f", quiz_totals[j] / 5.0f);
    printf("\nQuiz lowest scores:");
    for(j = 0; j < 5; j++)
        printf(" %d", min_score[j]);
    printf("\nQuiz highest scores:");
    for(j = 0; j < 5; j++)
        printf(" %d", max_score[j]);
    printf("\n");
    return 0;
} 
