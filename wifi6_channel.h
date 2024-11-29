#ifndef CHANNEL_H
#define CHANNEL_H

#include <string>

class Channel {
private:
    bool status = true; 
    std::string current_user_id;
    int channel_width; 
    int total_transmission = 0;
    long long total_data_bits = 0;
    float total_latency = 0;
    float max_transmission_time = 0;

public:
    Channel(int width);

    bool isfree();
    int get_channel_width() const;
    void set_channel(bool status, std::string user_id = "", int width = 0);
    void update_transmission(float transmission_time, int packet_size_kb);

    int get_total_transmission() const;
    long long get_total_data_bits() const;
    float get_total_latency() const;
    float get_max_transmission_time() const;
};

#endif
