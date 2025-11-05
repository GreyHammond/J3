#pragma once

struct sidebar_model {
    bool home_selected{ true };
    bool mods_selected{ false };
    bool archives_selected{ false };
    bool versions_selected{ false };
    bool settings_selected{ false };

    bool pinned{ false };
};
