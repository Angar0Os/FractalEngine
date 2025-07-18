#ifndef FRACTALENGINE_SOUNDTRACK_H
#define FRACTALENGINE_SOUNDTRACK_H

#include <iostream>

#include <bass.h>
#include <rocket/sync.h>

#pragma comment(lib, "bass.lib")

class SoundTrack
{
public:
	explicit SoundTrack();
	~SoundTrack();

	void PlayMusic(std::string musicPath);
	static void* GetFile(std::string* file);

	static void Pause(void* d, int flag);
	static void SetRow(void* d, int row);
	static int  IsPlaying(void* d);

	double CurrentRow() const;
	double CurrentTime() const;

	HSTREAM m_streamHandle;

	static sync_cb s_syncLink;

	const float tempo = 150.0f;

#define ROWS_PER_BEAT (8.0)
	const double m_rowRate = (tempo / 60.0) * ROWS_PER_BEAT;
};

#endif // FRACTALENGINE_SOUNDTRACK_H



