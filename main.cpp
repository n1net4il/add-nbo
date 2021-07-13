#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <netinet/in.h>

#include "util.h"

int main(int argc, char *argv[]) {
    uint32_t num1, num2;

    if (argc != 3) {
        printf("usage: %s <file1> <file2>\n", argv[0]);
        exit(-1);
    }
    
    read_from_file(argv[1], &num1, 4);
    read_from_file(argv[2], &num2, 4);

    num1 = ntohl(num1);
    num2 = ntohl(num2);

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", num1, num1, num2, num2, num1 + num2, num1 + num2);

    return 0;
}