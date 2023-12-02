#include "ClientWindow.h"
#include <glad/gl.h>

ClientWindow::ClientWindow(const std::string& window_title, uint32_t width, uint32_t height)
	: m_WindowTitle(window_title), m_Width(width), m_Height(height)
{
	m_GLFWWindow = CreateGLFWWindow();
}

void ClientWindow::Run()
{
	Create();

	while (!glfwWindowShouldClose(m_GLFWWindow))
		Update();

	Destroy();
}

void ClientWindow::PushLayer()
{
}

void ClientWindow::PopLayer()
{
}

void ClientWindow::Create()
{
	OnUserCreate();
}

void ClientWindow::Update()
{
	OnUserUpdate();
	GLFWUpdate();
}

void ClientWindow::Destroy()
{
	OnUserDestroy();
	glfwDestroyWindow(m_GLFWWindow);
	glfwTerminate();
}

GLFWwindow* ClientWindow::CreateGLFWWindow()
{

	glfwInit();

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);

	GLFWwindow* ptr = glfwCreateWindow(m_Width, m_Height, m_WindowTitle.c_str(), nullptr, nullptr);

	glfwMakeContextCurrent(ptr);

	gladLoadGL((GLADloadfunc)glfwGetProcAddress);
	glfwSwapInterval(1);

	return ptr;
}

void ClientWindow::GLFWUpdate()
{
	glfwSwapBuffers(m_GLFWWindow);
	glfwPollEvents();
}