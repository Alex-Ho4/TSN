#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <chrono>
#include "ccpp_tsn.h"

class message
{
  private:
    TSN::serial_number serial_num;
    std::string message_body; //message of post
    long creation_date;

  public:
    message(TSN::serial_number sn, std::string body, long doc); //constructor
    std::string get_body(); //return the post message
    long get_doc(); //return the date of creation
    TSN::serial_number get_sn(); //return the post's serial num

};

#endif
