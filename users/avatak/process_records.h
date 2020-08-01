#pragma once
#include "avatak.h"

#if defined(KEYMAP_SAFE_RANGE)
#   define USERSPACE_SAFE_RANGE KEYMAP_SAFE_RANGE
#else
#   define USERSPACE_SAFE_RANGE SAFE_RANGE
#endif

enum userspace_custom_keycodes {
    ALIGN = USERSPACE_SAFE_RANGE,
    ARRAY,
    DISPMTH,
    ENUM,
    ITEM,
    ITEMIZE,
    LINEMTH,
    NEW_SAFE_RANGE
}


