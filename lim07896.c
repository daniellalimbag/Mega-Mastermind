/******************************************************************************
This is to certify that this project is my own work, based on my personal
efforts in studying and applying the concepts learned. I have constructed 
the functions and their respective algorithms and corresponding code by 
myself. The program was run, tested, and debugged by my own efforts. I 
further certify that I have not copied in part or whole or otherwise 
plagiarized the work of other students and/or persons.
<Daniella Franxene P. Limbag> - <12207896> - <S17A>
******************************************************************************/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
/****************************************
Description : This function displays the instructions of the game
@return : void
*****************************************/
void DisplayInstructions()
{
	system("CLS");
	printf("OBJECTIVE\n"
			"The aim of the game is to guess a secret code: a pattern of 4 letters which represents 4 different colored code pegs.\n"
			"The roles of codebreaker and the codemaker are switched between the plays in every game.\n"
			"After every guess, feedback is immediately returned which helps narrow down the possibilities of the code.\n"
			"The player that used the least amount of attempts at the of all the games wins.\n\n");
	printf("ROLES\n"
			"> CODEBREAKER - guesses the code within a set number of attempts\n"
			"> CODEMAKER - makes the code using different code pegs\n\n");
	printf("INSTRUCTIONS\n"
			"1. Enter a number of games to be played. Number of games must be even, from 2 to a maximum of 10.\n"
			"2. Choose to start as either the codemaker or codebreaker.\n"
			"\t> You will alternate roles with the pseudo-AI player in each game\n"
			"\nCODEBREAKER...\n"
			"3. Enter a combination 4 code pegs.\n"
			"\t> You cannot duplicate code pegs.\n"
			"\t> Ex: R P G Y\n"
			"4. Within the given number of attempts, try to predict the pattern in both sequence and color.\n"
			"\t> 'B' is displayed for each peg that is correct in both position and color.\n"
			"\t> 'W' is displayed for each misplaced peg.\n"
			"5. The game ends when the you solve the code or run out of attempts.\n"
			"\nCODEMAKER...\n"
			"3. Enter a combination 4 code pegs.\n"
			"\t> You cannot duplicate code pegs.\n"
			"\t> Ex: R P G Y\n"
			"4. The game ends when the pseudo-AI player solves the code or runs out of attempts.\n\n"
			"Players can only earn points when playing as the codemaker.\n"
			"The codemaker gets one point for each attempt the codebreaker makes.\n"
			"The codemaker earns an extra point if the codebreaker fails to guess the exact code within the set number of attempts.\n"
			"The player with the most points wins.\n\n");
	printf("Select an option\n");
	printf("[1] Start Game\n");
	printf("[3] Exit Game\n");
}
/****************************************
Description : This function displays when there is an invalid input in the instructions screen and loops until a valid input is scanned
@return : int choice: Choice - 1 to start the game, 3 to exit the game
*****************************************/
int InstructionsPageInput()
{
	int choice;
	while(choice != 1 && choice != 3){
		scanf("%d", &choice);
		
		if (isalpha(choice) || (choice != 1 && choice != 3)){
			while (getchar() != '\n'){};
			DisplayInstructions();
			printf("Invalid input. Please try again.\n");
		}
	}
	
	return choice;
}
/****************************************
Description : This function displays when there is an invalid input in the starting screen and loops until a valid input is scanned
@param : int *pChoice : Choice - 1 to start the game, 2 to display instructions, and 3 to exit the game
@return : void
*****************************************/
void InvalidInput(int *pChoice)
{
	while(*pChoice != 1 && *pChoice != 2 && *pChoice != 3){
		if (isalpha(*pChoice) || (*pChoice != 1 && *pChoice != 2 && *pChoice != 3)){
			while (getchar() != '\n'){};
				system("CLS");
				printf("Welcome to Mega Mastermind!\n");
				printf("Invalid input. Please try again.\n");
				printf("[1] Start Game\n");
				printf("[2] Display Instructions\n");
				printf("[3] Exit Game\n");
		}
		scanf("%d", pChoice);
	}
}
/****************************************
Description : This function displays the different difficulty levels to the player
@return : void
*****************************************/
void DisplayLevels()
{
	printf("\n[1] EASY ................  6 code pegs | 10 attempts\n");
	printf("[2] AVERAGE .............  8 code pegs | 12 attempts\n");
	printf("[3] DIFFICULT ........... 10 code pegs | 16 attempts\n");
	printf("[4] EXTREME ............. 16 code pegs | 20 attempts\n");
}
/****************************************
Description : This function scans and checks the validity of difficulty level, and loops until a valid input is scanned
@param : int *pLevel: Difficulty level - 1 for EASY, 2 for AVERAGE, 3 for DICCIULT, 4 for EXTREME
@return : void
*****************************************/
void DifficultyLevel(int *pLevel)
{
	*pLevel = 5; //initialize level
	printf("Choose level: ");
	DisplayLevels();
	while(isalpha(*pLevel) || (*pLevel < 1 || *pLevel > 4)){
		scanf("%d", pLevel);
		if (isalpha(*pLevel) || (*pLevel < 1 || *pLevel > 4)){
			while (getchar() != '\n'){};
			system("CLS");
			printf("Invalid input!");
			DisplayLevels();
			printf("Choose level: ");
		}
	}
	system("CLS");
}
/****************************************
Description : This function checks and returns the number of code pegs based on your difficulty level
@param : int nDiffLevel: Level - 1 for EASY, 2 for AVERAGE, 3 for DICCIULT, 4 for EXTREME
@return : int nCodePegs: Number of Code Pegs - 6 for EASY, 8 for AVERAGE, 10 for DICCIULT, 16 for EXTREME
*****************************************/
int NumberOfCodePegs(int nDiffLevel)
{
	int nCodePegs;
	switch (nDiffLevel)
	{
		case 1: nCodePegs = 6; break;
		case 2: nCodePegs = 8; break;
		case 3: nCodePegs = 10; break;
		case 4: nCodePegs = 16; break;	
	}
	return nCodePegs;
}
/****************************************
Description : This function checks and returns the number of attempts based on your difficuty level.
@param : int lvl: Level - 1 for EASY, 2 for AVERAGE, 3 for DICCIULT, 4 for EXTREME
@return : int Attempts: Attempts - 10 for EASY, 12 for AVERAGE, 16 for DICCIULT, 20 for EXTREME
*****************************************/
int NumberOfAttempts(int lvl)
{
	int Attempts;
	switch (lvl)
	{
		case 1: Attempts = 10; break;
		case 2: Attempts = 12; break;
		case 3: Attempts = 16; break;
		case 4: Attempts = 20; break;
	}
	return Attempts;
}
/****************************************
Description : This function scans and checks the validity of the number of games
@return : int games: Number of games - a positive even number that is less than or equal to 10
*****************************************/
int NumberOfGames()
{
	int games = 1;
	printf("\nEnter an even number of games: ");
	
	while(isalpha(games) || (games <= 0 || games % 2 != 0 || games > 10)){
		scanf("%d", &games);
		if (isalpha(games) || (games <= 0 || games % 2 != 0 || games > 10)){
			system("CLS");
			while (getchar() != '\n'){};
			printf("Invalid input!");
			printf("\nEnter an even number of games: ");			
		}
	}
	system("CLS");
	return games;
}
/****************************************
Description : This function scans, checks the validity of, and returns the character that represents the role the player starts as
@return : char cRole: Choice - 'B' for codebreaker and 'M' for codemaker
*****************************************/
char AssignRole()
{
	char cRole;
	printf("Play as...\n");
	printf("[B] Codebreaker\n");
	printf("[M] Codemaker\n");
	scanf("%c", &cRole);
	while(cRole != 'B' && cRole != 'M'){
		scanf("%c", &cRole);
		if(!(isalpha(cRole)) || (cRole != 'B' && cRole != 'M')){
			while (getchar() != '\n'){};
			system("CLS");
			printf("Invalid input!\n");
			printf("Play as...\n");
			printf("[B] Codebreaker\n");
			printf("[M] Codemaker\n");
		}
	}
	return cRole;
}
/****************************************
Description : This function generates a character for each code peg using rand and upper limit
@param : int upper: the maximum number of codepegs for the chosen difficulty level
@return : char color: character that represents a codepeg
*****************************************/
char MakeCode(int upper)
{
    int codenum = (rand() % upper) + 1;
	char color;
	switch (codenum)
	{
		case 1: color = 'R'; break;
		case 2: color = 'P'; break;
		case 3: color = 'G'; break;
		case 4: color = 'Y'; break;
		case 5: color = 'O'; break;
		case 6: color = 'S'; break;
		case 7: color = 'A'; break;
		case 8: color = 'N'; break;
		case 9: color = 'T'; break;
		case 10: color = 'E'; break;
		case 11: color = 'V'; break;
		case 12: color = 'M'; break;
		case 13: color = 'C'; break;
		case 14: color = 'I'; break;
		case 15: color = 'F'; break;
		case 16: color = 'J'; break;
	}
	return color;
}
/****************************************
Description : This function displays the options for the code pegs based on the difficulty level and role
@param : int ilevel: Level
@param : char playerRole: Role
@return : void
*****************************************/
void ColorOptions(int iLevel, char playerRole)
{
	if (playerRole == 'B'){
		switch (iLevel){
			case 1: printf("You are the codebreaker\n(Use R P G Y O S for the pegs)"); break;
			case 2: printf("You are the codebreaker\n(Use R P G Y O S A N for the pegs)"); break;
			case 3: printf("You are the codebreaker\n(Use R P G Y O S A N T E for the pegs)"); break;
			case 4: printf("You are the codebreaker\n(Use R P G Y O S A N T E V M C I F J for the pegs)"); break;
		}
	}
	else{
		switch (iLevel){
			case 1: printf("(Use R P G Y O S for the pegs with spaces in between):\t"); break;
			case 2: printf("(Use R P G Y O S A N for the pegs with spaces in between):\t"); break;
			case 3: printf("(Use R P G Y O S A N T E for the pegs with spaces in between):\t"); break;
			case 4: printf("(Use R P G Y O S A N T E V M C I F J for the pegs with spaces in between):\t"); break;
		}
	}
}
/****************************************
Description : This function checks the validity of the inputs of the Code Guesser and Maker based on the dofficulty level
@param : int level: Difficulty level
@param : char inpt: Guesser input
@return : int validinpt: 1 when valid, 0 when invalid
*****************************************/
int ValidInput(int level, char inpt)
{
	int validinpt;
	switch (level){
		case 1:
			validinpt = inpt == 'R' || inpt == 'P' || inpt == 'G' || inpt == 'Y' || inpt == 'O' || inpt == 'S';
			break;
		case 2:
			validinpt = inpt == 'R' || inpt == 'P' || inpt == 'G' || inpt == 'Y' || inpt == 'O' || inpt == 'S' || inpt == 'A' || inpt == 'N';
			break;
		case 3:
			validinpt = inpt == 'R' || inpt == 'P' || inpt == 'G' || inpt == 'Y' || inpt == 'O' || inpt == 'S' || inpt == 'A' || inpt == 'N' || inpt == 'T' || inpt == 'E';
			break;
		case 4:
			validinpt = inpt == 'R' || inpt == 'P' || inpt == 'G' || inpt == 'Y' || inpt == 'O' || inpt == 'S' || inpt == 'A' || inpt == 'N' || inpt == 'T' || inpt == 'E' || inpt == 'V'|| inpt == 'M' || inpt == 'C' || inpt == 'I' || inpt == 'F' || inpt == 'J';
			break;
	}
	
	return validinpt;
}

