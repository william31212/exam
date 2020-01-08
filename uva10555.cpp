#include <bits/stdc++.h>

using namespace std;

int main()
{
	string str;
	while(getline(cin,str))
	{
		string num = "";
		if(str.size() == 1)
			break;
		else
		{
			for(int i = 2; str[i] != '.'; i++)
			{
				num += str[i];
			}
		}


		int all = 0;
		all = stoi(num);
		int mo_num=0,ch_num=0;
		int ans_mo = INT_MAX;
		int ans_ch = INT_MAX;

		for(int i = num.size()-1; i >= 0; i--)
		{
			string mo,ch;
			for(int j = i; j < num.size(); j++)
			{
				mo += '9';
			}
			for(int j = 0; j < i; j++)
			{
				mo += '0';
				ch += num[j];
			}

			if(ch.size() == 0)
				ch = '0';

			mo_num = stoi(mo);
			ch_num = all - stoi(ch);
			//printf("fuck:%d %d\n",ch_num,mo_num);

			int div = __gcd(mo_num,ch_num);
			if(div >= 1)
			{
				mo_num /= div;
				ch_num /= div;
			}

			if(ans_mo > mo_num)
			{
				ans_mo = mo_num;
				ans_ch = ch_num;
			}
		}

		printf("%d/%d\n",ans_ch,ans_mo);
	}
}