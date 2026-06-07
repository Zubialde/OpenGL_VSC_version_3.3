#ifndef SORTER_H
#define SORTER_H

#include <utils/Singleton.h>
#include <renderer/PreRenderer.h>

#include <vector>

class Sorter : public Singleton<Sorter>
{
    friend class Singleton<Sorter>;
    public:

    void Sort(std::vector<RenderPackage>* renderPackages);

    private:
    Sorter() = default;
    ~Sorter() = default;

};
#endif