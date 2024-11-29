#ifndef SINGLEUSER_SIMULATION_H
#define SINGLEUSER_SIMULATION_H

#include "utility.h"
#include <string>

class SingleUserSimulation : public Simulation
{
public:
    void run_simulation() override;
    float calculate_throughput() override;
    float calculate_average_latency() override;
    float calculate_max_latency() override;
};

#endif
