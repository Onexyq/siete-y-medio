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
	string suit;
	int rank;
};

class Hand
{
public:
	Hand();
	double get_sum() const;
	double draw_card() const;

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