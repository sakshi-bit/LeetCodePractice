#include "Min_stack_with_extra_space.h"
#include<stack>
using namespace std;
stack<int>s;
stack<int>ss;
void push(int a)
{
	s.push(a);
	if (ss.size() == 0 || ss.top() >= a) {
		ss.push(a);
		return;
	}
	return;

}

int pop()
{
	if (s.size() == 0) {
		return -1;
	}
	int ans = s.top();
	s.pop();
	if (ss.top() == ans) {
		ss.pop();
	}
	return ans;
}

int getMin()
{
	if (ss.size() == 0) {
		return -1;
	}
	return ss.top();
}
