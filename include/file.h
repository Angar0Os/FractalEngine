#ifndef FRACTALENGINE_FILE_H
#define FRACTALENGINE_FILE_H

#include <filesystem>

enum class FileStatus { MODIFIED, NOTHING_CHANGED };

class Renderer;
class Window;

class File
{
public:
    explicit File();
    ~File() noexcept;

    void UpdateFile(Renderer& render, Window& window, float t);
    void CheckModification();

    FileStatus status;

    std::filesystem::file_time_type fs_changed;
    std::filesystem::file_time_type vs_changed;

    const char* fragment_shader_file = "assets/shaders/shader.fs";
    const char* vertex_shader_file = "assets/shaders/shader.vs";
};

#endif // FRACTALENGINE_FILE_H

