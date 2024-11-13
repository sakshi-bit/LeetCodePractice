#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int maxToys(string str)
{
	unordered_map<char, int>mpp;
	int i = 0, j = 0;
	int mx = INT_MIN;
	int n = str.length();

	while (j < n) {
		mpp[str[j]]++;

		if (mpp.size() < 2) {
			j++;
		}
		else if (mpp.size() == 2) {
			mx = max(mx, j - i + 1);
			j++;
		}
		else if (mpp.size() > 2) {
			while (mpp.size() > 2) {
				mpp[str[i]]--;
				if (mpp[str[i]] == 0) {
					mpp.erase(str[i]);
				}
				i++;
			}
			j++;
		}
	}

	return mx;
}
