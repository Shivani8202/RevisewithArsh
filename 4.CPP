#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  
int maxRotateFunction(vector<int>& nums) {
	int ans = 0, sum = 0, n = nums.size();

	
	for(int i=0; i<n; i++) {
		ans += i*nums[i];
		sum += nums[i];
	}

	int maxi = ans;

	for(int i=n-1; i > 0; i--) {
		ans += sum - nums[i]*n;
		maxi = max(maxi, ans);
	}
	return maxi;
}};