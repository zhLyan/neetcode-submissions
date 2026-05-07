class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";

        for (string s : strs) {
            encoded += to_string(s.length()) + '#' + s;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;

        while (i < s.length()) {
            int j = i;

            while (s[j] != '#') { // find #
                ++j;
            }

            int len = stoi(s.substr(i, j - i)); // get the len
            ++j;

            string word = s.substr(j, len);
            res.push_back(word);

            i = j + len;
        }

        return res;
    }
};
