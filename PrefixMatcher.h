#ifndef PREFIXMATCHER_H
#define PREFIXMATCHER_H

#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

class PrefixMatcher{
public:
    int selectRouter(string networkAddress);
    void insert(string address, int routerNumber);
private:
    vector<string> addre;
    vector<int> numbers;
};

#endif
