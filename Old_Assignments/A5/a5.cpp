// a5b.cpp : Defines the entry point for the console application.
//


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]) {
	if (argc != 2) { std::cout << "error"; }
	else{
		std::ifstream file(argv[1]);
		if (!file.is_open()) { std::cout << "error"; }
		else{
			std::vector<int> numbers;
			int min = -1;
			int max = -1;
			int current = 0;
			bool fline = true;
			while (file) {
				file >> current;
				if (file.eof()) { break; }
				if (fline) {
					min = current;
					fline = false;
				} //if (fline)
				if (current > max) { max = current; }
				if (current < min) { min = current; }
				numbers.push_back(current);
			} //while (file)
			int size = ((numbers.size() - 1) / 2);
			std::nth_element(numbers.begin(), numbers.end() - 2, numbers.end());
			std::cout << min << " " << (*(numbers.end() - 2)) << " " << max << std::endl;
		} // else (is_open)
	} // else (has_file)
	return 0;
}

