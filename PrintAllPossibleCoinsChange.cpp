#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
vector<vector<int>> v;

void print(vector<int> v)
{
	for(auto i: v)
	{
		cout << i << " ";

	}
	cout << endl;
}

int ccm(int coins[], int sum, int n, vector<int> selectedCoins)
{
	
	if(sum == 0)
	{
		
		v.push_back(selectedCoins);
	//	print(selectedCoins);
		return 1;
	}
	if(n == 0)
		return 0;
	//if(dp[n][sum] == -1)
	{
		if(coins[n-1] > sum)
		{
			dp[n][sum] = ccm(coins, sum, n - 1, selectedCoins);
		}
		else
		{
			dp[n][sum] = ccm(coins, sum, n - 1, selectedCoins);
			selectedCoins.push_back(coins[n-1]);
			dp[n][sum] +=  ccm(coins, sum - coins[n-1], n, selectedCoins);
			selectedCoins.pop_back();
		}
	}
	return dp[n][sum];
}

int main()
{
	int coins[] = {1, 2, 3};
	vector<int> vc;
	int sum = 3, n = sizeof(coins) / sizeof(coins[0]);
	dp.resize(n + 1);
	for(int i = 0; i <= n; i++)
	{
		dp[i].resize(sum + 1, -1);
	}
	cout << endl <<endl <<ccm(coins, sum, n, vc) << endl <<endl <<endl;
	for(int i = 0; i < v.size(); i++)
	{
		for(int j = 0; j < v[i].size(); j++)
		{
			cout << v[i][j] << " ";
		}
		cout << endl;
	}


}
