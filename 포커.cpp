#pragma warning (disable:4996)
#include <stdio.h>
#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5
int num_in_rank[NUM_RANKS + 1];
int num_in_suit[NUM_SUITS];

char hand[5][2];
void array(void)
{
	int temp;

	for (int i = 0; i < NUM_RANKS - 1; i++)
		for (int j = 0; j < NUM_RANKS - 1 - i; j++)
		{
			if (num_in_rank[j] > num_in_rank[j + 1])
			{
				temp = num_in_rank[j];
				num_in_rank[j] = num_in_rank[j + 1];
				num_in_rank[j + 1] = temp;
			}
		}
}
int check_flush()
{
	for (int i = 0; i < NUM_SUITS; i++)
		if (num_in_suit[i] == 5)
			return 1;

	return 0;
}
int check_straight()
{
	for (int i = 1; i < 10; i++)
		if (num_in_rank[i] == 1 && num_in_rank[i + 1] == 1 && num_in_rank[i + 2] == 1 && num_in_rank[i + 3] == 1 && num_in_rank[i + 4] == 1)
			return 1;

	return 0;
}
int check_four_cards()
{
	for (int i = 1; i <= NUM_RANKS; i++)
		if (num_in_rank[i] == 4)
			return 1;

	return 0;
}
int check_three_cards()
{
	for (int i = 1; i <= NUM_RANKS; i++)
		if (num_in_rank[i] == 3)
			return 1;

	return 0;
}
int count_pairs()
{
	int count = 0;

	for (int i = 1; i <= NUM_RANKS; i++)
		if (num_in_rank[i] == 2)
			count++;

	if (count == 1)
		return 1;
	else if (count == 2)
		return 2;

	return 0;
}
void init_data()
{
	int rank, suit;
	for (rank = 0; rank < NUM_RANKS; rank++)
		num_in_rank[rank] = 0;
	for (suit = 0; suit < NUM_SUITS; suit++)
		num_in_suit[suit] = 0;
}
void read_cards(void)
{
	char rank_ch, suit_ch;
	int rank, suit;
	int cards_read = 0;

	init_data();

	while (cards_read < NUM_CARDS)
	{
		printf("Enter a card: ");
		scanf(" %c", &rank_ch);
		if (rank_ch != 'a' && (rank_ch < '2' && rank_ch > '9') && rank_ch != 't' && rank_ch != 'q' && rank_ch != 't')
		{
			printf("다시 입력하세요");
			continue;
		}
		switch (rank_ch)
		{
		case 'a':
			rank = 1;
			break;
		case '2':
			rank = 2;
			break;
		case '3':
			rank = 3;
			break;
		case '4':
			rank = 4;
			break;
		case '5':
			rank = 5;
			break;
		case '6':
			rank = 6;
			break;
		case '7':
			rank = 7;
			break;
		case '8':
			rank = 8;
			break;
		case '9':
			rank = 9;
			break;
		case 't':
			rank = 10;
			break;
		case 'j':
			rank = 11;
			break;
		case 'q':
			rank = 12;
			break;
		case 'k':
			rank = 13;
			break;
		}

		scanf(" %c", &suit_ch);
		if (suit_ch != 'c' && suit_ch != 'd' && suit_ch != 'h' && suit_ch != 's')
		{
			printf("다시 입력하세요\n");
			continue;
		}

		switch (suit_ch)
		{
		case 'c':
			suit = 0;
			break;
		case 'd':
			suit = 1;
			break;
		case 'h':
			suit = 2;
			break;
		case 's':
			suit = 3;
			break;
		}

		hand[cards_read][0] = rank_ch;
		hand[cards_read][1] = suit_ch;

		int flag = 1;
		for (int i = 0; i < cards_read; i++)
			if (hand[i][0] == rank_ch && hand[i][1] == suit_ch) {
				printf("중복입력\n");
				flag = 0;
				break;
			}

		if (flag==1)
		{
		    num_in_rank[rank]++;
	            num_in_suit[suit]++;
		    cards_read++;
		}
	}
	array();
}
void analyze_hand(void)
{

	if (check_flush() == 1 && check_straight() == 1)
		printf("straight flush\n");
	else if (check_four_cards() == 1)
		printf("four cards\n");
	else if (check_three_cards() == 1 && count_pairs() == 1)
		printf("full house\n");
	else if (check_flush() == 1)
		printf("flush\n");
	else if (check_straight() == 1)
		printf("straight\n");
	else if (check_three_cards() == 1)
		printf("triple\n");
	else if (count_pairs() == 2)
		printf("two pair\n");
	else if (count_pairs() == 1)
		printf("one pair\n");
	else
		printf("high card\n");

}
int main()
{
	while (1) {
		read_cards();
		analyze_hand();
	}
}
