/*
 * Measurement.h
 *
 *  Created on: 01-Feb-2024
 *      Author: giris
 */

#ifndef MEASUREMENT_H_
#define MEASUREMENT_H_

#include <cstdint>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <memory>

class Measurement
{
private:
	uint16_t timestamp;
public:
	Measurement(uint16_t timestamp = 0);
	virtual ~Measurement();
	static uint16_t toTimestamp(int hour, int minute);
	static std::string toTimeOfDay(uint16_t timestamp);
	long getTimestamp() const;
	virtual std::string toString() const = 0;
	static void parseLine(const std::string& line, uint16_t& timestamp,
			std::string& type, std::string& remainder);
};

std::ostream& operator<<(std::ostream& lhs, Measurement& rhs);

#endif /* MEASUREMENT_H_ */
