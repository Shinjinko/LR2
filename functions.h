#ifndef LR2_FUNCTIONS_H
#define LR2_FUNCTIONS_H
void mode_selection(void (*task)(char*), char* file_name);
int strCmp(const char *x, const char *y);
int occurrences(char *file_name, char *word);
#endif //LR2_FUNCTIONS_H
