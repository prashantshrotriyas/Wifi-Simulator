#ifndef UTILITY_H
#define UTILITY_H

#include <vector>
#include <string>
#include "user.h" 

class Channel
{
private:
    bool status = true; 
    std::string current_user_id;

public:
    bool isfree();
    void set_channel(bool status, std::string user_id = "");
    std::string get_current_user();
};

class Packet
{
private:
    int packet_size = 1; 
    int no_packet;

public:
    int get_packet_size();
    int get_no_packet();
    void set_packet_size(int packet_Size);
    void set_no_packet(int no_packet);
};

extern Packet pac; 
extern Channel chnl; 

class AccessPoint
{
private:
    std::string accesspoint_id;

public:
    AccessPoint(std::string id);
    
    
    template <typename T>
    void add_users(std::vector<User<T>>& users, int no_users)
    {
        for (int i = 1; i <= no_users; i++)
        {
            users.push_back(User<T>("U" + std::to_string(i), 10)); // Adding users with default max backoff time 10
        }
    }
};

class Simulation
{
protected:
    int total_transmission = 0;
    float total_latency = 0;
    float max_latency = 0;
    std::vector<User<std::string>> users;

public:
    virtual void run_simulation() = 0;
    virtual float calculate_throughput() = 0;
    virtual float calculate_average_latency() = 0;
    virtual float calculate_max_latency() = 0;
};

#endif
