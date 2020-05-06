#include<bits/stdc++.h>
using namespace std;
vector<int> dp;

int nw(int nums[], int sum, int n)
{
	if(sum < 0)
		return 0;
	if(sum == 0)
		return 1;
	if(dp[sum] != -1)
		return dp[sum];
	int var = 0;
	for(int i = 0; i < n; i++)
	{
		var += nw(nums, sum - nums[i], n);
	}
	return dp[sum] = var;
}

int main()
{
	int nums[] = {1, 3, 4};
	int sum = 5, n = sizeof(nums) / sizeof(nums[0]);
	dp.resize(sum + 1, -1);
	cout << nw(nums, sum, n);
}

