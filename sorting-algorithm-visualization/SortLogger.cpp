#include "SortLogger.hpp"

void SortLogger::logAlgorithmStep(int i, int j)
{
    m_algorithmSteps.push(Swap{ i,j });
}

void SortLogger::logInitialState(const std::vector<int>& v)
{
    m_initialState = v;
}

Swap SortLogger::getAlgorithmStep()
{
    Swap s = m_algorithmSteps.front();
    m_algorithmSteps.pop();
    return s;
}
