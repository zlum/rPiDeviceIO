#include "meanfilter.h"

MeanFilter::MeanFilter(uint16_t smNumber):
    smNumber(smNumber)
{
    if(this->smNumber == 0) // Filtration off
        this->smNumber = 1;
}

double MeanFilter::getFilteredValue(double value)
{
    samples.push_back(value);

    double sum = 0;

    for(double sample : samples)
    {
        sum += sample;
    }

    sum /= samples.size();

    if(samples.size() == smNumber)
    {
        samples.pop_front();
    }

    return sum;
}

uint16_t MeanFilter::getSmNumber() const
{
    return smNumber;
}

void MeanFilter::setSmNumber(uint16_t smNumber)
{
    uint16_t diff;

    if(smNumber == 0) // Filtration off
        smNumber = 1;

    if(smNumber < this->smNumber)
    {
        diff = this->smNumber - smNumber;
        samples.erase(samples.begin(), samples.begin() + diff);
    }

    this->smNumber = smNumber;
}
