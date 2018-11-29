#ifndef VIEW_H
#define VIEW_H

class view;
#include "system.h"

class view
{
  public:
  tsn_system& sys; //reference to a tsn_system instance

  view(tsn_system& s) : sys(s) {}; //constructor
  void print_main_menu();
  void print_edit_menu();
  void print_online(); //prints names of nodes on the network
  void select_user(); //prints list of users to select, then displays options
  void show_stats(); //shows stats about other known nodes and post content on the network
  void about(); //shows program info
  void search_posts();
  void send_quick_reply(); //send a reply to last pm sender

};
#endif
