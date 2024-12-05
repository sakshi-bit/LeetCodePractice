#include "Binary_search.h"

int binary_search(vector<int> arr, int n,int elem)
{
	int start = 0;
	int end = n - 1;
	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (elem == arr[mid]) {
			return mid;
		}
		else if (elem < arr[mid]) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	return -1;
}
