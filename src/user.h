#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "ccpp_tsn.h"
#include "post.h"
#include "message.h"

class user
{
  private:
    TSN::serial_number highest_pnum;
    TSN::serial_number highest_mnum;

  public:
    std::string first_name;
    std::string last_name;
    long date_of_birth;
    char uuid[TSN::UUID_SIZE];
    std::vector<std::string> interests;
    std::vector<post> posts;
    std::vector<message> messages;

    user(); //default constructor
    user(std::string fname, std::string lname, long dob, char *id, std::vector<std::string>& i,
        std::vector<post>& p,std::vector<message>& m,unsigned long long hm, unsigned long long hp);

    unsigned long long get_highest_pnum(); //returns the highest post number
    unsigned long long get_highest_mnum(); //returns the highest message number
    void add_post(post p); //adds to the posts vector and increments highest post num
    void add_message(message m); //adds to the posts vector and increments highest post num
    user& operator= (const user &rhs); //assignment operator overload
};

#endif
