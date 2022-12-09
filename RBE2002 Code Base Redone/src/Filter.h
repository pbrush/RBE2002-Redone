#pragma once

#include <Arduino.h>


class Filter {
    const int dataSize = 5;
    float data[5];
    uint8_t filterIndex = 0;

    public:
        Filter() {
            for(int i : data){
                data[i] = 0;
            }
        }

        void addDatum(float value);
        float addAndReturnAverage(float value);
        float addAndReturnMedian(float value);
        void swap(float v1, float v2);
};