#ifndef USER_H
#define USER_H

#include <string>

template <typename T>
class User
{
private:
    T user_id;
    int backoff_time;
    int maxm_backoff_time;

public:
    User(T id, int maxm_bt);
    void reset_backoff();
    int get_backoff_time();
    T get_user_id();
    void user_transmit_packet_single(int& total_transmission, float& total_latency, float& max_latency);
    void user_transmit_packet_multi(int& total_transmission, float& total_latency, float& max_latency, int no_users);
    void simulate_random_channel_occupancy(int no_users);
};

#endif
