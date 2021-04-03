#include<iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#include <sstream> 
using namespace std;

void shuffleCards(int deck[])
{
	int n = 0;
	for (int i = 1; i <= 13; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			deck[n] = 10 * i + j;
			n++;
		}
	}
	
	int r;
    srand((int)time(0));
    for(int i = 0; i < 52; ++i){
		int j = rand() % 52;
		int temp = deck[i];
		deck[i] = deck[j];
		deck[j] = temp;
    }  

}

char CheckSuits(int n)
{
	switch (n % 10)
	{
	case 0:
		return 3; // Hearts
	case 1:
		return 4; // Diamonds
	case 2:
		return 5; // Clubs
	case 3:
		return 6; // Spades
	
	default:
		return '0';
	}
}

string CheckRank(int n)
{
	int r = n / 10;
	if (r == 1)
		return "A";
	if (r == 11)
		return "J";
	if (r == 12)
		return "Q";
	if (r == 13)
		return "K";
	if (r == 10)
		return "10";
	if (r >= 2 || r <= 9)
	{
		stringstream ss;
		ss << r;
		string str = ss.str();
		return str;
	}

	return "ERR";
}

void printCardsShuffling(int deck[])
{
	for(int i = 0; i < 52; i++)
		cout << CheckRank(deck[i]) << CheckSuits(deck[i]) << " " << endl;
}
int main()
{

    int deck[52];
	shuffleCards(deck);
	for (int i = 0; i < 52; i++)
		cout << deck[i] << " ";  
	cout << endl;
	printCardsShuffling(deck);
	return 0;
}
