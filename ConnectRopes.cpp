#include "ConnectRopes.h"
#include <queue>

int minCost(vector<int> arr)
{
	priority_queue<int, vector<int>, greater<int>>minh;
	int minimumCost = 0;
	for (int i = 0; i < arr.size(); i++) {
		minh.push(arr[i]);
	}
	while (minh.size() >= 2) {
		int first = minh.top();
		minh.pop();
		int second = minh.top();
		minh.pop();
		// Cost to connect these two ropes
	
		minimumCost += first + second;

		// Push the combined rope back into the heap
		minh.push(first + second);
	}
	return minimumCost;
}
