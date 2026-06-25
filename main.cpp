#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <vector>
#include <stack>
#include <cstdint>
// other included files:
#include "HuffmanNode.h"
#include "HuffmanTree.h"
#include "FileManager.h"

using namespace std;

void showBanner() {
    cout << "╔══════════════════════════════╗\n";
    cout << "║      NCA COMPRESSOR v1.0     ║\n";
    cout << "║   Huffman File Compression   ║\n";
    cout << "║      Created by Nishchal     ║\n";
    cout << "╚══════════════════════════════╝\n\n";
}

int main(int argc, char* argv[]) {
    showBanner();
    // check if number of arguments are less:
    if(argc < 2) {
        cerr << "Invalid Argument!\n";
        cerr << "Usage : \n";
        cerr << " nca compress <file.txt> or /file_path\n";
        cerr << " nca decompress <file.nca> or /file_path\n";
        cerr << " nca help\n";

        return 1;
    }
    string command = argv[1];
    // check for compression:-
    if(command == "compress") {
        if(argc != 3) {
            cerr << "File Name Not Found!\n";
        }
        // open file and read it's content:-
        FileManager fm;
        string text;
        try {
            text = fm.readFile(string(argv[2]));
        }
        catch(const exception& e) {
            cout << e.what() << "\n";
            return 1;
        }

        // if the text we got correct then build the HuffmanTree for content:-
        HuffmanTree ht;
        ht.build(text);
        string encoded = ht.encode(text);
        map<char, int> freq = ht.getFrequencyTable();

        // open the file for writing argument:-
        try {
            fm.writeFile(string(argv[2]), encoded, freq);
        }
        catch(const exception& e) {
            cerr << e.what() << "\n";
            return 1;
        }
        cout << "\nFile Successfully Compressed\n";

        return 1;
    }
    // check for decompression:-
    if(command == "decompress") {
        if(argc != 3) {
            cerr << "File Name Not Found!\n";
        }
        // open file and read it's content:-
        FileManager fm;
        string text;
        try {
            text = fm.readFile(string(argv[2]));
        }
        catch(const exception& e) {
            cout << e.what() << "\n";
            return 1;
        }
        map<char, int> freq = fm.getFrequencyTable();
        uint8_t padding = fm.getPadding();
        
        // if the text is successfully readed then, build a Huffman Tree:
        HuffmanTree ht;
        ht.setFrequencyTable(freq);
        string decoded = ht.decode(text, (int)padding);

        // open the file for writing argument:-
        try {
            fm.writeFile(string(argv[2]), decoded, freq);
        }
        catch(const exception& e) {
            cerr << e.what() << "\n";
            return 1;
        }
        cout << "\nFile Successfully Decompressed\n";

        return 1;
    }
    // check for help:-
    if(command == "help") {
        if(argc > 2) {
            cerr << "Invalid Argument!\n";
            cerr << "Usage : \n";
            cerr << " nca compress <file.txt> or /file_path\n";
            cerr << " nca decompress <file.nca> or /file_path\n";
            cerr << " nca help\n";

            return 1;
        }
        cerr << "Usage : \n";
        cerr << " nca compress <file.txt> or /file_path\t\tFor File Compression into .nca file\n";
        cerr << " nca decompress <file.nca> or /file_path\tFor File Decompression into Original text file\n";
        
        return 1;
    }
    // or else the argument is not valid:-
    else {
        cerr << "Invalid Argument!\n";

        return 1;
    }


}