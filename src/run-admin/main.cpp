#include "CprocExec.hpp"

int main(int argc, char* argv[]) {
    // 引数がなければエラーコードを返す
    if (argc < 1) {
        return ERROR_BAD_ARGUMENTS;
    }

    // 第一引数のプログラムを管理者特権で動かすプロセスを立ち上げる
    const HANDLE Handle = CmpProc::ExecElevated(argv[1]);
    if (Handle == INVALID_HANDLE_VALUE) {
        return GetLastError();
    }

    // プロセスが終わるまで待機し、その終了コードを得る
    const auto ExitCode = CmpProc::WaitUntilExit(Handle);
    if (!ExitCode) {
        return ExitCode.error();
    }

    // プロセスを閉じる
    CloseHandle(Handle);

    // プログラムの終了コードを返す．
    return *ExitCode;
}