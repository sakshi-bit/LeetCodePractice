#include<iostream>
#include<stdlib.h>
#include<vector>
#include <queue>
#include "kLargestElementsInArray.h"

using namespace std;



void kLargestElementsInArray(std::vector<int> arr, int k, int size)
{
	priority_queue<int, vector<int>, greater<int >> minheap;
	for (int i = 0; i < size; i++) {
		minheap.push(arr[i]);
		if (minheap.size() > k) {
			minheap.pop();
		}
	}

	while (minheap.size() > 0) {
		cout << minheap.top() << " ";
		minheap.pop();
	}


}
