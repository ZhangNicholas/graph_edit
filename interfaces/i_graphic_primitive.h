/**
* \Graphic Primitive interface
* @brief Graphic Primitive interface
*/
#pragma once
class IGraphicPrimitive
{
public:
	virtual ~IGraphicPrimitive() = default;
	virtual void get_primitive() const = 0;
	virtual void set_x(const int&) = 0;
	virtual void set_y(const int&) = 0;
	virtual void set_radius(const int&) = 0;
	virtual int get_x() = 0;
	virtual int get_y() = 0;
	// virtual int get_r() = 0;
};