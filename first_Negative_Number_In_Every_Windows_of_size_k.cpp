#include "first_Negative_Number_In_Every_Windows_of_size_k.h"
#include <deque>

using namespace std;

vector<int> getFirstNegativeNumber(vector<int> A, int K)
{
	int start=0, end = 0;
	int N = A.size();

	vector<int>res;

	deque<int>ans;
	
    while (end < N) {
        if (A[end] < 0) {
            ans.push_back(A[end]);
        }
        if (end - start + 1 < K) {
            end++;
        }
        else if (end - start + 1 == K) {
            if (ans.size() == 0) {
                res.push_back(0);
            }
            else {
                res.push_back(ans.front());
                if (A[start] < 0)
                    ans.pop_front();
            }
            start++;
            end++;
        }
    }
    return res;
	
}
