#include <iomanip>
#include <iostream>
#include <cmath>

#include "LowpassFilter.h"

int main()
{
    // Initialize LowpassFilter with cutoff frequency of 45.4728 Hz, resistance of 35 kOhm, and capacitance of 100 nF
    LowpassFilter lpf(45.4728f, 35.f * pow(10, 3), 100.f * pow(10, -9));

    std::cout << "Resistance: " << lpf.calculateResistance() << std::endl;
    std::cout << "Capacitance: " << lpf.calculateCapacitance() << std::endl;
    std::cout << "Cutoff frequency: " << lpf.calculateCutoffFrequency() << std::endl;

    for (int i = 0; i < 10; i++)
    {
        std::cout << std::setprecision(10) << "Transfer at " << i << " = " << lpf.update(1.0f, 0.01) << std::endl;
    }

    return 0;
}
