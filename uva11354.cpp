#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define N 100005
#define P pair<int,int>
#define F first
#define S second

struct node
{
	int s,t,l;
	bool operator < (const node &rhs){
		return l < rhs.l;
	}
};

int arr[N];
int cnt[N];
int vis[N];

int n,t,e,a,b,len,tmp;
bool flag = 0;
vector<node> edge;
vector<P> span[N];

void init()
{
	for(int i = 1; i <= n; i++)
		arr[i] = i, cnt[i] = 1;
	memset(vis,0,sizeof(vis));
	tmp = INT_MIN;
	edge.clear();
	for(int i = 0; i < N; i++)
		span[i].clear();
}



int dfs(int s, int e, int ans)
{
	vis[s] = true;
	for(auto i : span[s])
	{
		if(!vis[i.F])
		{
			if(i.F == e)
				tmp = max(max(ans, i.S),tmp); 
			else
			{
				dfs(i.F, e, max(ans, i.S));
			}
		}
	}
}



int main()
{
	while(cin >> n >> e)
	{
		init();
		for(int i = 0; i < e; i++)
		{
			cin >> a >> b >> len;
			edge.PB({a,b,len});
		}
		sort(edge.begin(),edge.end());
		for(int i = 0; i < edge.size(); i++)
		{
			int aa = edge[i].s;
			int bb = edge[i].t;

			while(aa != arr[aa])
			{
				aa = arr[aa];
			}

			while(bb != arr[bb])
			{
				bb = arr[bb];
			}

			if(aa != bb)
			{
				span[edge[i].s].PB(MP(edge[i].t,edge[i].l));
				span[edge[i].t].PB(MP(edge[i].s,edge[i].l));
				if(cnt[aa] >= cnt[bb])
				{
					arr[bb] = aa;
					cnt[aa] += cnt[bb];
				}
				else
				{
					arr[aa] = bb;
					cnt[bb] += cnt[aa];
				}
			}
		}

		if(!flag)
			flag=1;
		else
			puts("");

		cin >> t;
		int st,en;
		for(int i = 0; i < t; i++)
		{
			memset(vis,0,sizeof(vis));
			tmp = INT_MIN;
			cin >> st >> en;
			dfs(st,en,INT_MIN);
			cout << tmp << '\n';
		}

	}
}