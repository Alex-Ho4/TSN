#include <iomanip>
#include "view.h"


void view::print_main_menu()
{
  std::cout << " ";
  std::cout << "\033[1;31m\t\t====Select what you want to do:====\033[0m\n";
  std::cout << "\033[1;32m\t(1) Add A Post\033[0m";
  std::cout << " creates the new post.\n";
  std::cout << "\033[1;32m\t(2) Publish A Request\033[0m";
  std::cout << " gets access to posts. Example: User B gets\n\tpermission to see posts posted by User A.\n";
  std::cout << "\033[1;32m\t(3) View Online Users\033[0m";
  std::cout << " sees online users. Example: User A can see\n\twho are online in the network.\n";
  std::cout << "\033[1;32m\t(4) Select User\033[0m";
  std::cout << " Select a user to view posts or PM.\n\tMust to publish a request at first.\n";
  std::cout << "\033[1;32m\t(5) Edit\033[0m";
  std::cout << " allows user to edit first name,last name and interest.\n";
  std::cout << "\033[1;32m\t(6) Resync\033[0m";
  std::cout << " clears all information.\n";
  std::cout << "\033[1;32m\t(7) Statistics\033[0m";
  std::cout << " prints out the number of all other nodes\n";
  std::cout << "\033[1;32m\t(8) About\033[0m";
  std::cout << " displays About info.\n";
  std::cout << "\033[1;32m\t(9) Reply to Private Message\033[0m";
  std::cout << " Sends PM to sender of last received PM\n";
  std::cout << "\033[1;32m\t(10) Select INTERESTS\033[0m";
  std::cout << " displays users matching input interests.\n";
  std::cout << "\033[1;32m\t(0) Exit\033[0m";
  std::cout << " closes the application.\n";
  std::cout << "\033[1;38mKEY>>  \033[0m";
}

void view::print_edit_menu()
{
  std::cout << "\n(1) First Name" << std::endl;
  std::cout << "(2) Last Name" << std::endl;
  std::cout << "(3) Interests" << std::endl;
  std::cout << "\nChoose what you'd like to change: " << std::endl;
}

void view::print_online()
{
  if(sys.online_users.size() == 0)
  {
    cout << string(50, '\n');
    std::cout << "\033[1;37m\t\tNo other users currently connected to TSN.\033[0m\n" << std::endl;
    return;
  }
  std::vector<user>::iterator it;
  cout << string(50, '\n');
  std::cout << "\033[1;31m\t\t=============================\033[0m\n";
	std::cout << " " << std::endl;
  std::cout << "\033[1;32m\t\t         ONLINE USERS\033[0m\n" << std::endl;
  std::cout << "\033[1;31m\t\t=============================\033[0m\n";
  for(it = sys.online_users.begin(); it != sys.online_users.end(); it++)
  {
    std::cout << "Name : " << it->first_name << " " << it->last_name << std::endl;
    std::cout << "Interests: ";

    std::vector<std::string>::iterator interests_it;
    for(interests_it = it->interests.begin(); interests_it != it->interests.end(); interests_it++)
    {
      std::cout << "  -- " <<*interests_it << std::endl;
    }
    std::cout << std::endl;
  }
  std::cout << " " << std::endl;
  std::cout << " " << std::endl;
  std::cout << " " << std::endl;
  std::cout << " " << std::endl;
  std::cout << "\033[1;38m\t\tPress any key and enter to return to Main Menu\033[0m\n";
  std::string close;
  cin>>close;
}


