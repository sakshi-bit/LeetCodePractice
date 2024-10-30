#include<iostream>
#include<stdlib.h>
#include<vector>
#include<queue>

using namespace std;

std::vector<int> kClosestNumbers(const std::vector<int>& arr, int n, int k,int x)
{
	priority_queue<pair<int, int>>maxh;
	vector<int>ans;

	for (int i = 0; i < n; i++) {
		maxh.push({abs(arr[i]-x),arr[i]});
		if (maxh.size() > k) {
			maxh.pop();
		}
	}

	while (maxh.size() > 0) {
		ans.push_back(maxh.top().second);
		maxh.pop();
	}

	return ans;
}
