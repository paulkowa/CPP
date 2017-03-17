// Merge sort
// Created: 3/14
// Author: Paul Kowalski <paulkowa@buffalo.edu>

#include <iostream>
#include <stdlib.h>
#include <iterator>
#include <vector>


void fill_array(std::vector<int> &input, int seed = 56) {
    srand(seed);
    for(int i = 0; i < 10; i++) {
        input.push_back(rand() % 100);
    }
}

// With Iterators
void merge(std::vector<int> &left, std::vector<int> &right, std::vector<int> &input) {
    std::vector<int>::iterator l = left.begin();
    std::vector<int>::iterator r = right.begin();
    std::vector<int>::iterator i = input.begin();

    while(l != left.end() && r != right.end()) {
        if(*l < *r) {
            *i = *l;
            i++;
            l++;
        }

        else{
            *i = *r;
            i++;
            r++;
        }
    }
        while(l != left.end()) {
            *i = *l;
            i++;
            l++;
        }

        while(r != right.end()) {
            *i = *r;
            i++;
            r++;
        } 
} // merge

// With indices
/**
void merge(std::vector<int> &left, std::vector<int> &right, std::vector<int> &input) {
    int l = 0, r = 0, i = 0;

    while(l < left.size() && r < right.size()) {
        if(left[l] < right[r])
            input[i++] = left[l++];

        else
            input[i++] = right[r++];
    }

        while(l < left.size())
            input[i++] = left[l++];

        while(r < right.size())
            input[i++] = right[r++];
} // merge
**/

void merge_sort(std::vector<int> &input) {
    // Exit if array contains only one element
    if (input.size() < 2)
        return;

    // Find mid point
    int mid = input.size() / 2;
    std::vector<int> left;
    std::vector<int> right;

    // Create left and right segments
    for(int l = 0; l < mid; l++)
        left.push_back(input[l]);

    for(int r = mid; r < input.size(); r++)
        right.push_back(input[r]);

    // Merge vectors into sorted list
    merge_sort(left);
    merge_sort(right);
    merge(left, right, input);
} // merge_sort

int main(int argc, char *argv[]){
    std::vector<int> numbers;
    fill_array(numbers);

     for(int i = 0; i < numbers.size(); i++){
        std::cout << numbers[i] << " ";
    } std::cout << std::endl;

    merge_sort(numbers);

    for(int i = 0; i < numbers.size(); i++){
        std::cout << numbers[i] << " ";
    } std::cout << std::endl;

    return 0;

} // main
