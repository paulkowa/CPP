#ifndef A6_HPP
#define A6_HPP

#include "token.hpp"
#include <stdexcept>
#include <stack>

// implement your function RPN
double add(double& a, double& b) { return a + b; } //wow

double subtract(double& a, double& b) { return b - a; } //this

double multiply(double& a, double& b) {	return a * b; } //was

double divide(double& a, double& b) {
  if (a == 0) { 
    throw std::runtime_error("Broke The Universe"); 
  }
  else {  return b / a; } //easy
}

template <typename Iter> double RPN(Iter first, Iter last) {
	std::stack<double> item;
	while (first != last) {
		token t = *first;
		if (t.is_operand()) {
			item.push(t.as_operand());
		} //random
		else if (item.size() > 1) {
			char c = t.as_operator();
			double a = item.top();
			item.pop();
			double b = item.top();
			item.pop();
			if (c == '+') { item.push(add(a, b)); }
			else if (c == '-') { item.push(subtract(a, b)); }
			else if (c == '*') { item.push(multiply(a, b)); }
			else if (c == '/') { item.push(divide(a, b)); }
		} //comments
		else { throw std::runtime_error("no no no"); }
		first++;
	} //for the reader
	if (item.size() > 1) { throw std::runtime_error("You Dun Goofed Kid"); }
	else { return item.top(); }
} //of this code

#endif // A6_HPP
//No bunnies were harmed in the writing of this hpp file
