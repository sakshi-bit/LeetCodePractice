class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        if (n > m) {
            return false;
        }
        vector<int> s1_string(26, 0);
        vector<int> s2_string(26, 0);

        for (char& ch : s1) {
            s1_string[ch - 'a']++;
        }
        int i = 0, j = 0;
        while (j < m) {
            s2_string[s2[j] - 'a']++;
            if (j - i + 1 > n) {
                s2_string[s2[i] - 'a']--;
                i++;
            }
            if (s1_string == s2_string) {
                return true;
            }
            j++;
        }
        return false;
    }
};
