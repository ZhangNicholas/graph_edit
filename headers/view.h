#pragma once

#include <iostream>
#include "i_model.h"
#include "i_view.h"
#include "i_controller.h"

class View : public IView {
public:
	View(std::shared_ptr<IModel>, const std::string&);
	virtual ~View() = default;

	//virtual void button_new_drawing() override;
	//virtual void button_open_drawing(const std::string&) override;
	//virtual void button_save_drawing(const std::string&) override;

	//virtual void button_add_point(const int&, const int&) override;
	//virtual void button_add_arc(const int&, const int&, const int&, const int&, 
	//	const int&) override;
	//virtual void button_delete_last_primitive() override;
	
	void update() const noexcept override;

private:
	// std::shared_ptr<IController> _controller;
	std::shared_ptr<IModel> _model;
	const std::string _name;
};