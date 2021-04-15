

struct t {
    int a;
};

void insert(void);
void search(void);
void update(void);
void print(void);

void (*f(struct t *a, long int n))(void);

int main(void) {
    char *(*p)(char *a);
    void (*a[])(void) = {insert, search, update, print};   
    struct t (*b[10])(int a, int b);
    return 0;
}



void insert(void){}
void search(void){}
void update(void){}
void print(void){}
