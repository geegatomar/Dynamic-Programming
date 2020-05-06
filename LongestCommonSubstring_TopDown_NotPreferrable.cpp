#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;

int lcs(string a, string b, int n, int m)
{
	if(n == 0 || m == 0)
		return 0;
	if(dp[n][m] == -1)
	{
		if(a[n-1] == b[m-1])
			dp[n][m] =  1 + lcs(a, b, n-1, m-1);
		else
		{
			dp[n][m] =  0;
			dp[n-1][m] = lcs(a, b, n-1, m);
			dp[n][m-1] = lcs(a, b, n , m-1);
		}
	}
	return dp[n][m];
}

int main()
{
	string a = "abcdeff", b = "aboeffh";
	int n = a.size(), m = b.size();
	dp.resize(n+1);
	for(int i = 0; i < n+1; i++)
	{
		dp[i].resize(m+1, -1);
	}
	dp[n][m] = lcs(a, b, n ,m);
	int max = 0;
	for(int i = 0; i <= n; i++)
	{
		for(int j = 0; j <= m; j++)
		{
			cout << dp[i][j] << " ";
			if(dp[i][j] > max)
				max = dp[i][j];
		}
		cout << endl;
	}
	cout << max <<endl;

}
