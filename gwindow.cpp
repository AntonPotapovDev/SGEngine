#include "gwindow.h"
#include <stdexcept>

GWindow::GWindow(int width, int height, const char* name, int majorV, int minorV)
{
	currentFrame = 0.0f;
	lastFrame = 0.0f;
	deltaTime = 0.0f;

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

	clearColor = new GLfloat[4];
	for (int i = 0; i < 4; i++)
	{
		clearColor[i] = 1.0f;
	}
}
GWindow::~GWindow()
{
	delete[] clearColor;
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
void GWindow::setClearColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a)
{
	clearColor[0] = r;
	clearColor[1] = g;
	clearColor[2] = b;
	clearColor[3] = a;
}
void GWindow::pollEvents()
{
	glfwPollEvents();
	currentFrame = glfwGetTime();
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;
}
void GWindow::swapBuffers()
{
	glfwSwapBuffers(window);
}
void GWindow::clear(bool needToClearDepth)
{
	glClearColor(clearColor[0], clearColor[1], clearColor[2], clearColor[3]);
	if (needToClearDepth)
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	else
		glClear(GL_COLOR_BUFFER_BIT);
}
GLFWwindow* GWindow::getWindow()
{
	return window;
}
GLfloat GWindow::getDeltaTime()
{
	return deltaTime;
}
GLfloat GWindow::getTime()
{
	return glfwGetTime();
}
int GWindow::getWidth()
{
	return screenWidth;
}
int GWindow::getHeight()
{
	return screenHeight;
}
bool GWindow::shouldClose()
{
	return glfwWindowShouldClose(window);
}