#include <iostream>

#include <window.h>
#include <renderer.h>
#include <soundTrack.h>
#include <synctracker.h>
#include <file.h>
#include <textloader.h>

#define GLEW_STATIC
#include <GL/glew.h>

#include <glm/gtc/matrix_transform.hpp>

int main(int argc, char** argv)
{
	File file;
	Window window;
	SoundTrack s;
	SyncTracker syncTracker;
	Renderer renderer(window);

	s.PlayMusic("assets/sound/exe_music.mp3");

	glm::vec3	color = glm::vec3(1.0f, 0.0f, 0.0f);
	
	do
	{
		color.x = syncTracker.FetchValue("color:X");
		color.y = syncTracker.FetchValue("color:Y");
		color.z = syncTracker.FetchValue("color:Z");

		glProgramUniform3f(renderer.m_shader, 3, color.x, color.y, color.z);

		syncTracker.Update(s);
		renderer.Render();
		file.UpdateFile(renderer, window, float(s.CurrentTime()));
        
	} while (window.SwapBuffers()/* && (SoundTrack::ms_IsPlaying(&s))*/);

	return 0;
}

int CALLBACK WinMain(
	HINSTANCE   hInstance,
	HINSTANCE   hPrevInstance,
	LPSTR       lpCmdLine,
	int         nCmdShow
)
{
	return main(0, nullptr);
}
