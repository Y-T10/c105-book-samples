#pragma once

#include <expected>

#include "win_string.hpp"

namespace CmpProc {
    /**
     * @brief 管理者権限でプログラムを起動する
     * @param execPath プログラムへのパス
     * @return 成功すれば起動したプロセスのハンドル．失敗したらnullptrを返す．
     */
    const HANDLE ExecElevated(
        const CompReg::win32str& execPath, const CompReg::win32str& param = TEXT(""),
        const bool isShow = false
    ) noexcept;

    /**
     * @brief プロセスが終了するまで待機し、その返値を返す．
     * @param handle プロセスのハンドル
     * @return 成功すればプロセスの返値を、失敗すればエラーコードを返す．
     */
    const std::expected<DWORD, DWORD> WaitUntilExit(const HANDLE& handle) noexcept;
}