#ifndef MEANFILTER_H
#define MEANFILTER_H

#include <cstdint>
#include <deque>

//Moving average filter

class MeanFilter
{
public:
    explicit MeanFilter(unsigned smNumber = 10);
    virtual ~MeanFilter();

    double getFilteredValue(double value);

    unsigned getSmNumber() const;
    unsigned getMaxSmNumber() const;
    void setMaxSmNumber(unsigned smNumber);

private:
    unsigned smNumber;
    std::deque<double> samples;
};

#endif // MEANFILTER_H
