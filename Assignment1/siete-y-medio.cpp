
#include"cards.h"
#include<iostream>
#include<cstdlib>
#include<ctime>

int main()
{
	srand(time(0));

	time_t t1, t2;

	Player player(100);
	Player dealer;

	int round = 1;  
	int i = 0;		

	cout << "Game start!" << endl;
	time(&t1);

	char answer;
	
	do {
		Hand *p_hand = new Hand;
		Hand *d_hand = new Hand;

		bool game_over = false;
		cout << "----------------------------------------------" << endl;
		cout << "Game round: " << round << endl;
		int bet;
		char choice = 'y';

		do{
			cout << "You have " << player.get_money() << " $ \t"
				<< "\tEnter bet:";
			cin >> bet;
			
			if (bet > player.get_money()) {
				cout << "You do not have enough money." << endl;
			}
		}while (bet > player.get_money());
		
		do {
			Card new_card1;
			cout << "\nNew card: \t" << new_card1.get_rank()
				<< " of " << new_card1.get_suit() << endl;
			p_hand->draw_card(new_card1);

			Card new_card2;
			cout << "dealer's new card: \t" << new_card2.get_rank()
				<< " of " << new_card2.get_suit() << endl;
			d_hand->draw_card(new_card2);

			if ((p_hand->get_total()> 7.5) && (d_hand->get_total() > 7.5))
			{
				cout << "\nNow your total is " << p_hand->get_total() << "!\n";
				cout << "The dealer's total is " << d_hand->get_total() << "!\n";
				cout << "Tie!" << endl; 
				game_over = true;
				break;
			}
			else if ((p_hand->get_total() > 7.5) && (d_hand->get_total() <= 7.5))
			{
				cout << "\nNow your total is " << p_hand->get_total() << "!\n";
				cout << "The dealer's total is " << d_hand->get_total() << "!\n";
				player.reduce_money(bet); 
				cout << " You lose " << bet << "$ " << endl;
				game_over = true;
				break;
			}
			else if ((p_hand->get_total() <= 7.5) && (d_hand->get_total() > 7.5))
			{
				cout << "\nNow your total is " << p_hand->get_total() << "!\n";
				cout << "The dealer's total is " << d_hand->get_total() << "!\n";
				player.add_money(bet);
				cout << " You win " << bet << "$ " << endl;
				game_over = true;
				break;
			}

			cout << "Do you want another cards (y/n)? ";
			cin >> choice;

		} while ((choice != 'n') && (d_hand->get_total() < 5.5));

		while ((game_over != true) && (choice != 'n') && (d_hand->get_total() >= 5.5))
		{
			Card new_card1;
			cout << "\nNew card: \t" << new_card1.get_rank()
				<< " of " << new_card1.get_suit() << endl;
			p_hand->draw_card(new_card1);

			if (p_hand->get_total() > 7.5)
			{
				cout << "\nNow your total is " << p_hand->get_total() << "!\n";
				cout << "The dealer's total is " << d_hand->get_total() << "!\n";
				player.reduce_money(bet);
				cout << " You lose " << bet << "$ " << endl;
				game_over = true;
				break;
			}
			cout << "Do you want another cards (y/n)? ";
			cin >> choice;
		}

		while ((game_over != true) && (choice == 'n') && (d_hand->get_total() >= 5.5))
		{
			if (d_hand->get_total() > p_hand->get_total())
			{
				cout << "\nNow your total is " << p_hand->get_total() << "!\n";
				cout << "The dealer's total is " << d_hand->get_total() << "!\n";
				player.reduce_money(bet);
				cout << " You lose " << bet << "$ " << endl;
				game_over = true;
				break;
			}
			else if (d_hand->get_total() == p_hand->get_total())
			{
				cout << "\nNow your total is " << p_hand->get_total() << "!\n";
				cout << "The dealer's total is " << d_hand->get_total() << "!\n";
				cout << "Tie!" << endl;
				game_over = true;
				break;
			}
			else if (d_hand->get_total() < p_hand->get_total())
			{
				cout << "\nNow your total is " << p_hand->get_total() << "!\n";
				cout << "The dealer's total is " << d_hand->get_total() << "!\n";
				player.add_money(bet);
				cout << " You win " << bet << "$ " << endl;
				game_over = true;
				break;
			}

		}

		while ((game_over != true) && (choice == 'n') && (d_hand->get_total() < 5.5))
		{
			Card new_card2;
			cout << "dealer's new card: \t" << new_card2.get_rank()
				<< " of " << new_card2.get_suit() << endl;
			d_hand->draw_card(new_card2);

			if (d_hand->get_total() > 7.5)
			{
				cout << "\nNow your total is " << p_hand->get_total() << "!\n";
				cout << "The dealer's total is " << d_hand->get_total() << "!\n";
				player.add_money(bet);
				cout << " You win " << bet << "$ " << endl;
				game_over = true;
				break;
			}
			else if ((d_hand->get_total() >= 5.5) && (d_hand->get_total() > p_hand->get_total()))
			{
				cout << "\nNow your total is " << p_hand->get_total() << "!\n";
				cout << "The dealer's total is " << d_hand->get_total() << "!\n";
				player.reduce_money(bet);
				cout << " You lose " << bet << "$ " << endl;
				game_over = true;
				break;
			}
			else if ((d_hand->get_total() >= 5.5) && (d_hand->get_total() == p_hand->get_total()))
			{
				cout << "\nNow your total is " << p_hand->get_total() << "!\n";
				cout << "The dealer's total is " << d_hand->get_total() << "!\n";
				cout << "Tie!" << endl;
				game_over = true;
				break;
			}
			else if ((d_hand->get_total() >= 5.5) && (d_hand->get_total() < p_hand->get_total()))
			{
				cout << "\nNow your total is " << p_hand->get_total() << "!\n";
				cout << "The dealer's total is " << d_hand->get_total() << "!\n";
				player.add_money(bet);
				cout << " You win " << bet << "$ " << endl;
				game_over = true;
				break;
			}
		}
		delete p_hand, d_hand;

		if (player.get_money() <= 0)
		{
			cout << "\nGame Over! " << endl;
			break;
		}
		round += 1;
		cout << "Continue<y/n>?";
		cin >> answer;
		cout << endl;
	} while (answer == 'y');

	time(&t2);
	cout << "You played " << t2 - t1 << " seconds." << endl;

	system("pause");
	return 0;
	
}

