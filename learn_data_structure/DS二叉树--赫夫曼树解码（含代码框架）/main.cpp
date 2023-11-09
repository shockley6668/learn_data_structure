#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int MaxW = 9999999; // 假设结点权值不超过9999999
#define error -1
#define ok  1

// 定义huffman树结点类
class HuffNode {
public:
    int weight;      // 权值
    int parent;      // 父结点下标
    int leftchild;   // 左孩子下标
    int rightchild;  // 右孩子下标
    char character;  // 字符（叶子结点特有）
};

// 定义赫夫曼树类
class HuffMan {
private:
    void MakeTree();  // 建树，私有函数，被公有函数调用
    void SelectMin(int pos, int* s1, int* s2);  // 从 1 到 pos 的位置找出权值最小的两个结点，把结点下标存在 s1 和 s2 中

public:
    int len;            // 结点数量
    int lnum;           // 叶子数量
    HuffNode* huffTree; // 赫夫曼树，用数组表示
    string* huffCode;   // 每个字符对应的赫夫曼编码
    void MakeTree(int n, int wt[], char chars[]); // 公有函数，被主函数main调用
    void Coding();  // 公有函数，被主函数main调用
    void Destroy();
    int Decode(const string codestr, char txtstr[]);
};

// 构建huffman树
void HuffMan::MakeTree(int n, int wt[], char chars[]) {
    // 参数是叶子结点数量、叶子权值，以及叶子字符
    // 公有函数，对外接口
    int i;
    lnum = n;
    len = 2 * n - 1;
    huffTree = new HuffNode[2 * n];
    huffCode = new string[lnum + 1]; // 位置从 1 开始计算

    // 赫夫曼树 huffTree 初始化
    for (i = 1; i <= n; i++) {
        huffTree[i].weight = wt[i - 1]; // 第0号不用，从1开始编号
        huffTree[i].character = chars[i - 1];
    }

    for (i = 1; i <= len; i++) {
        if (i > n) huffTree[i].weight = 0; // 前n个结点是叶子，已经设置
        huffTree[i].parent = 0;
        huffTree[i].leftchild = 0;
        huffTree[i].rightchild = 0;
    }

    MakeTree(); // 调用私有函数建树
}

void HuffMan::SelectMin(int pos, int* s1, int* s2) {
    // 找出最小的两个权值的下标
    // 函数采用地址传递的方法，找出两个下标保存在 s1 和 s2 中
    int w1, w2, i;
    w1 = w2 = MaxW; // 初始化 w1 和 w2 为最大值，在比较中会被实际的权值替换
    *s1 = *s2 = 0;

    for (i = 1; i <= pos; i++) {
        // 比较过程如下：
        // 如果第 i 个结点的权值小于 w1，且第 i 个结点是未选择的结点
        if (huffTree[i].parent == 0 && huffTree[i].weight < w1) {
            // 把第 w1 和 s1 保存到 w2 和 s2，即原来的第一最小值变成第二最小值
            w2 = w1;
            *s2 = *s1;
            // 把第 i 结点的权值和下标保存到 w1 和 s1，作为第一最小值
            w1 = huffTree[i].weight;
            *s1 = i;
        }
        else if (huffTree[i].parent == 0 && huffTree[i].weight < w2) {
            // 否则，如果第 i 结点的权值小于 w2，且第 i 结点是未选择的结点
            // 把第 i 结点的权值和下标保存到 w2 和 s2，作为第二最小值
            w2 = huffTree[i].weight;
            *s2 = i;
        }
    }
}

void HuffMan::MakeTree() {
// 私有函数，被公有函数调用
int i, s1, s2;
for (i= lnum + 1; i <= len; i++) {
     SelectMin(i - 1, &s1, &s2); // 找出两个最小权值的下标放入 s1 和 s2 中
     // 将找出的两棵权值最小的子树合并为一棵子树，过程包括
     // 结点 s1 和结点 s2 的父亲设为 i
     huffTree[s1].parent = i;
     huffTree[s2].parent = i;
     // 结点 i 的左右孩子分别设为 s1 和 s2
     huffTree[i].leftchild = s1;
     huffTree[i].rightchild = s2;
     // 结点 i 的权值等于 s1 和 s2 的权值和
     huffTree[i].weight = huffTree[s1].weight + huffTree[s2].weight;
 }
}

// 销毁赫夫曼树
void HuffMan::Destroy() {
 len = 0;
 lnum = 0;
 delete[] huffTree;
 delete[] huffCode;
}

// 赫夫曼编码
void HuffMan::Coding() {
 for (int i = 1; i <= lnum; ++i) {
     int start = lnum - 1; // 编码结束符位置
     string code;
     int c = i;
     int f = huffTree[i].parent;
     while (f != 0) {
         if (huffTree[f].leftchild == c)
             code = '0' + code; // 往左孩子移动，添加 0
         else
             code = '1' + code; // 往右孩子移动，添加 1
         c = f;
         f = huffTree[f].parent;
     }
     huffCode[i] = code; // 保存赫夫曼编码
 }
}

int HuffMan::Decode(const string codestr, char txtstr[]) {
    int i, k, c;
    char ch;
    c = len;
    k = 0;
    for (i = 0; i < codestr.length(); i++) {
    ch = codestr[i];
    if (ch == '0') {
        c = huffTree[c].leftchild;
    } else if (ch == '1') {
        c = huffTree[c].rightchild;
    } else {
        return -1;
    }

    if (huffTree[c].leftchild == 0 && huffTree[c].rightchild == 0) {
        txtstr[k] = huffTree[c].character;
        k++;
        c = len;
    }
    else{
        ch='\0';
    }
    
    }
    if(ch == '\0')
        return error;
    txtstr[k] = '\0';
    return 0;
}


int main() {
 int t, n, k;

 cin >> t;
 for (int testcase = 0; testcase < t; testcase++) {
     cin >> n;
     int wt[n];
     char chars[n];
     for (int i = 0; i < n; i++) {
         cin >> wt[i];
     }
     for (int i = 0; i < n; i++) {
         cin >> chars[i];
     }
     cin >> k;
     string encodedStrings[k];
     for (int i = 0; i < k; i++) {
         cin >> encodedStrings[i];
     }

     HuffMan myHuff;
     myHuff.MakeTree(n, wt, chars);
     myHuff.Coding();

     for (int i = 0; i < k; i++) {
         char txtstr[1000];
         int result = myHuff.Decode(encodedStrings[i], txtstr);
         if (result == error) {
             cout << "error" << endl;
         } else {
             cout << txtstr << endl;
         }
     }
     myHuff.Destroy();
 }
 return 0;
}

