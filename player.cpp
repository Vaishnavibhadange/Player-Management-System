#include "player.h"

Player::Player() {
	this->jerseyNumber=0;
	strcpy(this->playerName,"not given");
	this->matchesPlayed=0;
	this->runs=0;
	this->wickets=0;
}

Player::Player(int jno,const char* nm,int m,int r,int w) {
	this->jerseyNumber=jno;
	strcpy(this->playerName,nm);
	this->matchesPlayed=m;
	this->runs=r;
	this->wickets=w;
}

void Player::setJerseyNumber(int jno) {
	this->jerseyNumber=jno;
}
int Player::getJerseyNumber() {
	return this->jerseyNumber;
}
void Player::setPlayerName(const char*nm) {
	strcpy(this->playerName,nm);
}
const char* Player::getPlayerName() {
	return this->playerName;
}
void Player::setMatchesPlayed(int m) {
	this->matchesPlayed=m;
}
int Player::getMatchesPlayed() {
	return this->matchesPlayed;
}
void Player::setRuns(int r) {
	this->runs=r;
}
int Player::getRuns() {
	return this->runs;
}
void Player::setWickets(int w) {
	this->wickets=w;
}
int Player::getWickets() {
	return this->wickets;
}

void Player::displayData() {
	cout<<"Name : "<<this->playerName<<"\n";
	cout<<"Jersey Number : "<<this->jerseyNumber<<"\n";
	cout<<"Matches : "<<this->matchesPlayed<<"\n";
	cout<<"Runs : "<<this->runs<<"\n";
	cout<<"Wickets : "<<this->wickets<<"\n";
	cout<<endl;

}