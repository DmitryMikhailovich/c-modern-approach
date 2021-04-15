#include <stdio.h>

int evaluate_position(char board[8][8]);

int evaluate_position(char board[8][8]) {
    int wvalue = 0, bvalue = 0;
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            switch(board[i][j]) {
                case 'Q': wvalue += 9; break;
                case 'R': wvalue += 5; break;
                case 'B': wvalue += 3; break;
                case 'N': wvalue += 3; break;
                case 'P': wvalue += 1; break;
                case 'q': bvalue += 9; break;
                case 'r': bvalue += 5; break;
                case 'b': bvalue += 3; break;
                case 'n': bvalue += 3; break;
                case 'p': bvalue += 1; break;
            }
    return wvalue - bvalue;
} 
