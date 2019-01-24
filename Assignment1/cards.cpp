#include"cards.h"
#include<cstdlib>
#include<iostream>

Card::Card()
{
	int r = rand() % 4;
	switch (r) {
	case 1: suit = OROS; break;
	case 2: suit = COPAS; break;
	case 3: suit = ESPADAS; break;
	case 4: suit = BASTOS; break;
	default: break;
	}

	r = 1 + rand() % 10;
	switch (r) {
	case  1: rank = 1; break;
	case  2: rank = 2; break;
	case  3: rank = 3; break;
	case  4: rank = 4; break;
	case  5: rank = 5; break;
	case  6: rank = 6; break;
	case  7: rank = 7; break;
	case  8: rank = 8; break;
	case  9: rank = 9; break;
	case 10: rank = 10; break;
	default: break;
	}
}

string Card::get_suit() const
{
	string suit_name;
	switch (suit) {
		case OROS:suit_name = "golds"; break;
		case COPAS:suit_name = "cups"; break;
		case ESPASAS:suitname = "swords"; break;
		case BASTOS:suitname = "clubs"; break;
		default:break;
	}
	
	return suit_name;
}

