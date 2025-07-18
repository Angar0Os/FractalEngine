#ifndef FRACTALENGINE_RENDERER_H
#define FRACTALENGINE_RENDERER_H

#include <cstdint>
#include <string>

class Window;

class Renderer final
{
	uint32_t vao;
	uint32_t vertexBuffer;

	float positions[6];


	static unsigned int CompileShader(unsigned int type, const std::string& source);

public:
	uint32_t m_shader = 0;
	uint32_t m_buffer = 0;

	std::string m_vertexShader = "";
	std::string m_fragmentShader = "";

	void ReadAndWriteShader(const char* vertexPath, const char* fragmentPath);
	static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);

	explicit Renderer(const Window& window);
	~Renderer() noexcept;

	void Render();
};

#endif //FRACTALENGINE_RENDERER_H
