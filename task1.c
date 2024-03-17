#include <stdio.h>
#include <string.h>
#include "tasks.h"

void task1 (char* file_name)
{
    FILE *file;
    char word[100];
    char buffer[100];
    int count = 0;

    scanf("%s", word);

    file = fopen(file_name, "r");

    while (fscanf(file, "%s", buffer) == 1) {
        if (strcmp(buffer, word) == 0) {
            count++;
        }
    }

    printf("Count: %d \n", count);

    fclose(file);
}