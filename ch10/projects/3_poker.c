/* Classifies a poker hand */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5
#define RANK 0
#define SUIT 1

/* external variagles */
char hand[NUM_CARDS][2];
bool straight, flush, four, three;
int pairs; /* can be 0, 1, or 2 */

/* prototypes */
void read_cards(void);
void analyze_hand(void);
void print_result(void);

/* main: Calls read_cards, analyze_hand, and print_result repeatedly. */
int main(void)
{
    for(;;) {
        read_cards();
        analyze_hand();
        print_result();
    }
}

/* read_cards: Reads the cards into the extarnal variables num_in_rand and num_in_suit; 
 * checks for bad cards and duplicate cards. */
void read_cards(void)
{
    char ch, rank_ch, suit_ch;
    int rank, suit;
    bool bad_card, duplicate_card = false;
    int cards_read = 0;

    while(cards_read < NUM_CARDS) {
        bad_card = false;
        printf("Enter a card: ");
        
        rank_ch = getchar();
        switch(rank_ch) {
            case '0': exit(EXIT_SUCCESS);
            case '2': rank = 0; break;
            case '3': rank = 1; break; 
            case '4': rank = 2; break; 
            case '5': rank = 3; break; 
            case '6': rank = 4; break; 
            case '7': rank = 5; break; 
            case '8': rank = 6; break; 
            case '9': rank = 7; break; 
            case 't': case 'T': rank = 8; break; 
            case 'j': case 'J': rank = 9; break; 
            case 'q': case 'Q': rank = 10; break; 
            case 'k': case 'K': rank = 11; break; 
            case 'a': case 'A': rank = 12; break; 
            default: bad_card = true;
        }
    
            suit_ch = getchar();
            switch(suit_ch) {
                case 'c': case 'C': suit = 0; break;
                case 'd': case 'D': suit = 1; break;
                case 'h': case 'H': suit = 2; break;
                case 's': case 'S': suit = 3; break;
                default: bad_card = true;
            }

            while((ch = getchar()) != '\n')
                if(ch != ' ') bad_card = true;
            for(int i = 0; i < cards_read; i++)
                if(hand[i][RANK] == rank && hand[i][SUIT] == suit) {
                    duplicate_card = true;
                    break;
                }

            if(bad_card)
                printf("Bad card; ignored.\n");
            else if (duplicate_card)
                printf("Duplicate card; ignored.\n");
            else {
                hand[cards_read][RANK] = rank;
                hand[cards_read][SUIT] = suit;
                cards_read++;
            }
    }
}

/* analyze_hand: Determines whether the hand contains a straight, a flush, four-of-a-kind, and/or three-of-a-kind;
 * determines the number of pairs; stores the results into the external variables straight, flush, four, three, and pairs */
void analyze_hand(void)
{
    int num_consec = 0;
    int rank, suit;
    straight = false; 
    four = false;
    three = false;
    pairs = 0;

    /* check for flush */
    /*for (suit = 0; suit < NUM_SUITS; suit++)
        if(num_in_suit[suit] == NUM_CARDS)
            flush = true;
*/
    for(int i = 1; i < NUM_CARDS; i++)
        for(int j = 0; j < NUM_CARDS-1; j++) {
            int rank = hand[j][RANK];
            int suit = hand[j][SUIT];
            if(hand[j+1][RANK] < rank) {
                hand[j][RANK] = hand[j+1][RANK];
                hand[j][SUIT] = hand[j+1][SUIT];
                hand[j+1][RANK] = rank;
                hand[j+1][SUIT] = suit;
            }
    }
    int first_suit = hand[0][SUIT];
    flush = true;
    for(int i = 1; i < NUM_CARDS; i++)
        if(first_suit != hand[i][SUIT]) {
            flush = false;
            break;
        }
 
    /* check for straight */
    /*rank = 0;
    while (num_in_rank[rank] == 0) rank++;
    for (; rank < NUM_RANKS && num_in_rank[rank] > 0; rank++)
        num_consec++;
    */
    for(int i = 1; i < NUM_CARDS; i++)
        if(hand[i][RANK] == hand[i-1][RANK] - 1)
            num_consec++;
    if(num_consec == NUM_CARDS) {
        straight = true;
        return;
    }

    /* check for 4-of-a-kind, 3-of-a-kind, and pairs */
    /*for(rank = 0; rank < NUM_RANKS; rank++) {
        if(num_in_rank[rank] == 4) four = true;
        if(num_in_rank[rank] == 4) three = true;
        if(num_in_rank[rank] == 2) pairs++;
    }
    */
    for(int i = 0; i < NUM_CARDS - 1; i++) {
        if(i+3 < NUM_CARDS && hand[i][RANK] == hand[i+3][RANK])
            four = true;
        if(i+2 < NUM_CARDS && hand[i][RANK] == hand[i+2][RANK])
            three = true;
        if(i % 2 == 0 && i+1 < NUM_CARDS && hand[i][RANK] == hand[i+1][RANK])
            pairs++;
    }
}

/* print_result: Prints the classification of the hand, based on the values of the external variables straight, flush, four, three, and pairs. */
void print_result(void)
{
    if(straight && flush) printf("Straight flush");
    else if(four) printf("Four of a kind");
    else if(three && pairs == 1) printf("Full house");
    else if(flush) printf("Flush");
    else if(straight) printf("Straight");
    else if(three) printf("Three of a kind");
    else if(pairs == 2) printf("Two pairs"); 
    else if(pairs == 1) printf("Pair");
    else printf("High card");
    
    printf("\n\n");
}
