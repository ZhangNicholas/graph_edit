#pragma once
#include "graphic_primitive.h"

class Arc : public GraphicPrimitive
{
public:
	Arc(const int&, const int&, const int&, const int&, const int&);
	void get_primitive() const override;
	void set_s_angle(const int&);
	void set_e_angle(const int&);
	void set_radius(const int&);

private:
	int m_radius;
	int m_start_angle;
	int m_end_angle;
};

