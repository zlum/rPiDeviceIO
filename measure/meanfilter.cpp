#include "meanfilter.h"

MeanFilter::MeanFilter(uint16_t smNumber):
    smNumber(smNumber)
{
}

double MeanFilter::getFilteredValue(double value)
{
    samples.push_back(value);

    double sum = 0;

    for(double sample : samples)
    {
        sum += sample;
    }

    if(samples.size() == smNumber)
    {
        samples.pop_front();
    }

    return sum / samples.size();
}

uint16_t MeanFilter::getSmNumber() const
{
    return smNumber;
}

void MeanFilter::setSmNumber(uint16_t smNumber)
{
    uint16_t diff;

    if(smNumber < this->smNumber)
    {
        diff = this->smNumber - smNumber;
        samples.erase(samples.begin(), samples.begin() + diff + 1);
    }

    this->smNumber = smNumber;
}
