#include "CregHandler.hpp"
#include "win_string.hpp"

int main() {
    // キーの書込ハンドルを取得する
    const CompReg::win32str Path = TEXT("SYSTEM\\CurrentControlSet\\Control\\Keyboard Layout");
    const auto Handle = CompReg::OpenRegKey(HKEY_LOCAL_MACHINE, Path, KEY_SET_VALUE);

    // ハンドルが有効かを調べる
    if (!Handle.has_value()) {
        return Handle.error();
    }
    
    // 値を書き込む
    const std::vector<uint8_t> bin = {
        0x00, 0x00, 0x00 ,0x00,
        0x00, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00,
        0x1d, 0x00, 0x3a, 0x00,
        0x00, 0x00, 0x00, 0x00
    };
    
    return CompReg::WriteKeyValueBin(*Handle, TEXT("Scancode Map"), bin);
}