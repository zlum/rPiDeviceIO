#pragma once

template<typename Time>
class Timer
{
public:
    virtual ~Timer() = 0;

    virtual Time getTime() = 0;
};

template<typename Time>
inline Timer<Time>::~Timer() = default;
