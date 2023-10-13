#include<iostream>
#include<string>
using namespace std;

class myString {
private:
    string mainstr; // 串
    int size;       // 串长度

    void GetNext(string p, int next[]) {
        int j = 0;
        int k = -1;
        int L = p.length();
        next[0] = -1;

        while (j < L - 1) {
            if (k == -1 || p[j] == p[k]) {
                j++;
                k++;
                next[j] = k;
            } else {
                k = next[k];
            }
        }
    }

    int KMPFind(string p, int pos, int next[]) {
        int i = pos;
        int j = 0;
        int m = mainstr.length();
        int n = p.length();
        while (i < m && j < n) {
            if (j == -1 || mainstr[i] == p[j]) {
                i++;
                j++;
            } else {
                j = next[j];
            }
        }

        if (j == n) return i - j + 1; // 返回匹配的起始位置，从1开始计算
        else return 0; // 匹配失败
    }

public:
    myString() {
        size = 0;
        mainstr = "";
    }
    
    ~myString() {
        size = 0;
        mainstr = "";
    }

    void SetVal(string sp) {
        mainstr.assign(sp);
        size = mainstr.length();
    }

    int KMPFindSubstr(string p, int pos) {
        int L = p.length();
        int *next = new int[L];
        GetNext(p, next);
        for (int i = 0; i < L; i++)
            cout << next[i] << ' ';
        cout << endl;

        int v = KMPFind(p, pos, next);
        delete[] next;
        return v;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string mainstr, pattern;
        cin >> mainstr >> pattern;

        myString s;
        s.SetVal(mainstr);

        cout << s.KMPFindSubstr(pattern, 0) << endl;
    }

    return 0;
}
