#include <bits/stdc++.h>

using namespace std;

struct node
{
	int arr[8];
}vec[20000];

int check(int id, int pre_id, int pre)
{
	if(id > pre_id)
	{
		for(int i = 7; i >= 0; i--)
		{
			if(pre >= vec[id].arr[i])
				return i;
		}
	}
	else
	{
		for(int i = 7; i >= 0; i--)
		{
			if(pre > vec[id].arr[i])
				return i;
		}
	}
	return -1;


}

int main()
{
	int t,kase=1;
	int seq[20000];
	while(cin >> t && t)
	{
		memset(seq,0,sizeof(seq));
		double a,b,c;
		for(int i = 0; i < t; i++)
		{
			cin >> a >> b >> c;
			vec[i+1].arr[0] = 0;
			vec[i+1].arr[1] = round(a*100);
			vec[i+1].arr[2] = round(b*100);
			vec[i+1].arr[3] = round(c*100);
			vec[i+1].arr[4] = round((a+b)*100);
			vec[i+1].arr[5] = round((b+c)*100);
			vec[i+1].arr[6] = round((a+c)*100);
			vec[i+1].arr[7] = round((a+b+c)*100);
		}

		for(int i = 0; i < t; i++)
			cin >> seq[i];

		int pre_id,pre,flag=0;
		for(int i = 0; i < t; i++)
		{
			sort(vec[seq[i]].arr,vec[seq[i]].arr+8);
			if(i == 0)
			{
				pre_id = seq[i];
				pre = vec[seq[i]].arr[7];
			}
			else
			{
				int state = check(seq[i],pre_id,pre);
				if(state == -1)
				{
					flag = 1;
					break;
				}
				else
				{
					pre_id = seq[i];
					pre = vec[seq[i]].arr[state];
				}
			}
		}

		if(!flag)
			printf("Case %d: %.2f\n",kase++,pre/100.00);
		else
			printf("Case %d: No solution\n",kase++);
	}
}