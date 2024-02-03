/*
 * Humidity.h
 *
 *  Created on: 01-Feb-2024
 *      Author: giris
 */

#ifndef HUMIDITY_H_
#define HUMIDITY_H_

#include "Measurement.h"

class Humidity: public Measurement
{
private:
	float humidity;

public:
	Humidity(uint16_t timestamp, float humidity);
	virtual ~Humidity();
	float getHumidity() const;
	std::string toString() const override;
	static std::shared_ptr<Humidity> fromString(uint16_t timestamp, std::string value);
	static Humidity* toType(Measurement* ptr);
};

#endif /* HUMIDITY_H_ */
