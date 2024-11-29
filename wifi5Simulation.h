#ifndef WIFI5SIMULATION_H
#define WIFI5SIMULATION_H

#include "utility.h"
#include "wifi5accesspoint.h"
#include <vector>
#include <string>

class WiFi5Simulation : public Simulation
{
private:
    WiFi5AccessPoint* access_point;
    int num_users;

public:
    WiFi5Simulation(int num_users); 
    ~WiFi5Simulation();

    void run_simulation() override;
    float calculate_throughput() override;
    float calculate_average_latency() override;
    float calculate_max_latency() override;
};

#endif
