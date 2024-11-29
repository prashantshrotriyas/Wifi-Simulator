
# WiFi Communication Simulator

## Project Overview

This project simulates WiFi communication across three WiFi standards: WiFi 4, WiFi 5, and WiFi 6. The simulator uses object-oriented features such as inheritance, data abstraction, data hiding, and polymorphism. The goal of the project is to design a simple WiFi simulator that mimics the communication processes in WiFi 4, WiFi 5, and WiFi 6.

### Features

- Simulates communication between users and an access point (AP).
- Calculates throughput, average latency, and maximum latency for different WiFi standards.
- Uses channel sniffing, backoff times, and different communication protocols such as MIMO (WiFi 5) and OFDMA (WiFi 6).
- Handles single-user and multi-user communication scenarios.

---

## Simulation Details

1. **WiFi 4 Communication:**
   - Transmission happens via a single access point and a set of users.
   - Channel sniffing and backoff are implemented for transmission if the channel is not free.
   - The simulation calculates throughput, average, and maximum latency for scenarios with 1 user, 10 users, and 100 users.

2. **WiFi 5 Communication:**
   - Multi-user MIMO allows parallel communication after a broadcast packet is sent by the access point.
   - Each user sends a channel state packet before parallel communication starts.
   - Throughput, average latency, and maximum latency are calculated for different user scenarios.

3. **WiFi 6 Communication:**
   - OFDMA allows communication in parallel over sub-channels (2 MHz, 4 MHz, 10 MHz).
   - Channel allocation happens every 5ms, with round-robin scheduling.
   - The simulation calculates throughput, average, and maximum latency for various user scenarios.

---

## Building and Compilation Instructions

### WiFi 4

To compile WiFi 4 source files:

```bash
# Compile source files into object files
g++ -c wifi4.cpp -o wifi4.o
g++ -c user.cpp -o user.o
g++ -c utility.cpp -o utility.o
g++ -c singleusersimulation.cpp -o singleusersimulation.o
g++ -c multiusersimulation.cpp -o multiusersimulation.o

# Create debug binary
g++ -g wifi4.o user.o utility.o singleusersimulation.o multiusersimulation.o -o wifi4_debug

# Create optimized binary
g++ -O3 wifi4.o user.o utility.o singleusersimulation.o multiusersimulation.o -o wifi4_optimized
```

To clean up WiFi 4 compilation files:

```bash
rm -f wifi4.o user.o utility.o singleusersimulation.o multiusersimulation.o wifi4_debug wifi4_optimized wifi4_simulation
```

### WiFi 5

To compile WiFi 5 source files:

```bash
# Compile source files into object files
g++ -c wifi5.cpp -o wifi5.o
g++ -c user.cpp -o user.o
g++ -c utility.cpp -o utility.o
g++ -c wifi5simulation.cpp -o wifi5simulation.o
g++ -c wifi5accesspoint.cpp -o wifi5accesspoint.o

# Create debug binary
g++ -g wifi5.o user.o utility.o wifi5simulation.o wifi5accesspoint.o -o wifi5_debug

# Create optimized binary
g++ -O3 wifi5.o user.o utility.o wifi5simulation.o wifi5accesspoint.o -o wifi5_optimized
```

To clean up WiFi 5 compilation files:

```bash
rm -f wifi5.o user.o utility.o wifi5simulation.o wifi5accesspoint.o wifi5_debug wifi5_optimized wifi_simulation
```

### WiFi 6

To compile WiFi 6 source files:

```bash
# Compile source files into object files
g++ -c wifi6.cpp -o wifi6.o
g++ -c wifi6_channel.cpp -o wifi6_channel.o
g++ -c wifi6_simulation.cpp -o wifi6_simulation.o

# Create debug binary
g++ -g wifi6.o wifi6_channel.o wifi6_simulation.o -o wifi6_debug

# Create optimized binary
g++ -O3 wifi6.o wifi6_channel.o wifi6_simulation.o -o wifi6_optimized
```

To clean up WiFi 6 compilation files:

```bash
rm -f wifi6.o wifi6_channel.o wifi6_simulation.o wifi6_debug wifi6_optimized wifi6_simulation
```

### Clean All

To clean all compilation files from WiFi 4, WiFi 5, and WiFi 6:

```bash
rm -f wifi4.o user.o utility.o singleusersimulation.o multiusersimulation.o wifi4_debug wifi4_optimized wifi5.o user.o utility.o wifi5simulation.o wifi5accesspoint.o wifi5_debug wifi5_optimized wifi6.o wifi6_channel.o wifi6_simulation.o wifi6_debug wifi6_optimized wifi6_simulation
```

---

## Input File Format

The simulator assumes the following input for communication parameters:

1. **User Count:** Number of users (1, 10, 100).
2. **Packet Size:** Each packet is assumed to be 1 KB.
3. **Simulation Time:** Total time for the simulation in milliseconds.
4. **Channel Allocation:** The WiFi 6 simulation allocates the channel in blocks of 2 MHz, 4 MHz, or 10 MHz.
5. **Modulation and Coding:** 256-QAM with a coding rate of 5/6 is used for transmission.
6. **WiFi Standards:** Choose WiFi 4, WiFi 5, or WiFi 6 to run the respective simulation.

---

## References
Google and some AI tools

