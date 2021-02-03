/**
 * \Controller interface
 * @brief Controller drives the model( drawing)
 */

#pragma once

#include <memory>
#include "i_observer.h"
#include "i_model.h"
#include "i_view.h"

class IController
{
public:
	IController() = default;
	virtual ~IController() = default;

	/**
	* @brief Open drawing from file and render the view
	*/
	virtual void open_drawing(const std::string&) = 0;
	/**
	* @brief Reset current drawing and render the view
	*/
	virtual void new_drawing() = 0;
	/**
	* @brief Save current drawing and render the view
	*/
	virtual void save_drawing(const std::string&) = 0;
	/**
	* @brief Add point primitive and render the view
	*/
	virtual void add_point(const int&, const int&) = 0;
	/**
	* @brief Add arc primitive and render the view
	*/
	virtual void add_arc(const int&, const int&, const int&, const int&, const int&) = 0;
	/**
	* @brief Delete last added primitive and render the view
	*/
	virtual void delete_last_primitive() = 0;
	/**
	* @brief Render the view
	*/
	virtual void get_model() = 0;
};