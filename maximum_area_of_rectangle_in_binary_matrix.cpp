#include <iostream>
#include <vector>
#include <stack>
using namespace std;


vector<int> NSR(vector<int> arr, int n)
{
	vector<int>v;
	stack<pair<int,int>>s;
	int pseudoindex = n;
	for (int i = n-1; i >= 0; i--) {
		while (s.size() > 0 && s.top().first >= arr[i]) {
			s.pop();
		}
		if (s.size() == 0) {
			v.push_back(pseudoindex);
		}
		else {
			v.push_back(s.top().second);
		}
		s.push({ arr[i] ,i});
	}
	reverse(v.begin(), v.end());
	return v;
}


#include<vector>
#include <stack>

using namespace std;
vector<int> NSL(vector<int> arr, int n)
{
	vector<int>v;
	stack<pair<int,int>>s;
	int pseudoindex = -1;
	for (int i = 0; i < n; i++) {
		while (s.size() > 0 && s.top().first >= arr[i]) {
			s.pop();
		}
		if (s.size() == 0) {
			v.push_back(pseudoindex);
		}
		else {
			v.push_back(s.top().second);
		}
		s.push({ arr[i],i });
	}
	return v;
}


#include<iostream>
#include <vector>
#include "NextSmallerToLeft.h"
#include "NextSmallerToRight.h"
using namespace std;

int mah(vector<int> arr, int n)
{
	vector<int>left = NSL(arr, n);
	vector<int>right = NSR(arr, n);

	vector<int>width(n);
	for (int i = 0; i < n; i++) {
		width[i] = right[i] - left[i] - 1;
	}
	vector<int>area(n);
	for (int i = 0; i < n; i++) {
		area[i] = width[i] * arr[i];
	}

	int maxi = INT_MIN;
	for (int i = 0; i < n; i++) {
		maxi = max(maxi, area[i]);
	}
	return maxi;
}




#include "maximum_area_of_rectangle_in_binary_matrix.h"
#include "MaximumAreaHistogram.h"

int maximumArea(int n, int m, vector<vector<int>>& matrix)
{
	vector<int>v;
	for (int j = 0; j < m; j++) {
		v.push_back(matrix[0][j]);
	}
	int mx = mah(v,v.size());

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] == 0) {
				v[j] = 0;
			}
			else {
				v[j] = v[j] + matrix[i][j];
			}
		}
		mx = max(mx, mah(v, v.size()));
	}
	return mx;
}

int main(){
 int rows,cols;
    cout << "Enter the number of rows" << endl;
    cin >> rows;
    cout << "Enter the number of cols" << endl;
    cin >> cols;
    vector<vector<int>>matrix(rows, vector<int>(cols));
    cout << "Enter the matrix 0's and 1's" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    int maxArea = maximumArea(rows, cols, matrix);
    cout << "Maximum area of rectangle in binary matrix " << maxArea << endl;


    return 0;

}
