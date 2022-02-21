#include "utility.h"
#include <unistd.h>
#include <stdlib.h>


extern void current_Dir(char* pwd){
	getcwd(pwd, LINES_SIZE); //cwd gets current directory in the array and The BUFFER_LEN argument is the size of the character array 
//if getcwd() is succesful it return the pwd argument which is the path. Otherwise, getcwd() shall return null
}


void cd(char *path) {
    chdir(path);
}

void clr(void) {
    printf("\e[1;1H\e[2J");
}

void dir(char *directory) {
    system("ls -l");
}

void enviorn(void) {
    system("env");
}

void echoCustom(char *string) {
    printf("%s\n", string);
}

void help(void) {
    
}

void pauseCustom(void) {
    
}

void quit(void) {
    
}

void pwd(void) {
    system("pwd");
}