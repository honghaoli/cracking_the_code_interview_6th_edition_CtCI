//
// Created by Honghao Li on 5/25/17.
//

#ifndef CTCI_6TH_HELPER_H
#define CTCI_6TH_HELPER_H

#include <vector>
#include <iostream>

void print_vector(std::vector<int> &vec) {
  for (auto &v : vec) {
    std::cout << v << ", ";
  }
  std::cout << std::endl;
}

void print_vector2d(std::vector<std::vector<int>> &vec) {
  std::cout << std::endl;
  for (auto &v : vec) {
    print_vector(v);
  }
  std::cout << std::endl;
}


#endif //CTCI_6TH_HELPER_H