# Huffman-File-Compression
It is an C++ application, which creates a compressed version of your text file using Huffman Encoding Algorithm.

## About Its Workflow:

The Huffman-File-Compression works on Huffman Encoding and Decoding Algorithm which creates a common pattern for a each unique characters, present in the text file.

### Encoding :
#### You input an .txt file -> It will create an encoded file, an .huff file (less size than your text file) 
Here your frequency of text characters are recorded. Using the Frequency, Huffman Tree is formed which will used to get a unique code for each character (code is in 0's and 1's).
Your .huff file will contain two components:
1. Your text code -
2. Your Huffman Tree -

### Decoding :
#### You input the .huff file -> It will decode the file again into the .txt file
Here your .huff file will contain the Huffman Tree, which will be used to decode the code to get the character. Then characters to form words, and Finally It will be created like an text file.

## About Files:

#### 1. HuffmanNode.h : 
This is the class file. It includes the class of HuffmanNode, which have the following components:-
1. Character value
2. Frequency of the Character
3. Right Node Address
4. Left Node Address