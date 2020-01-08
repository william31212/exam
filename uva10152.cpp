#include <bits/stdc++.h>

#define PB push_back
using namespace std;

int main()
{
	int t,len;
	bool flag = 0;
	while(~scanf("%d\n",&t))
	{
		while(t--)
		{
			scanf("%d\n",&len);
			string tmp;
			vector<string> A,B;
			for(int i = 0; i < len; i++)
				getline(cin,tmp),A.PB(tmp);
			for(int i = 0; i < len; i++)
				getline(cin,tmp),B.PB(tmp);

			int idx = len;
			for(int i = len-1, j = len-1; i >= 0;)
			{
				if(A[i] == B[j])
					i--,j--,idx = j;
				else
					i--,idx = j;
			}

			if(!flag)
				flag = 1;
			else
				puts("");

			for(int i = idx; i >= 0; i--)
				cout << B[i] << '\n';

		}
		printf("\n");
	}

}