/****************************************
Description : This function counts the number of correct guesses
@param : char peg1, peg2, peg3, peg4, guess1, guess2, guess3, guess4: Guesses - the codepegs and the codebreaker's guesses
@return : int numBs: Correct guesses - number of B's to be printed
*****************************************/
int CorrectPegs(char peg1, char peg2, char peg3, char peg4, char guess1, char guess2, char guess3, char guess4)
{
	int numBs = 0;
	if (guess1 == peg1)
		numBs += 1;
	if (guess2 == peg2)
		numBs += 1;
	if (guess3 == peg3)
		numBs += 1;
	if (guess4 == peg4){
		numBs += 1;
	}
	return numBs;
}
/****************************************
Description : This function checks for misplaced pegs and displays W for each
@param : char c1, c2, c3, c4, inp1, inp2, inp3, inp4: Pegs - the codepegs and the codebreaker's inputs
@return : void
*****************************************/
void CheckForW(char c1, char c2, char c3, char c4, char inp1, char inpt2, char inpt3, char inpt4)
{
	if (inp1 == c2 || inp1 == c3 || inp1 == c4)
		printf(" W");
	if (inpt2 == c1 || inpt2 == c3 || inpt2 == c4)
		printf(" W");
	if (inpt3 == c1 || inpt3 == c2 || inpt3 == c4)
		printf(" W");
	if (inpt4 == c1 || inpt4 == c2 || inpt4 == c3)
		printf(" W");
}
/****************************************
Description : This function displays the overall result of the game (if the player won, lost, or drew)
@param : int nHuman: Human player's score
@param : nAI: AI player's score
@return : void
*****************************************/
void DisplayResult(int nHuman, int nAI)
{
	system("CLS");
	if (nHuman > nAI){
		system("COLOR 0E");
		printf("Congratulations! You won!");
	}
	else if (nHuman < nAI){
		system("COLOR 0C");
		printf("You lost!");
	}
	else
		printf("It's a draw!");
		
	printf("\n\n**************************************");
	printf("\nScoreboard");
	printf("\n\n**************************************");
	printf("\n\nHuman Player: %d \tAI Player: %d", nHuman, nAI);
}
/****************************************
Description : This function displays options and allows the user to either play again, display instructions, or exit the game
@return : int nInput: Player input - 1 to start a new game, 2 to display instructions, 3 to exit game
*****************************************/
int playAgain()
{
	int nInput;
	printf("\n\nPlay again?\n");
	printf("[1] New game\n");
	printf("[2] Display Instructions\n");
	printf("[3] Exit Game\n");
	while(nInput != 1 && nInput != 2 && nInput != 3){
		scanf("%d", &nInput);
		if (isalpha(nInput) || (nInput != 1 && nInput != 2 && nInput != 3)){
			system("CLS");
			while (getchar() != '\n'){};
			printf("Invalid input!\n");
			printf("Play again?\n");
			printf("[1] New game\n");
			printf("[2] Display Instructions\n");
			printf("[3] Exit Game\n");
		}
	}
	return nInput;
}

