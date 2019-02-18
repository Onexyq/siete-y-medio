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

	int get_rankNumber() const;

	bool operator<(Card Card2) const;

private:
	int suit;
	int rank;
};

class Hand
{
public:
	Hand();
	double get_total();
	void draw_card(Card new_card);

private:
	vector<Card>hand;
};

class Player
{
public:
	Player() {};
	Player(int m);
	int get_money() const;
	void add_money(int n);
	void reduce_money(int n);

private:
	int money;
};

#endif