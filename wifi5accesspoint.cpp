#include "wifi5accesspoint.h"
#include <iostream>

using namespace std;

#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

WiFi5AccessPoint::WiFi5AccessPoint(const string& id) : AccessPoint(id) {}

void WiFi5AccessPoint::broadcast_packet()
{
  cout << GREEN << "Access Point broadcasting packet to all users..." << RESET << endl;
}

void WiFi5AccessPoint::collect_channel_state_info(vector<User<string>>& users)
{
  cout << YELLOW << "Received Channel state information from all users" << RESET << endl;
}

void WiFi5AccessPoint::parallel_transmission(vector<User<string>>& users)
{
   cout << GREEN << "Parallel transmission for 15ms completed for all users" << RESET << endl << endl;
}
