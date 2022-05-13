#include "read_write_data.h"

Part_wp::Part_wp() 
{

}

Part_wp::Part_wp ( std::pair<std::string, std::string> name_type, std::string serial_number, boost::gregorian::date date_of_calibration ) 
            : name_type{name_type}, serial_number{serial_number}, date_of_calibration{date_of_calibration} 
{
    
}
void Part_wp::write_pwp_to_cout() 
{ 
    std::cout << this->name_type.first << " " 
            << this->name_type.second << " " 
            << this->serial_number << " " 
            << (*this).date_of_calibration << std::endl;
}

bool Part_wp::set_name(const std::string& name)
{
    this->name_type.first = name;
    return true;
}

bool Part_wp::set_type(const std::string& type)
{
    this->name_type.second = type;
    return true;
}

bool Part_wp::set_serial_num(const std::string& sr_nm)
{
    this->serial_number = sr_nm;
    return true;
}

bool Part_wp::set_date(const std::string& date)
{
    boost::gregorian::date buf = MMDDYYYYasDate(date);
    this->date_of_calibration = buf;
    return true;
}

std::ostream& operator << (std::ostream &os, const Part_wp& p_wp)
{
    return os << p_wp.name_type.first << " "
              << p_wp.name_type.second << " "
              << p_wp.serial_number << " "
              << p_wp.date_of_calibration << '\n';
}


std::istream& operator >> (std::istream &is, Part_wp& p_wp)
{
    is >> p_wp.name_type.first >> p_wp.name_type.second >> p_wp.serial_number >> p_wp.date_of_calibration;
    return is;
}

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
                       new boost::gregorian::date_input_facet("%d/%m/%Y")); // месяц день год
boost::gregorian::date MMDDYYYYasDate( const std::string& str)
{
    std::istringstream is(str);
    is.imbue(fmt2);
    boost::gregorian::date date;
    is >> date;
    return date;
} 