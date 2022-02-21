#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

// #define clear() printf("\033[H\033[J")

//Read the command
void readcmd ( char cmd[], char *parameters[] ){
	char line [0];
	int count = 0, i = 0, j = 0;
	char *array[100], *pch;

	//read line
	for ( ;; ){
		//printf("first for loop");
		int c = fgetc ( stdin );
		line[count++] = (char) c;
		if ( c == '\n' ) 
			break;
	}

	if ( count == 1) 
		//break;
		//return;

	pch = strtok ( line, " \n");

	//Break line into tokens
	while ( pch != NULL ){
		array[i++] = strdup ( pch );
		pch = strtok ( NULL, " \n");
	}

	strcpy ( cmd, array[0] );

	for ( int j = 0; j < i; j++ ){
		parameters[j] = array[j];
	}

	parameters[i] = NULL;
}

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
	char cmd[100], command[100], *parameters[20];
	char *envp[] = { (char *) "PATH=/bin", 0 };

	while ( 1 ){
		screen();
		
		readcmd ( command, parameters );

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
	}
	
	return 0;
}
