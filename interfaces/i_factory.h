/**
* \interface IFactory
* @brief Factories of graphic primitives..
*/

#pragma once

#include <memory>
#include "i_graphic_primitive.h"

class IFactory
{
	public:
	virtual ~IFactory() = default;
	/**
	* @brief Point primitive
	*/
	virtual std::unique_ptr<IGraphicPrimitive> add(const int&, const int&) const = 0;

	/**
	* @brief Arc primitive
	*/
	virtual std::unique_ptr<IGraphicPrimitive> add(const int&, const int&,
		const int&, const int&, const int&) const = 0;
};