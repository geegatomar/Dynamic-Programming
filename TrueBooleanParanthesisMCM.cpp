#include<bits/stdc++.h>
using namespace std;

int solve(string s, int i, int j, int istrue)
{
	if(i == j)
	{
		
		if(istrue)
		{
			return s[i] == 'T';
		}
		else
			return s[i] == 'F';
	}
	int temp = 0;
	for(int k = i + 1; k <= j - 1; k += 2)
	{
		int lt = solve(s, i, k-1, 1);
		int rf = solve(s, k + 1, j, 0);
		int rt = solve(s, k + 1, j, 1);
		int lf = solve(s, i, k - 1, 0);
		
		cout << "================================"<<endl;
		cout << "i: " << i << " j: " << j << " k: " << k << endl;
		cout << istrue <<endl;
		cout << lf << lt << rf << rt <<endl;
		cout << "operator: " <<  s[k] <<endl;
		cout << "=================================" <<endl;

		if(s[k] == '&')
		{
			if(istrue)
			{
				temp += rt * lt;
			}
			else
				temp += rt*lf + rf*lt + lf*rf;
		}

		else if(s[k] == '|')
		{
			if(istrue)
				temp += rt*lf + lt*rf + rt*lt;
			else
				temp += rf*lf;
		}
		else
		{
			if(istrue)
				temp += rt*lf + lt*rf;
			else
				temp += lf*rf + lt*rt;
		}
	}
	return temp;

}

int main()
{
	string s = "T|T&F^T";
	int n = s.size();
	cout << solve(s, 0, n - 1, 1) << endl;
}
