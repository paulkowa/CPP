#ifndef A4_HPP
#define A4_HPP

#include "Maze.hpp"
#include <queue>
#include <iostream>
#include <queue>
// implement your function distance


void check(Maze& maze, int x, int y, std::queue<int>& xvalue, std::queue<int>& yvalue) {
	if (maze.is_open(x - 1, y) && !(maze.is_visited(x - 1, y))) {
		xvalue.push(x - 1);
		yvalue.push(y);
		maze.mark(x - 1, y);
	}
	if (maze.is_open(x, y - 1) && !(maze.is_visited(x, y - 1))) {
		xvalue.push(x);
		yvalue.push(y - 1);
		maze.mark(x, y - 1);
	}
	if (maze.is_open(x + 1, y) && !(maze.is_visited(x + 1, y))) {
		xvalue.push(x + 1);
		yvalue.push(y);
		maze.mark(x + 1, y);
	}
	if (maze.is_open(x, y + 1) && !(maze.is_visited(x, y + 1))) {
		xvalue.push(x);
		yvalue.push(y + 1);
		maze.mark(x, y + 1);
	}
}

int search(Maze& maze, int fx, int fy, std::queue<int>& xvalue, std::queue<int>& yvalue, int& length) {
	std::queue<int> xtemp;
	std::queue<int> ytemp;
	if (length == 0) { maze.mark(xvalue.front(), yvalue.front()); }
	while (!(xvalue.empty()) && !(yvalue.empty())) {
		if (xvalue.front() == fx && yvalue.front() == fy) { return length; }
		check(maze, xvalue.front(), yvalue.front(), xtemp, ytemp);
		xvalue.pop();
		yvalue.pop();
	}
	xvalue = xtemp;
	yvalue = ytemp;
	length = length + 1;
	search(maze, fx, fy, xvalue, yvalue, length);

}

int distance(Maze& maze, int sx, int sy, int fx, int fy) {
	std::queue<int> xvalue;
	std::queue<int> yvalue;
	xvalue.push(sx);
	yvalue.push(sy);
	int length = 0;
	search(maze, fx, fy, xvalue, yvalue, length);
	return length;
} // distance


#endif // A4_HPP
