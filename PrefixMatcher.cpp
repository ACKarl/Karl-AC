#include "PrefixMatcher.h"

int PrefixMatcher::selectRouter(string networkAddress){
    int longest=0;
    int routerNumber=0;
    for(size_t i=0;i<addre.size();i++){
        int minim = min(static_cast<int>(networkAddress.length()),static_cast<int>(addre[i].length()));
        int match_len=0;
        for(int j=0;j<minim;j++){
            if(addre[i][j]==networkAddress[j]){
                match_len++;
            }else{
                j=minim;
            }
        }
        if(match_len>longest){
            longest=match_len;
            routerNumber=i;
        }
    }
    return numbers[routerNumber];
}

void PrefixMatcher::insert(string address,int routerNumber){
    addre.push_back(address);
    numbers.push_back(routerNumber);
    return;
}
