#include "singleusersimulation.h"
#include "utility.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

void SingleUserSimulation::run_simulation()
{
    AccessPoint ap("AP1");
    ap.add_users(users, 1);
    cout << GREEN << "Starting simulation for " << YELLOW << "1 User" << GREEN << "...\n" << RESET;
    users[0].user_transmit_packet_single(total_transmission, total_latency, max_latency);
}

float SingleUserSimulation::calculate_throughput()
{
    float throughput = (pac.get_no_packet() * 8 * 1024 * pac.get_packet_size()) / total_latency;

    cout << "\n";
    cout << GREEN << "Metric" << RESET << setw(24) << "|  " 
         << YELLOW << "Value" << RESET << "\n";
    cout << "-----------------------------------------\n";
    cout << GREEN << "Throughput" << RESET << setw(20) << "|  " 
         << throughput << " Mbps\n";

    return throughput;
}

float SingleUserSimulation::calculate_average_latency()
{
    float average_latency = total_latency / pac.get_no_packet();
    
    cout << GREEN << "Average Latency" << RESET << setw(15) << "|  " 
         << average_latency << " us\n";

    return average_latency;
}

float SingleUserSimulation::calculate_max_latency()
{
    cout << GREEN << "Max Latency" << RESET << setw(19) << "|  " 
         << max_latency << " us\n";

    return max_latency;
}
