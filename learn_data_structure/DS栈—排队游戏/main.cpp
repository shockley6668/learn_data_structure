#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;

    stack<int> boys;
    vector<pair<int, int>> pairs;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == s[0]) {
            boys.push(i);
        } else {
            pairs.push_back(make_pair(boys.top(), i));
            boys.pop();
        }
    }

    for (auto& p : pairs) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}
