// BarChartProxy.cpp

#include "BarChartProxy.h"
#include <iostream>

BarChartProxy::BarChartProxy(const std::string& title, int size, int count, const std::vector<BarChartStruct>& result)
        : title(title), size(size), count(count), result(result), realBarChart(nullptr) {}

BarChartProxy::~BarChartProxy() {
    delete realBarChart;
}

void BarChartProxy::show() {
    if (!realBarChart) {
        realBarChart = new BarChart(title, size, count, result);
        std::cout << "BarChart created lazily." << std::endl;
    }
    std::cout << "Displaying BarChart:" << std::endl;
    realBarChart->show();
}
