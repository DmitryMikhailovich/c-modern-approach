#include <stdio.h>
#include "7_queueADT.h"

int main(void) {
    Queue q1, q2;
    Item n;

    q1 = create();
    q2 = create();

    insert(q1, 1);
    insert(q1, 2);

    n = remove_item(q1);
    printf("Removed %d from q1\n", n);
    insert(q2, n);
    n = remove_item(q1);
    printf("Removed %d from q1\n", n);
    insert(q2, n);

    destroy(q1);

    while(!is_empty(q2))
        printf("Removed %d from q2\n", remove_item(q2));

    insert(q2, 3);
    make_empty(q2);
    if(is_empty(q2))
        printf("q2 is empty\n");
    else
        printf("q2 is not empty\n");

    destroy(q2);

    return 0;
}
    
    
