/*
- Name: Karl Merhi
- Student number: 150828168
- Seneca email: kmerhi1@myseneca.ca
- File: Utilities.h
- Project: MS1
- Date of completion: 11/22/2021

I confirm that I am the only author of this file
and the content was created entirely by me.
*/

#include <iostream>

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

namespace sdds {
	class Utilities {
		size_t m_widthField = 1;
		static char m_delimiter;
	public:
		void setFieldWidth(size_t newWidth);
		size_t getFieldWidth() const;
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
		static void setDelimiter(char newDelimiter);
		static char getDelimiter();
	};
}
#endif // !SDDS_UTILITIES_H