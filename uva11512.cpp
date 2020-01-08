#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "uva11512"
#define PB push_back
#define MAXN 2000
#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int is_thesame(string a, string b)
{
	int cnt = 0;
	for(int i = 0; i < min(a.size(),b.size()); i++)
	{
		if(a[i] == b[i])
			cnt++;
		else
			break;
	}

	return cnt;
}

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int t;
	string str;

	while(~scanf("%d\n",&t))
	{
		for(int i = 0; i < t; i++)
		{
			getline(cin,str);
			vector<string> vec;
			for(int k = 0; k < str.size(); k++)
				vec.PB(str.substr(k,str.size()));

			sort(vec.begin(),vec.end());

			int seq[MAXN], idx = 0, now_max = 0;
			memset(seq,0,sizeof(seq));
			for(int s = vec.size()-1; s >= 1; s--)
			{
				int tmp = is_thesame(vec[s], vec[s-1]);
				seq[s] = tmp;
				if(tmp > now_max)
					now_max = tmp;
			}

			int now_idx = -1;
			int cnt = 0;
			for(int i = 1; i < vec.size(); i++)
			{
				if(seq[i] == now_max)
				{
					cnt++;
					now_idx = i;
				}
				else if (cnt != 0)
					break;
			}

			if(now_max == 0)
				cout << "No repetitions found!" << '\n';
			else
				cout << vec[now_idx].substr(0,now_max) << " " << cnt+1 << '\n';
		}
	}

	return 0;
}