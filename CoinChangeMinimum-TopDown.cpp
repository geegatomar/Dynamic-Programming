#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;

int mc(int coins[], int sum, int n)
{
	if(sum == 0)
		return 0;
	if(n == 0)
		return INT_MAX-1;
	if(n == 1)
	{
		if(sum % coins[n-1] == 0)
			return sum/coins[n-1];
		else
			return INT_MAX-1;
	}
	if(dp[n][sum] == -1)
	{
		if(sum < coins[n-1])
			dp[n][sum] = mc(coins, sum, n - 1);
		else
		{
			dp[n][sum] = min( mc(coins, sum, n-1) , 1 + mc(coins, sum - coins[n-1], n));
		}
	}
	return dp[n][sum];

}

int main()
{
	int coins[] = {1, 2, 3};
	int sum = 5, n = 3;
	dp.resize(n+1);
	for(int i = 0; i < n+1; i++)
	{
		dp[i].resize(sum+1, -1);
	}
	cout << mc(coins, sum, n);
}
