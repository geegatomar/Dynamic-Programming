#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;

int cc(int coins[], int sum, int n)
{
	if(sum == 0)
		return 1;
	if(n == 0)
		return 0;
	if(dp[n][sum] == -1)
	{
		if(sum < coins[n] )
			dp[n][sum] = cc(coins, sum , n-1);
		else
		{
			dp[n][sum] = cc(coins, sum, n-1) + cc(coins, sum - coins[n], n);
		}
	}
	return dp[n][sum];
}

int main()
{
	int coins[] = {0, 1, 2, 3};
	int sum = 5;
	int n = 3;
	dp.resize(n+1);
	for(int i = 0; i < n+1; i++)
	{
		dp[i].resize(sum+1, -1);
	}
	cout << cc(coins, sum, n) << endl;
}
