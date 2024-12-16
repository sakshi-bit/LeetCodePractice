#include "next_letter.h"
char findNextLetter(vector<char> arr, char key, int start, int end)
{
	char res = '#';
	while (start <= end) {
		int mid = start + (end - start) / 2;
		 if (arr[mid] > key) {
			 res = arr[mid];
			 end = mid - 1;
		}
		else {
			
			start = mid + 1;
		}
	}
	return res == '#' ? arr[0] : res;
}
