#include "Minimum_difference_element.h"
int getMinimumDifference(vector<int> arr, int elem, int start, int end)
{
	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (arr[mid] == elem) {
			return arr[mid];
		}
		else if (elem < arr[mid]) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	int k1 = abs(arr[start] - elem);
	int k2 = abs(arr[end] - elem);

	if (k1 < k2) {
		return arr[start];
	}
	return arr[end];

}
