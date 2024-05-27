/// IBarChart.h

#ifndef OOP_IBARCHART_H
#define OOP_IBARCHART_H

#include <vector>
#include <string>

struct BarChartStruct {
    std::string name;
    double value;
};

class IBarChart {
public:
    virtual void show() = 0;
    virtual ~IBarChart() {}
};

#endif //OOP_IBARCHART_H
