#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "functions.h"
#define DELIM " ,.+/—()\n?!"

int task2(char* file_name)
{
    splitting_lines(file_name);
    return 0;
}

void splitting_lines (char* file_name)
{
    FILE *file = fopen(file_name, "r+");
    char line[100] = "";
    char separators[100] = "";
    char* words[100];
    int final_sequence[100];
    int words_count = 0;

    while (fgets(line, 100, file) != NULL)
    {

        process(line, separators, words, final_sequence, &words_count);

    }
//    printf("\n%s", separators);

    change_words (file_name, &words_count, words, final_sequence, separators);

//    for(int i = 0; i < words_count; i++)
//    {printf("%s ", words[i]);}


    fclose(file);
}

void process(char* line, char separators[], char* words[], int final_sequence[], int *words_count)
{
    char temp_line[100];
    int static num;
    strcpy(temp_line, line);

    char* token = strtok(temp_line, DELIM);
    while (token != NULL && *words_count < 100)
    {
        words[*words_count] = strdup(token);
        final_sequence[*words_count] = *words_count;
        char *found = strstr(line, words[*words_count]);
        int index = found - line;
        printf("%i %s ", *words_count, words[*words_count]);
        memcpy(&line[index + 1], &line[index + strlen(words[*words_count])], sizeof(char) * strlen(line));
//        printf("%d %s ", *words_count, words[*words_count]);
        (*words_count)++;
        token = strtok(NULL, DELIM);
    }
    strcat(separators, line);
}

void change_words (char* file_name, int *words_count, char* words[], int final_sequence[], char* separators)
{
    FILE *file = fopen(file_name, "r+");
    words[*words_count] = "end";
    int start = -1;
    for(int i = 0; i <= *words_count; i++)
    {
        if (strlen(words[i]) % 2 == 0 && start == -1)
        {
            start = i;
        }
        if ((strlen(words[i]) % 2 != 0 && start != -1))
        {
            int ind = i - 1;
            for(int y = start; y <= i - 1; y++)
            {
                final_sequence[y] = ind;
                ind--;
            }
            start = -1;
        }
    }
    printf("\n");
    for(int i = 0; i < *words_count; i++)
        printf("%i ", final_sequence[i]);

    int y = 0;
    rewind(file);
    for(int i = 0; i < strlen(separators); i++)
    {
        if(isdigit(separators[i]) || isalnum(separators[i]) || separators[i] == '\'')
        {
            fprintf(file, "%s", words[final_sequence[y]]);
            y++;
        }
        else
            fprintf(file, "%c", separators[i]);
    }

    fclose(file);
}
