# Huffman-File-Compression
It is an C++ application, which creates a compressed version of your text file using Huffman Encoding Algorithm.

## Features
    Lossless text file compression
    File decompression
    Custom .nca file format
    Binary file storage
    Huffman Tree based encoding and decoding
    Cross-platform C++ implementation

## Project Structure
    Huffman Tree Construction
    Frequency Table Generation
    Binary Encoding
    Binary Decoding
    File Manager
    Command Line Interface (CLI)

## Installation

Download the binary for your platform from [Releases](https://github.com/Nishchal-nicolas14/Huffman-File-Encoding/releases).

### Linux
Use these commands on bash:
```
chmod +x nca-Linux
sudo mv nca-Linux /usr/local/bin/nca
```

### macOS
Use these commands on bash:
```
chmod +x nca-macOS
sudo mv nca-macOS /usr/local/bin/nca
```

### Windows
Rename `nca-Windows.exe` to `nca.exe`, move it to a folder like `C:\tools\`, then add that folder to your system PATH.

#### Follow these Steps to add nca to system Path:
#### Follow these steps to add nca to system PATH:
1. Search for **Environment Variables** in the Windows search bar.
2. Click **"Edit the system environment variables"**.
3. In the dialog that opens, click the **"Environment Variables"** button at the bottom.
4. Under **"System variables"** (or "User variables" for current user only), select **Path** and click **Edit**.
5. Click **New** and paste the full path to the folder containing `nca.exe` (e.g. `C:\tools\nca\`).
6. Click **OK** on all dialogs to save.
7. Open a new terminal and type `nca` to verify it works. 

## Usage
Use these commands on bash:
nca --compress filename      # compress
nca --decompress filename      # decompress


### Usage
#### Compress a File
./nca --compress input.txt

Output:
input.nca

#### Decompress a File
./nca --decompress input.nca

Output:
input_decoded.txt

#### Help
./nca --help

### Example
./nca --compress notes.txt

./nca --decompress notes.nca

### File Format
The .nca file stores:

Frequency Table Header
Padding Information
Compressed Binary Data

This allows the Huffman Tree to be reconstructed during decompression.

## Technologies
- C++
- STL
- Priority Queue
- Unordered Map
- Binary Trees

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
