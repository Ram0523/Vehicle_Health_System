#include "api.h"
#include "mainwindow.h"
#include <gtest/gtest.h>

using namespace ::testing;

// Test fixture class
class VehicleHealthSystemTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Create an instance of the api class
        apiObj = new api();
    }

    void TearDown() override {
        // Clean up the api object
        delete apiObj;
        Filter_details::FilterList={};
        Fluid_details::FluidList={};
    }

    api* apiObj;
};

// Test cases derived from the VehicleHealthSystemTest fixture
TEST_F(VehicleHealthSystemTest, InitialListSizes) {
    EXPECT_EQ(apiObj->getFilterList().size(), 3);
    EXPECT_EQ(apiObj->getFluidList().size(), 3);
}

TEST_F(VehicleHealthSystemTest, FilterNames) {
    QStringList expectedNames = {"Cabin Air Filter", "Oil Filter", "Fuel Filter"};
    std::vector<Filter_details*>& filterList = apiObj->getFilterList();
    qDebug()<<filterList.size();
    if (filterList.size() != 3) {
        ADD_FAILURE() << "FilterList size is not 3";
        return;
    }

    for (int i = 0; i < filterList.size(); ++i) {
        EXPECT_EQ(filterList[i]->getName(), expectedNames[i]);
    }
}

TEST_F(VehicleHealthSystemTest, InitialFilterStatus) {
    std::vector<Filter_details*>& filterList = apiObj->getFilterList();

    for (Filter_details* filter : filterList) {
        EXPECT_EQ(filter->getStatus(), 100);
    }
}

TEST_F(VehicleHealthSystemTest, FluidNames) {
    QStringList expectedNames = {"Oil Fluid", "Rocket Fluid", "Petrol Fluid"};
    std::vector<Fluid_details*>& fluidList = apiObj->getFluidList();

    for (int i = 0; i < fluidList.size(); ++i) {
        EXPECT_EQ(fluidList[i]->getName(), expectedNames[i]);
    }
}

TEST_F(VehicleHealthSystemTest, InitialFluidStatus) {
    std::vector<Fluid_details*>& fluidList = apiObj->getFluidList();

    for (Fluid_details* fluid : fluidList) {
        EXPECT_EQ(fluid->getStatus(), 100);
    }
}
