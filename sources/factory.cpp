#include "factory.h"
#include "i_graphic_primitive.h"
#include "point.h"
#include "arc.h"

std::unique_ptr<IGraphicPrimitive> Factory::add(const int&, const int&) const
{
	return nullptr;
}

std::unique_ptr<IGraphicPrimitive> Factory::add(const int&, const int&,
	const int&, const int&, const int&) const
{
	return nullptr;
}

std::unique_ptr<IGraphicPrimitive> PointFactory::add(const int& x, const int& y) const {
	return std::make_unique<Point>(x , y);
}

std::unique_ptr<IGraphicPrimitive> ArcFactory::add(const int& x, const int& y,
	const int& radius, const int& start_angle, const int& end_angle) const
{
	return std::make_unique<Arc>(x, y, radius, start_angle, end_angle);
}