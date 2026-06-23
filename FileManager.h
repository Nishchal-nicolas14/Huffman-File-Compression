#pragma once

class FileManager {
public:

    // function to read the content of the file:
    string readFile(const string& file_path);

    // function to write the content into the file:
    void writeFile(const string& file_path, const string& data);
};