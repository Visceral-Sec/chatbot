#include <time.h>
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 255
#define SLEEP 2

void lower(char *str)
{
	for (size_t i = 0; i < strlen(str); i++)
	{
		str[i] = tolower(str[i]);
	}
}

void sleep_exit(char *str) //closing
{
	printf("%s\n", str);
	sleep(SLEEP);
	exit(1);
}

void commands() //prints valid commands
{
	char com[20][MAX] = {
		"help",
		"exit",
	};

	printf("\nCommands available are:");
	for (int outcom = 0; outcom < 20; outcom++) //iterate through array or strings and print
	{
		printf("\n%s", com[outcom]);
	}
}

int randomRange(int min, int max)
{
	return (rand() % (max-min)) + min;
}

void greet(char *usr_input)
{
	commands();
	char responses[10][MAX] = {//list of responses
		"wagwan peng ting",
		"Whats up hot stuff xx",
		"Did I want you to speak to me?",
		"Froge?",
		"Please dont commit toaster bath on my accord...",
		"sad!",
		"Why do birds... suddenlyyy appear"
	};	
	
	if (strcmp(usr_input, "help") == 0) //if "help" then fuck up the exe
	{
		system("rm -f a.out\n");
		exit(0);
	}
	else if (strstr(usr_input, "aaa")) //if aaa in any text then print error and exit
	{
		printf("Segmentation fault (core dumped)\n");
		sleep(2);
		exit(0);
	}
	else if (strcmp(usr_input, "exit") == 0) //if exit used then exe closes
	{
		puts("closing");
		exit(0);
	}
	else //print random greet if anything else
	{
		int rnd = randomRange(0,6);
		printf("%s\n",responses[rnd]);
	}
}

int main()
{
	int again = 1;
	srand(time(NULL));
	do
	{
		char greetings[10][MAX] = { //list of greetings
			"hello",
			"hi",
			"bonjour",
			"hallo",
			"wagwan"
		};

		if (access("core.dump", F_OK) != 0)
		{
			FILE *fp;
			fp = fopen("core.dump", "w");
			printf("Segmentation fault (core dumped)\n"); //if any core.dump file doesnt exist exit
			exit(1);
		}
		char usr_input[MAX];
		int rnd = randomRange(0,4);
		printf("%s\n", greetings[rnd]);
		fgets(usr_input, sizeof(usr_input), stdin); //take user input
		lower(usr_input); //lower case it all
		greet(usr_input); //greet the user
	}
	while (again = 1);
	return 0;
}
