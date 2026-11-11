class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if (m > n) return "";
        vector<int> freq(128, 0);
        for (char c : t) {
            freq[c]++;
        }
        int left = 0;
        int right = 0;
        int count = m;
        int minLen = INT_MAX;
        int start = 0;
        while (right < n) {
            if (freq[s[right]] > 0) {
                count--;
            }
            freq[s[right]]--;
            while (count == 0) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }
                freq[s[left]]++;
                if (freq[s[left]] > 0) {
                    count++;
                }
                left++;
            }
            right++;
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
