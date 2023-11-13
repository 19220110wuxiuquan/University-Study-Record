#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

struct HuffmanNode {
    char data;
    double weight;
    string code;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char d, double w) : data(d), weight(w), code(""), left(nullptr), right(nullptr) {}
};

struct Compare {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->weight > b->weight;
    }
};

void GetHuffmanCodes(HuffmanNode* root, string code, map<char, string>& codes) {
    if (root == nullptr)
        return;

    if (root->data != '\0') {
        codes[root->data] = code;
    }

    GetHuffmanCodes(root->left, code + "0", codes);
    GetHuffmanCodes(root->right, code + "1", codes);
}

string EncodeString(const string& input, const map<char, string>& codes) {
    string encodedString = "";
    string currentCode = "";
    for (char c : input) {
        currentCode += c;
        for (const auto& entry : codes) {
            if (entry.second == currentCode) {
                encodedString += entry.first;
                currentCode = "";
                break;
            }
        }
    }
    if (!currentCode.empty()) {
        return "Error: Code '" + currentCode + "' not found in Huffman codes.";
    }
    return encodedString;
}

int main() {
    int n;
    cout << "Enter the number of characters: ";
    cin >> n;

    vector<char> characters(n);
    vector<double> weights(n);

    cout << "Enter the characters and their weights:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> characters[i] >> weights[i];
    }

    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;
    for (int i = 0; i < n; i++) {
        pq.push(new HuffmanNode(characters[i], weights[i]));
    }

    while (pq.size() > 1) {
        HuffmanNode* left = pq.top();
        pq.pop();
        HuffmanNode* right = pq.top();
        pq.pop();

        HuffmanNode* parent = new HuffmanNode('\0', left->weight + right->weight);
        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }

    HuffmanNode* root = pq.top();
    map<char, string> huffmanCodes;
    GetHuffmanCodes(root, "", huffmanCodes);

    cout << "Huffman Codes:" << endl;
    for (const auto& entry : huffmanCodes) {
        cout << entry.first << ": " << entry.second << endl;
    }

    string input;
    cout << "Enter a binary string to encode: ";
    cin >> input;

    string encodedString = EncodeString(input, huffmanCodes);
    cout << "Encoded string: " << encodedString << endl;

    return 0;
}