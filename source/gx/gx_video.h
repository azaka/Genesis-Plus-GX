/****************************************************************************
 *  gx_video.c
 *
 *  Genesis Plus GX video support
 *
 *  code by Softdev (2006), Eke-Eke (2007,2008)
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 ***************************************************************************/

#ifndef _GC_VIDEO_H_
#define _GC_VIDEO_H_

/* EFB colors */
#define BLACK {0,0,0,0xff}
#define DARK_GREY {0x22,0x22,0x22,0xff}
#define WHITE {0xff,0xff,0xff,0xff}

/* image texture */
typedef struct
{
  u8 *data;
  u16 width;
  u16 height;
  u8 format;
} gx_texture;

/* Global variables */
extern unsigned int *xfb[2];
extern int whichfb;
extern GXRModeObj *vmode;
extern u8 *texturemem;
extern u8 gc_pal;

/* GX video emulation functions */
extern void gx_video_init(void);
extern void gx_video_start(void);
extern void gx_video_stop(void);
extern void gx_video_update(void);

/* GX draw functions */
extern gx_texture *gxTextureOpenPNG(const u8 *buffer);
extern void gxTextureClose(gx_texture **p_texture);
extern void gxDrawScreenshot(u8 alpha);
extern void gxDrawTexture(gx_texture *texture, s32 x, s32 y, s32 w, s32 h, u8 alpha);
extern void gxDrawTextureRepeat(gx_texture *texture, s32 x, s32 y, s32 w, s32 h, u8 alpha);
extern void gxResetAngle(f32 angle);
extern void gxClearScreen (GXColor color);
extern void gxSetScreen ();

#endif