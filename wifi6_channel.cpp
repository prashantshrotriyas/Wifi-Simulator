#include "wifi6_channel.h"
#include <algorithm>

using namespace std;

Channel::Channel(int width) : channel_width(width) {}

bool Channel::isfree() {
    return status;
}

int Channel::get_channel_width() const {
    return channel_width;
}

void Channel::set_channel(bool status, std::string user_id, int width) {
    this->status = status;
    this->current_user_id = user_id;
    if (width > 0) this->channel_width = width;
}

void Channel::update_transmission(float transmission_time, int packet_size_kb) {
    total_transmission++;
    
    long long packet_bits = packet_size_kb * 8192;
    total_data_bits += packet_bits;

    total_latency += transmission_time;

 
    max_transmission_time = max(max_transmission_time, transmission_time);
}

int Channel::get_total_transmission() const {
    return total_transmission;
}

long long Channel::get_total_data_bits() const {
    return total_data_bits;
}

float Channel::get_total_latency() const {
    return total_latency;
}

float Channel::get_max_transmission_time() const {
    return max_transmission_time;
}