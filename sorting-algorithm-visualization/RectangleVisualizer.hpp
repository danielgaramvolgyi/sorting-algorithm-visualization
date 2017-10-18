#pragma once

#include "SortLogger.hpp"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

class RectangleVisualizer 
{
public:
    RectangleVisualizer(SortLogger& logger, sf::RenderTarget& target);
    void draw();
    void update();

private:
    SortLogger& m_logger;
    sf::RenderTarget& m_target;
    std::vector<sf::RectangleShape> m_rectangleStrip;
    Swap lastSwap = { 0,0 };

    std::vector<sf::RectangleShape> setUpRectangleStrip();
    void swapRectangles(const Swap& s);
    void colorLastSwap();
    void decolorLastSwap();
};