#ifndef MODEL_H
#define MODEL_H

#include <utils/Component.h>

class Model : public Component{
    public:
        Model();

        void Update(float deltaTime)override ;

         void OnDestroy() override;

    private:
};

#endif