#pragma once

class FileManager {
public:

    // function to read the content of the file:
    string readFile(const string& file_path);

    // function to write the content into the file:
    void writeFile(const string& file_path, const string& data, const unordered_map<char, int>& freq);

    // function to write the header frequency table:
    void writeFrequencyTable(ofstream& file, const unordered_map<char, int>& freq);

    // function to write the padding of the data file:
    void writePadding(ofstream& file, const string& data);
};