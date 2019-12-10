#define _CRT_SECURE_NO_WARNINGS
/*********************************************************************************************
Class No.: 112
Student Name: Bryan Jug, Alec Smith, Katy Craig-Jones, Nick Barnett, Travis Pittman
Student No.: 011333579
Date: 10/20/17
IDE version: Microsoft Visual Studio
OS version: PC
Lab Assignment: Black Jack Lab
*********************************************************************************************/

/*********************************************************************************************
Lab Assignment: Blackjack Lab
*********************************************************************************************/
/*********************************************************************************************

Analysis

Inputs (data description your app accepts):
card.txt file which contains a 52 cards in the deck.

Outputs (data description data your program produces and in what formats):
Player hands in a point system.
Dealer hands in a point system.

Constraints (list ALL found in problem statement):
Use C file extension.
Output to csis.txt
Must use function named playHand with parameters: dealerWin and ranOut using semi-boolean values.
Function playHand must track total wins and check if cards have run out.
Must use function named getCard get next card and assign point value.
Function getCard must signal no more cards when EOF is reached.
Must count dealer wins using variable dealerTotal.
Must count player wins using variable playerTotal.
Must use a betting system which doubles bets for blackjack hands.
No global variables are to be used.

Formulas (in any):

*********************************************************************************************/
/*********************************************************************************************
Design (Requires one level of step-wise refinement for all steps)

1.
 // Get cards method
 // Check if EOF is true, meaning there are no more card in file.
 //  Assign value point to 0, meaning cards have run out.
 // Read next character/card in file.
 // Set points to appropriate value from 1 to 11.
 //  (10 represented as 'T' in file.)

*********************************************************************************************/
/*********************************************************************************************
Testing

*********************************************************************************************/
//Implementation starts here

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

FILE *fp;

int getCard();
int getBet(int betAmount);
int playHand(int ranOut, int playerWin, int dealerWin, int playerCardSum, int dealerCardSum);
int displayBet(int betAmount, int playerCardSum, int dealerCardSum, int doubleBet);
int convert_card(char playerCard1, char playerCard2, char playerCard3, char dealerCard1, char dealerCard2, char dealerCard3, int playerCardSum, int dealerCardSum);

int main() { //should repeatedly call playHand() and keep track of the total # of wins

	fp = fopen("csis.txt", "w");

	int endCondition = 0;

	while (!endCondition) {

		int ranOut = 0; int dealerWin = 0; int playerWin = 0; int betAmount = 0; int dealerCardSum = 0; int playerCardSum = 0;
		int doubleBet = 0;
		int playerCard1 = 0; int playerCard2 = 0; int playerCard3 = 0; int dealerCard1 = 0; int dealerCard2 = 0; int dealerCard3 = 0;

		getCard();
		getBet(betAmount);
		playHand(ranOut, playerWin, dealerWin, playerCardSum, dealerCardSum); //calls functions to main()
		displayBet(betAmount, playerCardSum, dealerCardSum, doubleBet);
		convert_card(playerCard1, playerCard2, playerCard3, dealerCard1, dealerCard2, dealerCard3, playerCardSum, dealerCardSum);

		if (ranOut) {
			return 0; //if user ran out of cards, end the solution
		}

		else if (dealerWin) {
			++dealerWin;
		}

		else {
			++playerWin;
		}

		printf("The total of wins for the dealer is: %d\n", dealerWin);
		printf("The total of wins for the player is: %d\n", playerWin);
	}

	fclose(fp);
	return 0;
}

int getCard() { //writes out the card and its score

	int value = 0;

	printf("You're given 2 cards, as well as the dealer.\n");

	int dealerCard1 = 5; int playerCard1 = 4;
	int dealerCard2 = 7; int playerCard2 = 10;
	int dealerCard3 = 2; int playerCard3 = 10;

	int playerCardSum = playerCard1 + playerCard2;
	int dealerCardSum = dealerCard1 + dealerCard2;

	if (playerCardSum <= 15) {

		printf("The player draws a third card with a score of: %d\n", playerCardSum);
		fprintf(fp, "The player draws a third card with a score of: %d\n", playerCardSum);
		return playerCardSum = playerCardSum + playerCard3;
	}

	else if (dealerCardSum <= 15) {

		printf("The dealer draws a third card with a score of: %d\n", dealerCardSum);
		fprintf(fp, "The dealer draws a third card with a score of: %d\n", dealerCardSum);
		return dealerCardSum = dealerCardSum + dealerCard3;
	}

	return playerCardSum = playerCard1 + playerCard2;
	return dealerCardSum = dealerCard1 + dealerCard2;
}

int playHand(int ranOut, int playerWin, int dealerWin, int playerCardSum, int dealerCardSum) { //writes out running point value after a card is obtained

	if (playerCardSum > 21 && dealerCardSum <= 21) {

		printf("It looks like your score went over 21. You lost!");
		return dealerWin + 1;
	}

	else if (dealerCardSum > 21 && playerCardSum <= 21) {

		printf("The dealer's score went over 21. You won!");
		return playerWin + 1;
	}

	else if (dealerCardSum == 21 && playerCardSum == 21) {

		printf("It's a draw!");
		return ranOut;
	}

	else if ((dealerCardSum) < 21 > (playerCardSum < dealerCardSum)) {

		printf("The dealer has more points. You lost!");
		return dealerWin + 1;
	}

	else if ((dealerCardSum) < 21 > (playerCardSum > dealerCardSum)) {

		printf("The dealer has less points. You won!");
		return playerWin + 1;
	}

	return 0;
}

int getBet(int betAmount) {

	printf("Enter the amount you would like to bet on the hand: ");
	scanf("%d", &betAmount);

	return betAmount;
}

int displayBet(int betAmount, int playerCardSum, int dealerCardSum, int doubleBet) {


	if (playerCardSum = 21) {

		doubleBet = betAmount * 2; //if the player lands 21 points, player wins double the bet

		printf("You have bet %d and won with a score of 21, therefor your bet is doubled: %d", betAmount, doubleBet);

	}

	else if (dealerCardSum = 21) {

		printf("You have bet %d and lost it all.", betAmount);
	}

	return 0;
}

int convert_card(char playerCard1, char playerCard2, char playerCard3, char dealerCard1, char dealerCard2, char dealerCard3, int playerCardSum, int dealerCardSum) {

	int value = 0; // not a valid card or no more cards.

	switch (playerCard1, playerCard2, playerCard3, dealerCard1, dealerCard2, dealerCard3) {

	case 'A': value = 1;
		puts("Ace");
		while (dealerCardSum > 10 < playerCardSum) {
			value = 11;
			break;
		}
		break;
	case '2': value = 2;
		break;
	case '3': value = 3;
		break;
	case '4': value = 4;
		break;
	case '5': value = 5;
		break;
	case '6': value = 6;
		break;
	case '7': value = 7;
		break;
	case '8': value = 8;
		break;
	case '9': value = 9;
		break;
	case 'T': value = 10;
		break;
	case 'J': value = 10;
		puts("Jack");
		break;
	case 'Q': value = 10;
		puts("Queen");
		break;
	case 'K': value = 10;
		puts("King");
		break;
	default:
		printf("Invaild Card! please try again");

	}
	return 0;
}
