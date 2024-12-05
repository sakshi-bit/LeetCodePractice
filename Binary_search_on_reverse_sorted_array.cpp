#include "Binary_search_on_reverse_sorted_array.h"
int reverse_binary_search(vector<int> arr, int n, int elem)
{
	int start = 0, end = n - 1;
	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (arr[mid] == elem) {
			return mid;
		}
		else if (elem < arr[mid]) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	return -1;
}
