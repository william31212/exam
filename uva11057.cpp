#include <bits/stdc++.h>

#define PB push_back
using namespace std;

int main()
{
	int t,check;
	vector<int> vec;
	while(cin >> t)
	{
		vec.clear();
		for(int i = 0,tmp; i < t; i++)
			cin >> tmp,vec.PB(tmp);

		cin >> check;
		int a=0,b=0;
		sort(vec.begin(),vec.end());
		for(int i = 0; i < t; i++)
		{
			for(int j = i+1; j < t; j++)
			{
				if(vec[i] + vec[j] == check)
				{
					a = vec[i];
					b = vec[j];
				}
			}
		}

		printf("Peter should buy books whose prices are %d and %d.\n\n",a,b);
	}
}