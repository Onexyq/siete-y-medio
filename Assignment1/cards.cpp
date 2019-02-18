#include"cards.h"
#include<cstdlib>
#include<iostream>


Card::Card()
{
	suit = 1 + rand() % 4;
	rank = 1 + rand() % 10;
}

string Card::get_suit() const
{
	string suit_name;
	switch (suit) {
		case 1:suit_name = "golds"; break;
		case 2:suit_name = "cups"; break;
		case 3:suit_name = "swords"; break;
		case 4:suit_name = "clubs"; break;
		default:break;
	}
	return suit_name;
	
}

string Card::get_rank() const
{
	string rank_name;
	switch (rank) {
		case 1:rank_name = "One"; break;
		case 2:rank_name = "Two"; break;
		case 3:rank_name = "Three"; break;
		case 4:rank_name = "Four"; break;
		case 5:rank_name = "Five"; break;
		case 6:rank_name = "Six"; break;
		case 7:rank_name = "Seven"; break;
		case 8:rank_name = "Jack"; break;
		case 9:rank_name = "Queen"; break;
		case 10:rank_name = "King"; break;
		default: break;
	}
	return rank_name;
}

int Card::get_rankNumber() const
{
	return rank;
}

bool Card::operator < (Card Card2) const 
{
	return rank < Card2.rank;
}

Hand::Hand()
{
}



double Hand::get_total()
{
	double total_value = 0;
	for (int i = 0; i != hand.size(); i++)
	{
		if ((1 <= hand[i].get_rankNumber())&& (hand[i].get_rankNumber() <= 7))
			total_value += hand[i].get_rankNumber();
		else
			total_value += 0.5;
	}
	return total_value;
}

void Hand::draw_card(Card new_card)
{
	hand.push_back(new_card);
}


Player::Player(int m)
{
	money = m;
}

int Player::get_money() const
{
	return money;
}

void Player::add_money(int n)
{
	money += n;
}

void Player::reduce_money(int n)
{
	money -= n;
}
