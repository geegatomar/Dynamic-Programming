#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;

int ksu(int wt[], int val[], int w, int n)
{
	
	if(w == 0 || n == 0)
		return 0;
	if(dp[n][w] == -1)
	{
		if(wt[n-1] > w)
			dp[n][w] = ksu(wt, val, w, n-1);
		else
		{
			dp[n][w] = max( ksu(wt, val, w, n-1) , val[n-1] + ksu(wt, val, w - wt[n-1], n));
		}
	}
	return dp[n][w];

}

int main()
{
	int wt[] = {1, 3, 4, 5};
	int val[] = {2, 4, 5, 7};
	int w = 7, n = 4;
	dp.resize(n+1);
	for(int i = 0; i < n+1; i++)
	{
		dp[i].resize(w+1, -1);
	}
	cout << ksu(wt, val, w, n);
	
}
