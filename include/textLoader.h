#ifndef FRACTALENGINE_TEXTLOADER_H
#define FRACTALENGINE_TEXTLOADER_H

class textLoader
{
	unsigned int texture;
public:
	void LoadImage(const char* image_path, int width, int height, int nrChannels, int req_comp);
	void Use(unsigned int unit);
};


#endif // FRACTALENGINE_TEXTLOADER_H

