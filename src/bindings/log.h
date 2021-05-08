#pragma once

#include <main.h>

void Log(const std::string &eventName)
{
    Core->LogColored(eventName);
}

void LogError(const std::string &eventName)
{
    Core->LogError(eventName);
}

void LogDebug(const std::string &eventName)
{
    Core->LogDebug(eventName);
}

void LogWarning(const std::string &eventName)
{
    Core->LogWarning(eventName);
}
