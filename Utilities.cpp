/*
- Name: Karl Merhi
- Student number: 150828168
- Seneca email: kmerhi1@myseneca.ca
- File: Utilities.cpp
- Project: MS1
- Date of completion: 11/22/2021

I confirm that I am the only author of this file
and the content was created entirely by me.
*/

#include <complex.h>
#include "Utilities.h"
#include <iostream>

namespace sdds
{

	char Utilities::m_delimiter = '\0';

	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
	{
		size_t end_pos = str.find(m_delimiter, next_pos);

		if (end_pos == next_pos)
		{
			more = false;
			throw std::string("*** Nothing between delimiters ***");
		}

		if (end_pos == std::string::npos || end_pos > 400000)
			more = false;

		std::string token = str.substr(next_pos, end_pos - next_pos);

		if (token == "" || token == "\n")
		{
			more = false;
			throw std::string("No token");
		}

		if (token.size() > m_widthField)
			m_widthField = token.size();


		next_pos = end_pos + 1u;

		return token;
	}
	void Utilities::setFieldWidth(size_t newWidth)
	{
		m_widthField = newWidth;
	}
	size_t Utilities::getFieldWidth() const
	{
		return m_widthField;
	}
	void Utilities::setDelimiter(char newDelimiter)
	{
		m_delimiter = newDelimiter;
	}
	char Utilities::getDelimiter()
	{
		return m_delimiter;
	}
}
