#include <iostream>
#include <stdexcept>
#include <ctime>
#include <iomanip>

#include "invalidMonth.h"
#include "invalidDay.h"

using namespace std;

int main() {
    int year, month, day;
    tm tm{};
    tm.tm_mday = 1;
    time_t time;

    while (true) {
        try{
            std::cin >> year;
            tm.tm_year = year - 1900; // - 1900;
            time = std::mktime(&tm);
            if (tm.tm_year == year - 1900) {
                year = tm.tm_year;
                break;
            }else{
                throw invalid_argument("Invalid year. Try again.");
            }
        }catch (invalid_argument& e){
            continue;
        }
    }

    while(true){
        try{
            std::cin >> month;
            tm.tm_mon = month - 1;
            time = std::mktime(&tm);
            if (tm.tm_mon == month - 1){
                month = tm.tm_mon;
                break;
            }else{
                throw invalidMonth();
            }
        }catch (invalid_argument& e){
//            cout << e.what() << endl;
            tm.tm_year = year;
            tm.tm_mday = 1;
            continue;
        }
    }

    while(true){
        try{
            std::cin >> day;
            tm.tm_mday = day;
            time = std::mktime(&tm);
            if (tm.tm_mday == day){
                day = tm.tm_mday;
                break;
            }else{
                throw invalidDay();
            }
        }catch (invalidDay& e){
//            cout << e.what() << endl;
            tm.tm_year = year;
            tm.tm_mon = month;
            tm.tm_mday = 1;
            continue;
        }
    }

    // "%c %Z": Thu Dec 21 00:00:00 2000 PST
    std::cout << put_time(std::localtime(&time), "%B ") <<
                                                       tm.tm_mday
    << put_time(std::localtime(&time), ", %Y") << std::endl;
    return 0;
}
