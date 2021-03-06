// O(1) space
class Solution {
public:
    void reverseWords(string &s) {
        // trim leading spaces
        while (s.front() == ' ')
            s.erase(s.begin());
        
        // trim trailing spaces
        while (s.back() == ' ')
            s.pop_back();

        // trim multiple spaces between two words
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == ' ' && s[i - 1] == ' ') {
                s.erase(s.begin() + i);
                i--;
            }
        }

        // reverse whole sentence
        int n = s.length();
        for (int i = 0; i < n / 2; i++) {
            char temp = s[i];
            s[i] = s[n - 1 - i];
            s[n - 1 - i] = temp;
        }

        // reverse back every word
        int start = 0, end = n - 1;
        while (start < n) {
            for (int i = start; i < n; i++) {
                if (s[i] == ' ') {
                    end = i - 1;
                    break;
                }
            }
            for (int i = 0; i < (end - start + 1) / 2; i++) {
                char temp = s[start + i];
                s[start + i] = s[end - i];
                s[end - i] = temp;
            }
            start = end + 2;
            end = n - 1;
        }
    }
};

// O(N) space
class Solution {
public:
    void reverseWords(string &s) {
        vector<string> words(1, "");
        for (char c : s) {
            if (c == ' ' && words.back().length() != 0)
                words.push_back("");
            else if (c != ' ')
                words.back().push_back(c);
        }
        s.clear();
        if (words.back().empty())
            words.pop_back();
        for (int i = words.size() - 1; i >= 0; i--)
            s += (words[i] + " ");
        s.pop_back();
    }
};