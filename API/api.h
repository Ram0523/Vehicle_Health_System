#ifndef API_H
#define API_H

#include <QObject>
#include "../Details/filter_details.h"
#include "../Details/fluid_details.h"

class api: public QObject
{
    Q_OBJECT
public:
    api();
    ~api();



private:
    Filter_details*  filterd;
    Fluid_details* fluidd;

public:
    std::vector<Filter_details*>& getFilterList();
    std::vector<Fluid_details*>& getFluidList();
};

#endif // API_H
