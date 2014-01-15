#include <iostream>
#include <vector>
#include <map>
#include <stdlib.h>

using namespace std;

int n = 10000000;
int seq = 1;

enum{RED,BLACK}; // myArr[RED] == myArr[0]. myArr[BLACK] == myArr[1]
map  <int, int> vals;
map <int, int> seqs;
vector <int> keys;

int main()
{
	cout << "Roulette" << endl;

	vals[RED] = 0;
	vals[BLACK] = 0;

	srand(time(0));
	int prevRnd = rand() % 2;	
	vals[prevRnd]++;

	for(int i = 0; i < n; i++)
	{
		int rnd = rand() % 2;
		vals[rnd]++;

		if (prevRnd == rnd) 
			seq++;
		else
		{
			if (seqs[seq] == 0)
			{
				keys.push_back(seq);
			}

			seqs[seq]++;
			seq = 1;
		}

		prevRnd = rnd;	
	}

	cout << "Number of black: " << vals[BLACK] << endl;
	cout << "Number of red: " << vals[RED] << endl;
	
	sort(keys.begin(),keys.end());
	for(int i = 0; i < keys.size(); i++)
	{
		cout << keys[i] << "\t" << seqs[keys[i]] << endl;
	}
}
