#ifndef FRACTALENGINE_TEXTLOADER_H
#define FRACTALENGINE_TEXTLOADER_H

#include <iostream>

#define GLEW_STATIC
#include <GL/glew.h>

#include <GLFW/glfw3.h>



class textLoader
{
	unsigned int texture;
public:
	void loadImage(const char* image_path, int width, int height, int nrChannels, int req_comp);
	void Use(unsigned int unit);
};


#endif // FRACTALENGINE_TEXTLOADER_H

