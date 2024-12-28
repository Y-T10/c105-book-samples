#include "CprocExec.hpp"

namespace CmpProc {
    const HANDLE ExecElevated(const CompReg::win32str& execPath, const CompReg::win32str& param, const bool isShow) noexcept {
        const SHELLEXECUTEINFO info = {
            .cbSize = sizeof(SHELLEXECUTEINFO),
            .fMask = SEE_MASK_DEFAULT | SEE_MASK_NOCLOSEPROCESS,
            .hwnd = NULL,
            .lpVerb = TEXT("runas"),
            .lpFile = execPath.c_str(),
            .lpParameters = param.empty()? nullptr: param.c_str(),
            .lpDirectory = nullptr,
            .nShow = isShow? SW_SHOW: SW_HIDE,
            .hInstApp = nullptr,
            .lpIDList = nullptr,
            .lpClass = nullptr,
            .hkeyClass = nullptr,
            .dwHotKey = 0,
            .hProcess = nullptr
        };

        if (ShellExecuteEx(const_cast<SHELLEXECUTEINFO*>(&info))) {
            return info.hProcess;
        }
        return nullptr;
    }

    const std::expected<DWORD, DWORD> WaitUntilExit(const HANDLE& handle) noexcept {
        // プログラムの終了を待つ
        WaitForSingleObject(handle, INFINITE);

        // プログラムの終了コードを取得する．
        if (DWORD code = 0; GetExitCodeProcess(handle, &code) != 0) {
            return std::expected<DWORD, DWORD>(code);
        }
        return std::unexpected(GetLastError());
    }
}