#include "Utils.hpp"
#include "ColorVisualizer.hpp"

#include <stdint.h>
#include <cmath>

ColorVisualizer::ColorVisualizer(SortLogger& logger, sf::RenderTarget& target)
    :m_logger{ logger },
    m_target{ target },
    m_colors{setUpColors()}
{}

void ColorVisualizer::draw()
{
    for (const auto& cell : m_colors) {
        m_target.draw(cell);
    }
}

void ColorVisualizer::update() {
    if (!m_logger.isFinished()) {
        swapColors(m_logger.getAlgorithmStep());
    }

}

std::vector<sf::RectangleShape> ColorVisualizer::setUpColors()
{
    size_t sampleSize = m_logger.getInitialStateSize();
    std::vector<sf::RectangleShape> colors(sampleSize);

    float drawRegionWidth = m_target.getSize().x * 0.8;
    float drawRegionHeight = m_target.getSize().y * 0.8;
    int rows = sampleSize / drawRegionWidth;

    float cellSize = sqrt(drawRegionWidth*drawRegionHeight / sampleSize);
    int rowSize = drawRegionWidth / cellSize;

    float leftBorder = m_target.getSize().x * 0.1;
    float topBorder = m_target.getSize().y * 0.1;

    int minValue = m_logger.getMinimumValue();
    int maxValue = m_logger.getMaximumValue();

    for (int i = 0; i < sampleSize; ++i) {
        colors[i].setSize({ cellSize,cellSize });
        colors[i].setPosition(leftBorder + (i % rowSize) * cellSize, topBorder + (i / rowSize) * cellSize);
        colors[i].setFillColor(utils::intToRGB(utils::scaleInterval(minValue, maxValue, 0, 256*6-1, m_logger.readInitialState(i))));
    }

    return colors;
}

void ColorVisualizer::swapColors(const Swap& s)
{
    sf::Color iColor = m_colors[s.i].getFillColor();
    m_colors[s.i].setFillColor(m_colors[s.j].getFillColor());
    m_colors[s.j].setFillColor(iColor);
}

