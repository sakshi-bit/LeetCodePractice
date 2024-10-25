#include<iostream>
#include<vector>
#include<stdlib.h>
#include <queue>

using namespace std;

int smallestKthElement(vector<int>arr, int k, int size) {

	priority_queue<int>maxh;

	for (int i = 0; i < size; i++) {
		maxh.push(arr[i]);
		if (maxh.size() > k) {
			maxh.pop();
		}
	}
	return maxh.top();

}
