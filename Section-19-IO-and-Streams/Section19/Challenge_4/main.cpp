// Section 19
// Challenge 4
// Copy Romeo and Juliet with line numbers
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
int main() {

    std::fstream in_file{"../romeoandjuliet", std::ios::in};
    std::fstream out_file{"../romeoandjuliet_out", std::ios::out};
    
    if (!in_file || !out_file) {
        std::cerr << "Error loading files" << std::endl;
        return 1;
    }
    std::string line;
    int count{1};
    while(std::getline(in_file, line)) {
        if(!line.empty()) {
            out_file << std::left << std::setw(10) << count << line << std::endl;
            ++count;
        }
        else {
            out_file << "\n" << std::endl;
        }
    }
    
    in_file.close();
    out_file.close();
    return 0;
}

