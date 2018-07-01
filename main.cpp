# include "Graph.class.hpp"

int 	main() {

	double *	mass = new double[10];
	double *	mass1 = new double[10];
	std::string name = "functioan";

	mass[0] = 72.95;
	mass[1] = 22.015;
	mass[2] = 3.4747;
	mass[3] = 42.3848;
	mass[4] = 5.47478;
	mass[5] = 20.386535;
	mass[6] = 7.12423637;
	mass[7] = 84.4647;
	mass[8] = 98.497479;
	mass[9] = 12;

	mass1[0] = 1;
	mass1[1] = 5;
	mass1[2] = 3;
	mass1[3] = 2;
	mass1[4] = 6;
	mass1[5] = 9;
	mass1[6] = 7;
	mass1[7] = 8;
	mass1[8] = 4;
	mass1[9] = 10;

	Graph * graph = new Graph[2];
	Graph * graph1 = new Graph[2];
	graph[0].setParams(mass1, name, 0);
	graph[1].setParams(mass1, name, 1);

	graph1[0].setParams(mass, name, 0);
	graph1[1].setParams(mass, name, 1);

	while (1) {
		graph1[0].setScreen(graph1);
		graph[0].setScreen(graph);
		graph[0].setScreen(graph);
	}

}
