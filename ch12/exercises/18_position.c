#include <stdio.h>

int evaluate_position(char board[8][8]);

int evaluate_position(char board[8][8]) {
    int wvalue = 0, bvalue = 0;
    for(char *p = board[0]; p < board[0] + 8*8; p++)
            switch(*p) {
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
