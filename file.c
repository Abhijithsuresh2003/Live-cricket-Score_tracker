#include<stdio.h>
#include "header.h"

void savetofile(SQUAD *team)
{
	FILE *fp =  fopen("squad.csv", "w");
		
	for(int i = 0; i < 2; i++)
	{
		fprintf(fp,"%s\n",  team-> squad_number[i].team_name);
		for(int j = 0; j < 15; j++)
		{
			fprintf(fp,"%s,%s\n",  team -> squad_number[i].team[j].player_name, team -> squad_number[i].team[j].role);
		}
		//fseek(fp, SEEK_END, 0);
	}
}
void loadtofile(SQUAD *team)
{
	FILE *lp =  fopen("squad.csv", "r");
	if(lp == NULL)
	{
		printf("File not exist\n");
	}
	for(int i = 0; i < 2; i++)
	{
		
		fscanf(lp,"%[^\n]\n", team-> squad_number[i].team_name);
		for(int j = 0; j < 15; j++)
		{
			fscanf(lp,"%[^,],%[^\n]\n", team -> squad_number[i].team[j].player_name, team -> squad_number[i].team[j].role);
		}
	}

}
