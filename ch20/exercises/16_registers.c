#include <stdio.h>

typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int DWORD;

int main(void) {
    union {
        struct {
            DWORD eax, ebx, ecx, edx;
        } dword;
        struct {
            WORD ax, ea, bx, eb, cx, ec, dx, ed;
        } word;
        struct {
            BYTE al, ah, eal, eah, 
            bl, bh, ebl, ebh, 
            cl, ch, ecl, ech, 
            dl, dh, edl, edh;
        } byte;
    } regs;

    regs.dword.eax = 0xABCDEF;
    printf("Value of EAX: %x, AX: %x, EA: %x\n", regs.dword.eax, regs.word.ax, regs.word.ea);

    return 0;
}
