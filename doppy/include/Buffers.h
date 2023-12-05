#pragma once

class VertexBuffer
{
public:
	VertexBuffer(unsigned int size, void* ptr = nullptr);

	unsigned int GetBufferID();
	void UploadBuffer(unsigned int size, void* ptr);
	void Bind();
	void Unbind();

private:
	unsigned int m_ID;
	unsigned int m_size;
};


class IndexBuffer
{
public:
	IndexBuffer(unsigned int size, void* ptr = nullptr);

	unsigned int GetBufferID();
	void UploadBuffer(unsigned int size, void* ptr);
	void Bind();
	void Unbind();

private:
	unsigned int m_ID;
	unsigned int m_size;
};