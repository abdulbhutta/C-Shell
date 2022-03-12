#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "utility.h"


int main(int argc, char *argv[]) {
	//Initializing variables
	int readFile = 0;
	char line[MAXCHARACTERS] = {0};
	char command[MAXCHARACTERS] = {0};
	char word[MAXWORDS][MAXCHARACTERS] = {0};
	int numberofWords=0;
	FILE *batchFile;

	//If the shell is ran with a file name,
	if (argc > 1)
	{
		//Open the file in read only 
		batchFile = fopen(argv[1], "r");
		//If the file does not exist, print out error
		if (batchFile == NULL){
			printf("Error, can not open file!!\n");
			exit(0);
		}

		//If file exist and read properly, change counter to 1; (0 = no file)
		readFile = 1;
	}

	//No read from the file, use standard input
	else{
		batchFile = stdin;
	}
	

	printf("\n========C Shell========\n\n");
	
	//If not read from file, print the current directory
	if (readFile != 1){
		printDirectory();
	}

	//while the input is not NULL (Either from stdin or File)
	while (fgets(line, MAXCHARACTERS, batchFile) != NULL)  {  
		int i = 0; 
		while (line[i] != '\n'){
			i++;
		}
		line[i] = '\0';

		numberofWords = tokenization(line, word); //Get the number of words after tokenizing
		//printf("words: %d \n", numberofWords);

		strcpy(command, word[0]); //Extract the command word

		// if (fork()> 0){
		// 	printf("PARENT");
		// 	wait(NULL);
		// }

		// else {
			//If user input is cd, cd
			if (strcmp(command, "cd") == 0) {
				changeDirectory (word[1]);
				if (readFile == 1){
					printf("\n");
				}
			}

			//if user input is clr, clear the screen
			else if (strcmp(command, "clr") == 0){
				clearScreen();
			}

			// If user input is dir, display all the files in the current directory
			else if (strcmp(command, "dir") == 0){
				showDirectory();
			}

			// If user input is echo, display the current input
			else if (strcmp(command, "echo") == 0){
				echoCustom(word, numberofWords);
			}

			//If user input is help, display the manual (readme file)
			else if (strcmp(command, "help") == 0){
				help();
			}
			
			//if user input is environ, List all environment variables and their values
			else if (strcmp(command, "environ") == 0){
				environmentStrings();
			}

			//If user input is pause, do not take any input from the user
			else if (strcmp(command, "pause") == 0){
				pauseCustom();
			}

			//If user input is quit, exit the shell
			else if (strcmp(command, "quit") == 0){
				quit();
			}
		// }
		
		//Reset the word array, or it will keep the stored values from last input
		memset(line, 0, sizeof line);
		memset(command, 0, sizeof command);
		for (int i = 0; i < MAXWORDS; i++)
		{
			memset(word[i], 0, sizeof word[i]);
		}

		//Display the current directory 
	 	printDirectory();
	}

}
