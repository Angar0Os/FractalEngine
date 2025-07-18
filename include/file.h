#ifndef FRACTALENGINE_FILE_H
#define FRACTALENGINE_FILE_H

#include <filesystem>
#include <chrono>
#include <thread>
#include <unordered_map>
#include <string>
#include <functional>

#include <window.h>
#include <renderer.h>

enum class FileStatus { modified, nothingchanged };

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

#endif // REVISION2022_FILE_H

