#include "LowpassFilter.h"

#include <iostream>
#include <cmath>

void TestLowpassFilterCorrectness();

int main()
{
    TestLowpassFilterCorrectness();

    // Initialize LowpassFilter with cutoff frequency of 50Hz
    Core::LowpassFilter lpf(1.0f);

    // Simulate input signal of 1.0 over 100ms with a timestep of 1ms
    for (int i = 0; i < 100; i++)
    {
        std::cout << "Transfer at " << i + 1 << "ms = " << lpf.RecalculateOutput(1.0f, 0.001) << "V" << std::endl;
    }

    return 0;
}

void TestLowpassFilterCorrectness()
{
    constexpr double cutoffFrequency = 1.0; // Hz
    constexpr double input = 1.0; // Volts
    constexpr double deltaTime = 0.001; // seconds
    Core::LowpassFilter lpf(cutoffFrequency);

    // Calculate expected output using the filter formula
    constexpr double expected = 0.006263487f;
    constexpr double tolerance = 1e-9;
    const double output = lpf.RecalculateOutput(input, deltaTime);

    if (std::abs(output - expected) < tolerance) {
        std::cout << "LowpassFilter test passed! Output: " << output << ", Expected: " << expected << std::endl;
    } else {
        std::cout << "LowpassFilter test FAILED! Output: " << output << ", Expected: " << expected << std::endl;
    }
}
