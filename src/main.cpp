#include <iostream>

#include <window.h>
#include <renderer.h>
#include <soundTrack.h>
#include <synctracker.h>
#include <file.h>
#include <textloader.h>

#include <glm/gtc/matrix_transform.hpp>

int main(int argc, char** argv)
{
	File file;
	Window window;
	SoundTrack s;
	SyncTracker syncTracker;
	Renderer renderer(window);

	//s.PlayMusic("assets/sound/your_music_name");

	do
	{
		syncTracker.Update(s);
		renderer.Render();
		file.UpdateFile(renderer, window, float(s.CurrentTime()));
        
	} while (window.SwapBuffers()/* && (SoundTrack::ms_IsPlaying(&s)) <-- Enable this for demo exe.*/);

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
