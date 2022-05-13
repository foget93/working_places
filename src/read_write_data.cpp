#include "read_write_data.h"

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