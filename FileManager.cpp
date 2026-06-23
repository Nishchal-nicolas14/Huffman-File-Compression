#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <vector>
#include <stack>
#include <fstream>
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

void FileManager::writeFile(const string& file_path, const string& data) {
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
        file << data;
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