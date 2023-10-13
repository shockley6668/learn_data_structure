#include <iostream>
#include <string>
using namespace std;

int longestRepeatingSubstring(string s) {
    int n = s.size();
    for (int len = n / 2; len > 0; len--) {
        for (int i = 0; i <= n - len; i++) {
            for (int j = i + len; j <= n - len; j++) {
                if (s.substr(i, len) == s.substr(j, len)) {
                    return len;
                }
            }
        }
    }
    return -1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << longestRepeatingSubstring(s) << endl;
    }
    return 0;
}
