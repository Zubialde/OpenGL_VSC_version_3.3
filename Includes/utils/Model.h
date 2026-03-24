#ifndef MODEL_H
#define MODEL_H

#include <utils/Components.h>

#include <iostream>
#include <glad/glad.h>

class Model : public Components{
    public:
        Model();

        virtual void Update(float deltaTime);

        std::unique_ptr<GLuint> vao;
    private:
};

#endif