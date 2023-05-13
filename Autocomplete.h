#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include <vector>
#include <iostream>
using namespace std;
class Autocomplete{
public:
    vector<string> getSuggestions(string partialWord);
    void insert(string word);
private:
    vector<string> WORD;
};
#endif
