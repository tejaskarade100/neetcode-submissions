class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        int prev2 = 1;
        int prev1 = (s[0] != '0') ? 1 : 0;
        for (int i = 2; i <= n; i++) {
            int curr = 0;
            int oneDigit = stoi(s.substr(i - 1, 1));
            int twoDigits = stoi(s.substr(i - 2, 2));
            if (oneDigit >= 1)
                curr+=prev1;
            if (twoDigits >= 10 && twoDigits <= 26)
                curr+=prev2;

            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};