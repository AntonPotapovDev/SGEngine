#include "gwindow.h"
#include <stdexcept>

GWindow::GWindow(int width, int height, const char* name, int majorV, int minorV)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, majorV);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minorV);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	
	window = glfwCreateWindow(width, height, name, nullptr, nullptr);
	if (window == NULL)
		throw std::exception("Error: window initialization failed!");
	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
		throw std::exception("Error: getting access to openGL functions failed!");

	glViewport(0, 0, width, height);
	glEnable(GL_DEPTH_TEST);
}
GWindow::~GWindow()
{
	glfwTerminate();
}
void GWindow::setParameter(int par, int newValue)
{
	glfwWindowHint(par, newValue);
}
void GWindow::setResizable(bool resizable)
{
	if (resizable)
		glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
	else
		glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
}
void GWindow::setCursorEnable(bool enable)
{
	if (enable)
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	else
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}
void GWindow::setKeyCallback(GLFWkeyfun func)
{
	glfwSetKeyCallback(window, func);
}
void GWindow::setCursorPosCallback(GLFWcursorposfun func)
{
	glfwSetCursorPosCallback(window, func);
}
void GWindow::pollEvents()
{
	glfwPollEvents();
}
void GWindow::swapBuffers()
{
	glfwSwapBuffers(window);
}
GLFWwindow* GWindow::getWindow()
{
	return window;
}
int GWindow::getWidth()
{
	return screenWidth;
}
int GWindow::getHeight()
{
	return screenHeight;
}
bool GWindow::windowShouldClose()
{
	return glfwWindowShouldClose(window);
}