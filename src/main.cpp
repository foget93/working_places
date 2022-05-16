#include "read_write_data.h"

#include <iostream>
#include <string>
#include <sstream>

#include <algorithm>
#include <chrono>

#include <fstream>
#include <filesystem>


// обратное преобразование

namespace fs = std::filesystem;

int main ()
{ 
  
    __cplusplus;
    
    fs::path path {"/home/dmitrii/cpp/working_places/data_files/database.txt"};
    std::cout << "parent_path: " << path.parent_path() << std::endl;
    std::cout << "extension: " << path.extension() << std::endl;
    std::cout << "filename: " << path.filename() << std::endl;
    std::cout << "root_name: " << path.root_name() << std::endl;
    std::cout << "has_relative_path: " << path.has_relative_path() << std::endl;
    std::cout << "has_root_directory: " << path.has_root_directory() << std::endl;

    std::cout << "preferred_separator: " << fs::path::preferred_separator << std::endl; // разделить unix систем

    fs::create_directories("banana/cocosa/mango");
    fs::create_directories("banana/apple/kiwi");
    system("ls -a banana/*");
    fs::remove_all("banana");
    system("ls -a banana/*");

    using namespace boost::gregorian;
    
    auto begin = std::chrono::steady_clock::now();

    std::fstream file("/home/dmitrii/cpp/working_places/data_files/database.txt",
                      std::ios::app | std::ios::in);
//data_files/database.txt

    date dat = day_clock::local_day();
    Part_wp p(std::make_pair<std::string, std::string>("PILA", "APPA-708"),
              "10101013",
              dat);
    //date d1(2012,5,13);
    std::cout << p << std::endl;
    p.set_date("10-11-2001");
    std::cout << p << std::endl;
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
        x.write_pwp_to_cout();
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