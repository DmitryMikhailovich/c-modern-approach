
typedef char Fcna(int);
typedef Fcna *Fcna_ptr;
typedef Fcna_ptr Fcna_ptr_array[10];
Fcna_ptr_array xa;

typedef int Int_array[5];
typedef Int_array *Fcnb(int);
Fcnb xb; 

typedef float *Fcnc_outer(int);
typedef Fcnc_outer *Fcnc_inner(void);
Fcnc_inner xc;

typedef void *Fcnd_outer(int, void (*y)(int));
typedef Fcnd_outer *Fcnd_ptr(int);
Fcnd_ptr xd;

int main(void) {

    return 0;
}
