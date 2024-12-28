#pragma once

#include <handleapi.h>
#include <memory>

#include <windows.h>
#include <winnt.h>

namespace CmpProc {
    /// WIN32ZAPIのオブジェクトハンドルをラップした型
    using object_handle = std::unique_ptr<
        std::remove_pointer_t<HANDLE>,
        decltype([](HANDLE h){
            CloseHandle(h);
        })
    >;
}