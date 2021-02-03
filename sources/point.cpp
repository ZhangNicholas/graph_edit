#include "point.h"
#include <iostream>

Point::Point(const int& x, const int& y)
{
	m_x = x;
	m_y = y;
}

void Point::get_primitive() const{
	std::cout << "Point x: " << m_x << " y: " << m_y << std::endl;
}