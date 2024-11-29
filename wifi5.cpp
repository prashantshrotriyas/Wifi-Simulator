#include <iostream>
#include <fstream>
#include "wifi5simulation.h"

using namespace std;

int main()
{
    
    ofstream log_file("simulation_results.log", ios::app);

    if (!log_file.is_open())
    {
        cerr << "Error: Could not open log file.\n";
        return 1;
    }

  
    log_file << "\n--- New Simulation Run for wifi5 ---\n";

    Simulation* wifi5_sim = new WiFi5Simulation(1);
    wifi5_sim->run_simulation();
    log_file << "WiFi5 Simulation (1 User):\n";
    log_file << "Throughput: " << wifi5_sim->calculate_throughput() << " Mbps\n";
    log_file << "Average Latency: " << wifi5_sim->calculate_average_latency() << " microseconds\n";
    log_file << "Max Latency: " << wifi5_sim->calculate_max_latency() << " microseconds\n";
    delete wifi5_sim;

    wifi5_sim = new WiFi5Simulation(10);
    wifi5_sim->run_simulation();
    log_file << "\nWiFi5 Simulation (10 Users):\n";
    log_file << "Throughput: " << wifi5_sim->calculate_throughput() << " Mbps\n";
    log_file << "Average Latency: " << wifi5_sim->calculate_average_latency() << " microseconds\n";
    log_file << "Max Latency: " << wifi5_sim->calculate_max_latency() << " microseconds\n";
    delete wifi5_sim;

    wifi5_sim = new WiFi5Simulation(100);
    wifi5_sim->run_simulation();
    log_file << "\nWiFi5 Simulation (100 Users):\n";
    log_file << "Throughput: " << wifi5_sim->calculate_throughput() << " Mbps\n";
    log_file << "Average Latency: " << wifi5_sim->calculate_average_latency() << " microseconds\n";
    log_file << "Max Latency: " << wifi5_sim->calculate_max_latency() << " microseconds\n";
    delete wifi5_sim;

    log_file.close();
    return 0;
}
