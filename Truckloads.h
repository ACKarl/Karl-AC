#ifndef TRUCKLOADS_H
#define TRUCKLOADS_H
//Class:Truckloads
//Method:numTrucks
//Parameters:int,int
//Returns:int
//Method signature:int numTrucks(int numCrates,int loadsize)
//(be sure your method is public)

class Truckloads{
public:
    int numTrucks(int numCrates,int loadSize);
protected:
    int TrueNumTrucks(int numCrates,int loadSize);
};

#endif