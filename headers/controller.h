#pragma once
#include "i_controller.h"
#include "i_model.h"
#include "i_view.h"
#include "i_graphic_primitive.h"

class Controller : public IController
{
public:
	Controller(std::shared_ptr<IModel>, std::shared_ptr<IView>);

	virtual ~Controller() = default;

	virtual void open_drawing(const std::string&) override;
	virtual void new_drawing() override;
	virtual void save_drawing(const std::string&) override;

	virtual void add_point(const int&, const int&) override;
	virtual void add_arc(const int&, const int&, const int&, const int&, const int&) override;
	virtual void delete_last_primitive() override;

	virtual void get_model() override;

private:
	std::shared_ptr<IModel> _model;
	std::shared_ptr<IView> _view;
};