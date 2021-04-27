#pragma once

#include <main.h>

void Log(std::string const &str)
{
    Core->LogInfo(str);
}

void LogError(std::string const &str)
{
    Core->LogError(str);
}

void LogDebug(std::string const &str)
{
    Core->LogDebug(str);
}

void LogWarning(std::string const &str)
{
    Core->LogWarning(str);
}
void LogColored(std::string const &str)
{
    Core->LogColored(str);
}