#include<bits/stdc++.h>
using namespace std;

int main()
{
	string a = "aapbcbceddp";
	int n = a.size(), i, j;
	vector<vector<int>> dp(n+1, vector<int> (n+1));
	for(i = 0; i <= n; i++)
	{
		for(j = 0; j <= n; j++)
		{
			if(i == 0 || j == 0)
			{
				dp[i][j] = 0;
				continue;
			}
			if(a[i-1] == a[j-1] && i != j)
			{
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else
			{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	cout << dp[n][n] << endl;
}
