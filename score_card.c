#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "header.h"

void toss(SQUAD *squad)
{
	int toss;
	if((squad -> flag) == 0)
	{
		printf("\n%s won the toss\n\n",  squad -> squad_number[0].team_name);
		printf("if bat (press 1) / bowl (press 0) : ");
		scanf("%d", &toss);
		system("clear");
		if(toss == 1)
		{
			printf("%s captain decided to bat first\n\n",  squad -> squad_number[0].team_name);
			squad -> toss = 1;
		}
		else
		{
			printf("%s captain decided to bowl first\n\n", squad -> squad_number[0].team_name);
			squad -> toss = 0;
		}
	}
	else
	{
		printf("\n%s won the toss\n\n",  squad -> squad_number[1].team_name);
		printf("if bat (press 1) / bowl (press 0) : ");
		scanf("%d", &toss);
		system("clear");
		if(toss == 1)
		{
			printf("\n%s captain decided to bat first\n", squad -> squad_number[1].team_name);
			squad -> toss = 1;
		}
		else
		{
			printf("\n%s captain decided to bowl first\n", squad -> squad_number[1].team_name);
			squad -> toss = 0;
		}
	}
	squad -> bat = (squad -> flag) ^ (squad -> toss);
	squad -> first_bat = !squad -> bat;
	squad -> first_bowl = squad -> bat;
	
}

void live(SQUAD *team)
{
	system("clear");
		printf("------------------------------------------------------------------------------------------------------------\n");
		printf("\n\t\t\t%s batting line up\n\n", team-> squad_number[!team -> bat].team_name);
		printf("------------------------------------------------------------------------------------------------------------\n");
		printf("%-10s%-20s%-10s%-10s%-10s%-10s%-15s\n", "sl no", " player name", "Runs", "Ball", "Four", "six", "Strike rate");
		printf("------------------------------------------------------------------------------------------------------------\n");
			printf("batsman\n");
			printf("%-10d* ",1);
			printf("%-18s", team -> squad_number[!team -> bat].team[team -> previous].player_name);
			printf("%-10d", team -> squad_number[!team -> bat].team[team -> previous].run);
			printf("%-10d", team -> squad_number[!team -> bat].team[team -> previous].ball);
			printf("%-10d", team -> squad_number[!team -> bat].team[team -> previous].four);
			printf("%-10d", team -> squad_number[!team -> bat].team[team -> previous].six);
			printf("%-10.2f\n", team -> squad_number[!team -> bat].team[team -> previous].strike_rate);
			printf("%-10d", 2);
			printf("%-20s", team -> squad_number[!team -> bat].team[team -> swap].player_name);
			printf("%-10d", team -> squad_number[!team -> bat].team[team -> swap].run);
			printf("%-10d", team -> squad_number[!team -> bat].team[team -> swap].ball);
			printf("%-10d", team -> squad_number[!team -> bat].team[team -> swap].four);
			printf("%-10d", team -> squad_number[!team -> bat].team[team -> swap].six);
			printf("%-10.2f\n", team -> squad_number[!team -> bat].team[team -> swap].strike_rate);
			printf("bowler\n");
			printf("%-10s%-20s%-10s%-10s%-10s%-10s%-15s\n", "sl no", " player name", "over", "Maiden", "Runs", "wicket", "Economy");
			printf("%-10d* ", 1);
			printf("%-18s", team -> squad_number[team -> bat].team[ team -> squad_number[team -> bat].bowler[team -> bowler_index - 1]].player_name);
			printf("%-d.%-10d", (team -> squad_number[team -> bat].team[ team -> squad_number[team -> bat].bowler[team -> bowler_index - 1]].bowler_over 
			/ 6),  (team -> squad_number[team -> bat].team[ team -> squad_number[team -> bat].bowler[team -> bowler_index - 1]].bowler_over % 6)) ;
			printf("%-10d", team -> squad_number[team -> bat].team[ team -> squad_number[team -> bat].bowler[team -> bowler_index - 1]].bowler_maiden);
			printf("%-10d", team -> squad_number[team -> bat].team[ team -> squad_number[team -> bat].bowler[team -> bowler_index - 1]].bowler_run);
			printf("%-10d", team -> squad_number[team -> bat].team[ team -> squad_number[team -> bat].bowler[team -> bowler_index - 1]].bowler_wicket);
			printf("%-10.2f\n", team -> squad_number[team -> bat].team[ team -> squad_number[team -> bat].bowler[team -> bowler_index - 1]].bowler_economy);
		printf("------------------------------------------------------------------------------------------------------------\n");
			
		if(team -> win == 1)
		{
			printf("%s won by %d wkts\n", team -> squad_number[team -> first_bowl].team_name, 10 - team -> squad_number[team -> first_bowl].total_wicket);
		}
		else if(team -> win == 2)
		{
			printf("%s won by %d  runs\n", team -> squad_number[team -> first_bat].team_name,  team -> squad_number[team -> first_bat].total_run -
                              team -> squad_number[team -> first_bowl].total_run );
		}
		else
		{
			printf("Target for %s %d\n",team -> squad_number[team -> first_bowl].team_name,team -> squad_number[team -> first_bat].total_run + 1);
		}
		printf("------------------------------------------------------------------------------------------------------------\n");

}

