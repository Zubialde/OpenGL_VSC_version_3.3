#ifndef RENDERER_H
#define RENDERER_H

#include <ECS/Systems/PreRenderer.h>
#include <utils/Singleton.h>

#include <memory>
#include <vector>

class Renderer : public Singleton<Renderer>
{
    friend class Singleton<Renderer>;
    public:   
        void Render(const std::vector<RenderPackage>& renderQueue, const GlobalRenderPackage& globalData);
    private:

        Renderer() = default;
        ~Renderer() = default;    
};
#endif