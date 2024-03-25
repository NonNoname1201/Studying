//
// Created by User on 24.11.2023.
//

#ifndef UNTITLED_MIX_H
#define UNTITLED_MIX_H

#include <boost/fusion/include/vector.hpp>
#include <boost/fusion/include/for_each.hpp>
#include <map>
#include <typeinfo>

struct TypeCounter
{
    std::map<std::string, int> &counts;

    TypeCounter(std::map<std::string, int> &counts) : counts(counts) {}

    template <typename T>
    void operator()(T &t) const
    {
        ++counts[typeid(T).name()];
    }
};

template <typename FusionVector>
std::map<std::string, int> countTypes(FusionVector &fv)
{
    std::map<std::string, int> counts;
    boost::fusion::for_each(fv, TypeCounter(counts));
    return counts;
}

#endif // UNTITLED_MIX_H
