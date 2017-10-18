#include "Utils.hpp"

#include <random>

double utils::scaleInterval(double oldMin, double oldMax, double newMin, double newMax, double oldVal)
{
    double scalingFactor = (newMax - newMin) / (oldMax - oldMin);
    return (oldVal - oldMin)*scalingFactor + newMin;
}

int utils::getRandomNumber(int min, int max) 
{
    static std::random_device seeder;
    static std::mt19937 engine(seeder());

    static std::uniform_int_distribution<> dist{ min,max };

    return dist(engine);
}

std::vector<int> utils::generateRandomVector(int size, int min, int max) 
{
    std::vector<int> result(size);
    for (int& n : result) {
        n = utils::getRandomNumber(min, max);
    }
    return result;
}

// Cycles through colors, red to green to blue to red, for i = 0 ... 6*256
sf::Color utils::intToRGB(int n) {
    sf::Color result;
    if (n < 256) {
        result.r = 255;
        result.g = n;
        result.b = 0;
    }
    else if (n < 2*256) {
        result.r = 255-(n % 256);
        result.g = 255;
        result.b = 0;
    }
    else if (n < 3*256) {
        result.r = 0;
        result.g = 255;
        result.b = n % 256;
    }
    else if (n < 4*256) {
        result.r = 0;
        result.g = 255 - (n % 256);
        result.b = 255;
    }
    else if (n < 5*256) {
        result.r = n % 256;
        result.g = 0;
        result.b = 255;
    }
    else if (n < 6*256) {
        result.r = 255;
        result.g = 0;
        result.b = 255 - (n % 256);
    }
    else {
        result = sf::Color::Red;
    }

    return result;
}