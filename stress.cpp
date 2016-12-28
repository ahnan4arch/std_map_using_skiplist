#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>
#include <random>
#include <chrono>
#include <iterator>
#include <cassert>
#include "Map.hpp"

using namespace cs540;
void stress(int stress_size) {
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine gen(seed);
    std::uniform_int_distribution<unsigned int> dist(0, 10000);
    
    cs540::Map<int, int> m;
    
    for(int i = 0; i < stress_size; ++i) {
        auto g = dist(gen);
        m.insert({g, g});
    }
    auto it=m.begin();
    it++;
    std::cout<< it.pos->key<<"----->"<<it.pos->value<<std::endl;
    auto it1=m.end();
    it1--;
    it1--;
    std::cout<< it1.pos->key<<"----->"<<it1.pos->value<<std::endl;
    
    int num_erases = gen() % m.size();
    for(int i = 0; i < num_erases; ++i) {
        //select a random element
        int choice = gen() % m.size();
        auto iter = std::begin(m);
        for (int j = 0; j < choice; ++j) {
            ++iter;
        }
        
        m.erase(iter);
    }
    
}


// creates a mapping from the values in the range [low, high) to their cubes
cs540::Map<int, int> cubes(int low, int high) {
    cs540::Map<int, int> cb;
    for (int i = low; i < high; ++i) {
        cb.insert({i, i*i*i});
    }

    return cb;
}


int main () {

    // constructors and assignment examples:
    // initializer_list example
    cs540::Map<int, double> int_double_map {{1, 1.0}, {3, 5.67}, {13, 6.9}};

    // must support copy construction
    cs540::Map<int, double> copy_example{int_double_map};

    cs540::Map<int, double> assign_example;
    // must support copy assignment
    assign_example = copy_example;

    stress(10000);

    return 0;
}