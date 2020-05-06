#include<bits/stdc++.h>
using namespace std;
int dp[100][100];

int solve(int arr[], int i, int j)
{
	if(i >= j) return 0;
	if(dp[i][j] != -1)
		return dp[i][j];
	int ans = INT_MAX;
	for(int k = i; k <= j-1; k++)
	{
		int tempans = solve(arr, i, k) + solve(arr, k+1, j) + arr[i-1]*arr[k]*arr[j];
		if(tempans < ans)
			ans = tempans;
	}
	return dp[i][j] = ans;
}

int main()
{
	int arr[] = {10, 20, 30, 40, 30};
	int n = sizeof(arr) / sizeof(arr[0]);
	memset(dp, -1, sizeof(dp));                   // *imp* using memset to initialize a static 2D array
	cout << solve(arr, 1, n-1) << endl;
}
