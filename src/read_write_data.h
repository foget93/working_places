#pragma once
#include <iostream>
#include <chrono>

class PartWP
{
private:
    std::pair<std::string, std::string>  name_type;     // наименование + тип, обозначение
    std::string serial_number;                          // заводской номер
    std::string date_of_calibration;                    // дата поверки

public:
    PartWP();
    ~PartWP();
};                          //****************часть рабочего места*******************

class WorkPlace 
{

};
