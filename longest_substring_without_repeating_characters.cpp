#include <string>
#include <unordered_map>
using namespace std;
int getMaximumSubstringUnique(string str)
{
	unordered_map<char, int>mpp;

	int i = 0, j = 0;
	int n = str.length();
	int mx = INT_MIN;
	while (j < n) {
		mpp[str[j]]++;
		if (mpp.size() == j-i+1) {
			mx = max(mx, j - i + 1);
			j++;
		}
		else if (mpp.size() < j - i + 1) {
			while (mpp.size() < j - i + 1) {
				mpp[str[i]]--;
				if (mpp[str[i]] == 0) {
					mpp.erase(str[i]);
				}
				i++;
			}
		}
		j++;
	}
	return mx;
}
