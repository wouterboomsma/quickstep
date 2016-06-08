#include "quickstep/random.h"

namespace quickstep {

std::random_device random_device;
std::mt19937 random_number_engine(random_device());

}
