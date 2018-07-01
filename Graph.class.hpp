/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graph.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 20:07:35 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/06/30 20:07:35 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_CLASS_H
# define GRAPH_CLASS_H

# include <ncurses.h>
# include <iostream>
# include <string>
# include <string>

class Graph
{

	const int	_width;
	const int	_height;
	const int	_mass_size;

	double	*	_mass;
	std::string	_name;
	int			_num;
public:
	Graph();
	Graph(Graph & copy);
	~Graph();

Graph &		operator=(Graph & copy);

std::string	getName() const;
double *		getMass() const;
int			getHeight() const;
int			getWidth() const;
int			getNum() const;
int			getMassSize() const;

void		setName(std::string name);
void		setParams(double * mass, std::string name, int num);
void		setMass(double * mass);
void		setScreen(Graph * graph);

void		print_graph(WINDOW * graph);
void		make_graph(WINDOW * win);

void		makeGraph();

private:

};

double 		find_min(double * mass);
double 		find_max(double * mass);

#endif
