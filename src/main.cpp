#include "read_write_data.h"

#include <iostream>
#include <string>
#include <sstream>

#include <algorithm>
#include <chrono>

#include <fstream>

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
    
    auto begin = std::chrono::steady_clock::now();
    std::fstream file("/home/dmitrii/cpp/working_places/data_files/database.txt",
                      std::ios::app | std::ios::in);
//data_files/database.txt

    date dat = day_clock::local_day();
    Part_wp p(std::make_pair<std::string, std::string>("Мультиметр", "APPA-708"),
              "10101013",
              dat);

    //file << p;
    //std::ifstream is("/home/dmitrii/cpp/working_places/data_files/database.txt");
    std::vector<Part_wp> vPwp;
    if(file.is_open())
    {
      Part_wp nP;
      while (file >> nP)
      {
        vPwp.push_back(nP);
      }
    }
    
    for (auto& x : vPwp)
    {
        x.write_pwp();
    }
    


    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
    std::cout << "The time: " << elapsed_ms.count() << " ms\n";

    // 

  //   date DD;
  //   date d = day_clock::local_day();
  //   date prev = d /*- months(1)*/;
  //   date next = d + months(1);
  //   std::cout << d.month() << " " << prev.month() << " " << next.month() << std::endl;
  //   std::cout << (d == prev) << std::endl;
  //   std::cout << d << std::endl;


  // /////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //   // std::string ds("20020125");

  //   // boost::gregorian::date d(from_simple_string(ds));

  //   //std::cout << d.day() <<" " << d.month() << " " << d.year() << std::endl;

 
  //   boost::gregorian::date dat(2002,boost::date_time::Jan,10);

  //   std::string test = dateAsMMDDYYYY(dat);
  //   std::cout << test <<" " << DD << std::endl;

   

  //   // // пример с буста
    std::cout << "Using Boost "     
          << BOOST_VERSION / 100000     << "."  // major version
          << BOOST_VERSION / 100 % 1000 << "."  // minor version
          << BOOST_VERSION % 100                // patch level
          << std::endl;


   
   

    return 0;
}