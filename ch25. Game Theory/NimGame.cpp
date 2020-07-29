/*============================================================================
 * Problem : Implement an algorithm to find the winner for a nim game
 *
 * Author  : Anand Kumar
============================================================================*/

#include<bits/stdc++.h>
using namespace std;

int calculateNimSum(int piles[], int n)
{
	int nim_sum = 0;
	for(int i=0; i<n; i++)
		nim_sum ^= piles[i];
	return nim_sum;
}

bool game_over(int piles[], int n)
{
	for(int i=0; i<n; i++)
		if(piles[i])
			return false;
	return true;
}

void show_configuration(int piles[], int n)
{
	cout<<"The current number of blocks in each pile is given by :::\n";
	for(int i=0; i<n; i++)
		cout<<piles[i]<<" ";
	cout<<endl;
}

void play_game(int piles[], int n, bool human_turn)
{

	while(!game_over(piles, n))
	{

		if(human_turn)
			cout<<"Human turn -> ";
		else
			cout<<"Computer turn -> ";

		show_configuration(piles, n);
		int sum = calculateNimSum(piles, n);
		if(sum)
		{
			// remove element using strategy
			for(int i=0; i<n; i++)
			{
				if((piles[i]^sum) < piles[i])
				{
					piles[i] = piles[i]^sum;
					break;
				}
			}
		}
		else
		{
			// remove elements randomly
			int m=0;
			int piles_idx_non_zero_emnt[n] = {0};
			for(int i=0; i<n; i++)
				if(piles[i])
					piles_idx_non_zero_emnt[m++] = i;

			int random_pile = rand()%m;
			piles[random_pile] = piles[random_pile] - (1+ (rand()%piles[random_pile]));

			if(piles[random_pile] < 0)
				piles[random_pile] = 0;

		}

		human_turn = !human_turn;

	}

	if(human_turn)
		cout<<"Computer won"<<endl;
	else
		cout<<"Human won"<<endl;

}

int main()
{

	int n = 3;
	int piles[] = {9, 12, 5};
	bool human_turn = true;

	play_game(piles, n, human_turn);

	return 0;

}
