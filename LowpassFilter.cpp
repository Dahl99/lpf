#include "LowpassFilter.h"

#include <cmath>

LowpassFilter::LowpassFilter(const double cutoffFrequency)
		: m_cutoffFrequency(cutoffFrequency)
		, m_output(0.0)
{}

double LowpassFilter::recalculateOutput(const double input, const double deltaTime)
{
	// Calculates the voltage output using a first-order lowpass filter formula
	m_output += (1-exp(-2 * M_PI * m_cutoffFrequency * deltaTime)) * (input - m_output);

	return m_output;
}