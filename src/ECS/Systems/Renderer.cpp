#include "ECS/Systems/Renderer.h"

void Renderer::Render(const std::vector<RenderPackage>& renderQueue, const GlobalRenderPackage& globalData)
{
    for(const RenderPackage& renderPackage : renderQueue)
    {
        glUseProgram(renderPackage.shaderID);

        glUniformMatrix4fv(glGetUniformLocation(renderPackage.shaderID, "model"), 1, GL_FALSE, glm::value_ptr(renderPackage.modelMatrix));

        glBindVertexArray(renderPackage.vaoID);

        glDrawElements(GL_TRIANGLES, renderPackage.indexCount, GL_UNSIGNED_INT, nullptr);
    }
}