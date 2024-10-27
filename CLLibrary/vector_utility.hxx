#pragma once

#include <vector>
#include <algorithm>

template <typename T>
void addIfNotFound(std::vector<T>& vec, const T& value)
{
    if (std::find(vec.begin(), vec.end(), value) == vec.end())
        vec.push_back(value);
}

template <typename T>
T findOrAdd(std::vector<T>& vec, const T& value)
{
    auto element = std::find(vec.begin(), vec.end(), value);
    if (element != vec.end())
        return *element;
    vec.push_back(value);
    return vec.back();
}