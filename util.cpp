#include <stdio.h>
#include <stdlib.h>

#include "util.h"

void read_from_file(char *filename, void *buf, size_t count) {
    FILE *fp;
    size_t result;

    fp = fopen(filename, "rb");
    if (!fp) {
        printf("fopen(): \"%s\" file not exists\n", filename);
        exit(-1);
    }
    
    result = fread(buf, 1, count, fp);
    if (result != count) {
        printf("fread(): failed to read %ldbytes from \"%s\"\n", count, filename);
        exit(-1);
    }
        
    fclose(fp);
    return;
}