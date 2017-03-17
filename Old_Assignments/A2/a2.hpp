// a2.hpp

#ifndef A2_HPP
#define A2_HPP

#include <algorithm> // for copy
#include <vector>

	class A2 {;
	public:
		
		explicit A2() {
			matrix.resize(0);
		} // A2

		A2(int r, int c)  {
			row = r;
			column = c;
			matrix.resize(r * c);

		} //A2 override

		double& operator()(const int row, const int col) {
			return matrix[row * column + col];
		} // operator()
		
		double operator()(const int row, const int col) const{
			return matrix[row * column + col];
		} // operator()

		~A2() { }

		int size() const { return matrix.size(); }

	//	const A2& operator[](int n) { return matrix[n]; }

	//	const A2& operator[](int n) const { return matrix[n]; }

		int rsum(int r) {
			int sum = 0;
			for (int i = 0; i < column; i++) {
				sum = matrix[r * column + i] + sum;
			}
			return sum;
		}

		int csum(int c) {
			int sum = 0;
			for (int i = 0; i < row; i++) {
				sum = matrix[i * column + c];
			}
			return sum;
		}

	private:
		std::vector<double> matrix;
		int row;
		int column;

	}; // class a2

#endif // A2_HPP
