#include "floor_of_element.h"
int find_floor(vector<int> arr, int elem, int start, int end)
{
	int res = -1;
	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (arr[mid] < elem) {
			res = arr[mid];
			start = mid + 1;
		}
		else if (arr[mid] > elem) {
			end = mid - 1;
		}
		if (arr[mid] == elem) {
			return arr[mid];
		}
	}
	return res;
}
