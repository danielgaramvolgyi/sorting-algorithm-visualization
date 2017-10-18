#include "RectangleVisualizer.hpp"
#include "Utils.hpp"

#include "SFML/System/Sleep.hpp"
#include <iostream>

constexpr int rectanglePadding = 0;

RectangleVisualizer::RectangleVisualizer(SortLogger& logger, sf::RenderTarget& target)
    :m_logger{ logger },
    m_target{ target },
    m_rectangleStrip{ setUpRectangleStrip() } 
{}

void RectangleVisualizer::draw()
{
    for (const auto& rect : m_rectangleStrip) {
        m_target.draw(rect);
    }
}

void RectangleVisualizer::update() {
   decolorLastSwap();
    if (!m_logger.isFinished()) {
        lastSwap = m_logger.getAlgorithmStep();
        swapRectangles(lastSwap);
        colorLastSwap();
    }
}

std::vector<sf::RectangleShape> RectangleVisualizer::setUpRectangleStrip()
{
    size_t sampleSize = m_logger.getInitialStateSize();
    std::vector<sf::RectangleShape> strip(sampleSize);
    
    double drawRegionWidth = m_target.getSize().x * 0.8;
    double drawRegionHeight = m_target.getSize().y * 0.8;
    double rectangleWidth =  drawRegionWidth / sampleSize - rectanglePadding;

    double leftBorder = m_target.getSize().x * 0.1;
    double bottomBorder = m_target.getSize().y * 0.9;

    int minValue = m_logger.getMinimumValue();
    int maxValue = m_logger.getMaximumValue();

    for (size_t i = 0; i < sampleSize; ++i) {
        double currentHeight = utils::scaleInterval(minValue, maxValue, 0, drawRegionHeight, m_logger.readInitialState(i));
        strip[i].setSize(sf::Vector2f(rectangleWidth,currentHeight));
        strip[i].setPosition(leftBorder + i*(rectangleWidth + rectanglePadding), bottomBorder - currentHeight);
        strip[i].setFillColor(sf::Color::White);
    }

    return strip;
}

void RectangleVisualizer::swapRectangles(const Swap& s)
{
    float width = m_rectangleStrip[s.i].getSize().x;
    float iheight = m_rectangleStrip[s.i].getSize().y;
    float jheight = m_rectangleStrip[s.j].getSize().y;
    m_rectangleStrip[s.i].setSize({ width, jheight });
    m_rectangleStrip[s.i].move(0, iheight - jheight);
    m_rectangleStrip[s.j].setSize({ width, iheight });
    m_rectangleStrip[s.j].move(0, jheight - iheight);
}

void RectangleVisualizer::colorLastSwap()
{
    m_rectangleStrip[lastSwap.i].setFillColor(sf::Color::Red);
    m_rectangleStrip[lastSwap.j].setFillColor(sf::Color::Red);
}

void RectangleVisualizer::decolorLastSwap()
{
    m_rectangleStrip[lastSwap.i].setFillColor(sf::Color::White);
    m_rectangleStrip[lastSwap.j].setFillColor(sf::Color::White);
}
