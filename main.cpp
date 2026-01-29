#include "LowpassFilter.h"

#include <iostream>

int main()
{
    // Initialize LowpassFilter with cutoff frequency of 50Hz
    LowpassFilter lpf(1.0f);

    // Simulate input signal of 1.0 over 100ms with a timestep of 1ms
    for (int i = 0; i < 100; i++)
    {
        std::cout << "Transfer at " << i + 1 << "ms = " << lpf.RecalculateOutput(1.0f, 0.001) << "V" << std::endl;
    }

    return 0;
}
