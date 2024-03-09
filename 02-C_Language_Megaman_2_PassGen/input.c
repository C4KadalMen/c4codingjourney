#include <stdio.h>

// Done at :
// March, 9th 2024
// 7:15PM (GMT+7)

int varNumber[8];
char varLetter[9];
int tankOffset = 99;
int tempV = 0;
int i;
int bankQuestion[8][2] =
{
	// Air, Bubble, Crash, Flash, Heat, Metal, Quick, Wood
	{17, 23}, {13, 16}, {22, 15}, {24, 11},
	{20, 7}, {21, 25}, {14, 9}, {10, 18}
};
char bossName[9][10] =
{
	"Airman", "Bubbleman", "Crashman", "Flashman",
	"Heatman", "Metalman", "Quickman", "Woodman",
};
int answerQ = 2;
char map[26];

void main()
{
	for(i = 1; i < 26; i++)
	{
		map[i] = '-';
	}
	printf("[Megaman 2 Password Generator V1.0]\n\tBy. C4_KadalMen\n\n");

	printf("\t[Order of answering]\nAirMan, BubbleMan, CrashMan, FlashMan, \nHeatMan, MetalMan, QuickMan, WoodMan\n");
	printf("|-------------------------------|\n");
	printf("|\t(How to answer)\t\t|\n| Type 0 for NO, Type 1 for YES\t|\n");
	printf("|-------------------------------|\n");

	// "While" Loop for failsafe, in case 
	while(tankOffset > 4)
	{
		printf("E-Tank amount(0-4) : ");
		scanf("%d", &tankOffset);
		if(tankOffset > 4)
			printf("E-Tanks invalid value!\n");
		map[tankOffset + 1] = '#';
	}

	for(i = 0; i < 8; i++)
	{
		answerQ = 2;
		while(answerQ > 1)
		{
			printf("%s beaten?(0-1) : ", bossName[i]);
			scanf("%d", &answerQ);
			if(answerQ > 1)
				printf("Answer invalid!\n");
		}
		int tempFilter = bankQuestion[i][answerQ] + tankOffset;
		if(tempFilter > 25)
			tempFilter = tempFilter - 20;
		valFilter(tempFilter);
		map[tempFilter] = '#';
	}

	// Prints out the password
	printf("[Code : ");
	printf("A%d ", tankOffset + 1);
	for(i = 0; i < 8; i++)
	{
		printf("%c%d ", varLetter[i], varNumber[i]);
	}
	printf("]\n|-------------------------------|\n");
	printf("\nPut the nine dots in the designated coordinate.\n");
	printf("|-------------------------------|\n\n");

	// Draws coordinate
	printf("N\t1\t2\t3\t4\t5\nA");
	int coorRow = 0;
	char rowName[5] = "ABCDE";
	for(i = 0; i < 26; i++)
	{
		printf("%c\t", map[i]);
		int remder = i % 5;
		if(remder == 0 && i > 0 && i != 25)
		{
			coorRow = coorRow + 1;
			printf("\n%c\t", rowName[coorRow]);
		}
	}
	printf("\nHave fun~\n");
}

int valFilter(int rawFilter)
{
	// Wraps back to B row, too stupid to came up with other workarounds
	if(rawFilter > 25)
	{
		rawFilter = rawFilter - 25;
		varLetter[i] = 'B';
	}

	else if(rawFilter > 20)
	{
		rawFilter = rawFilter - 20;
		varLetter[i] = 'E';
	}
	else if(rawFilter > 15)
	{
		rawFilter = rawFilter - 15;
		varLetter[i] = 'D';
	}
	else if(rawFilter > 10)
	{
		rawFilter = rawFilter - 10;
		varLetter[i] = 'C';
	}
	else if(rawFilter > 5)
	{
		rawFilter = rawFilter - 5;
		varLetter[i] = 'B';
	}
	// Unused, cuz I'm stupid
	else
	{
		varLetter[i] = 'A';
	}

	switch(rawFilter)
	{
		case 5:
			varNumber[i] = 5;
			break;
		case 4:
			varNumber[i] = 4;
			break;
		case 3:
			varNumber[i] = 3;
			break;
		case 2:
			varNumber[i] = 2;
			break;
		case 1:
			varNumber[i] = 1;
			break;
		default:
			break;
	}
	return 0;
}
