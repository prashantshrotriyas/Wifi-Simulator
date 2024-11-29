#include "wifi6_simulation.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <iomanip>  

using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"

WiFi6Simulation::WiFi6Simulation(int no_users) {
    channels.push_back(Channel(2));
    channels.push_back(Channel(4));
    channels.push_back(Channel(10));

    for (int i = 1; i <= no_users; i++) {
        users.push_back(User<string>("U" + to_string(i), 10, no_users));
    }
}

void WiFi6Simulation::run_simulation() {
    for (int current_time = 0; current_time < simulation_time_ms; current_time += channel_allocation_interval_ms) {
        if (users.size() == 1) {
            auto& user = users[0];
            auto& channel = channels[2];
            int num_packets = 20;
            float throughput = 0;
            user.transmit_packet_no_collision(channel, num_packets, throughput);

            // Print results in tabular format for 1 user with color coding
            cout << GREEN << "Simulation Results for 1 User:" << RESET << endl;
            cout << setw(25) << left << "Metric" 
                 << setw(25) << left << "Value" << endl;
            cout << setw(25) << left << "Overall Throughput"
                 << setw(25) << left << GREEN << throughput << " Mbps" << RESET << endl;
            break;
        } else {
            round_robin_channel_allocation();
        }
    }
}

void WiFi6Simulation::round_robin_channel_allocation() {
    for (size_t i = 0; i < users.size(); i++) {
        auto& user = users[i];
        if (user.has_packets()) {
            auto& channel = channels[i % channels.size()];
            user.transmit_packet(channel);
        }
    }
}

float WiFi6Simulation::calculate_throughput() {
    long long total_data_bits = 0;
    for (const auto& channel : channels) {
        total_data_bits += channel.get_total_data_bits();
    }
    float throughput = total_data_bits / (simulation_time_ms * 1000);
    if (users.size() > 1) {
        cout << GREEN << "Simulation Results:" << RESET << endl;
        cout << setw(25) << left << "Metric" 
           <<"                     " << setw(45) << left << "Value" << endl;
        cout << setw(25) << left << "Overall Throughput"
             << setw(25) << left << GREEN << throughput << " Mbps" << RESET << endl;
    }
    return throughput;
}

float WiFi6Simulation::calculate_average_latency() {
    float total_latency = 0;
    int total_transmissions = 0;

    for (const auto& channel : channels) {
        total_latency += channel.get_total_latency();
        total_transmissions += channel.get_total_transmission();
    }

    float average_latency = (total_transmissions > 0) ? (total_latency / total_transmissions) : 0.0f;

    // Print average latency in tabular format with color coding
    cout << setw(25) << left << "Average Latency"
         << setw(25) << left << YELLOW << average_latency << " us" << RESET << endl;
    return average_latency;
}

float WiFi6Simulation::calculate_max_latency() {
    float max_latency = 0;

    for (const auto& channel : channels) {
        max_latency = max(max_latency, channel.get_max_transmission_time());
    }


    cout << setw(25) << left << "Maximum Transmission Time"
         << setw(25) << left << RED << max_latency << " us" << RESET << endl;
    return max_latency;
}
