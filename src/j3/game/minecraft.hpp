#pragma once
#include "common.hpp"
#include "j3/version/minecraft_version.hpp"

#include <winrt/windows.applicationmodel.h>
#include <winrt/windows.system.h>

using namespace winrt::Windows::ApplicationModel;
using namespace winrt::Windows::System;

class minecraft {
public:
    static constexpr std::wstring_view FAMILY_NAME{ L"Microsoft.MinecraftUWP_8wekyb3d8bbwe" };
    
    minecraft_version version();
    
    std::filesystem::path install_path();
    std::filesystem::path data_path();
    
    bool is_store_managed();
    bool is_gdk();
    
private:
    std::unordered_map<std::string, std::string> version_overrides = {
        { "1.20.1.0", "1.20.0.1" },
        { "1.21.60.0", "1.21.60.10" }
    };
    
    std::optional<AppInfo> get_app_info();
};
