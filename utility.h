#ifndef utility_h
#define utility_h

#include <stdio.h>

#define LINES_SIZE 1024


extern void current_Dir(char* pwd);

void cd(char *path);
void clr(void);
void dir(char *directory);
void pwd(void);
void enviorn(void);
void echoCustom(char *string);

#endif /* utility_h */