void view::select_user()
{
  std::vector<user>::iterator it;
  int n = 0;
  std::cout << std::endl;

  //listing all online users whose info can be retrieved and shown
  int on_list_size = static_cast<int> (sys.online_users.size());
  if(on_list_size > 0)
  {
    cout << string(50, '\n');
    std::cout << "\033[1;31m\t\t=============================\033[0m\n";
    std::cout << " " << std::endl;
    std::cout << "\033[1;32m\t\t         ONLINE USERS\033[0m\n" << std::endl;
    std::cout << "\033[1;31m\t\t=============================\033[0m\n";
    for(it = sys.online_users.begin(); it != sys.online_users.end(); it++, n++)
    {
      std::cout << "(" << n << ") " << it->first_name << " " << it->last_name << std::endl;
    }
    std::cout << " " << std::endl;
    std::cout << "\nChoose which user to show: " << std::endl;

    n = 0;
    int choice;
    std::cin >> choice;

    for(it = sys.online_users.begin(); n < choice+1 ; it++, n++)
    {
      //retrieving and printing out the chosen user's information
      if(n == choice)
      {
        std::cout << "Name: " << it->first_name << " " << it->last_name << std::endl;
        std::cout << "\nInterests: " << std::endl;

        std::vector<std::string>::iterator interests_it;
        for(interests_it = it->interests.begin(); interests_it != it->interests.end(); interests_it++)
        {
          std::cout << "  -- " << *interests_it << std::endl;
        }

        std::cout << "\n\033[1;32m\t(1) View Posts\033[0m";
        std::cout << " View user's Posts\n";
        std::cout << "\033[1;32m\t(2) Send Private Message\033[0m";
        std::cout << " Send Private Messages\n";
        std::cout << "\033[1;32m\t(0) Exit\033[0m\n\n";
        std::cout << "\033[1;38mKEY>>  \033[0m";

        std::cin >> choice;
        cout << string(50, '\n');

        if(choice == 1)
        {
          std::cout << "\nPosts: " << std::endl;

          if(it->get_highest_pnum() == 0)
          {
            std::cout << "\033[1;37mEither there are no posts to show right now, or you haven't published request.\033[0m\n" << std::endl;
            std::cout << "\033[1;35m\t\tPLEASE select 2 to \"Publish a Request\" at first.\033[0m\n" << std::endl;
            std::cout << " " << std::endl;
            sleep(1);
          }
          else
          {
            choice = -1;
            std::cout << "\n\033[1;32m\t(0) Exit to main menu\033[0m\n";
            sys.request_all_posts(*it);
            std::cin >> choice;
            //sleep(it->get_highest_pnum());
          }
        }

        if(choice == 2)
        {
          std::cin.ignore();
          sys.send_pm(it->uuid);
        }

        break;
      }
    }
  }
  else
  {
    cout << string(50, '\n');
    std::cout << "\033[1;37m\t\tThere are no users online to show.\033[0m\n" << std::endl;
  }
}

void view::send_quick_reply()
{
  if(strcmp(sys.last_pm_sender, "NULL") == 0)
  {
    cout << string(50, '\n');
    std::cout << "\033[1;37m\t\tThere is currently no PM to respond to.\033[0m\n" << std::endl;
  }
  else
    sys.send_pm(sys.last_pm_sender);
}

void view::show_stats()
{
  std::vector<user>::iterator it;
  TSN::serial_number total_posts = 0;
  int total_num_users = 0; //number of known users

  //calculating number of all known posts available and all known users
  for(it = sys.all_users.begin(); it != sys.all_users.end(); it++)
  {
    total_posts += it->get_highest_pnum();
    total_num_users++;
  }

  //calculating the percentage of posts available on this node
  double content_percent = 0;
  if(sys.current_user.get_highest_pnum() > 0)
  {
    total_posts += sys.current_user.get_highest_pnum();
    content_percent = (double) sys.current_user.get_highest_pnum() / total_posts * 100;
  }
  std::cout << "\nThere are " << total_num_users << " other nodes known." << std::endl;
  std::cout << "This node contains " << fixed << std::setprecision(2) << content_percent << "\% of posts available on the TSN network." << std::endl;

}

void view::about()
{
  cout << string(50, '\n');
  std::cout << "\033[1;31m\t\t===============================\033[0m\n";
  std::cout << " " << std::endl;
  std::cout << "\033[1;32m\t\t              ABOUT\033[0m\n" << std::endl;
  std::cout << "\033[1;31m\t\t===============================\033[0m\n";
  std::cout << " " << std::endl;
//  std::cout << " ******* 𝕋𝕙𝕚𝕤 𝕒𝕡𝕡 𝕚𝕤 𝕕𝕖𝕧𝕖𝕝𝕠𝕡𝕖𝕕 𝕓𝕪 'ℤ𝕖𝕣𝕠𝕖𝕕 𝕋𝕖𝕒𝕞 ' *******" << std::endl;
  std::cout << "\033[1;33m\t ⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇\033[0m\n";
  std::cout << " " << std::endl;
  std::cout << "\t ******* Jeevan Gyawali *******" << std::endl;
  std::cout << "\t ******* Ishwor Rijal *******" << std::endl;
  std::cout << "\t ******* Alex Ho *******" << std::endl;
  std::cout << "\t ******* Donovan A. *******" << std::endl;
  std::cout << " " << std::endl;
  std::cout << " " << std::endl;
  std::cout << " " << std::endl;
  std::cout << " " << std::endl;
  std::cout << "\033[1;38m\t\tPress any key and enter to return to Main Menu\033[0m\n";
  string close;
  std::cin >> close; // created this so that it displays only About section in console and stops from displaying menu
}

