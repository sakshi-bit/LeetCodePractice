#include<iostream>
#include<vector>
using namespace std;
int getMaximumWindowSize(vector<int> arr, int n, int k)
{
	int i = 0, j = 0;
	int sum = 0;
	int mx = INT_MIN;

	while (j < n) {
		sum += arr[j];

		while (i <= j && sum > k) {
			sum -= arr[i];
			i++;
		}

		if (sum == k) {
			mx = max(mx, j-i+1);
		}
		j++;
	}
	return mx;
}
