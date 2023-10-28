//
// Created by Jacob Yeung on 10/27/23.
//

#ifndef CS216PROGRAMMINGEXERCISE1405_INVALIDDAY_H
#define CS216PROGRAMMINGEXERCISE1405_INVALIDDAY_H

#include <stdexcept>
#include <string>

using namespace std;

class invalidDay : public invalid_argument {
public:
    invalidDay():invalid_argument("Invalid Day"){
    }
protected:
    explicit invalidDay(const string& msg):invalid_argument(msg){
    }
};


#endif //CS216PROGRAMMINGEXERCISE1405_INVALIDDAY_H
