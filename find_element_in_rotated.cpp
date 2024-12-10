#include "Binary_search.h"

int binary_search(vector<int> arr,int elem,int start,int end)
{
	
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


#include "find_element_in_rotated_array.h"
#include "Binary_search.h"
#include "Number_of_times_sorted_array_rotated.h"

int findElementRotated(vector<int> arr, int n, int elem)
{
	int index = numberOfRotation(arr, n);
	int res1 = binary_search(arr, elem, 0, index - 1);
	int res2 = binary_search(arr, elem, index, n - 1);

	if (res1 == -1) {
		return res2;
	}
	return res1;
}
