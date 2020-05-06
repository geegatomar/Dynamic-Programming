#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;

int solve(int e, int f)
{
	if(f == 0 || f == 1)
		return f;
	if(e == 1)
		return f;
	if(dp[e][f] != -1) return dp[e][f];

	int mn = INT_MAX;

	for(int k = 1; k <= f; k++)
	{
		int temp = 1 + max( solve(e, f-k), solve(e-1, k-1));
		mn = min(mn, temp);
	}
	return dp[e][f] =  mn;
}

int main()
{
	int f = 36, e = 2;
	dp.resize(e + 1);
	for(int i = 0; i < e + 1; i++)
	{
		dp[i].resize(f+1, -1);
	}
	cout << solve(e, f) << endl;
}
