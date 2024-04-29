#ifndef FILTER_DETAILS_H
#define FILTER_DETAILS_H

#include <QObject>
#include <QDate>

class Filter_details:public QObject
{
    Q_OBJECT
private:
    QString Name;
    int status;
    QDate currentDate;
public:
    Filter_details(QObject *parent = nullptr);
    Filter_details(QString name,int status);
    // Getter methods
    QString getName() const;
    int getStatus() const;
    QDate getCurrentDate() const;

    // Setter methods
    void setName(const QString& name);
    Filter_details* setStatus(int newStatus);
    void setCurrentDate(const QDate& date);

    // Static member for storing details
    static std::vector<Filter_details*> FilterList;

    // Static method to add details to the list
    static void addFilterDetailsToList(Filter_details* newDetails);


    static void createAndAddFilterDetails(const QStringList& names, int status);
};

#endif // DETAILS_H
