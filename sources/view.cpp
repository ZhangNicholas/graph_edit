#include "view.h"
#include <stdexcept>

View::View(std::shared_ptr<IModel> model, 	const std::string& name = "default") : _name {name} {
	if (model)
		_model = model;
	else
		throw std::runtime_error("Model is missing");

	//if (controller)
	//	_controller = controller;
	//else
	//	throw std::runtime_error("Controller is missing");
}

void View::update() const noexcept {
	std::cout << "This model is rendered by view " << _name << std::endl;
	_model->get_model();
}

//void View::button_new_drawing()
//{
//	_controller->new_drawing();
//}
//
//void View::button_open_drawing(const std::string& filepath)
//{
//	_controller->open_drawing(filepath);
//}
//
//void View::button_save_drawing(const std::string& filepath)
//{
//	_controller->save_drawing(filepath);
//}
//
//void View::button_add_point(const int& x, const int& y)
//{
//	_controller->add_point(x, y);
//}
//
//void View::button_add_arc(const int& x, const int& y, const int& radius,
//	const int& start_angle, const int& end_angle)
//{
//	_controller->add_arc(x, y, radius, start_angle, end_angle);
//}
//
//void View::button_delete_last_primitive()
//{
//	_controller->delete_last_primitive();
//}