#include <stdio.h>
#include "clinic.h"
#include <string.h>

//Delete '\n'
void deleteFgets (char *buffer, int max_len) {
    if (buffer == NULL || max_len <= 0) {
        return;
    }
    if (fgets(buffer, max_len, stdin) == NULL) {
        buffer[0] = '\0';
        return;
    }
    size_t length = strlen(buffer);
    if (length > 0 && buffer[length - 1] == '\n') {
        buffer[length - 1] = '\0';
    } else {
        int discardedChar;
        while ((discardedChar = getchar()) != '\n' && discardedChar != EOF) { }
    }
}

int readInteger(int *value) {
    char inputText[INPUT_BUFFER_SIZE];
    char extra;

    deleteFgets(inputText, INPUT_BUFFER_SIZE);

    if (inputText[0] == '\0') {
        return feof(stdin) ? -1 : 0;
    }

    if (sscanf(inputText, " %d %c", value, &extra) != 1) {
        return 0;
    }

    return 1;
}