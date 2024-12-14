#include "ceil_of_element.h"
int find_ceil(vector<int> arr, int elem, int start, int end)
{
	int res = -1;
	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (arr[mid] == elem) {
			return arr[mid];
		}
		else if (arr[mid] < elem) {
			start = mid + 1;
		}
		else {
			res = arr[mid];
			end = mid - 1;
		}
	}
	return res;
}
