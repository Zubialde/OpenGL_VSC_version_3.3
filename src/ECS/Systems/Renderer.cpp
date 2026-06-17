#include "ECS/Systems/Renderer.h"

void Renderer::Render(const std::vector<RenderPackage>& renderQueue, const GlobalRenderPackage& globalData)
{
    glEnable(GL_DEPTH_TEST);
    for(const RenderPackage& renderPackage : renderQueue)
    {
        glUseProgram(renderPackage.shaderID);

        glUniformMatrix4fv(glGetUniformLocation(renderPackage.shaderID, "model"), 1, GL_FALSE, glm::value_ptr(renderPackage.modelMatrix));
        glUniformMatrix4fv(glGetUniformLocation(renderPackage.shaderID, "view"), 1, GL_FALSE, glm::value_ptr(globalData.viewMatrix));
        glUniformMatrix4fv(glGetUniformLocation(renderPackage.shaderID, "projection"), 1, GL_FALSE, glm::value_ptr(globalData.projectionMatrix));

        if(renderPackage.textureID[0] != 0)
        {
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, renderPackage.textureID[0]);
        }

        glBindVertexArray(renderPackage.vaoID);

        glDrawElements(GL_TRIANGLES, renderPackage.indexCount, GL_UNSIGNED_INT, nullptr);
    }
}