# include "Graph.class.hpp"

int 	main() {

	int *	mass = new int[10];
	int *	mass1 = new int[10];
	std::string name = "functioan";
	initscr();
	cbreak();
	noecho();

	mass[0] = 1;
	mass[1] = 2;
	mass[2] = 3;
	mass[3] = 4;
	mass[4] = 5;
	mass[5] = 20;
	mass[6] = 7;
	mass[7] = 84;
	mass[8] = 9;
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

	Graph * graph = new Graph[4];
	graph[0].setParams(mass, name, 0);
	graph[1].setParams(mass1, name, 1);
	graph[2].setParams(mass1, name, 2);
	graph[3].setParams(mass, name, 3);
	graph[0].makeGraph();
	graph[1].makeGraph();
	graph[2].makeGraph();
	graph[3].makeGraph();


	getch();
	endwin();
}
