#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <algorithm>

int main() {
    setlocale(LC_ALL, "Russian");
    std::ifstream file("input.txt");
    std::string word, line;
    std::map<std::string, int> wordCount;

    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл!" << std::endl;
        return 1;
    }


    while (std::getline(file, line)) {
        std::istringstream lineStream(line);
        while (lineStream >> word) {
            std::transform(word.begin(), word.end(), word.begin(), ::tolower);
            wordCount[word]++;
        }
    }
    file.close();

    std::string mostFrequentWord;
    int maxFrequency = 0;
    for (const auto& pair : wordCount) {
        if (pair.second > maxFrequency) {
            maxFrequency = pair.second;
            mostFrequentWord = pair.first;
        }
    }

    std::ofstream outputFile("output.txt");
    for (const auto& pair : wordCount) {
        std::cout << pair.first << ": " << pair.second << std::endl;
        outputFile << pair.first << ": " << pair.second << std::endl;
    }
    std::cout << "Наиболее часто встречающееся слово: " << mostFrequentWord << std::endl;
    outputFile << "Наиболее часто встречающееся слово: " << mostFrequentWord << std::endl;
    outputFile.close();

    return 0;
}
