#include "PrefixMatcher.h"

int PrefixMatcher::selectRouter(string networkAddress){
    int longest=0;
    int routerNumber=0;
    for(size_t i=0;i<ad.size();i++){
        int minim = min(static_cast<int>(networkAddress.length()),static_cast<int>(ad[i].length()));
        int match_len=0;
        for(int K=0;K<minim;K++){
            if(ad[i][K]==networkAddress[K]){
                match_len++;
            }else{
                K=minim;
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
    ad.push_back(address);
    numbers.push_back(routerNumber);
    return;
}
