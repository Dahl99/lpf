#include <cmath>

#include "LowpassFilter.h"

LowpassFilter::LowpassFilter(const double cutoffFrequency, const double resistance, const double capacitance)
		: m_cutoffFrequency(cutoffFrequency)
		, m_resistance(resistance)
		, m_capacitance(capacitance)
		, m_output(0.0)
{}

double LowpassFilter::calculateResistance() const
{
	return 1 / (2 * M_PI * m_cutoffFrequency * m_capacitance);
}

double LowpassFilter::calculateCapacitance() const
{
	return 1 / (2 * M_PI * m_cutoffFrequency * m_resistance);
}

double LowpassFilter::calculateCutoffFrequency() const
{
	return 1 / (2 * M_PI * m_resistance * m_capacitance);
}

double LowpassFilter::calculateTransfer(const double dt) const
{
	return 1 / (1 + dt * m_resistance * m_capacitance);
}

double LowpassFilter::update(const double input, const double deltaTime)
{
	m_output += (input - m_output) * (1-exp(-deltaTime * 2 * M_PI * m_cutoffFrequency));

	return m_output;
}