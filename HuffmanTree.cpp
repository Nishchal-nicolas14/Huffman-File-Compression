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

HuffmanQueue HuffmanTree::createPriorityQueue(const unordered_map<char, int>& freq) {
    HuffmanQueue pq;
    for(auto& [key, value]:freq) {
        HuffmanNode* newNode = new HuffmanNode(key, value);
        pq.push(newNode);
    }
    return pq;
}

void HuffmanTree::createTree(HuffmanQueue& pq) {
    while(pq.size() > 1) {
        HuffmanNode* left = pq.top();
        pq.pop();
        HuffmanNode* right = pq.top();
        pq.pop();
        HuffmanNode* parent = new HuffmanNode(left, right);
        pq.push(parent);
    }
    this->root = pq.top();
}

void HuffmanTree::build(const string& text) {
    unordered_map<char, int> freq = generateFrequency(text);
    HuffmanQueue pq = createPriorityQueue(freq);

    
}