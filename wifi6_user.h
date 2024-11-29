#ifndef WIFI6_USER_H
#define WIFI6_USER_H

#include <string>
#include <queue>
#include "wifi6_channel.h"

template <typename T>
class User {
private:
    T user_id;
    int backoff_time;
    int maxm_backoff_time;
    std::queue<int> packets_to_send;
    const int PACKET_SIZE_KB = 1;
    int total_users;

    void simulate_random_channel_occupation(Channel& channel, float& current_latency);

public:
    User(T id, int maxm_bt, int total_users);
    void reset_backoff();
    bool has_packets() const;
    bool transmit_packet(Channel& channel);
    bool transmit_packet_no_collision(Channel& channel, int num_packets, float& throughput);
};

template <typename T>
User<T>::User(T id, int maxm_bt, int total_users) : user_id(id), maxm_backoff_time(maxm_bt), total_users(total_users) {
    reset_backoff();
    for (int i = 0; i < 20; ++i) {
        packets_to_send.push(PACKET_SIZE_KB);
    }
}

template <typename T>
void User<T>::reset_backoff() {
    backoff_time = rand() % (maxm_backoff_time + 1);
}

template <typename T>
bool User<T>::has_packets() const {
    return !packets_to_send.empty();
}

template <typename T>
void User<T>::simulate_random_channel_occupation(Channel& channel, float& current_latency) {
    if (rand() % 10 < 2) {
        channel.set_channel(false, "RandomProcess");
        int random_occupy_time = rand() % 10 + 1;
        current_latency += random_occupy_time;
        channel.update_transmission(random_occupy_time, 0);
        channel.set_channel(true);
    }
}

template <typename T>
bool User<T>::transmit_packet(Channel& channel) {
    if (!has_packets()) return false;

    int packet_size = packets_to_send.front();
    packets_to_send.pop();

    float current_latency = 0;
    float transmission_time = 61.5;

    if (total_users > 1) {
        simulate_random_channel_occupation(channel, current_latency);
    }

    while (true) {
        if (channel.isfree()) {
            channel.set_channel(false, user_id);
            channel.update_transmission(transmission_time, packet_size);
            channel.set_channel(true);
            return true;
        } else {
            reset_backoff();
            current_latency += backoff_time;
        }
    }
}

template <typename T>
bool User<T>::transmit_packet_no_collision(Channel& channel, int num_packets, float& throughput) {
    if (num_packets == 0) return false;

    int total_data_sent = 0;
    float total_time = 0;

    for (int i = 0; i < num_packets; ++i) {
        if (!has_packets()) return false;

        int packet_size = packets_to_send.front();
        packets_to_send.pop();

        float transmission_time = 61.5;

        if (channel.isfree()) {
            channel.set_channel(false, user_id);
            channel.update_transmission(transmission_time, packet_size);
            total_data_sent += packet_size;
            total_time += transmission_time;
            channel.set_channel(true);
        }
    }

    throughput = total_data_sent * 8 * 1024 / total_time;
    return true;
}

#endif // WIFI6_USER_H
