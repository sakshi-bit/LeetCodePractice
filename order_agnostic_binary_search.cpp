#include "Order_Agnostic_Binary_Search.h"
#include "Binary_search.h"
#include "Binary_search_on_reverse_sorted_array.h"


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


int order_unknown_binary_search(vector<int> arr, int n, int elem)
{
	if (n == 1) {
		if (arr[0] == elem) {
			return 0;
		}
	}

		else if (arr[0] < arr[1]) {
			return binary_search(arr, n, elem);
		}
		else {
			return reverse_binary_search(arr, n, elem);
		}
	return -1;
}
