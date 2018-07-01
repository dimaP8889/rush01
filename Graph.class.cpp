/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graph.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 20:07:35 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/06/30 20:07:35 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Graph.class.hpp"

//-------------------------------Constructors------------------------------

Graph::Graph() : _width(40), _height(15), _mass_size(10) {

	_name = "String";
	_mass = NULL;
	_num = 0;
}

Graph::Graph(Graph & copy) : _width(40), _height(15), _mass_size(10) {

	*this = copy;
}

//--------------------------------Destructor-------------------------------

Graph::~Graph() {

}

//---------------------------------Operator--------------------------------

Graph &				Graph::operator=(Graph & copy) {

	_name = copy.getName();
	_mass = copy.getMass();
	return (*this);
}

//---------------------------------Getters---------------------------------

std::string			Graph::getName() const{

	return(_name);
}

double *			Graph::getMass() const{

	return(_mass);
}

int					Graph::getNum() const{

	return(_num);
}

int					Graph::getHeight() const{

	return(_height);
}

int					Graph::getWidth() const{

	return(_width);
}

int					Graph::getMassSize() const{

	return(_mass_size);
}

//---------------------------------Setters---------------------------------

void				Graph::setName(std::string name) {

	_name = name;
}

void				Graph::setMass(double * mass) {

	_mass = mass;
}

void				Graph::setParams(double * mass, std::string name, int num) {

	_mass = mass;
	_name = name;
	_num = num;
}

//--------------------------------Screen-----------------------------------

void	Graph::setScreen(Graph * graph) {

	initscr();
	cbreak();
	noecho();

	int hei, width, start_y = 0, start_x = 0;

	hei = getHeight() * 2 + 1;
	width = getWidth() * 2 + 1;

	WINDOW * win = newwin(hei, width, start_y, start_x);
	keypad(win, true);
	refresh();

	wborder(win, 32, 32, 32, 32, 32, 32, 32, 32);
	wrefresh(win);

	graph[0].makeGraph();
	graph[1].makeGraph();
	// graph[2].makeGraph();
	// graph[3].makeGraph();
	flushinp();
	delay_output(300);
	nodelay(win, true);
	int c = wgetch(win);
	if (c == 27) {

		std::cout << "LOL";
		exit(1);
	}
	wrefresh(win);
	clear();
	endwin();
}

//-------------------------------MakeGraph---------------------------------

void	Graph::print_graph(WINDOW * graph) {

	double 	max = find_max(getMass());
	double 	min = find_min(getMass());
	double 	move = (max - min + 1) / 10;
	int 	iter = 10;

	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);

	wattron(graph, COLOR_PAIR(1));
	for (int coun = 0; coun < 10; coun++) {

		iter = 10;
		for (double mv = min; mv <= getMass()[coun]; mv += move) {

			mvwprintw(graph, iter, 3 * coun + 1, "|");
			iter--;
			if (iter <= 0)
				break;
		}
	}
	wattroff(graph, COLOR_PAIR(1));
}

void	Graph::make_graph(WINDOW * win) {

	double 	max = find_max(getMass());
	double 	min = find_min(getMass());

	mvwprintw(win, 3, 1, "%f", max);
	mvwprintw(win, 12, 1, "%f", min);

	for (int coun = 0; coun < getMassSize(); coun++) {

		mvwprintw(win, 13, coun + 5 + 2 * coun," %i", coun);
	}
	wrefresh(win);

	int hei = 11;
	int width = 30;

	int start_x = getNum() % 3 * getWidth() + 5;
	int start_y = getNum() / 3 * getHeight() + 2;
	WINDOW *graph = newwin(hei, width, start_y, start_x);
	refresh();
	wborder(graph, 32, 32, 32, 32, 32, 32, 32, 32);
	wrefresh(graph);
	print_graph(graph);
	wrefresh(graph);

}

void				Graph::makeGraph() {

	int hei, width, start_y, start_x;

	hei = getHeight();
	width = getWidth();

	start_x = getNum() % 3 * getWidth();
	start_y = getNum() / 3 * getHeight();

	WINDOW * win = newwin(hei, width, start_y, start_x);
	refresh();

	mvwprintw(win, 1, 6, "%s", getName().c_str());
	box(win, 0, 0);
	wrefresh(win);

	make_graph(win);

	refresh();
}


//--------------------------------Min&Max----------------------------------

double 	find_min(double * mass) {

	double min = mass[0];

	for (int coun = 1; coun < 10; coun++) {

		if (min > mass[coun])
			min = mass[coun];
	}
	return (min);
}

double 	find_max(double * mass) {

	double max = mass[0];

	for (int coun = 1; coun < 10; coun++) {

		if (max < mass[coun])
			max = mass[coun];
	}
	return (max);
}
