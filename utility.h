#ifndef utility_h
#define utility_h

#include <stdio.h>

// defining contants 
#define MAXCHARACTERS 1024
#define MAXWORDS 3




void tokenization(char* str, char lines[][MAXCHARACTERS]);
void changeDirectory(char *path);
void list_Directories(char* path);
void environmentStrings(void);
void showDirectory(void);
void clearScreen(void);
void printDirectory (void);
void echoCustom(char string[10][1024]);
void pauseCustom(void);
void help(void);


void listDirectory(char *directory);
void pwd(char *workingDirectory);
//void echoCustom(char *string);
void quit(void);

#endif /* utility_h */