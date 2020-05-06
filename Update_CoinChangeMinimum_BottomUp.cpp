#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;

int mc(int coins[], int sum, int n)
{
	if(sum == 0)
		return 0;
	if(n == 0)
		return INT_MAX-1;
	
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
	int coins[] = {2, 4, 5, 6, 9};
	int sum = 3, n = 5;
	dp.resize(n+1);
	for(int i = 0; i < n+1; i++)
	{
		dp[i].resize(sum+1, -1);
	}
	cout << mc(coins, sum, n);
}
