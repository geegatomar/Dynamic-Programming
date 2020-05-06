#include<bits/stdc++.h>
using namespace std;

int ss(int n, int sum, int arr[], vector<vector<int>> dp)
{
	if(sum == 0)
		return 1;
	if(n == 0)
		return 0;
	if(dp[n][sum] == -1)
	{
		if(arr[n] > sum)
		{
			dp[n][sum] = ss(n - 1, sum, arr, dp);
		}
		else
		{
			dp[n][sum] = ss(n-1, sum, arr, dp) || ss(n-1, sum - arr[n], arr, dp);
		}
	}
	return dp[n][sum];
}

int main()
{
	int arr[] = {2,3,7,8,10};
	int sum = 14;
	vector<vector<int>> dp(6, vector<int> (sum+1, -1));

	cout << ss(5, sum, arr, dp); 

}