void view::search_posts()
{
  std::vector<user>::iterator it;
  int n = 0;
  std::cout << std::endl;

  //listing all online users whose info can be retrieved and shown
  int on_list_size = static_cast<int> (sys.online_users.size());
  if(on_list_size > 0)
  {
    cout << string(50, '\n');
    std::cout << "\033[1;31m\t\t=============================\033[0m\n";
    std::cout << " " << std::endl;
    std::cout << "\033[1;32m\t\t       INTERESTS\033[0m\n" << std::endl;
    std::cout << "\033[1;31m\t\t=============================\033[0m\n";
    std::cout << "Interests: ";

    std::vector<std::string>::iterator interests_it;
    for(it = sys.online_users.begin(); it != sys.online_users.end(); it++, n++)
    {
  //    std::cout << "(" << n << ") " << it->first_name << " " << it->last_name << std::endl;
      for(interests_it = it->interests.begin(); interests_it != it->interests.end(); interests_it++)
      {
        std::cout << "  -- " <<*interests_it << std::endl;
      }
    }
    std::cout << " " << std::endl;
    std::cout << "\033[1;37mChoose Keyword: \033[0m\n";


    n = 100;
    std::string choice;
    std::cin >> choice;

    for(it = sys.online_users.begin(); it != sys.online_users.end(); it++, n++)
    {
      for(interests_it = it->interests.begin(); interests_it != it->interests.end(); interests_it++)
      {
        if(*interests_it == choice){
        std::cout << " " << endl;
        std::cout << "(" << n << ") " << it->first_name << " " << it->last_name << std::endl;
        std::cout << " " << endl;
      }
    }
  }

  n = 100;
  std::cout << " " << std::endl;
  std::cout << "\033[1;37mSelect User code number: \033[0m\n";
  int opt ;
  std::cin >> opt;

  for(it = sys.online_users.begin(); it != sys.online_users.end(); it++, n++)
  {
  //  for(interests_it = it->interests.begin(); interests_it != it->interests.end(); interests_it++)
  //  {

    //  if(*interests_it == choice){
      if (n == opt){

        std::cout << "\n\033[1;32m\t(1) View Posts\033[0m";
        std::cout << " View user's Posts\n";
        std::cout << "\033[1;32m\t(2) Send Private Message\033[0m";
        std::cout << " Send Private Messages\n";
        std::cout << "\033[1;32m\t(0) Exit\033[0m\n\n";
        std::cout << "\033[1;38mKEY>>  \033[0m";
        cin.ignore();
        int selection;
        std::cin >> selection;
        cout << string(50, '\n');

        if(selection == 1)
        {
          std::cout << "\nPosts: " << std::endl;

          if(it->get_highest_pnum() == 0)
          {
            std::cout << "\033[1;37mEither there are no posts to show right now, or you haven't published request.\033[0m\n" << std::endl;
            std::cout << "\033[1;35m\t\tPLEASE select 2 to \"Publish a Request\" at first.\033[0m\n" << std::endl;
            std::cout << " " << std::endl;
            sleep(1);
          }
          else
          {
            choice = -1;
            std::cout << "\n\033[1;32m\t(0) Exit to main menu\033[0m\n";
            sys.request_all_posts(*it);
            std::cin >> choice;
            //sleep(it->get_highest_pnum());
          }
        }

        if(selection == 2)
        {
          std::cin.ignore();
          sys.send_pm(it->uuid);
        }
            break;
      }
    //  }
      }

      }
      else {
        cout << string(50, '\n');
        std::cout << "\033[1;37m\t\tThere are no users online to show.\033[0m\n" << std::endl;
      }
}
