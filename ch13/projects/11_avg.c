#include <stdio.h>

#define N 50

double compute_average_word_length(const char *sentence);
int read_line(char str[], int n);

int main(void)
{
    char sentence[N+1];
    double avg_len;
    printf("Enter a sentence: ");
    read_line(sentence, N);
    avg_len = compute_average_word_length(sentence);
    printf("Average word length: %.1f\n", avg_len);
    return 0;
}


double compute_average_word_length(const char *sentence) {

    int total_len, word_cnt;
    float avg_len;
    char ch, prev_ch = '\n';
    printf("Enter a sentence: ");
    while((ch = *sentence++)) {
        if(ch != ' ') {
            total_len++;
            if(prev_ch == '\n' || prev_ch == ' ') {
                word_cnt++;
            }
        }
        prev_ch = ch;


    }
    return (double) total_len / word_cnt;

}

int read_line(char str[], int n) {
  int ch, i = 0;
  while((ch = getchar()) != '\n')
    if(i < n)
      str[i++] = ch;
  str[i] = '\n';
  return i;
}
