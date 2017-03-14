// Bubble sort and Bi-Directional Bubble sort
//

#include <iostream>
#include <stdlib.h>
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

void bubble_sort(std::vector<int> &input) {
    int k = input.size();

    while(!is_sorted(input)) {
        for(int i = 0; i + 1 < k; i++) {
            if(input[i] > input[i + 1]){
                int temp = input[i + 1];
                input[i + 1] = input[i];
                input[i] = temp;
            }
        }
        k--;
    }
}

void bi_dir_bubble(std::vector<int> &input) {
    int k = input.size();
    int s = 0;

    while(!is_sorted(input)) {
        for(int i = 0; i + 1 < k; i++) {
            if(input[i] > input[i + 1]){
                int temp = input[i + 1];
                input[i + 1] = input[i];
                input[i] = temp;
            }
        }

        for(int i = input.size() - 1; i - 1 > s; i--) {
            if(input[i] < input[i - 1]){
                int temp = input[i - 1];
                input[i - 1] = input[i];
                input[i] = temp;
            }
        }

        k--;
        s++;
    }
}

int main(int argc, char *argv[]){
    std::vector<int> numbers;
    fill_array(numbers);

     for(int i = 0; i < numbers.size(); i++){
        std::cout << numbers[i] << " ";
    } std::cout << std::endl;

    // bubble_sort(numbers);
    bi_dir_bubble(numbers);

    for(int i = 0; i < numbers.size(); i++){
        std::cout << numbers[i] << " ";
    } std::cout << std::endl;

    return 0;

}
