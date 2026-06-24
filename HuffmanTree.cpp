#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <vector>
#include <stack>
#include <cstdint>
#include "HuffmanNode.h"
#include "HuffmanTree.h"

using namespace std;

HuffmanTree::HuffmanTree() {
    root = nullptr;
}

void HuffmanTree::generateFrequency(const string& text) {
    
    for(auto ch:text) {
        freq[ch]++;
    }

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

string HuffmanTree::encode(const string& text) {
    string result = "";
    for(char t:text) {
        result += codes[t];
    }
    return result;
}

string HuffmanTree::decode(const string& encodedText) {
    // tranverse using HuffmanNode* root:-
    string decodedText = "";
    // pointer to traverse the HuffmanTree:-
    HuffmanNode* temp = root;
    for(auto text:encodedText) {
        if(text == '0') {
            temp = temp->left;
        }
        else {
            temp = temp->right;
        }
        if(temp->left==nullptr && temp->right==nullptr) {
            decodedText += temp->ch;
            temp = root;
        }
    }

    return decodedText;
}

void HuffmanTree::build(const string& text) {
    // First, generate the frequency table:
    generateFrequency(text);
    
    // Then, generate the Min-Heap for Huffman Tree:
    HuffmanQueue pq = createPriorityQueue(freq);

    // Generate the Huffman Tree:
    createTree(pq);
    
    // Generate Codes for characters:
    generateCodes();
    
}

// getter method for the frequency table:-
const unordered_map<char, int>& HuffmanTree::getFrequencyTable() {
    return freq;
}