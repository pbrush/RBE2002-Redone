#include <Filter.h>

float Filter::addAndReturnAverage(float value)
{
    addDatum(value);

    float average = 0;
    for(int i = 0; i < dataSize; i++) {
        average += data[i];
    }

    return average/dataSize;

}

float Filter::addAndReturnMedian(float value)   //might need to add some stuff to only make it work after 5 new values
{
    addDatum(value);

    float tempArray[dataSize];
    for(int i = 0; i< dataSize; i++) {
        tempArray[i] = data[i];
    }

    for (int i = 0; i < dataSize; i++) {
        for (int j = i + 1; j < dataSize; j++) {
            if (tempArray[j] < tempArray[i]) {
                float temp1 = tempArray[j];
                float temp2 = tempArray[i];
                tempArray[i] = temp1;
                tempArray[j] = temp2;
            }
        }
    }
    return tempArray[dataSize/2];
}

void Filter::addDatum(float value)
{
    data[filterIndex++] = value;
    if(filterIndex == dataSize) filterIndex = 0;
}