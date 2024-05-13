//
// Created by Dobricean Ioan Dorian on 10.05.2024.
#include "BarChart.h"
#include <algorithm>

BarChart::BarChart(const std::string& title, int size, int count, const std::vector<BarChartStruct>& result) {
    this->title = title;
    this->size = size;
    this->result = result;
    this->count = count;
    this->maxNum = getMaxValue(result);
    this->height = maxNum / this->count;
}

double BarChart::getMaxValue(const std::vector<BarChartStruct>& input) {
    double max = 0;
    for (const auto& i : input) {
        if (i.value > max) {
            max = i.value;
        }
    }
    return max;
}

void BarChart::numString(int num, int ma) {
    std::string n = std::to_string(num);
    std::string mn = std::to_string(ma);

    int c = n.size();
    int mc = mn.size();

    if (c < mc) {
        for (int i = 0; i < mc - c; i++) std::cout << "0";
    }
    std::cout << n;
}

void BarChart::show() {
    int x_width = (int)this->result.size() * this->size;

    std::cout << "====[ " << this->title << " ]";
    for (int z = 0; z < x_width * 2; z++) std::cout << "=";
    std::cout << std::endl;
    std::cout << std::endl;
    int maxGap = std::to_string(this->maxNum).size();

    for (const auto& r : this->result) {
        for (int w = 0; w < maxGap; w++) std::cout << " ";
        std::cout << "| " << r.name << " : " << r.value;
        if (r.value == this->maxNum) std::cout << " √ (Max)" << std::endl;
        else std::cout << std::endl;
    }

    std::cout << std::endl;
    for (double y = 0; y < this->height; y++) {
        numString((this->height - y) * this->count, this->maxNum);
        numString(-(this->height - y) * this->count - 1, this->maxNum);
        std::cout << "| ";
        for (int x = 0; x < x_width; x++) {
            if (x % size == 0) {
                int index = x / size;
                double value = this->result[index].value;

                if (this->height - y <= (double)(value / this->count)) {
                    std::cout << "▩▩▩"; //
                } else {
                    std::cout << "   ";
                }
            } else {
                std::cout << "   ";
            }
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < x_width + 10; i++) std::cout << "▬▬▬";
    std::cout << std::endl;
    for (int a = 0; a < 10; a++) {
        std::cout << "  ";
        for (int w = 0; w < 3; w++) std::cout << " ";
        for (int i = 0; i < x_width; i++) {
            if (i % size == 0) {
                std::string n = this->result[i / size].name;
                if (a < (int)n.size()) {
                    std::cout << " " << n[a] << " ";
                } else {
                    std::cout << "   ";
                }
            } else {
                std::cout << "   ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

//
