#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;

bool ispal(string s, int st, int en)
{
	for(int i = st; i < en; i++)
	{
		if(s[i] != s[en+st-i])
			return false;
	}
	return true;
}

int solve(string s, int i, int j)
{
	cout << "i : " << i << "   j: " << j <<endl;
	if(i >= j)
		return 0;
	if(ispal(s, i, j)) return 0;
	if(dp[i][j] != -1)
		return dp[i][j];
	int ans = INT_MAX;
	for(int k = i; k <= j-1; k++)
	{
		int tempans = solve(s, i, k) + solve(s, k+1, j) + 1;
		ans = min(ans, tempans);
	}
	return dp[i][j] = ans;
}

int main()
{
	string s = "ababbbabbababa";
	int n = s.size();
	dp.resize(n+1);
	cout << ispal(s, 1, 5) << endl;
	for(int i = 0;	i < n+1; i++)
	{
		dp[i].resize(n+1, -1);
	}

	cout << solve(s, 0, n-1) <<endl;
	for(int i = 0; i < n+1; i++)
	{
		for(int j = 0; j < n+1; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
}
