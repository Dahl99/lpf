#pragma once

class LowpassFilter
{
private:
		double m_cutoffFrequency;
private:
		double m_resistance;
private:
		double m_capacitance;
private:
		mutable double m_output;
public:
		LowpassFilter(const double cutoffFrequency, const double resistance, const double capacitance);
public:
		[[nodiscard]] double calculateResistance() const;
public:
		[[nodiscard]] double calculateCapacitance() const;
public:
		[[nodiscard]] double calculateCutoffFrequency() const;
public:
		[[nodiscard]] double calculateTransfer(const double dt) const;
public:
		double update(const double input, const double deltaTime);
};