int main()
{
	int nChoice; //input in game intro screen
	int nGames; //input for number of games
	int nLevel, nCodePegs, nAttempt; //input for game difficulty level, number of code pegs, and number of total attempts,
	int nCurrentAttempt; //counter for the attempts of the codebreaker
	char p1, p2, p3, p4; //characters for each code peg
	char g1, g2, g3, g4; //guesses of codebreaker
	int numCorrectPegs; //number of correct pegs
	int valid1, valid2, valid3, valid4; //validity of each code peg
	int countB; //counter for number of times 'B' was printed
	int playerScore, aiScore; //scores of the players
	char role; //role of the player
	
	//starting screen
	system("CLS");
	printf("Welcome to Mega Mastermind!\n");
	printf("Select an option\n");
	printf("[1] Start Game\n");
	printf("[2] Display Instructions\n");
	printf("[3] Exit Game\n");
	scanf(" %d", &nChoice);
	
	do{
		system("COLOR 07");
		switch(nChoice)
		{
			case 1: //start game
				system("CLS");
				
				//initialize scores
				playerScore = 0;
				aiScore = 0;
				
				//player chooses level, number of games, and starting role
				DifficultyLevel(&nLevel);
				nCodePegs = NumberOfCodePegs(nLevel);
				nAttempt = NumberOfAttempts(nLevel);
				printf("Level: %d | Code pegs: %d | Attempts: %d", nLevel, nCodePegs, nAttempt);
				nGames = NumberOfGames();
				role = AssignRole();
				
				while(nGames != 0){
					system("CLS");
					srand(time(0)); //use current time as seed for random generator
					printf("Games left: %d\n", nGames);
					printf("*************\n");
					switch(role)
					{
						//codebreaker
						case 'B':
							do{
							//makes the AI's code
							p1 = MakeCode(nCodePegs);
							p2 = MakeCode(nCodePegs);
							p3 = MakeCode(nCodePegs);
							p4 = MakeCode(nCodePegs);
							}while(p1 == p2 || p1 == p3 || p1 == p4 || p2 == p3 || p2 == p4 || p3 == p4); //loops while having duplicate pegs to make sure pegs are unique
							
							//printf("\n*Assuming the Pseudo-AI's secret code is %c %c %c %c\n", p1, p2, p3, p4);
							ColorOptions(nLevel, role);
							
							for(nCurrentAttempt = 1; nAttempt >= nCurrentAttempt; nCurrentAttempt ++){
								do{
									printf("\n\nAttempt %d (use spaces in between):\t", nCurrentAttempt);
									scanf(" %c %c %c %c", &g1, &g2, &g3, &g4);
									while (getchar() != '\n'){}; //discards '\n' so that the player can input again
									printf("Checking pegs........... done!");
									valid1 = ValidInput(nLevel, g1);
									valid2 = ValidInput(nLevel, g2);
									valid3 = ValidInput(nLevel, g3);
									valid4 = ValidInput(nLevel, g4);
									if (valid1 == 0 || valid2 == 0 || valid3 == 0 || valid4 == 0) //checks if invalid
										printf("\nInvalid input!");
									else if (g1 == g2 || g1 == g3 || g1 == g4 || g2 == g3 || g2 == g4 || g3 == g4) //checks if not unique
										printf("\nCode pegs cannot be duplicated!");
								}while((valid1 == 0 || valid2 == 0 || valid3 == 0 || valid4 == 0) || (g1 == g2 || g1 == g3 || g1 == g4 || g2 == g3 || g2 == g4 || g3 == g4)); //loops while invalid or has duplicate pegs
								
								printf("\nHere are the results: ");
								numCorrectPegs = CorrectPegs(p1, p2, p3, p4, g1, g2, g3, g4);
								countB = 1; //initalizes the counter to print B for each correct peg
								
								//prints B pegs
								while(numCorrectPegs >= countB){
									printf(" B");
									countB ++;
								}
								//prints W pegs
								CheckForW(p1, p2, p3, p4, g1, g2, g3, g4);
								
								aiScore ++; //gets a point for every attempt
								
								if (nCurrentAttempt == nAttempt && numCorrectPegs != 4)
									aiScore ++; //gets an extra point when AI player fails to break the code
								
								if (numCorrectPegs == 4){
									printf("\n\nCongratulations! You got the code!");
									nCurrentAttempt += nAttempt; //to exit the loop when code is solved
								}
							}
							if (numCorrectPegs != 4) //displays the AI's code if the player did not solve it after using all attempts
								printf("\n\nThe code was: %c %c %c %c", p1, p2, p3, p4);
								
							break;
						
						//codemaker
						case 'M':
							printf("You are the codemaker.\nEnter your code ");
							ColorOptions(nLevel, role);
					
							do{
								scanf(" %c %c %c %c", &p1, &p2, &p3, &p4);
								while (getchar() != '\n'){};
								valid1 = ValidInput(nLevel, p1);
								valid2 = ValidInput(nLevel, p2);
								valid3 = ValidInput(nLevel, p3);
								valid4 = ValidInput(nLevel, p4);
								if (valid1 == 0 || valid2 == 0 || valid3 == 0 || valid4 == 0){ //checks if invalid
									printf("Invalid input! ");
									ColorOptions(nLevel, nGames);
								}
								else if (p1 == p2 || p1 == p3 || p1 == p4 || p2 == p3 || p2 == p4 || p3 == p4){ //checks if not unique
									printf("Code pegs cannot be duplicated! ");
									ColorOptions(nLevel, nGames);
								}
							}while((valid1 == 0 || valid2 == 0 || valid3 == 0 || valid4 == 0) || (p1 == p2 || p1 == p3 || p1 == p4 || p2 == p3 || p2 == p4 || p3 == p4)); //loops while invalid or has duplicate pegs
							
							do{
								//randomize guess variables again to initialize them to a random combination of characters
								g1 = MakeCode(nCodePegs);
								g2 = MakeCode(nCodePegs);
								g3 = MakeCode(nCodePegs);
								g4 = MakeCode(nCodePegs);
							}while(g1 == g2 || g1 == g3 || g1 == g4 || g2 == g3 || g2 == g4 || g3 == g4);
							
							for(nCurrentAttempt = 1; nAttempt >= nCurrentAttempt; nCurrentAttempt ++){
								do{
								//only generates code peg when guess is wrong
								if (g1 != p1)
									g1 = MakeCode(nCodePegs);
								if (g2 != p2)
									g2 = MakeCode(nCodePegs);
								if (g3 != p3)
									g3 = MakeCode(nCodePegs);
								if (g4 != p4)
									g4 = MakeCode(nCodePegs);
								}while(g1 == g2 || g1 == g3 || g1 == g4 || g2 == g3 || g2 == g4 || g3 == g4); //loops while having duplicate pegs to make sure pegs are unique
								
								printf("\nGuessing pegs........... done!");
								printf(" Attempt %d:\t%c %c %c %c", nCurrentAttempt, g1, g2, g3, g4);
								printf("\nHere are the results: ");
								numCorrectPegs = CorrectPegs(g1, g2, g3, g4, p1, p2, p3, p4);
								countB = 1; //initalizes the counter to print B for each correct peg
								
								//prints B pegs
								while(numCorrectPegs >= countB){
									printf(" B");
									countB ++;
								}
								//prints W pegs
								CheckForW(g1, g2, g3, g4, p1, p2, p3, p4);
								printf("\n");
								
								if (numCorrectPegs == 4){
									printf("\nPlayer 2 got the code!");
									nCurrentAttempt += nAttempt; //to exit the loop when code is solved
								}
								
								playerScore ++; //gets a point for every attempt
								if (nCurrentAttempt == nAttempt && numCorrectPegs != 4)
									playerScore ++; //gets an extra point when AI player fails to break the code
							}
							break;
					} 
					if (role == 'B') //switch from codebreaker to codemaker
						role = 'M';
					else if (role == 'M') //switch from codemaker to codebreaker
						role = 'B';
					
					//scoreboard
					printf("\n\n**************************************");
					printf("\nScoreboard");
					printf("\n\n**************************************");
					printf("\n\nHuman Player: %d \tAI Player: %d", playerScore, aiScore);
					printf("\n\nEnter any character to continue");
					getch(); //pauses the output console until a key is pressed
					nGames --;
				}
				DisplayResult(playerScore, aiScore);
				nChoice = playAgain();
				break;
			
			case 2: //display instructions
				DisplayInstructions();
				nChoice = InstructionsPageInput();
				break;
			
			case 3: break; //ends game
			
			default: InvalidInput(&nChoice); break; //invalid input
		}
	}while(nChoice != 3);
	system("CLS");
	printf("Good bye...");
	return 0;
}