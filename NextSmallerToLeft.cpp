#include<vector>
#include <stack>

using namespace std;
vector<int> NSL(vector<int> arr, int n)
{
	vector<int>v;
	stack<int>s;
	for (int i = 0; i < n; i++) {
		while (s.size() > 0 && s.top() >= arr[i]) {
			s.pop();
		}
		if (s.size() == 0) {
			v.push_back(-1);
		}
		else {
			v.push_back(s.top());
		}
		s.push(arr[i]);
	}
	return v;
}
