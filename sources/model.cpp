#include<iostream>
#include "model.h"

void Model::new_drawing()
{
	drawing.clear();
}

void Model::open_drawing(const std::string& file_path)
{
	std::string m_file_path = file_path;
	m_file_path = "mock_file";
	new_drawing();
	// open drawing from file
}

void Model::save_drawing(const std::string& file_path)
{
	std::string m_file_path = file_path;
	m_file_path = "mock_file";
	// save_drawing to file
}

void Model::add_point(const int& x, const int& y)
{
	if (!point_factory)
	{
		point_factory = std::make_unique<PointFactory>();
	}
	drawing.push_back(point_factory->add(x, y));
	// notify();
}

void Model::add_arc(const int& x, const int& y, const int& radius,
	const int& start_angle, const int& end_angle)
{
	if (!arc_factory)
	{
		arc_factory = std::make_unique<ArcFactory>();
	}
	drawing.push_back(arc_factory->add(x, y, radius, start_angle, end_angle));
	// notify();
}

void Model::delete_last_primitive()
{
	if (!drawing.empty())
	{
		drawing.pop_back();
	}
	else std::cout << "The model is empty\n";
	// notify();
}

void Model::get_model() const
{
	if (!drawing.empty())
	{
		for (const auto& primitive : drawing)
		{
			primitive->get_primitive();
		}
	}
	else std::cout << "The model is empty\n";
}

size_t Model::get_number_of_primitives() const
{
	return drawing.size();
}