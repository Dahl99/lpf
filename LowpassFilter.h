#pragma once

class LowpassFilter
{
private:
		double m_cutoffFrequency;
private:
		double m_output;
public:
		explicit LowpassFilter(const double cutoffFrequency);
public:
		double recalculateOutput(const double input, const double deltaTime);
};