#pragma once

#include <string>

#include <windows.h>

namespace CompReg {
#ifdef _WIN32
    /// Win32APIの文字型を扱う文字列型．
    using win32str = std::basic_string<TCHAR>;
#endif
};