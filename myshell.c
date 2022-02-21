#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include "utility.h"
#include <sys/types.h>
#include <sys/stat.h>

// #define clear() printf("\033[H\033[J")
// defining contants 
#define LINES_SIZE 1024
#define MAX_lines 10


//print the shell
void screen (){
	static int screen = 1;

	if (screen == 1){
		const char* CLEAR_SCREEN_ANSI = " \e[1;1H\e[2J";
		write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
		screen = 0;
	}

	printf("#");
}

int main(){
	char cmd[100], *parameters[20];
	char *envp[] = { (char *) "PATH=/bin", 0 };

	char environ[2][LINES_SIZE] = {0};
	char pwd[LINES_SIZE] = {0};
	char myshell[LINES_SIZE] = {0};
	char buffer[LINES_SIZE] = {0};
	char command[LINES_SIZE] = {0};
	char lines[MAX_lines][LINES_SIZE] = {0};
	int lines_count = 0;

	printf("\n-------------------- SHELL STARTED --------------------\n");
	printf("\n Type 'help' to display the shell commands\n\n");
	current_Dir(pwd);
	current_Dir(myshell);
	strcpy(environ[0], "PWD: ");
	strcpy(environ[1], "MYSHELL: ");
	strcat(environ[0], pwd);
	strcat(environ[1], myshell);

	/*
	while ( 1 ){
		screen();
		
		//readcmd ( command, parameters );

		if ( fork() != 0 ){
			wait ( NULL );
		}

		else {
			strcpy ( cmd, "/bin/" );
			strcat ( cmd, command );
			execve ( cmd, parameters, envp );
		}

		if ( strcmp ( command, "quit" ) == 0 )
			break;
	}*/
	
	return 0;
}
