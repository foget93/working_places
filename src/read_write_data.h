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
    Part_wp () {}
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

    friend std::ostream& operator << (std::ostream &os, const Part_wp& p_wp);
    friend std::istream& operator >> (std::istream &is, Part_wp& p_wp);
};                          //****************часть рабочего места*******************


class Work_place 
{

};

/*
   Define a series of char arrays for short and long name strings 
   * to be associated with German date output (US names will be 
   * retrieved from the locale). 
  const char* const de_short_month_names[] = 
  {
    "Jan", "Feb", "Mar", "Apr", "Mai", "Jun",
    "Jul", "Aug", "Sep", "Okt", "Nov", "Dez", "NAM" 
  };
  const char* const de_long_month_names[] =
  {
    "Januar", "Februar", "Marz", "April", "Mai",
    "Juni", "Juli", "August", "September", "Oktober",
    "November", "Dezember", "NichtDerMonat"
  };
  const char* const de_long_weekday_names[] = 
  {
    "Sonntag", "Montag", "Dienstag", "Mittwoch",
    "Donnerstag", "Freitag", "Samstag"
  };
  const char* const de_short_weekday_names[] =
  {
    "Son", "Mon", "Die","Mit", "Don", "Fre", "Sam"
  };
*/