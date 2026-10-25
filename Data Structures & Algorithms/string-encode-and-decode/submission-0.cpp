class Solution {
public:
    string encode(vector<string>& strs) {
        string encoded = "";

        for (string &str : strs) {
            encoded += to_string(str.size()) + "#" + str;
        }
        return encoded;
    }
    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        int n = s.size();

        while (i < n) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            int len = stoi(s.substr(i, j - i));
            string str = s.substr(j + 1, len);
            result.push_back(str);
            i = j + 1 + len;
        }
        return result;
    }
};
