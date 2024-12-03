#include<iostream>
#include<string.h>
using namespace std;


class Player
{
	int jerseyNumber;
	char playerName[20];
	int matchesPlayed;
	int runs;
	int wickets;

public:
	Player();
	Player(int,const char*,int,int,int);
	void setJerseyNumber(int);
	int getJerseyNumber();
	void setPlayerName(const char*);
	const char* getPlayerName();
	void setMatchesPlayed(int);
	int getMatchesPlayed();
	void setRuns(int);
	int getRuns();
	void setWickets(int);
	int getWickets();
	
	void displayData();
};