// Section 19
// Challenge 3
// Word counter
#include <iostream>
#include <fstream>
#include <algorithm>
#include <bits/stdc++.h>
#include <cctype>
#include <string>
using namespace std;

int countWords(std::string word_to_find, std::fstream& file);

int main() {
    std::string input_word;
    std::fstream my_file{"../romeoandjuliet.txt", std::ios::in};
    if(!my_file) {
        std::cerr << "Can not open file" << endl;
        return 1;
    }
    cout << "Please enter the word you want to look for: ";
    cin >> input_word;
    cout << "The word you want to find appears " << countWords(input_word, my_file) << " times" << endl;
    
    cout << endl;
    my_file.close();
    return 0;
}

int countWords(std::string word_to_find, std::fstream& file) {
    std::transform(word_to_find.begin(), word_to_find.end(), word_to_find.begin(), ::tolower);
    int count{0};
    std::string current_line{};
    while(std::getline(file, current_line)) {
        std::transform(current_line.begin(), current_line.end(), current_line.begin(), ::tolower);
        std::size_t pos{0};
        while(current_line.find(word_to_find, pos) != std::string::npos) {
            pos = current_line.find(word_to_find, pos);
            pos += word_to_find.length();
            count++;
        }
    }
    return count;
}