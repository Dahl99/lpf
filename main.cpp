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
    constexpr double tolerance = 1e-9;

    Core::LowpassFilter lpf(cutoffFrequency);

    // Calculate expected output using the filter formula
    constexpr double expectedOneMs = 0.006263487f;
    double output = lpf.RecalculateOutput(input, deltaTime);
    if (std::abs(output - expectedOneMs) < tolerance) {
        std::cout << "LowpassFilter test 1ms passed! Output: " << output << ", Expected: " << expectedOneMs << std::endl;
    } else {
        std::cout << "LowpassFilter test 1ms FAILED! Output: " << output << ", Expected: " << expectedOneMs << std::endl;
    }

    constexpr double expectedTwoMs = 0.012487743f;
    output = lpf.RecalculateOutput(input, deltaTime);
    if (std::abs(output - expectedTwoMs) < tolerance) {
        std::cout << "LowpassFilter test 2ms passed! Output: " << output << ", Expected: " << expectedTwoMs << std::endl;
    } else {
        std::cout << "LowpassFilter test 2ms FAILED! Output: " << output << ", Expected: " << expectedTwoMs << std::endl;
    }
}
