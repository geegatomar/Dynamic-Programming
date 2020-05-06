#include<bits/stdc++.h>
using namespace std;

int solve(int nums[], int l, int r, int year)            //year variable is not needed as its equal to r-l+1
{
	if(l == r)
		return year * nums[l];

	return max( solve(nums, l + 1, r, year+1) + nums[l] * year, solve(nums, l, r - 1, year+1) + nums[r] * year);
}

int main()
{
	int nums[] = {2, 3, 5, 1, 4};
	int n = sizeof(nums) / sizeof(nums[0]);
	cout << solve(nums, 0, n - 1, 1) << endl;
}
