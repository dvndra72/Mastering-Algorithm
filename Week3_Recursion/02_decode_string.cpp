#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return helper(s, i);
    }

private:
    string helper(const string& s, int& i) {
        string result = "";
        int n = s.length();

        while (i < n && s[i] != ']') {
            if (isdigit(s[i])) {
                int count = 0;
                while (i < n && isdigit(s[i])) {
                    count = count * 10 + (s[i] - '0');
                    i++;
                }
                i++; 
                string decodedPart = helper(s, i);
                i++; 
                while (count--) result += decodedPart;
            } else {
                result += s[i++];
            }
        }

        return result;
    }
};
class SolutionIterative {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> strStack;
        string curr = "";
        int k = 0;

        for (char c : s) {
            if (isdigit(c)) {
                k = k * 10 + (c - '0');
            } else if (c == '[') {
                countStack.push(k);
                strStack.push(curr);
                curr = "";
                k = 0;
            } else if (c == ']') {
                string temp = curr;
                curr = strStack.top(); strStack.pop();
                int count = countStack.top(); countStack.pop();
                while (count--) curr += temp;
            } else {
                curr += c;
            }
        }

        return curr;
    }
};
