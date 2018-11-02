#include "message.h"

message::message(TSN::serial_number sn, std::string body, long doc)
{
    serial_num = sn;
    message_body = body;
    creation_date = doc;
}

std::string message::get_body()
{
    return message_body;
}
long message::get_doc()
{
    return creation_date;
}
TSN::serial_number message::get_sn()
{
    return serial_num;
}
