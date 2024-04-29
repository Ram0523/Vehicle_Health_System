#include "api.h"
#include "QDebug"
api::api(){
    // Initialize filterd and fluidd
    filterd = new Filter_details(this);
    fluidd = new Fluid_details(this);
    qDebug()<<"api called";
    // Create and add three Filter_details objects to the FilterList
    QStringList filterNames = {"Cabin Air Filter", "Oil Filter", "Fuel Filter"};
    Filter_details::createAndAddFilterDetails(filterNames, 100);

    // Create and add three Fluid_details objects to the FluidList
    QStringList fluidNames = {"Oil Fluid", "Rocket Fluid", "Petrol Fluid"};
    Fluid_details::createAndAddFluidDetails(fluidNames, 100);

}

api::~api()
{
    delete filterd;
    delete fluidd;
}

std::vector<Filter_details*>& api::getFilterList() {
    return Filter_details::FilterList;
}

std::vector<Fluid_details*>& api::getFluidList(){
    return Fluid_details::FluidList;
}
