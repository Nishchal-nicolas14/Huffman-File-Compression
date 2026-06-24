#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <vector>
#include <stack>
#include <fstream>
#include <cstdint>
#include "HuffmanNode.h"
#include "HuffmanTree.h"
#include "FileManager.h"

using namespace std;

string FileManager::readFile(const string& file_path) {
    // check if the file has any extension:-
    size_t pos = file_path.find_last_of('.');
    if(pos == string::npos) {
        throw runtime_error("File has no Extension");
    }
    string content;
    // this will get the substring from '.' to the end, start checking from the end of the string
    string extension = file_path.substr(pos);  

    if(extension == ".nca") {
        ifstream file(file_path, ios::binary);
        if(!file) {
            throw runtime_error("File Not Found!");
        }
        content.assign(
            (istreambuf_iterator<char>(file)), 
            istreambuf_iterator<char>()
        );
        file.close();
    }
    else if(extension == ".txt") {
        ifstream file(file_path);
        if(!file) {
            throw runtime_error("File Not Found!");
        }
        content.assign(
            (istreambuf_iterator<char>(file)), 
            istreambuf_iterator<char>()
        );
        file.close();
    }
    else {
        throw runtime_error("Unsupported File Extension!");
    }

    return content;
}

void FileManager::writeFile(const string& file_path, const string& data, const unordered_map<char, int>& freq) {
    // getting the file name:-
    string file_name = "";
    size_t pos1 = file_path.find_last_of('/');
    size_t pos2 = file_path.find_last_of('.');
    if(pos1 == string::npos) {
        file_name.assign(file_path.substr(0, pos2));
    }
    else {
        file_name.assign(file_path.substr(pos1+1, (pos2-pos1-1)));
    }
    string extension = file_path.substr(pos2); 

    if(extension == ".txt") {
        // if current file is txt -> we have encoded file(.nca) data
        file_name += ".nca";
        ofstream file(file_name, ios::binary);
        if(!file) {
            throw runtime_error("Unable to Create File");
        }
        // function call to write the header of the file:-
        writeFrequencyTable(file, freq);
        // function call to write the padding(extra bits) in the data section:-
        writePadding(file, data);
        // bit-packing of the data:
        uint8_t packedBits = 0;
        int count = 8;
        for(auto c : data) {
            if(count == 0) {
                file.write(reinterpret_cast<const char*>(&packedBits), sizeof(packedBits));
                packedBits = 0;
                count = 8;
            }
            packedBits <<= 1;
            if(c == '1') {
                packedBits = packedBits | 1;
            }
            count--;
        }
        if(count) {
            packedBits <<= count;
            file.write(reinterpret_cast<const char*>(&packedBits), sizeof(packedBits));
        }
        file.close();
    }
    else if(extension == ".nca") {
        // if current file is nca -> we have decoded file(.txt) data
        file_name += "_decoded.txt";
        ofstream file(file_name);
        if(!file) {
            throw runtime_error("Unable to Create File");
        }
        file << data;
        file.close();
    }
    else {
        throw runtime_error("File Extension not Found!");
    }
}

// helping function - 1 to write the header of the file:
void FileManager::writeFrequencyTable(ofstream& file, const unordered_map<char, int>& freq) {
    /*
        static_cast<type>(expression)
        this static_cast is used to explicitly convert expression into given type
    */
    uint16_t size = static_cast<uint16_t>(freq.size());
    /*
        reinterpret_cast<pointer>(expression address)
        this reinterpret_cast is used to treat a collection of bytes(or bits) as completely different, and convert it into the conversion pointer
    */
    file.write(reinterpret_cast<char*>(&size), sizeof(size));
    
    for(auto& [key, value]:freq) {
        file.write(reinterpret_cast<const char*>(&key), sizeof(key));
        file.write(reinterpret_cast<const char*>(&value), sizeof(value));
    }
}

// helping function - 2 to write the padding of the file:
void FileManager::writePadding(ofstream& file, const string& data) {
    uint8_t padding = (8 - (data.size() % 8)) % 8;
    file.write(reinterpret_cast<const char*>(&padding), sizeof(padding));
}
