#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <vector>
#include <stack>
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

void HuffmanTree::generateCodeHelper(HuffmanNode* temp, string code) {
    if(temp == nullptr)
        return;

    if(temp->right==nullptr && temp->left==nullptr) {
        codes[temp->ch] = code;
        return;
    }
    
    // calling the function for left node and right node:
    generateCodeHelper(temp->left, code+"0");
    generateCodeHelper(temp->right, code+"1");
}

void HuffmanTree::generateCodes() {
    generateCodeHelper(root, "");
    
    return;
}

void HuffmanTree::build(const string& text) {
    // First, generate the frequency table:
    unordered_map<char, int> freq = generateFrequency(text);
    for(auto& [key, value]:freq) {
        cout << key << " : " << value << endl;
    }
    // Then, generate the Min-Heap for Huffman Tree:
    HuffmanQueue pq = createPriorityQueue(freq);

    // Generate the Huffman Tree:
    createTree(pq);
    
    // Generate Codes for characters:
    generateCodes();
    
}