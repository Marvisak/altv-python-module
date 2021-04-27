#pragma once

#include <main.h>

void log_info(std::string const &str)
{
    Core->LogInfo(str);
}

void log_error(std::string const &str)
{
    Core->LogError(str);
}

void log_debug(std::string const &str)
{
    Core->LogDebug(str);
}

void log_warning(std::string const &str)
{
    Core->LogWarning(str);
}
void log_colored(std::string const &str)
{
    Core->LogColored(str);
}