#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "header.h"
int main()
{
	system("clear");
	printf("Welcome to cricscore\nThis tool contains\n1.live       : To track live score\n2 squad      : To Track full squad\n3 ScoreBoard : To track full score\n");
	printf("Lets start\n\n");
	printf("Are you sure yo want to continue(press any key) :");
	int decision, option;
	char file_option;
	SQUAD squad = {0};
	scanf("%c", &file_option);
	getchar();
	loadtofile(&squad);
	print_squad_list(&squad);
	printf("To change squad list press (y) / else press any key: ");
	scanf("%c",&file_option);
	getchar();
	if(option == 'y')
	{
		squad_list(&squad);
		validate_11(&squad);
		savetofile(&squad);
	}
	
	loadtofile(&squad);
	printf("Enter number of overs: ");
	scanf("%hd", &squad.over);
	printf("Team 1 wins press 0, Team 2 wins press 1 : ");
	scanf("%d", &decision);
	squad.flag = decision; 
	toss(&squad);
	//batsman(&squad);
	printf("First innings scoreboard\n");
	user_board(&squad);
	squad.first_bowler_index = squad.bowler_index;
        squad.first_batsman_index = squad.batsman_index;	
	do
	{
		printf("enter the option to view\n");

		printf("1 live\n2 squad\n3 scorecard\n4  Second innings\n5 exit\n");
		printf("Enter the option : ");
		scanf("%d", &option);
		switch(option)
		{
			case 1 : printf("live\n");
				 live(&squad);
				 break;
			case 2 : printf("squad list\n");
				 print_squad_list(&squad);
				 break;
			case 3 : printf("scorecard\n");
				 score_card(&squad);
				 break;
			case 4 : system("clear");
				 printf("second innings scoreboard\n");
				 squad.bat = !squad.bat;
				 if(squad.flag1 == 0)
				 {
					 squad.flag1 = 1;
					 squad.bowler_index = 0;
					 squad.batsman_index = 0;
					 user_board(&squad);
					 squad.second_bowler_index = squad.bowler_index;
					 squad.second_batsman_index = squad.batsman_index;
				 }
				 else
				 {
					 printf("GAME OVER\n");
				 } 
				 break;

			case 5 : break;


				 
		}
	}while(option != 5);
	return 0;
}
