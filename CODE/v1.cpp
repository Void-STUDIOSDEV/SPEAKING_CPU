#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <random>
#include <algorithm>
#include <sstream>
using namespace std;
// required modules


int main() {
    vector<string> words;
    ifstream file("dictionary.txt");

    if (!file) {
        cout << "Failed to open dictionary.txt\n";
        return 1;
    }

    string line;

    // Read file line-by-line so we can skip category markers
    while (getline(file, line)) {
        if (line.empty()) continue;

        // Skip category headers like: // greetings
        if (line.rfind("//", 0) == 0) continue;

        stringstream ss(line);
        string word;

        while (ss >> word) {
            words.push_back(word);
        }
    }

    if (words.empty()) {
        cout << "No data loaded\n";
        return 1;
    }

    random_device rd;
    mt19937 gen(rd());

    // Shuffle words
    shuffle(words.begin(), words.end(), gen);

    // Random output length
    uniform_int_distribution<> dist(1, words.size());
    int limit = dist(gen);

    // Print limited output
    for (int i = 0; i < limit; i++) {
        cout << words[i] << " ";
    }

    cout << "\n";
    return 0;
}
