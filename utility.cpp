#include "utility.h"
#include "user.h"  

Packet pac;  
Channel chnl;  

bool Channel::isfree()
{
    return status;
}

void Channel::set_channel(bool status, std::string user_id)
{
    this->status = status;
    this->current_user_id = user_id;
}

std::string Channel::get_current_user()
{
    return current_user_id;
}

int Packet::get_packet_size()
{
    return packet_size;
}

int Packet::get_no_packet()
{
    return no_packet;
}

void Packet::set_packet_size(int packet_Size)
{
    this->packet_size = packet_Size;
}

void Packet::set_no_packet(int no_packet)
{
    this->no_packet = no_packet;
}

AccessPoint::AccessPoint(std::string id) : accesspoint_id(id) {}


