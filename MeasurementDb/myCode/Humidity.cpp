/*
 * Humidity.cpp
 *
 *  Created on: 01-Feb-2024
 *      Author: giris
 */

#include "Humidity.h"

using namespace std;

Humidity::Humidity(uint16_t timestamp, float humidity)
: Measurement(timestamp), humidity(humidity)
{
}

Humidity::~Humidity()
{

}

float Humidity::getHumidity() const
{
	return this->humidity;
}

std::string Humidity::toString() const
{
	ostringstream oss;

	oss << "Humidity: " << this->humidity << "%";

	return oss.str();

	//	return ("Humidity: " + to_string(this->humidity) + "%");
}

std::shared_ptr<Humidity> Humidity::fromString(uint16_t timestamp,
		std::string value)
{
	return make_shared<Humidity>(Humidity(timestamp, stof(value)));
}

Humidity* Humidity::toType(Measurement *ptr)
{
	if(Humidity* pHumidity = dynamic_cast<Humidity*>(ptr))
	{
		return pHumidity;
	}
	else
	{
		return nullptr;
	}
}
