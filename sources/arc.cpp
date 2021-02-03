#include <iostream>
#include "arc.h"

Arc::Arc(const int& x, const int& y, const int& radius, const int& start_angle, const int& end_angle)
{
	m_x = x ;
	m_y = y;
	m_radius = radius;
	m_start_angle = start_angle;
	m_end_angle = end_angle;
}

void Arc::get_primitive() const{
	std::cout << "Arc x: " << m_x << " y: " << m_y << " radius: " << m_radius
		<< " start: " << m_start_angle << " end: " << m_end_angle << std::endl;
}

void Arc::set_s_angle(const int& start_angle) {
	m_start_angle = start_angle;
}

void Arc::set_e_angle(const int& end_angle) {
	m_end_angle = end_angle;
}

void Arc::set_radius(const int& radius) {
	m_radius = radius;
}