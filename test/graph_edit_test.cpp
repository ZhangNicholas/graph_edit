#include <memory>
#include <i_model.h>
#include <model.h>
#include "i_controller.h"
#include "controller.h"
#include "i_view.h"
#include "view.h"

#include <gtest/gtest.h>

TEST(controller, addPrimitive) {
	std::string str{ "1" };
	ASSERT_EQ(1, 1);
}

TEST(controller, removePrimitive) {
	std::string str{ "1" };
	ASSERT_EQ(1, 1);
}

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}