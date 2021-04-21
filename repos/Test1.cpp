#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main() 
{
	const int N = 10, NUM = 2;
	int k = 0, data[N] = {32, 45, 98, 2, 101, 56, 89, 78, 24, 100}, loc[NUM], temp[NUM];
	
	while (k < 2)
	{
		int i = 0, Oloop = 0, j = 1;
		while (Oloop < N)
		{
			if (data[i] > data[i + j]
				{
					i = j;
					j = 1;
					Oloop++;
				}
			else
			{
				j++;
				Oloop++;
			}
		}
		loc[k] = i;
		temp[k] = data[i];
		data[i] = 0;
	}

	while (k < 2)
	{
		data[loc[k]] = temp[k];
		cout << loc[k];
	}
}