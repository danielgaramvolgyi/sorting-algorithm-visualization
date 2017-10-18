#include "sort.hpp"
#include "SortLogger.hpp"
#include "RectangleVisualizer.hpp"
#include "Utils.hpp"
#include "ColorVisualizer.hpp"

#include <SFML\Graphics.hpp>

namespace constant 
{
    const sf::Time timePerFrame = sf::seconds(1.f / 60.f);
}

int main() 
{

    sf::RenderWindow window(sf::VideoMode(500, 500), "Sorting");
    window.setFramerateLimit(120);
    
    std::vector<int> v = utils::generateRandomVector(10000,0,500);
    SortLogger log;
    bubbleSort(v, log);
    ColorVisualizer vis(log, window);
    
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    
    while (window.isOpen())
    {
        while (timeSinceLastUpdate < constant::timePerFrame) 
        {
            timeSinceLastUpdate += clock.restart();
            vis.update();
        }
        timeSinceLastUpdate -= constant::timePerFrame;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        vis.draw();
        window.display();
    }

}