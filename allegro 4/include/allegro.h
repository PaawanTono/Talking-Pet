#ifndef ALLEGRO_H
#define ALLEGRO_H

#include "allegro/base.h"

#include "allegro/system.h"
#include "allegro/debug.h"

#include "allegro/unicode.h"

#include "allegro/mouse.h"
#include "allegro/timer.h"
#include "allegro/keyboard.h"
#include "allegro/joystick.h"

#include "allegro/palette.h"
#include "allegro/gfx.h"
#include "allegro/color.h"
#include "allegro/draw.h"
#include "allegro/rle.h"
#include "allegro/compiled.h"
#include "allegro/text.h"
#include "allegro/font.h"

#include "allegro/fli.h"
#include "allegro/config.h"
#include "allegro/gui.h"

#include "allegro/sound.h"

#include "allegro/file.h"
#include "allegro/lzss.h"
#include "allegro/datafile.h"

#include "allegro/fixed.h"
#include "allegro/fmaths.h"
#include "allegro/matrix.h"
#include "allegro/quat.h"

#include "allegro/3d.h"
#include "allegro/3dmaths.h"


#ifndef ALLEGRO_NO_COMPATIBILITY
   #include "allegro/alcompat.h"
#endif

#ifndef ALLEGRO_NO_FIX_CLASS
   #ifdef __cplusplus
      #include "allegro/fix.h"
   #endif
#endif


#ifdef ALLEGRO_EXTRA_HEADER
   #include ALLEGRO_EXTRA_HEADER
#endif

#endif          /* ifndef ALLEGRO_H */


