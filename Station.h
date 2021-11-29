/*
- Name: Karl Merhi
- Student number: 150828168
- Seneca email: kmerhi1@myseneca.ca
- File: Station.h
- Project: MS1
- Date of completion: 11/22/2021

I confirm that I am the only author of this file
and the content was created entirely by me.
*/

#include <string>
#ifndef SDDS_STATION_H
#define SDDS_STATION_H

namespace sdds {

	class Station {
		size_t m_stationId;
		std::string m_itemName;
		std::string m_stationDescription;
		size_t m_serialNumber;
		size_t m_itemStock;
		static size_t m_widthField;
		static size_t id_generator;
	public:
		Station(const std::string& line);
		const std::string& getItemName() const;
		size_t getNextSerialNumber();
		size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;
	};
}

#endif // !SDDS_STATION_H