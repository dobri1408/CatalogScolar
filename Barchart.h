//
// Created by Dobricean Ioan Dorian on 10.05.2024.
//

#ifndef OOP_BARCHART_H
#define OOP_BARCHART_H
#pragma once
#include <vector>
#include <string>
#include <iostream>

// Forward declare a struct that will be used in the BarChart class.
struct BarChartStruct {
    std::string name;
    double value;
};

class BarChart {
private:
    std::vector<BarChartStruct> result;
    std::string title;
    int size;
    double height;
    double maxNum;
    int count;

    double getMaxValue(const std::vector<BarChartStruct>& input);
    void numString(int num, int ma);

public:
    BarChart(const std::string& title, int size, int count, const std::vector<BarChartStruct>& result);
    void show();
};

#endif //OOP_BARCHART_H
