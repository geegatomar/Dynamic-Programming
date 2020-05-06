#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;

int lcs(string a, string b, int n, int m)
{
	if(n == 0 || m == 0)
		return 0;
	if(dp[n][m] == -1)
	{
		if(a[n-1] == b[m-1])
			dp[n][m] = 1 + lcs(a, b, n-1, m-1);
		else
		{
			dp[n][m] = max( lcs(a, b, n-1, m) , lcs(a, b, n, m-1));
		}
	}
	return dp[n][m];
}

int main()
{
	string a = "aggtab", b = "gxtxayb";
	int n = a.size(), m = b.size();
	dp.resize(n+1);
	for(int i = 0; i <n+1; i++)
	{
		dp[i].resize(m+1, -1);
	}
	dp[n][m] = lcs(a, b, n, m);
	int i = n, j = m;
	string s;
	while(i >= 0 && j >= 0)
	{
		if(a[i-1] == b[j-1])
		{
			s += a[i-1];
			i--;
			j--;
		}
		else
		{
			if(dp[i-1][j] > dp[i][j-1])
				i--;
			else
				j--;
		}

	}
	reverse(s.begin(), s.end());
	cout << s <<endl;
	i = 0; j = 0;
	int k = 0;
	string res;

	while(k < s.size())
	{
		while(a[i] != s[k])
		{
			res += a[i];
			i++;
		}
		while(b[j] != s[k])
		{
			res += b[j];
			j++;
		}
		res += s[k];
		i++;
		j++;
		k++;
	}
	while(i < n)
	{
		res += a[i];
	}
	while(j < m)
	{
		res += b[j];
	}
	cout << res << endl;
}

