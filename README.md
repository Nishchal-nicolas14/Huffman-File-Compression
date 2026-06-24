# Huffman-File-Compression
It is an C++ application, which creates a compressed version of your text file using Huffman Encoding Algorithm.

## File Format
[uint16_t unique_chars]
[char][uint32_t freq]
[char][uint32_t freq]
...
[encoded data]

## Features
- Huffman Tree Construction
- Text Encoding
- Text Decoding
- Lossless Compression Algorithm

## Technologies
- C++
- STL
- Priority Queue
- Unordered Map
- Binary Trees

## Future Improvements
- .nca file format
- Bit-level compression
- Command Line Interface

## About Its Workflow:

The Huffman-File-Compression works on Huffman Encoding and Decoding Algorithm which creates a common pattern for a each unique characters, present in the text file.

### Encoding :
#### You input an .txt file -> It will create an encoded file, an .nca file (less size than your text file) 
Here your frequency of text characters are recorded. Using the Frequency, Huffman Tree is formed which will used to get a unique code for each character (code is in 0's and 1's).

### Decoding :
#### You input the .nca file -> It will decode the file again into the .txt file
Here your .huff file will contain the Huffman Tree, which will be used to decode the code to get the character. Then characters to form words, and Finally It will be created like an text file.

## About Files:

### 1. HuffmanNode.h : 
This is the header file which includes the class of HuffmanNode. The HuffmanNode will have the following components :-
1. Character value
2. Frequency of the Character
3. Right Node Address
4. Left Node Address

### 2. HuffmanTree.h :
This is the header file which defines all the class members and its functions. 
The Members include :-
1. HuffmanNode* root :- It  stores the root address of HuffmanTree.
2. string encodedText :- It stores the text after encoding the original text.

The Functions are :-
1. build() :- It is the function responsible for calling all the functions for creation of code using Huffman Tree.
2. encoded() :- It is the function responsible for creating the encoded and compressed file, having extension (.nca).
3. decode() :- It is the function responsible for getting the original text file using the encoded file (having extension .nca)

## Compressed File:
The Compressed File will have the extension .nca 
The Components of Compressed File are:-

### 1. MetaData:
This is the header of the Compressed File, contains the information about the Characters of the compressed File, like the frequency of each Character. This information will be required at the time of recovering the original file.

### 2. Padding:
This is the extra bits added to the end to make the compressed data in multiple of 8. This makes the data easier to store and compress.

### 3. Packed Binary Data:
This is the main content of the file after Compression. These are packed binary data, looks like an garbage values. But it is how the compressed data looks like.