#include<bits/stdc++.h>
using namespace std;

int solve(int arr[], int i, int j)
{
	if(i >= j)
		return 0;
	int ans = INT_MAX;
	for(int k = i; k <= j-1; k++)
	{
		int tempans = solve(arr, i, k) + solve(arr, k+1, j) + arr[i-1] * arr[k] * arr[j];
		if(tempans < ans)
			ans = tempans;
	}
	return ans;
}

int main()
{
	int arr[] = {40, 20 , 30 , 10 ,30};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << solve(arr, 1, n-1) << endl;
}
