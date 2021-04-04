#include<iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#include <sstream> 
using namespace std;
// Phan 1
void shuffleCards(int deck[])
{
	int n = 0;
	for (int i = 2; i <= 14; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			deck[n] = 10 * i + j;
			n++;
		}
	}

	int r;
	srand((int)time(0));
	for (int i = 0; i < 52; ++i) {
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
	if (r == 14)
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
	for (int i = 0; i < 52; i++)
		cout << CheckRank(deck[i]) << CheckSuits(deck[i]) << "\t";
}
// Phan 2
int* dealingForHand(int deck[])
{
	int* ptr = NULL;
	ptr = new int[5];

	for (int i = 0; i < 5; i++)
		ptr[i] = deck[i];

	return ptr;
}

void printHand(int* hand)
{
	for (int i = 0; i < 5; i++)
		cout << CheckRank(hand[i]) << CheckSuits(hand[i]) << "  ";
}

void SapXep(int* hand)
{
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5 - i - 1; j++)
			if ((hand[j]) > (hand[j + 1]))
			{
				int temp = hand[j];
				hand[j] = hand[j + 1];
				hand[j + 1] = temp;
			}
}


int isRoyalFlush(int* hand) //(1) Sanh hoang gia (rong) 10 J Q K A -> Cung chat, lien tiep 
{
	SapXep(hand);
	if (hand[0] / 10 == 10)
		return 0;
	else
	{
	for (int i = 0; i < 4; i++)
		if ((hand[i] + 10) != (hand[i + 1]))
		{
			return 0;
		}
	}
	return 1;
}

int isStraightFlush(int* hand) //(2) Thung pha sanh -> Cung chat, lien tiep 
{
	SapXep(hand);
	int text[5];
	for (int i = 0; i < 5; i++)
	{
		if (hand[i] >= 140)
			text[i] = hand[i] - 130;
		else
			text[i] = hand[i];
	}
	
	for (int i = 0; i < 4; i++)
		if ((text[i] + 10) != (text[i + 1]))
		{
			return 0;
		}
	return 2;
}

int isFourOfAKind(int* hand) // (3) Tu quy
{
	SapXep(hand);
	if ((hand[0] == hand[1] && hand[1] == hand[2] && hand[2] == hand[3]) ||
		(hand[4] == hand[1] && hand[1] == hand[2] && hand[2] == hand[3]))
		return 3;
	else
		return 0;
}

int isFullHouse(int* hand) // (4) Cu lu ->  3 (sam) + 2 (doi)
{
	int rank1 = hand[0] / 10;
	int count1 = 0, count2 = 0;
	int rank2 = 0;
	for (int i = 0; i < 5; i++)
	{
		if (hand[i] / 10 == rank1)
		{
			count1++;
		}
		rank2 = hand[i] / 10;
	}
	for (int i = 0; i < 5; i++)
	{
		if (hand[i] / 10 == rank2)
		{
			count2++;
		}
	}
	if (count1 == 2 && count2 == 3 || count1 == 3 && count2 == 2)
		return	4;
	else
		return 0;
}

int isFlush(int* hand) // (5) Thung -> 5 con cung chat
{
	for (int i = 0; i < 4; i++)
		if ((hand[i] % 10) != (hand[i + 1] % 10))
		{
			return 0;
		}
	return 5;
}

int isStraight(int* hand) // (6) Sanh -> 5 con lien tiep
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = i + 1; j < 5; j++)
		{
			if (hand[i] > hand[j])
			{
				int temp = hand[j];
				hand[j] = hand[i];
				hand[i] = temp;
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		if (hand[i + 1] / 10 - hand[i] / 10 != 1)
			return 0;
	}
	return 6;
}

int isThreeOfAKind(int* hand) // (7) Sam co -> 1 Sam
{
	SapXep(hand);
	if (hand[0] / 10 == hand[1] / 10 && hand[1] / 10 == hand[2] / 10)
	{
		if (hand[3] / 10 != hand[4] / 10)
			return 7;
		else
			return 0;
	}
	else if (hand[1] / 10 == hand[2] / 10 && hand[2] / 10 == hand[3] / 10)
	{
		if (hand[0] / 10 != hand[4] / 10)
			return 7;
		else
			return 0;
	}
	else if (hand[2] / 10 == hand[3] / 10 && hand[3] / 10 == hand[4] / 10)
	{
		if (hand[0] / 10 != hand[1] / 10)
			return 7;
		else
			return 0;
	}
	else
		return 0;
}

int isTwoPairs(int* hand) // (8) Thu -> 2 doi
{
	SapXep(hand);
	if (((hand[0] / 10) == (hand[1] / 10) && (hand[2] / 10) == (hand[3] / 10) && (hand[3] / 10) != (hand[4] / 10)) ||
		((hand[1] / 10) == (hand[2] / 10) && (hand[3] / 10) == (hand[4] / 10) && (hand[0] / 10) != (hand[1] / 10)) ||
		((hand[0] / 10) == (hand[1] / 10) && (hand[3] / 10) == (hand[4] / 10) && (hand[1] / 10) != (hand[2] / 10) && (hand[2] / 10) != (hand[3] / 10)))
			return 8;
	return 0;
}	

int isPair(int* hand) // (9) Doi
{
	SapXep(hand);
	if (hand[0] / 10 == hand[1] / 10)
	{
		if (hand[2] / 10 != hand[3] / 10 && hand[3] / 10 != hand[4] / 10 && hand[2] / 10 != hand[4] / 10)
			return 9;
		else
			return 0;
	}
	else if (hand[1] / 10 == hand[2] / 10)
	{
		if (hand[0] / 10 != hand[3] / 10 && hand[3] / 10 != hand[4] / 10 && hand[0] / 10 != hand[4] / 10)
			return 9;
		else
			return 0;
	}
	else if (hand[2] / 10 == hand[3] / 10)
	{
		if (hand[0] / 10 != hand[1] / 10 && hand[1] / 10 != hand[4] / 10 && hand[0] / 10 != hand[4] / 10)
			return 9;
		else
			return 0;
	}
	else if (hand[2] / 10 == hand[3] / 10)
	{
		if (hand[0] / 10 != hand[1] / 10 && hand[1] / 10 != hand[4] / 10 && hand[0] / 10 != hand[4] / 10)
			return 9;
		else
			return 0;
	}
	else if (hand[3] / 10 == hand[4] / 10)
	{
		if (hand[0] / 10 != hand[1] / 10 && hand[1] / 10 != hand[2] / 10 && hand[0] / 10 != hand[2] / 10)
			return 9;
		else
			return 0;
	}
	else
		return 0;

}
int getHighestCard(int* hand)
{
	if (isRoyalFlush(hand) == 1)
		return 1;
	if (isStraightFlush(hand) == 2)
		return 2;
	if (isFourOfAKind(hand) == 3)
		return 3;
	if (isFullHouse(hand) == 4)
		return 4;
	if (isFlush(hand) == 5)
		return 5;
	if (isStraight(hand) == 6)
		return 6;
	if (isThreeOfAKind(hand) == 7)
		return 7;
	if (isTwoPairs(hand) == 8)
		return 8;
	if (isPair(hand) == 9)
		return 9;
	return 10;
}
int main()
{

	int deck[52];
	shuffleCards(deck);
	for (int i = 0; i < 52; i++)
		cout << deck[i] << " ";
	cout << endl;
	printCardsShuffling(deck);
	cout << endl;

	int* hand;
	hand = dealingForHand(deck);
	SapXep(hand);
	printHand(hand);

	return 0;
}
