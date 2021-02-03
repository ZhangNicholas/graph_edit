/**
 * \Model interface
 * @brief Model (drawing) contains graphic primitive objects and updates the view
 * via Observer/ Observable pattern.
 */

#pragma once

#include <memory>
#include <string>

#include "i_graphic_primitive.h"
#include "i_observer.h"

class IModel : public IObservable
{
	public:
	virtual ~IModel() = default;

	virtual void new_drawing() = 0;

	virtual void open_drawing(const std::string&) = 0;

	virtual void save_drawing(const std::string&) = 0;

	// virtual voide close_drawing() = 0;

	virtual void add_point(const int&, const int&) = 0;

	virtual void add_arc(const int&, const int&, const int&, const int&, const int&) = 0;

	virtual void delete_last_primitive() = 0;

	virtual void get_model() const = 0;

	virtual size_t get_number_of_primitives() const = 0;

 };