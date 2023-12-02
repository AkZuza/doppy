#pragma once

#include <string>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

class ClientWindow
{
public:
	ClientWindow() = default;
	ClientWindow(const std::string& window_title, uint32_t width, uint32_t height);


	// functions to overload
	virtual void OnUserCreate() = 0;
	virtual void OnUserUpdate() = 0;
	virtual void OnUserDestroy() = 0;

	void Run();

	// Layer functions
	void PushLayer();
	void PopLayer();


private:
	void Create();
	void Update();
	void Destroy();

private:
	GLFWwindow* CreateGLFWWindow();
	void GLFWUpdate();
	GLFWwindow* m_GLFWWindow;

private:
	std::string m_WindowTitle;
	uint32_t m_Width, m_Height;
};
