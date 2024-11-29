#include "user.h"
#include "utility.h"
#include <iostream>

using namespace std;

template <typename T>
User<T>::User(T id, int maxm_bt) : user_id(id), maxm_backoff_time(maxm_bt)
{
    reset_backoff();
}

template <typename T>
void User<T>::reset_backoff()
{
    backoff_time = rand() % (maxm_backoff_time + 1);
}

template <typename T>
int User<T>::get_backoff_time()
{
    return backoff_time;
}

template <typename T>
T User<T>::get_user_id()
{
    return user_id;
}

template <typename T>
void User<T>::simulate_random_channel_occupancy(int no_users)
{
    if (no_users == 100)
    {
        if (rand() % 2 == 0)
            chnl.set_channel(false, "RandomUser");
        else
            chnl.set_channel(true);
    }
    else
    {
        if (rand() % 3 == 0)
            chnl.set_channel(false, "RandomUser");
        else
            chnl.set_channel(true);
    }
}

template <typename T>
void User<T>::user_transmit_packet_single(int &total_transmission, float &total_latency, float &max_latency)
{
    pac.set_no_packet(5);
    for (int i = 0; i < pac.get_no_packet(); i++)
    {
        float current_latency = 0;
        while (true)
        {
            if (chnl.isfree())
            {
                chnl.set_channel(false, user_id);
                float transmission_time = 61.5;
                current_latency += transmission_time;
                total_latency += current_latency;
                max_latency = max(max_latency, current_latency);
                total_transmission++;
                chnl.set_channel(true);
                break;
            }
            else
            {
                reset_backoff();
                current_latency += backoff_time;
            }
        }
    }
}

template <typename T>
void User<T>::user_transmit_packet_multi(int &total_transmission, float &total_latency, float &max_latency, int no_users)
{
    for (int i = 0; i < pac.get_no_packet(); i++)
    {
        float current_latency = 0;
        while (true)
        {
            simulate_random_channel_occupancy(no_users);

            if (chnl.isfree())
            {
                chnl.set_channel(false, user_id);
                float transmission_time = 61.5;
                current_latency += transmission_time;
                total_latency += current_latency;
                max_latency = max(max_latency, current_latency);
                total_transmission++;
                chnl.set_channel(true);
                break;
            }
            else
            {
                reset_backoff();
                current_latency += backoff_time;
            }
        }
    }
}

template class User<std::string>;
