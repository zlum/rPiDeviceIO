#ifndef MEANFILTER_H
#define MEANFILTER_H

#include <cstdint>
#include <deque>

//Moving average filter

class MeanFilter
{
public:
    explicit MeanFilter(uint16_t smNumber = 10);
    virtual ~MeanFilter() {}

    double getFilteredValue(double value);

    uint16_t getSmNumber() const;
    void setSmNumber(uint16_t smNumber);

private:
    uint16_t smNumber;
    std::deque<double> samples;
};

#endif // MEANFILTER_H
