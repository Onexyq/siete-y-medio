#include<vector>
#include<string>
#include<fstream>

using namespace std;

#ifndef CARDS_H
#define CARDS_H

class Card
{
public:
	Card();

	string get_suit() const;
	string get_rank() const;

	bool operator<(Card Card2) const;

private:
	int suit;
	int rank;
};

class Hand
{
public:
	Hand();
	double get_total() const;
	void draw_card();

private:
	vector<Card>hand;
};

class Player
{
public:
	Player(int m);

private:
	int money;
};

#endif