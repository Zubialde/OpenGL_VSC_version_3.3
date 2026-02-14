#include "TextureClass.h"


/// @param internalFormat |1 = JPG, 2 =  PNG|
TextureClass::TextureClass(const char* path,GLint wrapS, GLint wrapT, GLint minFilter, GLint magFilter)
{
    glGenTextures(1, &ID);
    glBindTexture(GL_TEXTURE_2D, ID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapS);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFilter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magFilter);

    stbi_set_flip_vertically_on_load(true);

    // Load texture data
    int width, height, nrChannels;
    unsigned char* data = stbi_load(path, &width, &height, &nrChannels, 0);
    
    if (data)
    {
        GLenum format;
        if(nrChannels == 1)
            format = GL_RED;
        else if(nrChannels == 3)
            format = GL_RGB;
        else if(nrChannels == 4)
            format = GL_RGBA;

        // Generate texture
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        stbi_image_free(data);
    }    
    else
    {
        std::cerr << "Failed to load texture" << std::endl;
        stbi_image_free(data);
    }
}

/// @brief Activates and binds the desired texture
/// @param textureUnit The texture unit to activate DISC: it has to be (eg. TEXTURE0, TEXTURE1...)
void TextureClass::use(GLenum textureUnit)
{
    glActiveTexture(textureUnit);
    glBindTexture(GL_TEXTURE_2D, ID);
}