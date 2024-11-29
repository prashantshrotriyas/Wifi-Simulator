#ifndef MULTIUSER_SIMULATION_H
#define MULTIUSER_SIMULATION_H

#include "utility.h"
#include <vector>

class MultiUserSimulation : public Simulation
{
private:
    int no_users;

public:
    MultiUserSimulation(int no_users);
    void run_simulation() override;
    float calculate_throughput() override;
    float calculate_average_latency() override;
    float calculate_max_latency() override;
};

#endif
