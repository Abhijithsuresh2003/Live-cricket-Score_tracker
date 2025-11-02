#ifndef HEADER_H
#define HEADER_H
typedef struct {
	char player_name[30];
	char role[10];
	short int total_over;
	short int run;
	short int ball;
	short int four;
	short int  six;
	short int bowler_over;
	short int bowler_maiden;
	float bowler_economy;
	short int bowler_wicket;
	short int bowler_run;
	float strike_rate;
	char Team_name[15];
}score_list;
typedef struct team
{
	score_list team[15];
	char team_name[15];
	short int total_ball;
	short int total_run;
	short int total_wicket;
	short int extra;
	int batsman_list[11];
	int bowler[11];
}list;
typedef struct
{
	list squad_number[2];
	list batsman[2];
	char event_name[30];
	short int over;
	short int previous;
	short int bowler_index;
	short int batsman_index;
	short int first_bowler_index;
	short int second_bowler_index;
	short int first_batsman_index;
	short int second_batsman_index;
	short int swap;
	short int previous1;
	short int swap1;
	//static int k;
	unsigned int flag : 1;
	unsigned int win : 2;
	unsigned int toss : 1;
	unsigned int bat : 1;
	unsigned int first_bat : 1;
	unsigned int first_bowl : 1;
	unsigned int flag1: 1;

}SQUAD;
void squad_list(SQUAD *squad);
void print_squad_list(SQUAD *squad);
void toss(SQUAD *squad);
void savetofile(SQUAD *squad);
void loadtofile(SQUAD *squad);
void batsman(SQUAD *squad);
void live(SQUAD *squad);
void scorecard(SQUAD *team);
void user_board(SQUAD *team);
int validate_batsman(SQUAD *team, int arr[]);
int validate_bowler(SQUAD *team);
void validate_11(SQUAD *team);
void print_11(SQUAD *team);
void score_card(SQUAD *team);

#endif
