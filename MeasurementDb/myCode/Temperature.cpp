/*
 * Temperature.cpp
 *
 *  Created on: 01-Feb-2024
 *      Author: giris
 */

#include "Temperature.h"

using namespace std;

Temperature::Temperature(uint16_t timestamp, float temperature)
: Measurement(timestamp), temperature(temperature)
{
}

Temperature::~Temperature()
{
}

float Temperature::getTemperature() const
{
	return this->temperature;
}

std::string Temperature::toString() const
{
	ostringstream oss;

	oss << "Temperature: " << this->temperature << "�C";

	return oss.str();

//	return ("Temperature: " + to_string(this->temperature) + "�C");
}

std::shared_ptr<Temperature> Temperature::fromString(uint16_t timestamp, std::string value)
{
	return make_shared<Temperature>(Temperature(timestamp, stof(value)));
}

Temperature* Temperature::toType(Measurement *ptr)
{
	if(Temperature* pTemp = dynamic_cast<Temperature*>(ptr))
	{
		return pTemp;
	}
	else
	{
		return nullptr;
	}
}
