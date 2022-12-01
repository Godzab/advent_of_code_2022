//
// Created by Godfrey Bafana on 2022/12/01.
//
#include "iostream"
#include "fstream"
#include <sstream>
#include <map>

void elfCalorieCounter(std::string dataFilePath);

using namespace std;

int main(){
    // You could do some weird file path grab here.
    string dataFilePath = "/Users/godfreybafana/advent_of_code_2022/day_1/data2.txt";
    elfCalorieCounter(dataFilePath);
    return 0;
}

void elfCalorieCounter(const string dataFilePath) {
    ifstream stream(dataFilePath);
    string line;

    int key;
    int resultIndex, calorieMapIndex = 1;

    map<int,int> elf_calories;

    if(stream.is_open()){
        while (getline(stream, line)) {
            istringstream lineStream(line);

            // Check whether streamed line is empty
            if(!lineStream.str().empty()){
                lineStream >> key; // converts to int
                elf_calories[calorieMapIndex] += key;
                continue;
            }
            // Move to next elf's data aggregation.
            calorieMapIndex++;
        }
    }

    // Search for the result
    // Could be done better during calorie map population.
    for (auto it=elf_calories.begin(); it!=elf_calories.end(); ++it){
        if(it->second > elf_calories[resultIndex]){
            resultIndex = it->first;
        }
    }


    cout<<"The most calories come from --> "<<resultIndex <<" With "<<elf_calories[resultIndex]<<"\n";
}
