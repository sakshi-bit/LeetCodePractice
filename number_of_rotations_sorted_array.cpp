#include "Number_of_times_sorted_array_rotated.h"
int numberOfRotation(vector<int> arr, int n)
{
	// code here
	int s = 0;
	int e = n - 1;
	while (s <= e) {
		int mid = s + (e - s) / 2;
		int prev = (mid - 1 + n) % n;
		int next = (mid + 1) % n;
		if (arr[mid] <= arr[prev] && arr[mid] <= arr[next]) {
			return mid;
		}
		else if (arr[s] <= arr[e]) {
			return s;
		}
		else if (arr[s] <= arr[mid]) {
			s = mid + 1;
		}
		else if (arr[mid] <= arr[e]) {
			e = mid - 1;
		}
	}
	return -1;
}
