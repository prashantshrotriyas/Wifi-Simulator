#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "singleusersimulation.h"
#include "multiusersimulation.h"

using namespace std; // Use the std namespace

int main()
{
    srand(time(0));
    ofstream log_file("simulation_results.log", ios::app);

    if (!log_file.is_open())
    {
        cerr << "Error: Could not open log file.\n";
        return 1;
    }


    log_file << "\n--- New Simulation Run for wifi4 ---\n";

    Simulation *sim = new SingleUserSimulation();
    sim->run_simulation();
    log_file << "Single User Simulation:\n";
    log_file << "Throughput: " << sim->calculate_throughput() << " Mbps\n";
    log_file << "Average Latency: " << sim->calculate_average_latency() << " us\n";
    log_file << "Max Latency: " << sim->calculate_max_latency() << " us\n";
    delete sim;

    sim = new MultiUserSimulation(10);
    sim->run_simulation();
    log_file << "\nMulti-User Simulation (10 Users):\n";
    log_file << "Throughput: " << sim->calculate_throughput() << " Mbps\n";
    log_file << "Average Latency: " << sim->calculate_average_latency() << " us\n";
    log_file << "Max Latency: " << sim->calculate_max_latency() << " us\n";
    delete sim;

    sim = new MultiUserSimulation(100);
    sim->run_simulation();
    log_file << "\nMulti-User Simulation (100 Users):\n";
    log_file << "Throughput: " << sim->calculate_throughput() << " Mbps\n";
    log_file << "Average Latency: " << sim->calculate_average_latency() << " us\n";
    log_file << "Max Latency: " << sim->calculate_max_latency() << " us\n";
    delete sim;

    log_file.close();
    return 0;
}
