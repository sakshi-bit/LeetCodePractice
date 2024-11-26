#include "min_stack_using_no_extra_space.h"
#include<stack>
using namespace std;
stack<int>s;
int min_elem = -1;
void push_stack(int x)
{
	if (s.size() == 0) {
		s.push(x);
		min_elem = x;
	}
	else {
		if (x >= min_elem) {
			s.push(x);
		}
		else if (x < min_elem) {
			s.push(2 * x - min_elem);
			min_elem = x;
		}
	}

}

int pop_stack()
{
	int ans = -1;
	if (s.size() == 0) {
		return -1;
	}
	else {
		if (s.top() >= min_elem) {
			ans = s.top();
			s.pop();
		}
		else if (s.top() < min_elem) {
			min_elem = 2 * min_elem - s.top();
			ans = s.top();
			s.pop();
		}
	}
	return ans;
}

int top_stack()
{
	if (s.size() == 0) {
		return -1;
	}
	if (s.top() < min_elem) {
		return min_elem;
	}
	else if (s.top() >= min_elem) {
		return s.top();
	}
}

int getMin_stack()
{
	if (s.size() == 0) {
		return -1;
	}
	return min_elem;
}
