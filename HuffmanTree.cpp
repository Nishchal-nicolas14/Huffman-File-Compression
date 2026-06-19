#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <vector>
#include "HuffmanNode.h"
#include "HuffmanTree.h"

using namespace std;

HuffmanTree::HuffmanTree() {
    root = nullptr;
}

unordered_map<char, int> HuffmanTree::generateFrequency(const string& text) {
    unordered_map<char, int> freq;
    
    for(auto ch:text) {
        freq[ch]++;
    }

    return freq;
}