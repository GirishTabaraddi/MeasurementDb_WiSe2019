/*
 * Measurement.cpp
 *
 *  Created on: 01-Feb-2024
 *      Author: giris
 */

#include "Measurement.h"

using namespace std;

Measurement::Measurement(uint16_t timestamp) : timestamp(timestamp)
{
}

Measurement::~Measurement()
{
}

uint16_t Measurement::toTimestamp(int hour, int minute)
{
	uint16_t minSinceMidnight = 0;

	if(hour >= 0 && hour <= 23 && minute >= 0 && minute <= 59)
	{
		minSinceMidnight = (hour * 60) + minute;
	}
	else
	{
		cout << "Invalid Argument" << endl;
	}

	return minSinceMidnight;
}

std::string Measurement::toTimeOfDay(uint16_t timestamp)
{
	ostringstream oss;

	int hour = (timestamp/60);
	int minute = timestamp%60;

	oss << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << minute;

	return oss.str();
}

long Measurement::getTimestamp() const
{
	return this->timestamp;
}

std::ostream& operator <<(std::ostream &lhs, Measurement &rhs)
{
	lhs << rhs.toTimeOfDay(rhs.getTimestamp()) << " " << rhs.toString();

	return lhs;
}

void Measurement::parseLine(const std::string &line, uint16_t &timestamp,
		std::string &type, std::string &remainder)
{
	string temp;

	string::size_type pos, pos1;

	if(line.find(";") != string::npos)
	{
		pos = line.find(";");

		timestamp = atol(line.substr(0, pos).c_str());

		pos1 = line.find(":");

		if(pos1 != string::npos)
		{
			type = line.substr(pos+1, pos1 - pos - 1);

			remainder = line.substr(pos1+2);
		}
	}
}
