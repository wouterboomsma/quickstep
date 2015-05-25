#ifndef QUICKSTEP_RANDOM_H
#define QUICKSTEP_RANDOM_H

#include <random>

namespace quickstep {

std::random_device rd;
std::mt19937 random_number_engine(rd());

auto normal_distribution = std::bind(std::normal_distribution<>(), std::ref(random_number_engine));
auto uniform_01_distribution = std::bind(std::uniform_real_distribution<>(), std::ref(random_number_engine));

}

#endif // QUICKSTEP_RANDOM_H
