#pragma once
#include <glad/glad.h>
#include <vector>

struct VertexBufferElement
{
    uint32_t type;
    uitn32_t count;
    bool normalized;
};


class VertexBufferLayout
{
public:
    VertexBufferLayout();

    template<typename T>
    void Push(int count)
    {
        static_assert(false);
    }

    template<>
    void Push<float>(int count)
    {
        m_Elements.push_back({GL_FLOAT, count, false});
        
    }

    template<>
    void Push<uint32_t>(int Count)
    {
        m_Elements.push_back({GL_UNSIGNED_INT, count, false});
    }

    template<>
    void Push<unsigned char>(int Count)
    {
        m_Elements.push_back({GL_UNSIGNED_BYTE, count, false});
    }

    inline unsigned int GetStride() const { return m_Stride; }

private:
    std::vector<VertexBufferElement> m_Elements;
};