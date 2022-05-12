
//#include "read_write_data.h"
#include "boost/date_time/gregorian/gregorian.hpp"
#include <iostream>
#include <string>
#include <sstream>

#include <algorithm>

/* Define a series of char arrays for short and long name strings 
   * to be associated with German date output (US names will be 
   * retrieved from the locale). */
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

const std::locale fmt(std::locale::classic(),
                      new boost::gregorian::date_facet("%d/%m/%Y")); //день месяц год
std::string dateAsMMDDYYYY( const boost::gregorian::date& date )
{
    std::ostringstream os;
    os.imbue(fmt);
    os << date;
    return os.str();
}

const std::locale fmt2(std::locale::classic(),
                       new boost::gregorian::date_input_facet("%m/%d/%Y")); // месяц день год
boost::gregorian::date MMDDYYYYasDate( const std::string& str)
{
    std::istringstream is(str);
    is.imbue(fmt2);
    boost::gregorian::date date;
    is >> date;
    return date;
} // обратное преобразование


int main ()
{
    using namespace boost::gregorian;

    
    date d = day_clock::local_day();
    date prev = d /*- months(1)*/;
    date next = d + months(1);
    std::cout << d.month() << " " << prev.month() << " " << next.month() << std::endl;
    std::cout << (d == prev) << std::endl;


  /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // std::string ds("20020125");

    // boost::gregorian::date d(from_simple_string(ds));

    //std::cout << d.day() <<" " << d.month() << " " << d.year() << std::endl;

 
    boost::gregorian::date dat(2002,boost::date_time::Jan,10);

    std::string test = dateAsMMDDYYYY(dat);
    std::cout << test << std::endl;

   

    // // пример с буста
    std::cout << "Using Boost "     
          << BOOST_VERSION / 100000     << "."  // major version
          << BOOST_VERSION / 100 % 1000 << "."  // minor version
          << BOOST_VERSION % 100                // patch level
          << std::endl;


   
   

    return 0;
}