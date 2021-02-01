// Program to use STL map to count the frequency of words in an input file

#include <fstream>
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() 
{
    map<string, int> words;
    map<string, int>::iterator it;
    string fileName, word;
    ifstream input;
    
    while (!input.is_open()) {
        cout << "\nPlease enter a filename (with path if neccesary) to open: ";
        cin >> fileName;            // use "ipsum.txt" from this repo
    
        input.open(fileName);

        if (!input.is_open())
            cout << "Unable to open " << fileName << ", please re-enter.\n";
    }

    while (input >> word)
        words[word]++;  // inserts word if not in map, increments value if it is

    input.close();

    for (it = words.begin(); it != words.end(); ++it)
        cout << "number of occurences for '" << it->first << "' is " << it->second << "\n";

    return 0;
}