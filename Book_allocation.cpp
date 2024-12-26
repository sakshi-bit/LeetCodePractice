#include "PageAllocation.h"
#include <algorithm>
#include <numeric>

bool isValid(vector<int>arr,int n,int k,int mx) {
	int student = 1;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		if (sum > mx) {
			student++;
			sum = arr[i];
		}
		if (student > k) {
			return false;
		}
	}
	return true;
}

int allocate(vector<int> arr, int k,int n)
{
	
	int start = *max_element(arr.begin(), arr.end());
	int end = accumulate(arr.begin(), arr.end(),0);

	int res = -1;

	if (n < k) {
		return -1;
	}
	while (start < end) {
		int mid = start + (end - start) / 2;
		if (isValid(arr, n, k,mid) == true) {
			res = mid;
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	return res;
}
