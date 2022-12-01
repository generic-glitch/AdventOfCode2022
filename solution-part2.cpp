#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

std::vector<int> sortVector(std::vector<int>& vec){
    std::vector<int> sortedVec;
    int max = 0;
    int maxIndex = 0;
    for (int i = 0; i < vec.size(); i++){
        for (int j = 0; j < vec.size(); j++){
            if (vec.at(j) > max){
                max = vec.at(j);
                maxIndex = j;
            }
        }
        sortedVec.push_back(max);
        vec.erase(vec.begin() + maxIndex);
        max = 0;
        maxIndex = 0;
    }
    return sortedVec;
}

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

int * findGreatestCalories(std::vector<std::string>& lines){
    std::vector<int> topCalories;
    int currentTotal = 0;
    for (int i = 0; i < lines.size(); i++){
        if (lines.at(i) == "\n" or lines.at(i) == ""){
            topCalories.push_back(currentTotal);
            currentTotal = 0;
        }
        else {
            currentTotal += std::stoi(lines.at(i));
        }
    }
    topCalories = sortVector(topCalories);
    int greatestCaloriesArray[] = {topCalories.at(0), topCalories.at(1), topCalories.at(2)};
    return greatestCaloriesArray;
}

int main () {
    std::string puzzleText = readFile("puzzle_input.txt");
    std::vector<std::string> puzzleLines = splitString(puzzleText);
    int *topCalories = findGreatestCalories(puzzleLines);
    int total = topCalories[0] + topCalories[1] + topCalories[2];
    std::cout << total << std::endl;
    return 0;
}