#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;

int cs(int arr[], int sum, int n)
{
	if(sum == 0)
		return 1;
	if(n == 0)
		return 0;
	if(dp[n][sum] == -1)
	{
		if(sum < arr[n])
			dp[n][sum] = cs(arr, sum, n-1);
		else
		{
			dp[n][sum] = cs(arr, sum - arr[n], n-1) + cs(arr, sum, n - 1);
		}
	}
	return dp[n][sum];

}

int main()
{
	int arr[] = {0, 2, 3, 5, 6, 7, 8};
	int sum = 11;
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << n << endl;
	dp.resize(n);
	for(int i = 0; i < n; i++)
	{
		dp[i].resize(sum+1, -1);
	}
	cout << cs(arr, sum,n-1) << endl; 
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < sum+1; j++)
		{
			cout << dp[i][j] << "   ";
		}
		cout << endl;
	}

}
