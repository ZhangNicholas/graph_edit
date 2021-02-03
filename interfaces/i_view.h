/**
 * \View interface
 * @brief View reprsents the model state via Observable/ Observer pattern
 */

#pragma once

#include <memory>

// #include "controller.h"
#include "model.h"
#include "i_observer.h"


class IView : public IObserver
{
	public:
	// IView() = default;

	virtual ~IView() = default;

	//virtual void button_new_drawing() = 0;
	//virtual void button_open_drawing(const std::string&) = 0;
	//virtual void button_save_drawing(const std::string&) = 0;

	//virtual void button_add_point(const int&, const int&) = 0;
	//virtual void button_add_arc(const int&, const int&, const int&, const int&, const int&) = 0;
	//virtual void button_delete_last_primitive() = 0;
};