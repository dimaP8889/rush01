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

	int	*		_mass;
	std::string	_name;
	int			_num;
public:
	Graph();
	Graph(Graph & copy);
	~Graph();

Graph &		operator=(Graph & copy);

std::string	getName() const;
int *		getMass() const;
int			getHeight() const;
int			getWidth() const;
int			getNum() const;
int			getMassSize() const;

void		setName(std::string name);
void		setParams(int * int_ar, std::string name, int num);
void		setMass(int * mass);

void		print_graph(WINDOW * graph);
void		make_graph(WINDOW * win);

void		makeGraph();

private:

};

int 	find_min(int * mass);
int 	find_max(int * mass);

#endif
