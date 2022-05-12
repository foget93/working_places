#pragma once
#include <iostream>
#include "boost/date_time/gregorian/gregorian.hpp"

class Part_wp
{
private:
    std::pair<std::string, std::string>  name_type;     // наименование + тип, обозначение
    std::string serial_number;                          // заводской номер
    boost::gregorian::date date_of_calibration;         // дата поверки

public:
    Part_wp ( std::pair<std::string, std::string> name_type,
              std::string serial_number, 
              boost::gregorian::date date_of_calibration ) 
              : name_type{name_type}, 
                serial_number{serial_number}, 
                date_of_calibration{date_of_calibration} {}

    void write_pwp() 
    { 
      std::cout << this->name_type.first << " " 
                        << this->name_type.second << " " 
                        << this->serial_number << " " 
                        << this->date_of_calibration << std::endl;
    }
    ~Part_wp() { };
};                          //****************часть рабочего места*******************

class Work_place 
{

};