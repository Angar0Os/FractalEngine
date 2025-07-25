#ifndef FRACTALENGINE_WINDOW_H
#define FRACTALENGINE_WINDOW_H

#include <glm/glm.hpp>

struct GLFWwindow;
struct GLFWmonitor;

class Window final
{
	GLFWwindow* m_window = nullptr;
	GLFWmonitor* m_monitor = nullptr;
	glm::ivec2   m_size;

	void FullScreenMode(GLFWwindow* window);

	void ErrorCallBack(int error, const char* description);

	static void s_KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

public:
	static const int32_t kDEFAULT_WIDTH = 800, kDEFAULT_HEIGHT = 600;

	explicit Window(const glm::ivec2& size = glm::ivec2(kDEFAULT_WIDTH, kDEFAULT_HEIGHT));
	~Window();

	bool SwapBuffers();
	glm::ivec2 Size() const;
};

#endif //FRACTALENGINE_WINDOW_H
