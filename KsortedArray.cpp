#include<iostream>
#include<stdlib.h>
#include<vector>
#include<queue>
#include "SortNearlySortedArray.h"
using namespace std;



std::vector<int> nearlySortedArray(const std::vector<int>& arr, int n, int k)
{
	priority_queue<int, vector<int>, greater<int>>minh;

	vector<int>ans;
	for (int i = 0; i < arr.size(); i++) {
		minh.push(arr[i]);
		if (minh.size() > k) {
			ans.push_back(minh.top());
			minh.pop();
		}
	}

	while (minh.size() > 0) {
		ans.push_back(minh.top());
		minh.pop();
	}

	return ans;
	
}
