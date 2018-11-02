#include "user.h"
#include <cstring>
#include <vector>

user::user()
{
    first_name = "fname";
    last_name = "lname";
    date_of_birth = 0;

    std::vector<std::string> i;
    interests = i;

    std::vector<post> p;
    posts = p;

    std::vector<message> m;
    messages = m;
    highest_mnum = 0;
    highest_pnum = 0;
}
user::user(std::string fname, std::string lname, long dob, char *id, std::vector<std::string> &i, std::vector<post> &p,std::vector<message>& m,unsigned long long hm, unsigned long long hp)
{
    first_name = fname;
    last_name = lname;
    date_of_birth = dob;
    strcpy(uuid, id);
    interests = i;
    posts = p;
    messages=m;
    highest_pnum = hp;
    highest_mnum = hm;
}

void user::add_post(post p)
{
    posts.push_back(p);
    highest_pnum++;
}

void user::add_message(message m)
{
    messages.push_back(m);
    highest_mnum++;
}

unsigned long long user::get_highest_mnum()
{
    return highest_mnum;
}

unsigned long long user::get_highest_pnum()
{
    return highest_pnum;
}

//assignment operator overload
user &user::operator=(const user &rhs)
{
    first_name = rhs.first_name;
    last_name = rhs.last_name;
    date_of_birth = rhs.date_of_birth;
    strcpy(uuid, rhs.uuid);
    interests = rhs.interests;
    posts = rhs.posts;
    messages = rhs.messages;
    highest_pnum = rhs.highest_pnum;
    highest_mnum = rhs.highest_mnum;

    return *this;
}
