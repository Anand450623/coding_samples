/*============================================================================
 * Problem   : Implement Sqrt root decomposition algorithm to update array element and to find range sum queries.
 * Author    : Anand Kumar
============================================================================*/

#include<bits/stdc++.h>
using namespace std;

void update(int input[], int block_sum[], int block_size, int index, int new_value)
{
	int old_value = input[index];
	input[index] = new_value;
	block_sum[index/block_size] += (new_value-old_value);
}

int range_sum(int input[], int block_sum[], int block_size, int start_index, int end_index)
{

	int sum = 0;

	// first part: calculates the portion from left sub-array for which the whole part  cannot be considered as sum of whole block
	for( ; start_index%block_size!=0 and start_index < end_index; start_index++)
		sum += input[start_index];

	// middle part: calculates all the possible sub-array sum where sum can be taken as the sum of blocks
	for( ; start_index+block_size <= end_index; start_index += block_size)
		sum += block_sum[start_index/block_size];

	// last part: calculates the portion from right sub-array for which the whole part  cannot be considered as sum of whole block
	for( ; start_index <= end_index; start_index++)
		sum += input[start_index];

	return sum;

}

int main()
{

	int input[] = {1, 5, 2, 4, 6, 1, 3, 5, 7, 10};
    int n = sizeof(input)/sizeof(input[0]);
    int block_size = ceil(sqrt(n));

    int block_sum[block_size] = {0};
    for(int i=0; i<n; i++)
    	block_sum[i/block_size] += input[i];

    cout<<"The input array is = ";
    for(int i=0; i<n; i++)
    	cout<<input[i]<<" ";
    cout<<endl;

    cout<<"Block sum before update in array = ";
    for(int i=0; i<block_size; i++)
    	cout<<block_sum[i]<<" ";
    cout<<endl;

    // calculating range sum for index [3, 8]
    cout<<"The required range[3,8] sum is = "<<range_sum(input, block_sum, block_size, 3, 8)<<endl;

    // updating 3rd index element to zero(0)
    update(input, block_sum, block_size, 3, 0);

    cout<<"Block sum after update in array = ";
    for(int i=0; i<block_size; i++)
		cout<<block_sum[i]<<" ";
	cout<<endl;

	return 0;

}
