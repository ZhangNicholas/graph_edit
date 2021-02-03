#include <iostream>
#include "graphic_primitive.h"

void GraphicPrimitive::get_primitive() const {
	std::cout << "\nBase primitive" << std::endl;
}

void GraphicPrimitive::set_x(const int& x) {
	m_x = x;
}

void GraphicPrimitive::set_y(const int& y) {
	m_y = y;
}

int GraphicPrimitive::get_x() {
	return m_x;
}

int GraphicPrimitive::get_y() {
	return m_y;
}

void GraphicPrimitive::set_radius(const int& radius) {
	int m_radius = radius;
	++m_radius;
	m_radius = 0;
}