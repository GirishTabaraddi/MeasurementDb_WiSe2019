/*
 * MeasurementDb.h
 *
 *  Created on: 01-Feb-2024
 *      Author: giris
 */

#ifndef MEASUREMENTDB_H_
#define MEASUREMENTDB_H_

#include "Measurement.h"
#include "Temperature.h"
#include "Humidity.h"

#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <boost/algorithm/string.hpp>

class MeasurementDb
{
private:
	std::map<std::string, std::vector<std::shared_ptr<Measurement>>> data;

public:
	void addMeasurement(const std::string& location, std::shared_ptr<Measurement> measurement);

	void print();

	void save(std::ostream& to);

	void load(std::istream& from);

	bool maximumTemperature(std::string& location, std::shared_ptr<Measurement>& measurement);
};

#endif /* MEASUREMENTDB_H_ */