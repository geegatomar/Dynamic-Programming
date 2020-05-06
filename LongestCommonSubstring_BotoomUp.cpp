#include<bits/stdc++.h>
using namespace std;


int main()
{
	string a = "abcdeff", b = "aboceffr";
	int n = a.size(), m = b.size();
	vector<vector<int>> dp(n+1, vector<int> (m+1));
	for(int i = 0; i <= n; i++)
	{
		for(int j = 0; j <= m; j++)
		{
			if(i == 0 || j == 0)
			{
				dp[i][j] = 0;
				continue;
			}
			if(a[i-1] == b[j-1])
				dp[i][j] = 1 + dp[i-1][j-1];
			else
				dp[i][j] = 0;
		}
	}
	int max = 0;
	for(int i = 0; i <= n; i++)
	{
		for(int j = 0; j <= m; j++)
		{
			if(dp[i][j] > max)
				max= dp[i][j];
		}

	}
	cout << max <<endl;
}
