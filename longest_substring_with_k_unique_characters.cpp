#include<iostream>
#include<stdlib.h>
using namespace std;
#include "longest_substring_with_k_unique_characters.h"
#include <unordered_map>

int getLongestSubstring(string str, int n, int k)
{
	unordered_map<char, int>mpp;

	int i = 0, j = 0;
	int mx = INT_MIN;

	while (j < n) {
		mpp[str[j]]++;

		if (mpp.size() < k) {
			j++;
		}
		
		else if (mpp.size() == k) {
			mx = max(mx,j - i + 1);
			j++;
		}
		else if (mpp.size() > k) {
			while (i <= j && mpp.size() > k) {
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
