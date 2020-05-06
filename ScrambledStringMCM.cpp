#include<bits/stdc++.h>
using namespace std;

int solve(string a, string b)                        //returns true or false
{
	if(a == b)
		return 1;
	if(a.size() <= 0)
		return 0;
	int n = a.length();
	int flag = 0;
	for(int i = 1; i <= n- 1; i++)
	{
		int cond1 = solve(a.substr(0, i), b.substr(n - i, i)) && solve(a.substr(i, n-i), b.substr(0, n-i));
		int cond2 = solve(a.substr(0, i), b.substr(0, i)) && solve(a.substr(i, n-i), b.substr(i, n-i));
		if(cond1 || cond2)
		{
			flag = 1;
			return flag;
		}
	}
	return flag;

}

int main()
{
//	string a = "great", b = "rteag";
	string a = "phqtrnilf", b = "ilthnqrpf";
	cout << solve(a, b);
}
