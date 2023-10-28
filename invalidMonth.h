//
// Created by Jacob Yeung on 10/27/23.
//

#ifndef CS216PROGRAMMINGEXERCISE1405_INVALIDMONTH_H
#define CS216PROGRAMMINGEXERCISE1405_INVALIDMONTH_H

#include <stdexcept>
#include <string>
#include "invalidDay.h"

using namespace std;

class invalidMonth : public invalidDay{
public:
    invalidMonth():invalidDay("Invalid Month"){
    };
};


#endif //CS216PROGRAMMINGEXERCISE1405_INVALIDMONTH_H
