#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;

int lcs(string s1, string s2, int n, int m)
{
	if(n == 0 || m == 0)
		return 0;
	if(dp[n][m] != -1)
		return dp[n][m];
	if(s1[n-1] == s2[m-1])
		return dp[n][m] = 1 + lcs(s1, s2, n-1, m-1);
	return dp[n][m] = max( lcs(s1, s2, n-1, m) , lcs(s1, s2, n, m-1));
}

int main()
{
	string s1 = "abcdgh";
	string s2 = "abedfhr";
	dp.resize(s1.size() + 1);
	for(int i = 0; i < s1.size() + 1; i++)
	{
		dp[i].resize(s2.size() + 1, -1);
	}
	cout << lcs(s1, s2, s1.size(), s2.size()) << endl;
}

