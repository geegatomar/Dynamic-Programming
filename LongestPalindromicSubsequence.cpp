#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;

int main()
{
	int i, j;
	string a = "agbcba";
	string b = a;
	reverse(b.begin(), b.end());
	int n = a.size(), m = b.size();
	dp.resize(n+1);
	for(i = 0; i < n+1; i++)
	{
		dp[i].resize(m+1, -1);
	}
	for(i = 0; i <= n; i++)
	{
		for(j = 0; j <= m; j++)
		{
			if(i == 0 || j == 0)
			{
				dp[i][j] = 0;
				continue;
			}
			if(a[i-1] == b[j-1])
			{
				dp[i][j] = dp[i-1][j-1] + 1;

			}
			else
			{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}


		}
	}
	cout << dp[n][m] << endl;
}
