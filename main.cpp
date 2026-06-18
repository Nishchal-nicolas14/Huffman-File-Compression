#include<bits/stdc++.h>
using namespace std;

class HuffmanNode {
    char ch;
    int freq;
    HuffmanNode* left;
    HuffmanNode* right;

    // for leaf node call:
    HuffmanNode(char c, int f) {
        ch = c;
        freq = f;
        left = nullptr;
        right = nullptr;
    }

    // for internal node call:
    HuffmanNode(int f, HuffmanNode* l, HuffmanNode* r) {
        ch = '/0';
        freq = l->freq + r->freq;
        left = l;
        right = r;
    }
};