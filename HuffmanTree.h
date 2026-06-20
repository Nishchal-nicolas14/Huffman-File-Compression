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

    // genrate frequency for each character:
    unordered_map<char, int> generateFrequency(const string& text);

    // make the priority queue for HuffmanNodes:
    HuffmanQueue createPriorityQueue(const unordered_map<char, int>& freq);

    // make the Huffman Tree:
    void createTree(HuffmanQueue& pq);

public:
    HuffmanTree();

    void build(const string& text);
};