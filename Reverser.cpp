#include <iostream>
#include "Reverser.h"
#include <cmath>

int Reverser::reverseDigit(int value){
   if(value < 0){return -1;}

//base case
   if(value/10 == 0){return value;}

//确定数字
   int num = value - ((value/10)*10);

//确定位数
   int power = 0;
   while(value/pow(10,power)>=1 ){
   power++;
}
   power--;

//把数字放到对应位数上
   int sum = num * pow(10,power);

//处理下一个数字
   return sum + reverseDigit(value/10);
}

std::string Reverser::reverseString(std::string letters){
//base case
   if(letters == ""){return "ERROR";}
   if(letters.length() <= 1){return letters;}
   
   char last = letters.back();
   letters.pop_back();

   return last + reverseString(letters);
}
