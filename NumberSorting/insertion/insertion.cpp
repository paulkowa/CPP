// Insertion sort
// Created: 3/14
// Author: Paul Kowalski <paulkowa@buffalo.edu>

#include <iostream>
#include <stdlib.h>
#include <iterator>
#include <vector>

void fill_array(std::vector<int> &input, int seed = 56) {
    srand(seed);
    for(int i = 0; i < 100; i++) {
        input.push_back(rand() % 100);
    }
}

bool is_sorted(std::vector<int> &input) {
    bool sorted = true;
    for(int i = 0; i + 1 < input.size(); i++) {
        if(input[i] > input[i + 1]) {
            sorted = false;
            break;
        }
    }

    return sorted;
}

void insertion_sort(std::vector<int> &input) {
    std::vector<int>::iterator it = input.begin() + 1;
    std::vector<int>::iterator cur = input.begin() + 1;

    while(!is_sorted(input)) {
        while(it != input.begin() && *it < *(it - 1)) {
            int temp = *it;
            *it = *(it - 1);
            *(it - 1) = temp;
            it--;
        }
        cur++;
        it = cur;
    }
}

int main(int argc, char *argv[]){
    std::vector<int> numbers;
    fill_array(numbers);

     for(int i = 0; i < numbers.size(); i++){
        std::cout << numbers[i] << " ";
    } std::cout << std::endl;

    insertion_sort(numbers);

    for(int i = 0; i < numbers.size(); i++){
        std::cout << numbers[i] << " ";
    } std::cout << std::endl;

    return 0;

}
