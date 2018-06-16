#include "meanfilter.h"

MeanFilter::MeanFilter(unsigned smNumber):
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

MeanFilter::~MeanFilter()
{}

unsigned MeanFilter::getSmNumber() const
{
    return samples.size();
}

unsigned MeanFilter::getMaxSmNumber() const
{
    return smNumber;
}

void MeanFilter::setMaxSmNumber(unsigned smNumber)
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
