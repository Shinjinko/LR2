#ifndef LR2_FUNCTIONS_H
#define LR2_FUNCTIONS_H
void mode_selection(void (*task)(char*), char* file_name);
int occurrences(char *file_name, char *word);
void process(char* line, char separators[], char* words[], int final_sequence[], int *words_count);
void change_words (char* file_name, int *words_count, char* words[], int final_sequence[], char* separators);
void splitting_lines (char* file_name);
void reverse_words(char* file_name);
#endif //LR2_FUNCTIONS_H
