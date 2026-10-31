#include <stdio.h>
#include "clinic.h"
#include <string.h>

//Delete '\n'
void deleteFgets (char *buffer, int max_len) {
    fgets(buffer, max_len,stdin); 
    size_t len = strlen(buffer);
    if(len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    }else {
        int discardedChar;
        while ((discardedChar = getchar()) != '\n' && discardedChar != EOF) { }
    }
}