#pragma once

#if !defined(TAPPING_TERM)
#   define TAPPING_TERM 150
#endif


#if !defined(TAPPING_TOGGLE)
#   define TAPPING_TOGGLE 2
#endif

#define IGNORE_MOD_TAP_INTERRUPT

#ifdef AUDIO_ENABLE
#   include "custom_songs.h"
#   if !defined(STARTUP_SONG)
/*
#       define STARTUP_SONG SONG(\
            Q__NOTE(_B2), QD_NOTE(_DF3), Q__NOTE(_D3), QD_NOTE(_E3), \
            QD_NOTE(_GF3), QD_NOTE(_D3), H__NOTE(_GF3), BD_NOTE(_REST), \
            QD_NOTE(_F3), QD_NOTE(_DF3), H__NOTE(_F3), BD_NOTE(_REST), \
            QD_NOTE(_E3), QD_NOTE(_C3), H__NOTE(_E3), BD_NOTE(_REST), E__NOTE(_REST), \
            Q__NOTE(_B2), QD_NOTE(_DF3), Q__NOTE(_D3), QD_NOTE(_E3), \
            Q__NOTE(_GF3), QD_NOTE(_D3), Q__NOTE(_GF3), \
            QD_NOTE(_B3), QD_NOTE(_A3), Q__NOTE(_GF3), QD_NOTE(_D3), Q__NOTE(_GF3), W__NOTE(_A3),\
        )
*/
#       define STARTUP_SONG SONG(_TO_BOLDLY_GO)
#   endif
#endif
