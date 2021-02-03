#include <memory>
#include "i_model.h"
#include "model.h"
#include "i_controller.h"
#include "controller.h"
#include "i_view.h"
#include "view.h"

#include <gtest/gtest.h>
#include <iostream>
#include <sstream>

class ModelTest : public ::testing::Test
{
	public:
	std::shared_ptr<IModel> model;
	std::shared_ptr<IView> view_0;
	std::shared_ptr<IController> controller;

	virtual void SetUp()
	{
		model = std::make_shared<Model>();
		view_0 = std::make_shared<View>(model, "view_0");
		controller = std::make_shared<Controller>(model, view_0);
	}

	virtual void TearDown()
	{
	}
};

TEST_F(ModelTest, AddPoint)
{
	model->add_point(42, 42);
	ASSERT_TRUE(model->get_number_of_primitives() == 1);
}


TEST_F(ModelTest, AddArc)
{
	model->add_arc(200, 200, 50, 0, 360);
	ASSERT_TRUE(model->get_number_of_primitives() == 1);
}

TEST_F(ModelTest, RemovePrimitive)
{
	model->add_arc(200, 200, 50, 0, 360);
	model->delete_last_primitive();
	ASSERT_TRUE(model->get_number_of_primitives() == 0);
}

TEST_F(ModelTest, ClearDrawing)
{
	model->add_arc(200, 200, 50, 0, 360);
	model->new_drawing();
	ASSERT_TRUE(model->get_number_of_primitives() == 0);
}

int main(int argc, char** argv) {
	std::cout.rdbuf(nullptr); // disable console output
	:: testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}