

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
