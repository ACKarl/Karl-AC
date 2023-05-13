#include "Autocomplete.h"

vector<string> Autocomplete::getSuggestions(string partialWord){
    vector<string> r;
    for(size_t i=0;i<WORD.size();i++){
        size_t K=0;
        if(partialWord.length()<=WORD[i].length()){
            while(K<=partialWord.length()-1 && WORD[i][K]==partialWord[K]){
                if(K>=partialWord.length()-1){
                    r.push_back(WORD[i]);
                }
                K++;
            }
        }
    }
    return r;
}

void Autocomplete::insert(string word){
    WORD.push_back(word);
    return;
}
