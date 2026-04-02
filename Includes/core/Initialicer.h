#ifndef INITIALISER_H
#define INITIALISER_H

#include <renderer/ShaderClass.h>
#include <renderer/TextureClass.h>


class Initialicer
{
    public:
        Initialicer() {
            ShaderClass::SetShaderPath(SHADER_DIR);
            TextureClass::SetTexturePath(TEXTURE_DIR);
        };

        ~Initialicer() {
            ShaderClass::SetShaderPath("");
            TextureClass::SetTexturePath("");
        };

    private:

};

#endif