#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read_line.h"

#define NAME_LEN 25

struct part {
    int number;
    char name[NAME_LEN+1];
    int on_hand;
    struct part *next;
};

struct part *inventory = NULL;

int num_parts = 0;

struct part *find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
void dump(void);
void restore(void);
void print_part(struct part *p);

int main(void) {
    char code;
    for(;;) {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while(getchar() != '\n')
            ;
        switch(code) {
            case 'i': insert();
                    break;
            case 's': search();
                    break;
            case 'u': update();
                    break;
            case 'p': print();
                    break;
            case 'd': dump();
                    break;
            case 'r': restore();
                    break;
            case 'q': return 0;
            default: printf("Illegal code\n");
        }
        printf("\n");
    }
}

struct part *find_part(int number) {
    struct part *p;
    for (p = inventory;
        p != NULL && number > p->number;
        p = p->next)
        ;
    if (p != NULL && number == p->number)
        return p;
    return NULL;
}

void insert(void) {
    struct part *cur, *prev, *new_node;

    new_node = malloc(sizeof(struct part));
    if (new_node == NULL) {
        printf("Database is full; can't add more parts.\n");
        return;
    }
    printf("Enter part number: ");
    scanf("%d", &new_node->number);
    for (cur = inventory, prev = NULL;
        cur != NULL && new_node->number > cur->number;
        prev = cur, cur = cur->next)
        ;
    if (cur != NULL && new_node->number == cur->number) {
        printf("Part already exists.\n");
        free(new_node);
        return;
    }

    printf("Enter part name: ");
    read_line(new_node->name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &new_node->on_hand);
    new_node->next = cur;
    if (prev == NULL)
        inventory = new_node;
    else
        prev->next = new_node;
}

void search(void) {
    int number;
    struct part *p;

    printf("Enter part number: ");
    scanf("%d", &number);
    p = find_part(number);
    if (p != NULL) {
        printf("Part name: %s\n", p->name);
        printf("Quantity on hand: %d\n", p->on_hand);
    } else {
        printf("Part not found\n");
    }
}

void update(void) {
    int number, change;
    struct part *p;

    printf("Enter part number: ");
    scanf("%d", &number);
    p = find_part(number);
    if (p != NULL) {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        p->on_hand += change;
    } else {
        printf("Part not found.\n");
    }
}

void print(void) {
    struct part *p;
    printf("Part Number\tPart Name\tQuantity on Hand\n");
    for (p = inventory; p != NULL; p = p->next)
        printf("%7d\t%-25s%11d\n", p->number, p->name, p->on_hand);
}

void dump(void) {

    FILE *fd;
    char filename[25+1];
    struct part *item = inventory;
    printf("Enter name of output file: ");
    read_line(filename, 25);
    if((fd = fopen(filename, "wb")) != NULL) {
        while(item != NULL) {
            fprintf(fd, "%d|%d|%s|%d\n", 
                item->number, strlen(item->name), item->name, item->on_hand); 
            item = item->next;
        } 
        fwrite(inventory, sizeof(struct part), num_parts, fd);         
        fclose(fd);
    } else {
        printf("Failed to open file %s\n", filename);
    }
}

void restore(void) {

    FILE *fd;
    char filename[25+1];
    char fmt[10];
    struct part *head, *item, *new_inventory = NULL;
    int name_len;
    printf("Enter name of input file: ");
    read_line(filename, 25);
    if((fd = fopen(filename, "rb")) != NULL) {
        while(1) {
            item = malloc(sizeof(struct part));
            if(2 != fscanf(fd, "%d|%d|", &item->number, &name_len)) {
                break;
            }
            sprintf(fmt, "%%%dc|%%d\n", name_len);
            fscanf(fd, fmt, &item->name, &item->on_hand);
            item->name[name_len+1] = '\0';

            if(new_inventory == NULL) {
                new_inventory = item;
                head = item;
            } else {
                head->next = item;
                head = item;
            }
        }
        inventory = new_inventory;

        fclose(fd);
    } else {
        printf("Failed to open file %s\n", filename);
    }
}

void print_part(struct part *p) {
    printf("Part Number\tPart Name\tQuantity on Hand\n");
    for (p = inventory; p != NULL; p = p->next)
        printf("%7d\t%-25s%11d\n", p->number, p->name, p->on_hand);
}
    
