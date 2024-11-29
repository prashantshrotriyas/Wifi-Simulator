#include "multiusersimulation.h"
#include "utility.h"
#include <iostream>
#include <iomanip>

using namespace std;

#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

MultiUserSimulation::MultiUserSimulation(int no_users) : no_users(no_users) {}

void MultiUserSimulation::run_simulation()
{
    AccessPoint ap("AP1");
    ap.add_users(users, no_users);
    cout << endl;
    cout << GREEN << "Starting simulation for " << YELLOW << no_users << GREEN << " users...\n" << RESET;

    for (auto &user : users)
    {
        user.user_transmit_packet_multi(total_transmission, total_latency, max_latency, no_users);
    }
}

float MultiUserSimulation::calculate_throughput()
{
    float throughput = (pac.get_no_packet() * users.size() * 8 * 1024 * pac.get_packet_size()) / total_latency;

    cout << "\n";
    cout << GREEN << "Metric" << RESET << setw(24) << "|  " 
         << YELLOW << "Value" << RESET << "\n";
    cout << "-----------------------------------------\n";

    cout << GREEN << "Throughput" << RESET << setw(20) << "|  " 
         << throughput << " Mbps\n";

    return throughput;
}

float MultiUserSimulation::calculate_average_latency()
{
    float average_latency = total_latency / (pac.get_no_packet() * users.size());

    cout << GREEN << "Average Latency" << RESET << setw(15) << "|  " 
         << average_latency << " us\n";

    return average_latency;
}

float MultiUserSimulation::calculate_max_latency()
{
    cout << GREEN << "Max Latency" << RESET << setw(19) << "|  " 
         << max_latency << " us\n";

    return max_latency;
}
