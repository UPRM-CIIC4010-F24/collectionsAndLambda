#include<iostream>
#include<map>
#include<vector>
#include<string>

using namespace std;

void showLetterFrequency(vector<char> letters) {
    unordered_map<char, int> frequencies;
    for(auto c: letters) {
        if(frequencies.find(c) == frequencies.end())
            frequencies[c] = 1;
        else
            frequencies[c] = frequencies[c] + 1;
    }

    cout << "Frequencies of all the letters: " << endl;
    for (const auto pair : frequencies) {
        cout << pair.first << ": " << pair.second << endl;
    }
}

int main() {
    vector<char> letters = {'a', 'b', 'c', 'a', 'b', 'd', 'e', 'f', 'g', 'a',
                            'b', 'a', 'a', 'c', 'd', 'e', 'a', 'b', 'w', 'f', 'g'};
    showLetterFrequency(letters);
    return 0;
}