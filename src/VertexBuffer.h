#pragma once
#include <glad/glad.h>

class VertexBuffer
{
public:
    VertexBuffer(const void* data, int size);
    ~VertexBuffer();
    void Bind();
    void Unbind();
private:
    uint32_t m_Buffer;
};