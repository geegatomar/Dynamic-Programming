#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int ks(vector<int> wt, vector<int> val, int w, int n)
{
	if(n == 0 || w == 0)
		return 0;
	if(dp[n][w] == -1)
	{
		if(wt[n] > w)
			dp[n][w] = ks(wt, val, w, n-1);
		else
		{
			dp[n][w] = max( val[n] + ks(wt, val, w-wt[n], n-1) , ks(wt, val, w, n-1));
		}
	}
	return dp[n][w];
}

int main()
{
	vector<int> wt = {2, 4, 4, 6}, val = {2, 4, 5, 7};
	wt.insert(wt.begin(), 0);
	val.insert(val.begin(), 0);
	int w = 7, n = wt.size();
	dp.resize(n);
	for(int i = 0; i < n; i++)
	{
		dp[i].resize(w+1, -1);
	}
	cout << ks(wt, val, w, n-1 ) << endl;

}
