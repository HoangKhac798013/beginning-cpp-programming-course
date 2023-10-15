// Section 19
// Challenge 2
// Automated Grader
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>

using namespace std;

int compareWithKey (string key, string answer);
int main() {
    fstream my_file{ "../responses.txt", std::ios::in};
    string current_line;
    string answer_key;
    int i{-2};
    const int table_width{30};
    const string table_name{"Result table"};
    std::cout << std::setw(table_width/2 + table_name.length()/2 ) << table_name << endl;
    std::cout << std::setw(table_width) << std::setfill('-') << "" << endl;
    std::cout << setfill(' ') << std::setw(table_width*2/3) << left << "Student name";
    std::cout << setw(table_width/3) << "Score" << endl;
    std::cout << std::setw(table_width) << std::setfill('-') << "" << std::setfill(' ') << endl;
    if(my_file.is_open()) {
        float accumulated_score;
        while(std::getline(my_file, current_line)) {
            current_line.erase (std::remove (current_line.begin(), current_line.end(), ' '), current_line.end());
            i++;
            if(i == -1) {
                answer_key = current_line;
                continue;
            }
            if(i%2 == 0) {
                std::cout << setw(table_width/3*2) << std::left << current_line;
                continue;
            }
            if(i%2 == 1) {
                int current_score = compareWithKey(answer_key, current_line);
                accumulated_score += current_score;
                std::cout << setw(table_width/3) << current_score << endl;
                continue;
            }
        }
        std::cout << std::setw(table_width) << std::setfill('-') << "" << endl << setfill(' ');
        std::cout << setw(table_width/3*2) << left << "Average score" << setw(table_width/3) << accumulated_score/(i+1)*2 << endl;
    }
    return 0;
}

int compareWithKey (string key, string answer) {
    int output{0};
    for(size_t i = 0; i < key.length(); i ++)
    {
        if (key[i] == answer[i]) {
            output++;
        }
    }
    return output;
}
