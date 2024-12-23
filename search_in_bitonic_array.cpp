#include "Search_in_bitonic.h"
#include "peak_element.h"
#include "Binary_search.h"
#include "Binary_search_on_reverse_sorted_array.h"

#include "Binary_search_on_reverse_sorted_array.h"

#include "Binary_search.h"
#include "peak_element.h"

int findPeakElement(vector<int> arr, int n)
{
	int low = 0, high = n - 1;
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (mid > 0 && mid < n - 1) {
			if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
				return mid;
			}
			else if (arr[mid - 1] > arr[mid]) {
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}
		}
		else if (mid == 0) {
			if (arr[0] > arr[1]) {
				return 0;
			}
			else {
				return 1;
			}
		}
		else if (mid == n - 1) {
			if (arr[n - 1] > arr[n - 2]) {
				return n - 1;
			}
			else {
				return n - 2;
			}
		}
	}
	return -1;
}


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

int reverse_binary_search(vector<int> arr, int n,int start,int end, int elem)
{
	
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



int bitonic_search_key(vector<int> arr, int elem, int start, int end)
{
	int index = findPeakElement(arr, end + 1);
	int idx1 = binary_search(arr, elem, start, index-1);
	int idx2 = reverse_binary_search(arr,end+1,index+1,end,elem);

	if (idx1 == -1) {
		return idx2;
	}
	else {
		return idx1;
	}
	return -1;
}
