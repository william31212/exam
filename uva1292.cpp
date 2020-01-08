#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "uva1292"

#define PB push_back
#define MAXN 2000
#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)


vector<int> G[2000];
int dp[MAXN][2];
bool vis[MAXN];

void dfs(int a)
{
	vis[a] = 1;
	dp[a][0] = 0;
	dp[a][1] = 1;

	for(auto i : G[a])
	{
		if(vis[i])
			continue;
		dfs(i);
		//該格沒人的狀態
		dp[a][0] += dp[i][1];
		//該格有人的狀態
		dp[a][1] += min(dp[i][0],dp[i][1]);
		// printf("%d: %d,%d\n",a,dp[a][0],dp[a][1]);
	}
}


int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int t;
	while(cin >> t)
	{
		memset(dp,0,sizeof(dp));
		memset(vis,0,sizeof(vis));
		for(int i = 0; i < 2000; i++)
			G[i].clear();

		int node, n;

		for(int k = 0; k < t; k++)
		{
			scanf("%d:(%d) ",&node,&n);
			for (int i = 0, tmp; i < n; i++)
			{
				cin >> tmp;
				G[node].PB(tmp);
				G[tmp].PB(node);
			}
		}

		int ans = 0;
		for(int i = 0; i < t; i++)
		{
			if(vis[i])
				continue;
			dfs(i);
			ans += min(dp[i][0], dp[i][1]);
		}
		printf("%d\n",ans);

	}

	return 0;
}