/*void scorecard(SQUAD *team)
{
	printf("%-10s%-10s%-10s\n", "Total", "Extra", "wicket");
	printf("%-10d", (team -> squad_number[0].total_run));
	printf("%-10d", (team -> squad_number[0].extra));
	printf("%-10d\n", (team -> squad_number[0].total_wicket));
}*/

void user_board(SQUAD *team)
{

	print_11(team);
	char user[4];
	char *wd, *nb, *w;
	int arr[11] = {0};
	team -> previous = 0, team -> swap = 1;
	for(int i = 0; i < team -> over; i++)
	{
		int j = 0, num = 0, extra = 0;
		if(!(i || j))
		{
			printf("enter the strike batsman : ");
			team -> previous = validate_batsman(team, arr);
			printf("enter the non strike batsman : ");
			team -> swap = validate_batsman(team, arr);
		}
		validate_bowler(team);
		while(j < 6)
		{
			num = 0, extra = 0;
			printf("over %d.%d : ", i, j);
			scanf("\n%[^\n]", user);
			wd = strchr(user, 'w');
			nb = strchr(user, 'n');
			//printf("%p %p", wd, nb);
			//w = strchr(user, 'w');
			if(!(wd == NULL))
			{
				if(*(wd + 1) != 'd')
				{
					printf("wicket\n");
					if(strlen(wd) == 1)
					{
						num = 0;
					}
					else
					{
						num = (*(wd + 2)) - 48;
					}
					(team -> squad_number[!team -> bat].total_ball)++;
					team -> squad_number[!team -> bat].total_wicket++;
					(team -> squad_number[!team -> bat].team[team -> previous].ball)++;
					(team -> squad_number[!team -> bat].team[team -> previous].run) = 
					(team -> squad_number[!team -> bat].team[team -> previous].run) + num;
			team -> squad_number[team -> bat].team[ team -> squad_number[team -> bat].bowler[team -> bowler_index - 1]].bowler_over++;
					(team -> squad_number[team -> bat].team[ team -> squad_number[team -> bat].bowler[team -> bowler_index - 1]].bowler_wicket)++;
					if(team -> squad_number[!team -> bat].total_wicket == 10)
					{
						if(team -> flag1 == 1)
						{
							team -> win = 2;
							return;

						}
						break;
					}
					printf("enter the next batsman : ");
					team -> previous = validate_batsman(team, arr);
					extra = 0;
					j++;
				}
				else if(wd)
				{

					num = (*(wd + 3)) - 48;
					extra++;
				}
			}
			else if(!(nb == NULL))
			{
				if(nb)
				{
					num = (*(nb + 3)) - 48;
				(team -> squad_number[!team -> bat].team[team -> previous].run) = (team -> squad_number[!team -> bat].team[team -> previous].run) + num;
					extra++;

				}

			}
			else
			{
				num = user[0] - 48;
				(team -> squad_number[!team -> bat].team[team -> previous].ball)++;
				(team -> squad_number[!team -> bat].team[team -> previous].run) = (team -> squad_number[!team -> bat].team[team -> previous].run) + num;
				(team -> squad_number[!team -> bat].total_ball)++;
			team -> squad_number[team -> bat].team[ team -> squad_number[team -> bat].bowler[team -> bowler_index - 1]].bowler_over++;
				j++;
			}
				(team -> squad_number[team -> bat].team[ team -> squad_number[team -> bat].bowler[team -> bowler_index - 1]].bowler_run) = (team -> squad_number[team -> bat].team[ team -> squad_number[team -> bat].bowler[team -> bowler_index - 1]].bowler_run) + num;
				(team -> squad_number[!team -> bat].team[team -> previous].strike_rate) = ((team -> squad_number[!team -> bat].team[team -> previous].run)
					                              / (float)(team -> squad_number[!team -> bat].team[team -> previous].ball)) * 100;
				(team -> squad_number[!team -> bat].total_run) = (team -> squad_number[!team -> bat].total_run) + (num + extra);
				(team -> squad_number[!team -> bat].extra) = (team -> squad_number[!team -> bat].extra) + extra;
			if((num == 4) || (num == 2) || (num == 6) || (num == 0))
			{
				if(num == 4)
				{
					(team -> squad_number[!team -> bat].team[team -> previous].four)++;
				}
				else if(num == 6)
				{
					(team -> squad_number[!team -> bat].team[team -> previous].six)++;

				}
			}
			else
			{
				int temp = team -> previous;
				team -> previous = team -> swap;
				team -> swap = temp;
			}
			if(team -> flag1 == 1)
			{
				if(team -> squad_number[team -> first_bat].total_run < team -> squad_number[team -> first_bowl].total_run)
				{
					team -> win = 1;
					return;
				}
			}
			
(team -> squad_number[team -> bat].team[ team -> squad_number[team -> bat].bowler[team -> bowler_index - 1]].bowler_economy) = (team -> squad_number[team -> bat].team[ team -> squad_number[team -> bat].bowler[team -> bowler_index - 1]]
                                                .bowler_run) / ((float)(team -> squad_number[team -> bat].team[ team -> squad_number[team -> bat].bowler[team -> bowler_index - 1]]. bowler_over)) * 6;
		}
		if(num == 0)
		{
			team -> squad_number[team -> bat].team[ team -> squad_number[team -> bat].bowler[team -> bowler_index - 1]].bowler_maiden++;
		}
		if(j != 6)
		{
			break;
		}
		int temp = team -> previous;
		team -> previous = team -> swap;
		team -> swap = temp;
	}
	if(team -> flag1 == 1)
	{
		team -> win = 2;
		return;
	}
	else
	{
		team -> previous1 = team -> previous;
		team -> swap1 = team -> swap;
	}
	printf("Target for %s %d\n",team -> squad_number[team -> bat].team_name,team -> squad_number[!team -> bat].total_run + 1);
}
int validate_batsman(SQUAD *team, int arr[])
{
	
	char batsman[30];
        int j, k;
label:
        scanf("\n%[^\n]", batsman);
        for(j = 0; j < 11; j++)
        {
                if(!(strcmp(team -> squad_number[!team -> bat].team[j].player_name, batsman)))
                {

                        team -> squad_number[!team -> bat].batsman_list[(team -> batsman_index)] = -1;
                        int count = team -> batsman_index;
                        int i = 0;
                        for(i = 0; i < count; i++)
                        {
                                if(team -> squad_number[!team -> bat].batsman_list[i] == j)
                                {
                                        printf("Batsman already enter\n");
                                        printf("Next batsman name : ");
                                        goto label;
                                }
                                
                        }
                        if(i == count)
                        {
                                team -> squad_number[!team -> bat].batsman_list[(team -> batsman_index)++] = j;
                        }

                        return j;
                }

        }
        if(j == 11)
        {
                printf("Enter the correct batsman name : ");
                goto label;
        }
}
int validate_bowler(SQUAD *team)
{
	char bowler[30];
	printf("enter the next bowler: ");
	int j, k;
label:
	scanf("\n%[^\n]", bowler);
        for(j = 0; j < 11; j++)
        {
                if(!(strcmp(team -> squad_number[team -> bat].team[j].player_name, bowler)))
                {
    
			team -> squad_number[team -> bat].bowler[(team -> bowler_index)] = -1;
			int count = team -> bowler_index;
			int i = 0;
			for(i = 0; i < count; i++)
			{
				if(team -> squad_number[team -> bat].bowler[team -> bowler_index - 1] == j)
				{
					printf("No bowler can bowl continuos overs\n");
					printf("Next bowler name : ");
					goto label;
				}
				else if(team -> squad_number[team -> bat].bowler[i] == j)
				{
					return j;
				}
			}
			if(i == count)
			{
				team -> squad_number[team -> bat].bowler[(team -> bowler_index)++] = j;
			}

                        return j;
                }

        }
        if(j == 11)
	{
		printf("Enter the correct bowler name : ");
		goto label;
	}
}

