#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <vector>
#include "HuffmanNode.h"

using namespace std;

// comparator function used in min-heap for comparing two Huffman Node:
struct comparator {
    bool operator()(HuffmanNode* node1, HuffmanNode* node2) {
        if(node1->freq != node2->freq)
            return node1->freq > node2->freq;
        return node1->ch > node2->ch;
    }
};

using HuffmanQueue = priority_queue<HuffmanNode*, vector<HuffmanNode*>, comparator>;


// Huffman class to genrate the huffman tree:
class HuffmanTree {
private:
    HuffmanNode* root;
    unordered_map<char, string> codes;
    unordered_map<char, int> freq;

    // genrate frequency for each character:
    void generateFrequency(const string& text);

    // make the priority queue for HuffmanNodes:
    HuffmanQueue createPriorityQueue(const unordered_map<char, int>& freq);

    // make the Huffman Tree:
    void createTree(HuffmanQueue& pq);

    // generate a coded string for each character:
    void generateCodes();

    // Helper Function for generating code:
    void generateCodeHelper(HuffmanNode* temp, string code); 

public:
    HuffmanTree();

    // getter method for getting the frequency table:-
    const unordered_map<char, int>& getFrequencyTable();

    // from creating the huffman tree to creating the nodes:
    void build(const string& text);


    // generate a string for the encoded part, using codes for each character:
    string encode(const string& text);

    // recover the original string from the compressed(.nca) file:
    string decode(const string& encodedText);
};