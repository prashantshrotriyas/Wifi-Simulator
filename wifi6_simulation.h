#ifndef WIFI6_SIMULATION_H
#define WIFI6_SIMULATION_H

#include <vector>
#include <string>
#include "wifi6_channel.h"
#include "wifi6_user.h"

class WiFi6Simulation {
private:
    std::vector<User<std::string>> users;
    std::vector<Channel> channels;
    int simulation_time_ms = 100; 
    int channel_allocation_interval_ms = 5; 

public:
  WiFi6Simulation(int no_users);  
    void run_simulation();
    void round_robin_channel_allocation();
    float calculate_throughput();
    float calculate_average_latency();
    float calculate_max_latency();
};

#endif