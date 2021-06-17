#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    unsigned short input = atoi(argv[1]);
    // ここでinputをc1, c2に分割してください

    unsigned char c1, c2;
    c1 = input>>8;
    c2 = input;

    printf("%d %d\n", c1, c2);
}
