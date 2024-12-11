#include "nearly_sorted.h"
int modified_binary_search(vector<int> arr, int elem, int start, int end)
{
	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (elem == arr[mid]) {
			return mid;
		}
		else if (mid-1 >= start && arr[mid - 1] == elem) {
			return mid - 1;
		}
		else if (mid + 1 <= end && arr[mid + 1] == elem) {
			return mid + 1;
		}

		if (elem <= arr[mid - 2]) {
			end = mid - 2;
		}
		else if (elem >= arr[mid + 2]) {
			start = mid + 2;
		}
	}
	return -1;
}
