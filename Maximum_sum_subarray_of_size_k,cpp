#include <iostream>
#include "Maximum_sum_of_subarray_size_k.h"
using namespace std;

int getMaximumSubarray(vector<int> arr, int k)
{
	int i = 0, j = 0;
	int sum = 0;
	int mx = INT_MIN;

	while (j < arr.size()) {
		sum = sum+arr[j];

	
		 if (j - i + 1 == k) {
			mx = max(mx, sum);
			sum-= arr[i];
			i++;
		}
		 j++;
	}
	return mx;
}
