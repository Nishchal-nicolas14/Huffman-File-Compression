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
    }
    else {
        throw runtime_error("Unsupported File Extension!");
    }

    cout << content;
    return content;
}

void FileManager::writeFile(const string& file_path, const string& data) {

}