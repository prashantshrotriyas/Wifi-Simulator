#ifndef WIFI5ACCESSPOINT_H
#define WIFI5ACCESSPOINT_H

#include "utility.h"
#include <vector>
#include <string>

using namespace std;

class WiFi5AccessPoint : public AccessPoint
{
public:
    WiFi5AccessPoint(const string& id);

    void broadcast_packet();
    void collect_channel_state_info(vector<User<string>>& users);
    void parallel_transmission(vector<User<string>>& users);
};

#endif
