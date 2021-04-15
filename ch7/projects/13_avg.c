#include <stdio.h>

int main(void)
{
    int total_len, word_cnt;
    float avg_len;
    char ch, prev_ch = '\n';
    printf("Enter a sentence: ");
    while((ch = getchar()) != '\n') {
        if(ch != ' ') {
            total_len++;
            if(prev_ch == '\n' || prev_ch == ' ') {
                word_cnt++;
            }
        }
        prev_ch = ch;


    }
    avg_len = (float) total_len / word_cnt;
    printf("Average word length: %.1f\n", avg_len);
    return 0;
}
