/**
	\file
	\mainpage Homework 4 of the course "C ++ Developer. Professional" LLC "Otus Online Education"
	\brief Homework 4 of the course "C ++ Developer. Professional" LLC "Otus Online Education"
	\author Nicholas Zhang
	\date January 2021

*This project is an implementation of the graphic editor functionality using MVC design pattern.
*/

#include <memory>
#include "i_model.h"
#include "model.h"
#include "i_controller.h"
#include "controller.h"
#include "i_view.h"
#include "view.h"
#include <iostream>

int main()
{
	std::shared_ptr<IModel> model{ std::make_shared<Model>() };
	std::shared_ptr<IView> view_0{ std::make_shared<View>(model, "view_0") };
	std::shared_ptr<IController> controller{ std::make_shared<Controller>(model, view_0) };
	
	controller->add_point(42, 42);
	controller->add_arc(200, 200, 50, 0, 360);
	controller->new_drawing();
	controller->add_point(24, 24);
	controller->add_arc(100, 100, 25, 0, 180);
}