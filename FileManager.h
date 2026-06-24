#pragma once

class FileManager {
private:
    // private members:-
    unordered_map<char, int> freq;
    uint8_t padding;

    // function to read the header of the file:
    void readFrequencyTable(ifstream& file);

    // function to read the padding of the file(how many bits are not useful from the last):
    void readPadding(ifstream& file);

    // function to write the header frequency table:
    void writeFrequencyTable(ofstream& file, const unordered_map<char, int>& freq);

    // function to write the padding of the data file:
    void writePadding(ofstream& file, const string& data);

public:
    // getter function for private members:
    unordered_map<char, int> getFrequencyTable();
    
    uint8_t getPadding();

    // function to read the content of the file:
    string readFile(const string& file_path);

    // function to write the content into the file:
    void writeFile(const string& file_path, const string& data, const unordered_map<char, int>& freq);

};