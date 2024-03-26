#include <stdio.h>
#include <string.h>
#include "tasks.h"
#include "functions.h"

void task1(char* file_name)
{
    char word[100];
    printf("Enter a word to search for: ");
    scanf("%s", word);

    int count = occurrences(file_name, word);

    if (count != -1)
    {
        printf("Count: %d\n", count);
    }
}

int occurrences(char *file_name, char *word)
{
    FILE *file;
    char buffer[100];
    int count = 0;

    file = fopen(file_name, "r");

    if (file == NULL)
    {
        printf("File opening error.\n");
        return -1; // Возвращаем -1 в случае ошибки
    }

    while (fscanf(file, "%s", buffer) == 1)
    {
        if (strcmp(buffer, word) == 0)
        {
            count++;
        }
    }

    fclose(file);

    return count;
}