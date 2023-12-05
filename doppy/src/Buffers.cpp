#include "Buffers.h"
#include <glad/gl.h>

VertexBuffer::VertexBuffer(unsigned int size, void *ptr)
{
    glCreateBuffers(1, &m_ID);
    glBindBuffer(GL_ARRAY_BUFFER, m_ID);
    glBufferData(GL_ARRAY_BUFFER, size, ptr, GL_STATIC_DRAW); // static draw assumption
}

unsigned int VertexBuffer::GetBufferID()
{
    return m_ID;
}

void VertexBuffer::UploadBuffer(unsigned int size, void *ptr)
{
    Bind();
    glBufferData(GL_ARRAY_BUFFER, size, ptr, GL_STATIC_DRAW);
}

void VertexBuffer::Bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, m_ID);
}

void VertexBuffer::Unbind()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

IndexBuffer::IndexBuffer(unsigned int size, void *ptr)
{
    glCreateBuffers(1, &m_ID);
    Bind();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, ptr, GL_STATIC_DRAW);
}

unsigned int IndexBuffer::GetBufferID()
{
    return m_ID;
}

void IndexBuffer::UploadBuffer(unsigned int size, void *ptr)
{
    Bind();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, ptr, GL_STATIC_DRAW);
}

void IndexBuffer::Bind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
}

void IndexBuffer::Unbind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

