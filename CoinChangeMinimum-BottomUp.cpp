#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;

int main()
{
	int coins[] = {1, 2, 3};
	int sum = 5, n = sizeof(coins)/sizeof(coins[0]);
	dp.resize(n+1);
	for(int i = 0; i < n+1; i++)
	{
		dp[i].resize(sum+1);
	}

	for(int i = 0; i < n+1; i++)
	{
		for(int j = 0; j < sum+1; j++)
		{
			if(i == 0)
				dp[i][j] = INT_MAX - 1;
			if(j == 0)
				dp[i][j] = 0;
			if(i == 1)
			{
				if(j % coins[i-1] == 0)
					dp[i][j] = j / coins[i-1];
				else
					dp[i][j] = INT_MAX - 1;
			}
		}
	}

	for(int i = 2; i < n+1; i++)
	{
		for(int j = 1; j < sum+1; j++)
		{
			if(j < coins[i-1])
			{
				dp[i][j] = dp[i-1][j];
			}

			else
			{
				dp[i][j] = min( dp[i-1][j], dp[i][j-coins[i-1]] + 1);
			}
		}
	}
	cout << dp[n][sum] <<endl;
}
