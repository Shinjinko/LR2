#include <stdio.h>
#include <string.h>
#include "functions.h"

void mode_selection(void (*task)(char*), char* file_name)
{
    FILE *file;
    int choise;
    printf("Select the appropriate option (1 - prepared file, 2 - keyboard input): ");
    scanf("%d", &choise);
    switch (choise)
    {
        case 1:
            task("D:\\Test.txt");
            break;
        case 2:
            file = fopen(file_name, "w");
            char input[100];
            printf("Enter numbers to write to the file (press '/' to stop):\n");
            rewind(file);
            gets(input);
            int length = strlen(input);
            do
            {
                fwrite(input, 1, length, file);
                fwrite("\n", 1, 1, file);
                gets(input);
                length = strlen(input);
            } while (input[length - 1] != '/');
            fclose(file);
            task(file_name);
            break;
        default:
            break;
    }
}