void score_card(SQUAD *team)
{
	system("clear");
	if(team -> win)
	{
printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
		if(team -> win == 1)
		{
			printf("%s won by %d wkts\n", team -> squad_number[team -> first_bowl].team_name, 10 - team -> squad_number[team -> first_bowl].total_wicket);
		}
		else if(team -> win == 2)
		{
			printf("%s won by %d  runs\n", team -> squad_number[team -> first_bat].team_name,  team -> squad_number[team -> first_bat].total_run -
                              team -> squad_number[team -> first_bowl].total_run );
		}
printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	}
	int option; 
	printf("1 1st innings score\n2 2nd innings score\n3 exit\nenter the option : ");
	scanf("%d", &option);
	float RR;

		switch(option)
		{
			case 1: 
printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
				printf("\n\t\t\t%s batting line up\n\n", team-> squad_number[team -> first_bat].team_name);
printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
				printf("%-10s%-20s%-10s%-10s%-10s%-10s%-15s\n", "sl no", "batter", "Runs", "Ball", "Four", "six", "Strike rate");
printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

				for(int i = 0; i < team -> first_batsman_index; i++)
				{

					if((team -> squad_number[team -> first_bat].batsman_list[i] == team -> previous1) ||
					  (team -> squad_number[team -> first_bat].batsman_list[i] == team -> swap1))
					{
						printf("%-10d*",i + 1);
					}
					else
					{
						printf("%-10d ",i + 1);

					}
					printf("%-20s", team -> squad_number[team -> first_bat].team[team -> squad_number[team ->first_bat].batsman_list[i]].player_name);
					printf("%-10d", team -> squad_number[team -> first_bat].team[team -> squad_number[team->first_bat].batsman_list[i]].run);
					printf("%-10d", team -> squad_number[team -> first_bat].team[team -> squad_number[team->first_bat].batsman_list[i]].ball);
					printf("%-10d", team -> squad_number[team -> first_bat].team[team -> squad_number[team->first_bat].batsman_list[i]].four);
					printf("%-10d", team -> squad_number[team -> first_bat].team[team -> squad_number[team->first_bat].batsman_list[i]].six);
					printf("%-10.2f\n", team -> squad_number[team -> first_bat].team[team -> squad_number[team->first_bat].batsman_list[i]].strike_rate);

				}
printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
				printf("%-20s%-d\n", "Extras", team -> squad_number[team -> first_bat].extra);
printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
				if( team -> squad_number[team -> first_bat].total_ball == 0)
				{
					RR = 0.0;
				}
				else
				{
					RR = ((team -> squad_number[team -> first_bat].total_run / (float)team -> squad_number[team -> first_bat].total_ball)) * 6;
				}

				printf("%-20s%-d - %-d(%-d.%-dovers,RR:%.f)\n", "Total",team -> squad_number[team -> first_bat].total_run,
						team -> squad_number[team -> first_bat].total_wicket, team -> squad_number[team -> first_bat].total_ball / 6,
						team -> squad_number[team -> first_bat].total_ball % 6, RR);
printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
				printf("%s\n", "yet to bat");
printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

				for(int i = 0; i< 11; i++)
				{
					int j;
					for(j = 0; j < team -> first_batsman_index;j++)
					{
						if(team -> squad_number[team -> first_bat].batsman_list[team -> squad_number[team -> first_bat].batsman_list[j]] == i)
						{
							break;
						}
					}
					if(j == team -> first_batsman_index)
					{
						printf("%s,", team -> squad_number[team -> first_bat].team[i].player_name);
					}

				}
				printf("\n");
printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
				printf("\n\t\t\t%s Bowlers list\n\n", team-> squad_number[team -> first_bowl].team_name);
printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
				printf("%-10s%-20s%-10s%-10s%-10s%-10s%-15s\n", "sl no", " player name", "over", "Maiden", "Runs", "wicket", "Economy");
				for(int i = 0; i < team -> first_bowler_index; i++)
				{
					printf("%-10d ",i + 1);
					printf("%-18s", team -> squad_number[team -> first_bowl].team[ team -> squad_number[team -> first_bowl].bowler[i]].player_name);
					printf("%-d.%-10d",(team -> squad_number[team -> first_bowl].team[ team -> squad_number[team -> first_bowl].bowler[i]].bowler_over 
					/ 6),  (team -> squad_number[team -> first_bowl].team[ team -> squad_number[team -> first_bowl].bowler[i]].bowler_over                                                      % 6)) ;
					printf("%-10d", team -> squad_number[team -> first_bowl].team[ team -> squad_number[team -> first_bowl].bowler[i]].bowler_maiden);
					printf("%-10d", team -> squad_number[team -> first_bowl].team[ team -> squad_number[team -> first_bowl].bowler[i]].bowler_run);
					printf("%-10d", team -> squad_number[team -> first_bowl].team[ team -> squad_number[team -> first_bowl].bowler[i]].bowler_wicket);
					printf("%-10.2f\n", team -> squad_number[team -> first_bowl].team[ team -> squad_number[team -> first_bowl].bowler[i]].bowler_economy);

				}
				printf("\n");
printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
				break;
			case 2: 
printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
				if(team -> flag1 == 0)
				{
					printf("........................................\n");
					printf("Second innings is not yet started\n");
					printf("........................................\n");
					return;
				}
				printf("\n\t\t\t%s batting line up\n\n", team-> squad_number[team -> first_bowl].team_name);
printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
				printf("%-10s%-20s%-10s%-10s%-10s%-10s%-15s\n", "sl no", "batter", "Runs", "Ball", "Four", "six", "Strike rate");
printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

				for(int i = 0; i < team -> second_batsman_index; i++)
				{

					if((team -> squad_number[team -> first_bowl].batsman_list[i] == team -> previous) ||                                                                                         (team -> squad_number[team -> first_bowl].batsman_list[i] == team -> swap))
					{
						printf("%-10d*",i + 1);
					}
					else
					{
						printf("%-10d ",i + 1);

					}
					printf("%-20s", team -> squad_number[team -> first_bowl].team[team -> squad_number[team->first_bowl].batsman_list[i]].player_name);
					printf("%-10d", team -> squad_number[team -> first_bowl].team[team -> squad_number[team->first_bowl].batsman_list[i]].run);
					printf("%-10d", team -> squad_number[team -> first_bowl].team[team -> squad_number[team->first_bowl].batsman_list[i]].ball);
					printf("%-10d", team -> squad_number[team -> first_bowl].team[team -> squad_number[team->first_bowl].batsman_list[i]].four);
					printf("%-10d", team -> squad_number[team -> first_bowl].team[team -> squad_number[team->first_bowl].batsman_list[i]].six);
					printf("%-10.2f\n", team -> squad_number[team -> first_bowl].team[team -> squad_number[team->first_bowl].batsman_list[i]].strike_rate);

				}
printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
				printf("%-20s%-d\n", "Extras", team -> squad_number[team -> first_bowl].extra);
printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
				if( team -> squad_number[team -> first_bat].total_ball == 0)
				{
					RR = 0.0;
				}
				else
				{
					RR = ((team -> squad_number[team -> first_bowl].total_run / (float)team -> squad_number[team -> first_bowl].total_ball)) * 6;
				}

				printf("%-20s%-d - %-d(%-d.%-dovers,RR:%.f)\n", "Total",team -> squad_number[team -> first_bowl].total_run,
						team -> squad_number[team -> first_bowl].total_wicket, team -> squad_number[team -> first_bowl].total_ball / 6,
						team -> squad_number[team -> first_bowl].total_ball % 6, RR);
printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
				printf("%s\n", "yet to bat");
printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

				for(int i = 0; i< 11; i++)
				{
					int j;
					for(j = 0; j < team -> second_batsman_index;j++)
					{
						if(team -> squad_number[team -> first_bowl].batsman_list[team -> squad_number[team -> first_bowl].batsman_list[j]] == i)
						{
							break;
						}
					}
					if(j == team -> second_batsman_index)
					{
						printf("%s,", team -> squad_number[team -> first_bowl].team[i].player_name);
					}

				}
				printf("\n");
				printf("\n");
printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
				printf("\n\t\t\t%s Bowlers list\n\n", team-> squad_number[team -> first_bat].team_name);
printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
				printf("%-10s%-20s%-10s%-10s%-10s%-10s%-15s\n", "sl no", " player name", "over", "Maiden", "Runs", "wicket", "Economy");
				for(int i = 0; i < team -> second_bowler_index; i++)
				{
					printf("%-10d ",i + 1);
					printf("%-18s", team -> squad_number[team -> first_bat].team[ team -> squad_number[team -> first_bat].bowler[i]].player_name);
					printf("%-d.%-10d", (team -> squad_number[team -> first_bat].team[ team -> squad_number[team -> first_bat].bowler[i]].bowler_over 
					/ 6),  (team -> squad_number[team -> first_bat].team[ team -> squad_number[team -> first_bat].bowler[i]].bowler_over                                                      % 6)) ;
					printf("%-10d", team -> squad_number[team -> first_bat].team[ team -> squad_number[team -> first_bat].bowler[i]].bowler_maiden);
					printf("%-10d", team -> squad_number[team -> first_bat].team[ team -> squad_number[team -> first_bat].bowler[i]].bowler_run);
					printf("%-10d", team -> squad_number[team -> first_bat].team[ team -> squad_number[team -> first_bat].bowler[i]].bowler_wicket);
					printf("%-10.2f\n", team -> squad_number[team -> first_bat].team[ team -> squad_number[team -> first_bat].bowler[i]].bowler_economy);

				}
				printf("\n");
printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
				break;
			case 3: break;
		}
}

