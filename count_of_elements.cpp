#include "Count_of_element.h"
#include "first_occurence_of_an_element.h"
#include "last_occurence_of_element.h"
#include "first_occurence_of_an_element.h"
int firstOccurenceOfElement(vector<int> arr, int n, int elem)
{
	int start = 0;
	int end = n - 1;
	int res = -1;
	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (elem == arr[mid]) {
			res = mid;
			end = mid - 1;
		}
		else if (elem < arr[mid]) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	return res;
}
#include "last_occurence_of_element.h"
int lastOccurenceOfElement(vector<int> arr, int n, int elem)
{
	int start = 0;
	int end = n - 1;
	int res = -1;
	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (elem == arr[mid]) {
			res = mid;
			start = mid + 1;
		}
		else if (elem < arr[mid]) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	return res;
}

int countOccurence(vector<int> arr, int n, int elem)
{
	int indexFirst = firstOccurenceOfElement(arr, n, elem);
	int indexLast = lastOccurenceOfElement(arr, n, elem);

	return indexLast - indexFirst + 1;
}
