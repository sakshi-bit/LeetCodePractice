#include "frequencySort.h"
#include<iostream>
#include<vector>
#include<stdlib.h>
#include<unordered_map>
#include <queue>

using namespace std;

std::vector<int> frequenctSort(const std::vector<int>& arr, int n)
{
	vector<int>ans;
	unordered_map<int, int>mpp;

	for (int i = 0; i < n; i++) {
		mpp[arr[i]]++;
	}

	priority_queue<pair<int,int>>maxh;

	for (auto it : mpp) {
		maxh.push({ it.second,it.first });
	}

	while (maxh.size() > 0) {
		int freq = maxh.top().first;
		int elem = maxh.top().second;

		for (int i = 1; i <= freq; i++) {
			ans.push_back(elem);
		}
		maxh.pop();

	}
	return ans;
}
