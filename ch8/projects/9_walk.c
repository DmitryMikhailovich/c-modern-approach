#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 10

int main(void)
{
    char grid[N][N];
    int i, j, k, di, dj, move;
    
    srand((unsigned) time(NULL));

    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            grid[i][j] = '.';
    //start at upper left corner
    i = 0; j = 0;
    for(k = 0; k < 26; k++) {
        grid[i][j] = 'A' + k;
        move = rand() % 4;

        int moves[4][2] = {0};
        if(i - 1 >= 0 && grid[i-1][j] == '.') {
            moves[0][0] = -1;
        }
        if(j + 1 < N && grid[i][j+1] == '.') {
            moves[1][1] = 1;
        }
        if(i + 1 < N && grid[i+1][j] == '.') {
            moves[2][0] = 1;
        }
        if(j - 1 >= 0 && grid[i][j-1] == '.') {
            moves[3][1] = -1;
        }
        for(int m = 0; m < 4; m++) {
            di = moves[move][0], dj = moves[move][1];
            if(di == 0 && dj == 0) {
                move = (move + 1) % 4;
            } else {
                i += di, j += dj;
                break;
            }
        }
        
        if(di == 0 && dj == 0) 
            break;
    }

    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++) {
            printf("%c ", grid[i][j]);
        if (j == N - 1)
            printf("\n");
        }
    return 0;
}
