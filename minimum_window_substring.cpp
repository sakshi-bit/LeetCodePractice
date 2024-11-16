#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

string getMinimumWindowSubstring(string s, string t) {
	int n = s.length();
	if (t.length() > n) {
		return"";
	}
	int i = 0, j = 0;
	int start_i = 0;
	int minWindowSize = INT_MAX;

	unordered_map<char, int>mpp;
	for (char ch : t) {
		mpp[ch]++;
	}

	int count = t.length();

	while (j < n) {
		char ch = s[j];
		if (mpp[ch] > 0) {
			count--;
		}
		mpp[ch]--;

		while (count == 0) {
			int currentWindowSize = j - i + 1;
			if (minWindowSize > currentWindowSize) {
				minWindowSize = currentWindowSize;
				start_i = i;
			}
			mpp[s[i]]++;

			if (mpp[s[i]] > 0) {
				count++;
			}
			i++;
		}
		j++;
	}

	return minWindowSize == INT_MAX ? "" : s.substr(start_i, minWindowSize);
}
