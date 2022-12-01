#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

std::vector<std::string> splitString(const std::string& str)
{
    std::vector<std::string> tokens;
    std::string::size_type pos = 0;
    std::string::size_type prev = 0;
    while ((pos = str.find('\n', prev)) != std::string::npos) {
        tokens.push_back(str.substr(prev, pos - prev));
        prev = pos + 1;
    }
    tokens.push_back(str.substr(prev));
    return tokens;
}

std::string readFile(const std::string& fileName){
    std::ifstream puzzleFile; 
    puzzleFile.open(fileName);
    std::string puzzleText;
    if ( puzzleFile.is_open() ) {
        std::stringstream puzzleStream;
        puzzleStream << puzzleFile.rdbuf();
        puzzleText = puzzleStream.str();
    }
    puzzleFile.close();
    return puzzleText;
}

int findGreatestCalories(std::vector<std::string>& lines){
    int MaxCalories = 0;
    int currentTotal = 0;
    for (int i = 0; i < lines.size(); i++){
        if (lines.at(i) == "\n" or lines.at(i) == ""){
            if (currentTotal > MaxCalories){
                MaxCalories = currentTotal;
            }
            currentTotal = 0;
        }
        else {
            currentTotal += std::stoi(lines.at(i));
        }
    }
    return MaxCalories;
}

int main () {
    std::string puzzleText = readFile("puzzle_input.txt");
    std::vector<std::string> puzzleLines = splitString(puzzleText);
    std::cout << findGreatestCalories(puzzleLines) << std::endl;
    return 0;
}