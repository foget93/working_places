#pragma once
#include <iostream>
#include "boost/date_time/gregorian/gregorian.hpp"
#include <sstream>

class Part_wp
{
private:
  std::pair<std::string, std::string>  name_type;     // наименование + тип, обозначение
  std::string serial_number;                          // заводской номер
  boost::gregorian::date date_of_calibration;         // дата поверки

public:
  Part_wp ();
  Part_wp ( std::pair<std::string, std::string> name_type,
            std::string serial_number, 
            boost::gregorian::date date_of_calibration );
  ~Part_wp() { };

  void write_pwp_to_cout();

  bool set_name(const std::string& name);
  bool set_type(const std::string& type);
  bool set_serial_num(const std::string& sr_nm);
  bool set_date(const std::string& date);

  const std::string& get_name() noexcept;
  const std::string& get_type() noexcept;
  const std::string& get_serial_num() noexcept;
  const boost::gregorian::date& get_date() noexcept; //сделать

  friend std::ostream& operator << (std::ostream &os, const Part_wp& p_wp);
  friend std::istream& operator >> (std::istream &is, Part_wp& p_wp);
};                          //****************часть рабочего места*******************


std::string dateAsMMDDYYYY( const boost::gregorian::date& date );//   преобразование date->str
boost::gregorian::date MMDDYYYYasDate( const std::string& str);//     str->преобразование date


class Work_place 
{
private:
  std::string name_wp;
  std::vector<Part_wp> parts_wp;

public:

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