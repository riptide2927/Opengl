#pragma once
#include <glad/glad.h>
#include <unordered_map>
#include <string>
#include <iostream>

class Shader
{
public:
    Shader(const std::string& verfilepath, const std::string& fragfilepath);
    ~Shader();
    int GetUniformLocation(const std::string& name);
private:
    void CreateProgram(const std::string& verfilepath, const std::string& fragfilepath);
    uint32_t CreateShader(const std::string& shadersrc_path, GLenum type);
    const char* ParseFile(const std::string& filepath);
private:
    std::unordered_map<std::string, int> m_UniformLocationCache;
    uint32_t m_Program;
};