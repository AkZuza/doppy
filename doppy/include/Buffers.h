#pragma once

enum DataType {
	Float32, Int32, UInt32
};

struct Element {
	const char* name;
	DataType type;

	int gl_data_type();
	int gl_data_size();
};

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

class VertexArray
{
public:
	VertexArray();
	void AddVertexBuffer(VertexBuffer& buffer);
	void SetIndexBuffer(IndexBuffer& buffer);
	void Bind();
	void Unbind();

private:
	unsigned int m_ID;
};