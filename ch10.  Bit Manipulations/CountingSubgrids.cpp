/*
 * Problem : Given n*n grid whose each square is either black(1) or white(0), calculate the number of subgrids whose all corners are black.
 * Author: Anand Kumar
 */

#include<bits/stdc++.h>
using namespace std;

int count_subgrids(int n,void *input)
{
	
	int (*color)[n] = static_cast<int (*)[n]>(input);	
    int subgrids = 0;
    for(int a=0; a<n; ++a)
    {
        for(int b=a+1; b<n; ++b) 
        {			   
            int count=0;
            for(int i=0; i<n; ++i) 
            { 
                if(color[a][i]==1 && color[b][i]==1)
                    ++count;
            }
            subgrids += ((count-1)*count)/2;
        }
	}
	
    return subgrids;
    
}

int main()
{
	int n=5;
	int arr[n][n] = {{0,1,0,0,1},{0,1,1,0,0},{1,0,0,0,0},{0,1,1,0,1},{0,0,0,0,0}};
	
	//cout<<count_subgrids(n,arr)<<endl;  O(n^3) approach
	
	/*
	 *  Using bitWise manipulation this can be optimized 15 times
	 */
	
	int block_size = 32;
	int col = (n%block_size)?n/block_size+1:n/block_size;
	int modified_array[n][col];
	
	memset(modified_array,0,sizeof(modified_array));
	
	for(int i=0;i<n;i++)
	{
		int j=0;
		int l=0;
		while(j<n)
		{
			int value=0;
			int delta = 0;
			if((n-j)<=(block_size-1))
				delta = (block_size+j-n);
			for(int k=block_size-1-(delta);k>=0 && j<n;k--)
			{
				value += arr[i][j]*(1<<k);
				j++;
			}
			modified_array[i][l++] = value;
		}
	}
	
	/*
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<col;j++)
		{
			cout<<modified_array[i][j]<<" ";
		}
		cout<<endl;
	}
	*/
	
	int number_of_rect = 0;
	for(int a=0;a<n;a++)
	{
		for(int b=a+1;b<n;b++)
		{
			int count = 0;
			for(int i=0;i<col;i++)
			{
				count += __builtin_popcount(modified_array[a][i]&modified_array[b][i]);
			}
			number_of_rect += (count*(count-1))/2;
		}
	}
	
	cout<<number_of_rect<<endl;
	
	return 0;
}
