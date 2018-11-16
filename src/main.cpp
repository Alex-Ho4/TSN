#include <thread>
#include <iostream>
#include "controller.h"

int main()
{
  cout << string(50, '\n');
  std::cout << "\033[1;31m\t\t===============================\033[0m\n";
	std::cout << " " << std::endl;
 	std::cout << "\033[1;32m\t\tWelcome to The Social Network.\033[0m\n" << std::endl;
	std::cout << "\033[1;31m\t\t===============================\033[0m\n";

  user current_user; //user instance to construct a tsn_system
  tsn_system sys = tsn_system(current_user); //tsn_system instance for view constructor
  sys.load_user_data();

  view v = view(sys); //view instance for controller constructor

  controller ctrl = controller(sys, v);
  std::thread bg (&controller::background, &ctrl); //starting the background threads

  while(1) //executing user commands
  {
    ctrl.execute_cmd();
  }

  return 0;
}
