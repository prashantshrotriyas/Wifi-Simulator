#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "wifi6_simulation.h"

using namespace std;

int main() {
    srand(time(0));

    ofstream log_file("simulation_results.log", ios::app);

    if (!log_file.is_open()) {
        cerr << "Error: Could not open log file.\n";
        return 1;
    }

     log_file << "\n--- New Simulation Run for wifi6 ---\n";

    int user_counts[] = {1, 10, 100};

    for (int users : user_counts) {
        cout << "\n--- Simulation for " << users << " Users ---\n";

        WiFi6Simulation sim(users);
        sim.run_simulation();

        float throughput = sim.calculate_throughput();
        float avg_latency = sim.calculate_average_latency();
        float max_latency = sim.calculate_max_latency();

        
        log_file << "\n--- Simulation for " << users << " Users ---\n";
        log_file << "Throughput: " << throughput << " Mbps\n";
        log_file << "Average Latency: " << avg_latency << " us\n";
        log_file << "Max Latency: " << max_latency << " us\n";
    }

    log_file.close(); 

    return 0;
}
