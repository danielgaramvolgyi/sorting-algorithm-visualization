#pragma once

#include <vector>
#include <queue>
#include <algorithm>

struct Swap 
{
    int i, j;
};

class SortLogger 
{
public:
    void logAlgorithmStep(int i, int j);
    void logInitialState(const std::vector<int>& v);

    size_t getInitialStateSize() const { return m_initialState.size(); }
    int readInitialState(size_t i) const { return m_initialState[i]; }
    int getMinimumValue() const { return *std::min_element(m_initialState.begin(), m_initialState.end()); }
    int getMaximumValue() const { return *std::max_element(m_initialState.begin(), m_initialState.end()); }
    bool isFinished() const { return m_algorithmSteps.empty(); }

    Swap getAlgorithmStep();

private:
    std::vector<int> m_initialState;
    std::queue<Swap> m_algorithmSteps;
};