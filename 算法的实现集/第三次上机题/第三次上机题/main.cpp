#include<iostream>
#include<string>
#include<cstring> // ��Ӵ�ͷ�ļ���ʹ��strlen����
using namespace std;

int next[100]; // ����next����

// ����ģʽ�ַ�����next����
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

// ���ַ���s��ִ��KMP�㷨������ģʽ�ַ���t��ƥ��λ��
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

// ���ַ���s�����г��ֵ��ַ���t�滻Ϊ�ַ���p
string replaceString(const string& s, const string& t, const string& p) {
    string result = s;
    char* str = new char[s.length() + 1];
    strcpy(str, s.c_str());
    char* pattern = new char[t.length() + 1];
    strcpy(pattern, t.c_str());

    getnext(pattern); // ����ģʽ�ַ�����next����

    int pos = KMPmatching(str, pattern); // ���ҵ�һ��ƥ��λ��
    while (pos != -1) {
        result.replace(pos, t.length(), p); // �滻ƥ��λ�õ��ַ���
        pos = KMPmatching(str + pos + 1, pattern); // ������һ��ƥ��λ��
    }

    delete[] str;
    delete[] pattern;

    return result;
}

int main() {
    string s;
    string t;
    string p;

    cout << "�������ַ���s:" << endl;
    cin >> s;
    cout << "�������ַ���t:" << endl;
    cin >> t;
    cout << "�������ַ���p:" << endl;
    cin >> p;

    string result = replaceString(s, t, p);
    cout << result << endl;

    return 0;
}