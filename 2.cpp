#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;

int ccm(int coins[], int sum, int n)
{
	if(sum == 0)
		return 0;

	if(n == 0)
		return INT_MAX - 1;


	if(dp[n][sum] == -1)
	{
		if(sum < coins[n-1])
		{
			dp[n][sum] = ccm(coins, sum, n-1);
		}
		else
		{
			dp[n][sum] = min(ccm(coins, sum, n-1) , 1 + ccm(coins, sum - coins[n-1], n));
		}
	}
	return dp[n][sum];
}


int main()
{
	int coins[] = {1, 2, 3, 6, 5, 8, 10};
	int sum = 11, n = sizeof(coins) / sizeof(coins[0]);
	dp.resize(n + 1);
	for(int i = 0 ; i < n+1; i++)
	{
		dp[i].resize(sum + 1, -1);
	}
	cout << ccm(coins, sum, n);
	
		
}

