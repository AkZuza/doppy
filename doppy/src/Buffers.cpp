#include "Buffers.h"
#include <glad/gl.h>

int Element::gl_data_type()
{
    switch(type)
    {
        case DataType::Float32:
            return GL_FLOAT;

        case DataType::Int32:
            return GL_INT;

        case DataType::UInt32:
            return GL_UNSIGNED_INT;
    }

    return 0;
}

int Element::gl_data_size()
{
    switch(type)
    {
        case DataType::Float32:
            return sizeof(float);

        case DataType::Int32:
            return sizeof(int);

        case DataType::UInt32:
            return sizeof(unsigned int);
    }

    return 0;
}

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



VertexArray::VertexArray()
{
    glCreateVertexArrays(1, &m_ID);
}

void VertexArray::Bind()
{
    glBindVertexArray(m_ID);
}

void VertexArray::Unbind()
{
    glBindVertexArray(0);
}

void VertexArray::AddVertexBuffer(VertexBuffer& buffer)
{
    Bind();
    buffer.Bind();
}

void VertexArray::SetIndexBuffer(IndexBuffer& buffer)
{
    Bind();
    buffer.Bind();
}

