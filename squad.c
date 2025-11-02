#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "header.h"

void squad_list(SQUAD *team)
{
	for(int i = 0; i < 2; i++)
	{
			printf("Enter team %d name : ", i + 1);
			scanf(" %[^\n]", team-> squad_number[i].team_name);
			for(int j = 0; j < 15; j++)
			{
				printf("enter player name %d: ", j + 1);
				scanf(" %[^\n]", team -> squad_number[i].team[j].player_name);
				printf("enter role: ");
				scanf(" %[^\n]", team -> squad_number[i].team[j].role);
			}
	}

}
void print_squad_list(SQUAD *team)
{
	system("clear");
	
printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
				printf("\n%80s \n\n", "SQUAD");
printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
                printf("%30s%41s%30s\n",team-> squad_number[0].team_name,"|", team -> squad_number[1].team_name);
printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
                printf("%-10s%-5s%-30s%-25s%-5s%-30s%-30s\n", "sl no","|", " player name", "Role","|", "player name", "role");
printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
                for(int j = 0; j < 15; j++)
                {
                        printf("%-10d", j + 1);
                        printf("%-5s", "|");
                        printf("%-30s", team -> squad_number[0].team[j].player_name);
                        printf("%-25s", team -> squad_number[0].team[j].role);
                        printf("%-5s", "|");
                        printf("%-30s", team -> squad_number[1].team[j].player_name);
                        printf("%-30s\n", team -> squad_number[1].team[j].role);
                }
printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

}
void validate_11(SQUAD *team)
{
	char player[30];
	int validate[11];
	int i = 0;
label1:
	printf("Enter team %s 11\n", team -> squad_number[i].team_name);
		int j;
		int k = 0;
		for(int y = 0; y < 11; y++)
		{
label:
			printf("Enter the player name %d : ", y + 1);
			scanf("\n%[^\n]", player);
			for(j = 0; j < 15; j++)
			{
				if(!(strcmp(team -> squad_number[i].team[j].player_name, player)))
				{
					for(int x = 0; x < k; x++)
					{
						if(!(strcmp(team -> squad_number[i].team[x].player_name, player)))
						{
							printf("player already exist\n");
							goto label;
						}
					}
					if(j == k)
					{
						k++;
						break;
					}
					char temp[20];
					strcpy(temp,team -> squad_number[i].team[k].player_name);
					strcpy(team -> squad_number[i].team[k].player_name,team -> squad_number[i].team[j].player_name);
					strcpy(team ->squad_number[i].team[j].player_name, temp);

					strcpy(temp,team -> squad_number[i].team[k].role);
					strcpy(team -> squad_number[i].team[k++].role,team -> squad_number[i].team[j].role);
					strcpy(team ->squad_number[i].team[j].role, temp);
					break;


				}
			}
			if(j == 15)
			{
				printf("player doesn't exist in squad\n");
				goto label;
			}
		}
		i++;
		if(i <= 1)
		{
			goto label1;
		}
	
}
void print_11(SQUAD *team)
{
	
		printf("...............................................................................................................................\n");
		printf("%30s%41s%30s\n",team-> squad_number[0].team_name,"|", team -> squad_number[1].team_name);
		printf("...............................................................................................................................\n");
		printf("...............................................................................................................................\n");
		printf("%-10s%-5s%-30s%-25s%-5s%-30s%-30s\n", "sl no","|", " player name", "Role","|", "player name", "role");
		printf("...............................................................................................................................\n");
		for(int j = 0; j < 15; j++)
		{
			if(j == 11)
			{
				printf("...............................................................................................................\n");
				printf("\n%50s\n\n", "SUBSTITUTE" );
				printf("...............................................................................................................\n");
			}
			printf("%-10d", j + 1);
			printf("%-5s", "|");
			printf("%-30s", team -> squad_number[0].team[j].player_name);
			printf("%-25s", team -> squad_number[0].team[j].role);
			printf("%-5s", "|");
			printf("%-30s", team -> squad_number[1].team[j].player_name);
			printf("%-30s\n", team -> squad_number[1].team[j].role);
		}
		printf("...............................................................................................................................\n");
	

}
