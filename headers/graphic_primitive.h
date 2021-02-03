#pragma once
#include "i_graphic_primitive.h"

class GraphicPrimitive : public IGraphicPrimitive
{
public:
	virtual void get_primitive() const override;
	void set_x(const int&);
	void set_y(const int&);
	virtual void set_radius(const int&) override;
	int get_x();
	int get_y();

	virtual ~GraphicPrimitive() = default;

protected:
	int m_x;
	int m_y;
};