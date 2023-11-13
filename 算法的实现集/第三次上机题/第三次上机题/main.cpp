#include<iostream>
#include<string>
#include<cstring> // 添加此头文件以使用strlen函数
using namespace std;

int next[100]; // 定义next数组

// 计算模式字符串的next数组
void getnext(char* t) {
    int j = 0;
    int k = -1;
    int m = strlen(t);
    next[0] = -1;
    while (j < m - 1) {
        if (k == -1 || t[j] == t[k]) {
            j++;
            k++;
            next[j] = k;
        }
        else {
            k = next[k];
        }
    }
}

// 在字符串s中执行KMP算法，查找模式字符串t的匹配位置
int KMPmatching(char* s, char* t) {
    int i = 0;
    int j = 0;
    int n = strlen(s);
    int m = strlen(t);
    while (i < n && j < m) {
        if (j == -1 || s[i] == t[j]) {
            i++;
            j++;
        }
        else {
            j = next[j];
        }
    }
    if (j >= m) {
        return i - m;
    }
    else {
        return -1;
    }
}

// 将字符串s中所有出现的字符串t替换为字符串p
string replaceString(const string& s, const string& t, const string& p) {
    string result = s;
    char* str = new char[s.length() + 1];
    strcpy(str, s.c_str());
    char* pattern = new char[t.length() + 1];
    strcpy(pattern, t.c_str());

    getnext(pattern); // 计算模式字符串的next数组

    int pos = KMPmatching(str, pattern); // 查找第一个匹配位置
    while (pos != -1) {
        result.replace(pos, t.length(), p); // 替换匹配位置的字符串
        pos = KMPmatching(str + pos + 1, pattern); // 查找下一个匹配位置
    }

    delete[] str;
    delete[] pattern;

    return result;
}

int main() {
    string s;
    string t;
    string p;

    cout << "请输入字符串s:" << endl;
    cin >> s;
    cout << "请输入字符串t:" << endl;
    cin >> t;
    cout << "请输入字符串p:" << endl;
    cin >> p;

    string result = replaceString(s, t, p);
    cout << result << endl;

    return 0;
}