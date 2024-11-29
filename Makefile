wifi4:
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

clean_wifi4:
	rm -f wifi4.o user.o utility.o singleusersimulation.o multiusersimulation.o wifi4_debug wifi4_optimized wifi4_simulation 

wifi5:
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

clean_wifi5:
	rm -f wifi5.o user.o utility.o wifi5simulation.o wifi5accesspoint.o wifi5_debug wifi5_optimized wifi_simulation

wifi6:
	# Compile source files into object files
	g++ -c wifi6.cpp -o wifi6.o
	g++ -c wifi6_channel.cpp -o wifi6_channel.o
	g++ -c wifi6_simulation.cpp -o wifi6_simulation.o

	# Create debug binary
	g++ -g wifi6.o wifi6_channel.o wifi6_simulation.o -o wifi6_debug

	# Create optimized binary
	g++ -O3 wifi6.o wifi6_channel.o wifi6_simulation.o -o wifi6_optimized

clean_wifi6:
	rm -f wifi6.o wifi6_channel.o wifi6_simulation.o wifi6_debug wifi6_optimized wifi6_simulation

clean_all: clean_wifi4 clean_wifi5 clean_wifi6
	rm -f wifi4_debug wifi4_optimized wifi5_debug wifi5_optimized wifi6_debug wifi6_optimized
