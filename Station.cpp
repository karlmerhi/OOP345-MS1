/*
- Name: Karl Merhi
- Student number: 150828168
- Seneca email: kmerhi1@myseneca.ca
- File: Station.cpp
- Project: MS1
- Date of completion: 11/22/2021

I confirm that I am the only author of this file
and the content was created entirely by me.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <algorithm>
#include <string_view>
#include <iostream>
#include <iomanip>  
#include "Station.h"
#include "Utilities.h"

namespace sdds {

	size_t Station::m_widthField = 0u;
	size_t Station::id_generator = 0u;

	Station::Station(const std::string& line)
	{
		id_generator++;

		Utilities temp;
		bool more = true;
		size_t npos = 0u;

		m_itemName = temp.extractToken(line, npos, more);
		m_serialNumber = std::stoi(temp.extractToken(line, npos, more));
		m_itemStock = std::stoi(temp.extractToken(line, npos, more));
		m_widthField = std::max(temp.getFieldWidth(), m_widthField);
		m_stationDescription = temp.extractToken(line, npos, more);

		m_stationId = id_generator;
	}
	const std::string& Station::getItemName() const
	{
		return m_itemName;
	}
	size_t Station::getNextSerialNumber()
	{
		return m_serialNumber++;
	}
	size_t Station::getQuantity() const
	{
		return m_itemStock;
	}
	void Station::updateQuantity()
	{
		if (m_itemStock > 0)
		{
			m_itemStock -= 1;
		}
	}
	void Station::display(std::ostream& os, bool full) const
	{
		os << "[" << std::setfill('0') << std::setw(3) << m_stationId << "] Item: " <<
			std::setfill(' ') << std::setw(m_widthField) << std::left << m_itemName
			<< " [" << std::right << std::setfill('0') << std::setw(6) <<
			m_serialNumber << "]" << std::setfill(' ');
		if (full) {
			os << " Quantity: " << std::setw(m_widthField) << std::left <<
				m_itemStock << std::right << " Description: " << m_stationDescription;
		}
		os << "\n";
	}
}
