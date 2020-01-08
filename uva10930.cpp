#include <bits/stdc++.h>

#define PB push_back
using namespace std;

vector <int> vec;
int main()
{
	int dp[30000],kase=1,t;
	while(cin >> t)
	{
		memset(dp,0,sizeof(dp));
		vec.clear();
		for(int i = 0,tmp; i < t; i++)
			cin >> tmp,vec.PB(tmp);

		bool flag = 1;
		for(int i = 0; i < t-1; i++)
		{
			if(vec[i] > vec[i+1])
				flag = 0;
		}

		for(int i = 0; i < t; i++)
		{
			if(dp[vec[i]])
			{
				flag = 0;
				break;
			}
			for(int j = 30000; j >= vec[i]; j--)
			{
				if(dp[j-vec[i]])
					dp[j] = 1;
			}
			dp[vec[i]] = 1;
		}

		printf("Case #%d:",kase++);
		for(int i = 0; i < t; i++)
			printf(" %d",vec[i]);

		printf("\n");
		if(!flag)
			printf("This is not an A-sequence.\n");
		else
			printf("This is an A-sequence.\n");

	}
}