#include "controller.h"
#include "i_model.h"
#include "i_view.h"


#include <iostream>
#include <stdexcept>

Controller::Controller(std::shared_ptr<IModel> model, std::shared_ptr<IView> view)
	: _model(model), _view(view) {
	if (model)
		_model = model;
	else
		throw std::runtime_error("Expected model missing");

	if (view)
		_view = view;
	else
		throw std::runtime_error("Expected view is missing");

	_model->subscribe(_view);
	_model->notify();
}

void Controller::new_drawing()
{
	_model->new_drawing();
	_model->notify();
}

void Controller::open_drawing(const std::string& file_path)
{
	_model->new_drawing();
	// read file
	_model->notify();
}

void Controller::save_drawing(const std::string& file_path)
{
	// save file
	_model->notify();
}

void Controller::add_point(const int& x, const int& y)
{
	_model->add_point(x, y);
	_model->notify();
}

void Controller::add_arc(const int& x, const int& y, const int& radius,
	const int& start_angle, const int& end_angle)
{
	_model->add_arc(x, y, radius, start_angle, end_angle);
	_model->notify();
}

void Controller::delete_last_primitive()
{
	_model->delete_last_primitive();
	_model->notify();
}

void Controller::get_model()
{
	_model->get_model();
	_model->notify();
}