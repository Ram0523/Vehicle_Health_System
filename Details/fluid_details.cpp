#include "fluid_details.h"
std::vector<Fluid_details*>  Fluid_details::FluidList;

Fluid_details::Fluid_details(QObject *parent) : QObject(parent){}

Fluid_details::Fluid_details(QString name,int status):Name(name),status(status){}

// Getter methods
QString Fluid_details::getName() const { return Name; }
int Fluid_details::getStatus() const { return status; }
QDate Fluid_details::getCurrentDate() const { return currentDate; }

// Setter methods
void Fluid_details::setName(const QString& name) { Name = name; }
Fluid_details* Fluid_details::setStatus(int newStatus) { status = status-newStatus;
    qDebug()<<status;
    return this;}
void Fluid_details::setCurrentDate(const QDate& date) { currentDate = date; }


// Static method to add details to the list
void Fluid_details:: addFluidDetailsToList(Fluid_details* newDetails) {
    FluidList.push_back(newDetails);
}



void Fluid_details::createAndAddFluidDetails(const QStringList& names, int status) {
    for (const QString& name : names) {
        Fluid_details* newFluid = new Fluid_details(name,status);
        // newFluid->setName(name);
        // newFluid->setStatus(status);
        newFluid->setCurrentDate(QDate::currentDate());
        Fluid_details::addFluidDetailsToList(newFluid);
    }
}
