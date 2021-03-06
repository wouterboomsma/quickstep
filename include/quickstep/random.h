#ifndef QUICKSTEP_RANDOM_H
#define QUICKSTEP_RANDOM_H

#include <random>
#include <functional>

namespace quickstep {

extern std::random_device random_device;
extern std::mt19937 random_number_engine;

static auto normal_distribution = std::bind(std::normal_distribution<>(), std::ref(random_number_engine));
static auto uniform_01_distribution = std::bind(std::uniform_real_distribution<>(), std::ref(random_number_engine));

}

#endif // QUICKSTEP_RANDOM_H
