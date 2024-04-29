#include "filter_details.h"

std::vector<Filter_details*> Filter_details::FilterList;

Filter_details::Filter_details(QObject *parent) : QObject(parent){}

Filter_details::Filter_details(QString name,int status):Name(name),status(status){}
// Getter methods
QString Filter_details::getName() const { return Name; }
int Filter_details::getStatus() const { return status; }
QDate Filter_details::getCurrentDate() const { return currentDate; }

// Setter methods
void Filter_details::setName(const QString& name) { Name = name; }
Filter_details* Filter_details::setStatus(int newStatus) { status = status-newStatus;
    qDebug()<<status;
    return this;}
void Filter_details::setCurrentDate(const QDate& date) { currentDate = date; }


// Static method to add details to the list
void Filter_details:: addFilterDetailsToList(Filter_details* newDetails) {
    FilterList.push_back(newDetails);
}


void Filter_details::createAndAddFilterDetails(const QStringList& names, int status) {
    for (const QString& name : names) {
        Filter_details* newFilter = new Filter_details(name,status);
        // newFilter->setName(name);
        // newFilter->setStatus(status);
        newFilter->setCurrentDate(QDate::currentDate());
        Filter_details::addFilterDetailsToList(newFilter);
    }
}
