// BarChartProxy.h

#ifndef OOP_BARCHARTPROXY_H
#define OOP_BARCHARTPROXY_H

#include "IBarChart.h"
#include "BarChart.h"

class BarChartProxy : public IBarChart {
private:
    BarChart* realBarChart;
    std::string title;
    int size;
    int count;
    std::vector<BarChartStruct> result;

public:
    BarChartProxy(const std::string& title, int size, int count, const std::vector<BarChartStruct>& result);
    ~BarChartProxy();

    void show() override;
};

#endif //OOP_BARCHARTPROXY_H
