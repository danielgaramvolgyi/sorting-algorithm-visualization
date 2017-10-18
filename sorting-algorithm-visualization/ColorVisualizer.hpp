#pragma once

#include "SortLogger.hpp"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

class ColorVisualizer
{
public:
    ColorVisualizer(SortLogger& logger, sf::RenderTarget& target);
    void draw();
    void update();

private:
    SortLogger& m_logger;
    sf::RenderTarget& m_target;
    std::vector<sf::RectangleShape> m_colors;

    std::vector<sf::RectangleShape> setUpColors();
    void swapColors(const Swap& s);

};