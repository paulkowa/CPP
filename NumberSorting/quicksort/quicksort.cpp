// In place Quicksort
// Created: 3/16
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
} // fill_array

void swap(std::vector<int>::iterator left, std::vector<int>::iterator right) {
    int temp = *left;
    *left = *right;
    *right = temp;
} // swap

/**
* Recursive with iterators
**/
void quicksort(std::vector<int>::iterator left, std::vector<int>::iterator right) {
    std::vector<int>::iterator pivot = right;
    std::vector<int>::iterator start = left;
    std::vector<int>::iterator end = right;

    while(left != right) {
        if(right == pivot) {
            if(*left >= *pivot) {
                swap(left, pivot);
                pivot = left;
            }
            else
                left++;
        }

        else {
            if(*right < *pivot) {
                swap(right, pivot);
                pivot = right;
            }
            else
                right--;

        }
    }

    if(pivot != start)
        quicksort(start, pivot - 1);
    if(pivot != end)
        quicksort(pivot + 1, end);

} // quicksort

int main(int argc, char *argv[]){
    std::vector<int> numbers;
    fill_array(numbers);

     for(int i = 0; i < numbers.size(); i++){
        std::cout << numbers[i] << " ";
    } std::cout << std::endl;

    quicksort(numbers.begin(), numbers.end() -1);

    for(int i = 0; i < numbers.size(); i++){
        std::cout << numbers[i] << " ";
    } std::cout << std::endl;

    return 0;

} // main
