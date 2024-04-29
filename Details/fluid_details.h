#ifndef FLUID_DETAILS_H
#define FLUID_DETAILS_H

#include <QObject>
#include <QDate>

class Fluid_details:public QObject
{
    Q_OBJECT
private:
    QString Name;
    int status;
    QDate currentDate;
public:
    Fluid_details(QObject *parent = nullptr);    // Getter methods
    Fluid_details(QString name,int status);
    QString getName() const;
    int getStatus() const;
    QDate getCurrentDate() const;

    // Setter methods
    void setName(const QString& name);
    Fluid_details* setStatus(int newStatus);
    void setCurrentDate(const QDate& date);

    // Static member for storing details
    static std::vector<Fluid_details*> FluidList;

    // Static method to add details to the list
    static void addFluidDetailsToList(Fluid_details* newDetails);


     static void createAndAddFluidDetails(const QStringList& names, int status);
};


#endif // FLUID_DETAILS_H
