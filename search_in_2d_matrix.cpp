#include "Search_in_2d_matrix.h"
vector<int> search_in_matrix(vector<vector<int>> arr, int key, int m, int n)
{
	int i = 0, j = m - 1;
	while (i >= 0 && i < n && j >= 0 && j < m) {
		if (arr[i][j] == key) {
			return { i,j };
		}
		else if (arr[i][j] > key) {
			j--;
		}
		else if (arr[i][j] < key) {
			i++;
		}
	}
	return { -1,-1 };
}
