#include "wifi5simulation.h"
#include <iostream>
#include <iomanip>

using namespace std;

#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

WiFi5Simulation::WiFi5Simulation(int num_users)
{
    this->num_users = num_users;
    access_point = new WiFi5AccessPoint("WiFi5-AP");
    pac.set_packet_size(1);
    access_point->add_users(users, num_users);
    
    cout << endl;
    cout << YELLOW << "WiFi5 Simulation initialized with " << num_users << " users.\n" << RESET;
}

WiFi5Simulation::~WiFi5Simulation()
{
    delete access_point;
}

void WiFi5Simulation::run_simulation()
{
    cout << GREEN << "WiFi5 Simulation started.\n" << RESET;
    cout << endl;
    int total_simulation_time_ms = 100;
    float transmission_time_1KB_us = 61.5;
    float elapsed_time_ms = 0;

    while (elapsed_time_ms < total_simulation_time_ms)
    {
        float broadcast_time_us = transmission_time_1KB_us;
        access_point->broadcast_packet();

        float csi_packet_size_kb = 200.0 / 1024;
        float csi_time_per_user_us = csi_packet_size_kb * transmission_time_1KB_us;
        float total_csi_time_us = csi_time_per_user_us * num_users;
        access_point->collect_channel_state_info(users);

        float parallel_transmission_time_ms = 15;
        access_point->parallel_transmission(users);

        float parallel_transmission_time_us = parallel_transmission_time_ms * 1000.0;
        float packets_per_user = parallel_transmission_time_us / transmission_time_1KB_us;
        float total_packets_sent = packets_per_user;

        float total_overhead_time_us = broadcast_time_us + total_csi_time_us;
        float total_time_us = total_overhead_time_us + parallel_transmission_time_us;

        total_transmission += total_packets_sent;
        total_latency += total_time_us;

        elapsed_time_ms += (total_time_us / 1000.0);
    }
}

float WiFi5Simulation::calculate_throughput()
{
    float data_transmitted_bits = total_transmission * pac.get_packet_size() * 8 * 1024;
    float throughput_mbps = (data_transmitted_bits / total_latency);

    cout << "\n";
    cout << GREEN << "Metric" << RESET << setw(34) << "|  "
         << YELLOW << "Value" << RESET << endl;
    cout << string(70, '-') << endl;

    cout << GREEN  << "Throughput" << RESET << setw(30) << "|  "
         << throughput_mbps << " Mbps" << endl;

    return throughput_mbps;
}

float WiFi5Simulation::calculate_average_latency()
{
    float avg_latency = total_latency / total_transmission;

    cout << GREEN  << "Average Latency" << RESET << setw(25) << "|  "
         << avg_latency << " microseconds" << endl;

    return avg_latency;
}

float WiFi5Simulation::calculate_max_latency()
{
    float maximum_latency = total_latency / total_transmission;

    cout << GREEN  << "Maximum Latency" << RESET << setw(25) << "|  "
         << maximum_latency << " microseconds" << endl;

    return maximum_latency;
}
