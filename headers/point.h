#pragma once
#include "graphic_primitive.h"

class Point : public GraphicPrimitive
{
public:
	Point(const int&, const int&);
	void get_primitive() const override;

private:
};