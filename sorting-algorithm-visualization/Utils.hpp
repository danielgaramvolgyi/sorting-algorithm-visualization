#pragma once

#include "SFML/Graphics/Color.hpp"

#include <vector>

namespace utils 
{
    double scaleInterval(double oldMin, double oldMax, double newMin, double newMax, double oldVal);
    int getRandomNumber(int min, int max);
    std::vector<int> generateRandomVector(int size, int min, int max);
    sf::Color intToRGB(int n);

}