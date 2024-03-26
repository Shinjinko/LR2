#include <stdio.h>
#include <string.h>
#include "tasks.h"

int is_even_length(char *word)
{
    return (strlen(word) % 2 == 0);
}

void reverse(char *line, char* file_name, int line_size)
{
    FILE *file = fopen(file_name, "r+");

    char *words[81];
    int indices[81];
    int word_count = 0;
    int even = -1;

    char *word = strtok(line, " \n");
    while (word != NULL)
    {
        words[word_count] = word;
        if (is_even_length(word))
        {
            even++;
            indices[even] = word_count;
        }
        word_count++;
        word = strtok(NULL, " \n");
    }

    fseek(file, line_size, SEEK_SET);
    for (int i = 0; i < word_count; i++)
    {
        if (is_even_length(words[i]))
        {
            fwrite(words[indices[even]], strlen(words[indices[even]]), 1, file);
            even--;
        }
        else
        {
            fwrite(words[i], strlen(words[i]), 1, file);
        }
        if (i < word_count - 1)
        {
            fprintf(file, " ");
        }
    }
    fclose(file);
}



void wrong_task2(char* file_name)
{
    FILE *file = fopen(file_name, "r");
    char line[10000];
    long int pos = 0;

    while (fgets(line, sizeof(line), file) != NULL)
    {
        reverse(line, file_name, pos);
        pos = ftell(file);
    }

    fclose(file);
}