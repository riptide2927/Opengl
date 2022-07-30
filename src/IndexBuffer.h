#pragma once
#include <glad/glad.h>

class IndexBuffer
{
public:
    IndexBuffer(const void* data, int size);
    ~IndexBuffer();
    void Bind();
    void Unbind();
private:
    uint32_t m_Buffer;
};