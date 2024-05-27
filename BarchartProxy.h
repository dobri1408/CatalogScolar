// BarChartProxy.h

#ifndef OOP_BARCHARTPROXY_H
#define OOP_BARCHARTPROXY_H

#include "IBarchart.h"
#include "Barchart.h"

class BarChartProxy : public IBarChart {
private:
    std::string title;
    int size;
    int count;
    std::vector<BarChartStruct> result;
    BarChart* realBarChart;

public:
    BarChartProxy(const std::string& title, int size, int count, const std::vector<BarChartStruct>& result);
    ~BarChartProxy();

    void show() override;
};

#endif //OOP_BARCHARTPROXY_H
