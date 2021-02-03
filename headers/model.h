#pragma once

#include <list>
#include "factory.h"
// #include <string>
#include "i_model.h"
#include "i_observer.h"

class Model : public IModel
{
	public:
	Model() = default;
	~Model() = default;

	void new_drawing() override;
	void open_drawing(const std::string&) override;
	void save_drawing(const std::string&) override;
	void add_point(const int&, const int&) override;
	void add_arc(const int&, const int&, const int&, const int&, const int&) override;
	void delete_last_primitive() override;

	void get_model() const override;

	size_t get_number_of_primitives() const override;

	private:
		std::list<std::unique_ptr<IGraphicPrimitive>> drawing;
		std::unique_ptr<Factory> point_factory{nullptr};
		std::unique_ptr<Factory> arc_factory{nullptr};
};