#pragma once
#include "i_factory.h"
#include "i_graphic_primitive.h"

class Factory : public IFactory
{
	public:
	virtual ~Factory() = default;

	virtual std::unique_ptr<IGraphicPrimitive> add(const int&, const int&) const override;
	virtual std::unique_ptr<IGraphicPrimitive> add(const int&, const int&,
		const int&, const int&, const int&) const override;
};

class PointFactory : public Factory
{
	public:
	PointFactory() = default;
	virtual std::unique_ptr<IGraphicPrimitive> add(const int&, const int&) const override;
};

class ArcFactory : public Factory
{
public:
	ArcFactory() = default;
	virtual std::unique_ptr<IGraphicPrimitive> add(const int&, const int&, 
		const int&, const int&, const int&) const override;
};