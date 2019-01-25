#include"cards.h"
#include<iostream>
#include<cstdlib>
#include<ctime>

int main()
{
	Player player(100);
	Player dealer(100);
	
	Hand p_hand;
	Hand d_hand;

	int round;
	int i = 0;		//index of the player's cards

	cout << "Game start!" << endl;
	
	cout << "You have " << player.get_money() << " $ \t"
		<< "\tEnter bet:";
	int bet;
	cin >> bet;
	char choice;

	do {
		
		Card new_card1;
		cout << "New card: \t" <<new_card1.get_rank()
			<<" of "<<new_card1.get_suit()<< endl;
		p_hand.draw_card(new_card1);

		Card new_card2;
		cout <<"dealer's new card: \t"<<new_card2.get_rank()
			<< " of " << new_card2.get_suit() << endl;
		d_hand.draw_card(new_card2);

		if ((p_hand.get_total() > 7.5)&&(d_hand.get_total()>7.5))
		{
			cout << "Now your total is " << p_hand.get_total() << "!\n";
			cout<<"The dealer's total is "<< d_hand.get_total() << "!\n";
			cout << "Tie!" << endl; 
			break;
		}
		else if ((p_hand.get_total() > 7.5) && (d_hand.get_total() <= 7.5))
		{
			cout << "Now your total is " << p_hand.get_total() << "!\n";
			cout << "The dealer's total is " << d_hand.get_total() << "!\n";
			player.add_money(bet);
			cout<<" You lose "<<bet<<"$ "<<endl;
				break;
		}
		else if ((p_hand.get_total() <= 7.5) && (d_hand.get_total() > 7.5))
		{
			cout << "Now your total is " << p_hand.get_total() << "!\n";
			cout << "The dealer's total is " << d_hand.get_total() << "!\n";
			dealer.add_money(bet);
			cout<<" You win "<<bet<<"$ "<<endl;
				break;
		}

		cout << "Do you want another cards (y/n)? ";
		cin >> choice;

	} while (choice != 'n');

	while ((choice == 'n')&& (d_hand.get_total()<5.5))
	{
		Card new_card2;
		cout << "dealer's new card: \t" << new_card2.get_rank()
			<< " of " << new_card2.get_suit() << endl;
		d_hand.draw_card(new_card2);
		
		if (d_hand.get_total() > 7.5)
		{
			cout << "Now your total is " << p_hand.get_total() << "!\n";
			cout << "The dealer's total is " << d_hand.get_total() << "!\n";
			dealer.add_money(bet);
			cout << " You win " << bet << "$ " << endl;
		}
		if ((d_hand.get_total() >= 5.5) && (d_hand.get_total() > p_hand.get_total()))
		{
			cout << "Now your total is " << p_hand.get_total() << "!\n";
			cout << "The dealer's total is " << d_hand.get_total() << "!\n";
			player.add_money(bet);
			cout << " You lose " << bet << "$ " << endl;
		}
		if ((d_hand.get_total() >= 5.5) && (d_hand.get_total() == p_hand.get_total()))
		{
			cout << "Now your total is " << p_hand.get_total() << "!\n";
			cout << "The dealer's total is " << d_hand.get_total() << "!\n";
			cout << "Tie!" << endl;
		}
		if ((d_hand.get_total() >= 5.5) && (d_hand.get_total() < p_hand.get_total()))
		{
			cout << "Now your total is " << p_hand.get_total() << "!\n";
			cout << "The dealer's total is " << d_hand.get_total() << "!\n";
			dealer.add_money(bet);
			cout << " You win " << bet << "$ " << endl;
		}
	}
	


	system("pause");
	return 0;
	
}

