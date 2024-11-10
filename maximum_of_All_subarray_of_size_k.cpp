#include<algorithm>
#include <stdlib.h>
#include<vector>
#include<deque>
using namespace std;


vector<int> getMaximumSubarray(vector<int> arr, int k, int n)
{
	vector<int>ans;
	deque<int>deq;
	if (k > n) {
		ans.push_back(*max_element(arr.begin(), arr.end()));
		return ans;
	}
	int i = 0, j = 0;
	while (j < n) {
		//calculation
		while (deq.size() > 0 && deq.back() < arr[j]) {
			deq.pop_back();
		}
		deq.push_back(arr[j]);

		if (j - i + 1 < k) {
			j++;
		}
		else if (j - i + 1 == k) {
			
				ans.push_back(deq.front());
				if (deq.front() == arr[i]) {
					deq.pop_front();
				}
				i++;
				j++;
		}
		

	}
	return ans;
}
