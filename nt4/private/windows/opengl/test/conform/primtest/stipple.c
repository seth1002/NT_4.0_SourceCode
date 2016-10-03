/*
** Copyright 1992, Silicon Graphics, Inc.
** All Rights Reserved.
**
** This is UNPUBLISHED PROPRIETARY SOURCE CODE of Silicon Graphics, Inc.;
** the contents of this file may not be disclosed to third parties, copied or
** duplicated in any form, in whole or in part, without the prior written
** permission of Silicon Graphics, Inc.
**
** RESTRICTED RIGHTS LEGEND:
** Use, duplication or disclosure by the Government is subject to restrictions
** as set forth in subdivision (c)(1)(ii) of the Rights in Technical Data
** and Computer Software clause at DFARS 252.227-7013, and/or in similar or
** successor clauses in the FAR, DOD or NASA FAR Supplement. Unpublished -
** rights reserved under the Copyright Laws of the United States.
*/

#include <windows.h>
#include <GL/gl.h>
#include "shell.h"


void StippleInit(void *data)
{
    static GLubyte buf[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x0F, 0xF0, 0x00, 0x00, 0x0F, 0xF0, 0x00,
	0x00, 0x0F, 0xF0, 0x00, 0x00, 0x0F, 0xF0, 0x00,
	0x00, 0x0F, 0xF0, 0x00, 0x00, 0x0F, 0xF0, 0x00,
	0x00, 0x0F, 0xF0, 0x00, 0x00, 0x0F, 0xF0, 0x00,
	0x00, 0x0F, 0xF0, 0x00, 0x00, 0x0F, 0xF0, 0x00,
	0x00, 0x0F, 0xF0, 0x00, 0x00, 0x0F, 0xF0, 0x00,
	0x00, 0x0F, 0xF0, 0x00, 0x00, 0x0F, 0xF0, 0x00,
	0x00, 0x0F, 0xF0, 0x00, 0x00, 0x0F, 0xF0, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    *((void **)data) = (void *)0;
    glLineStipple(1, 0xA5A5);
    glPolygonStipple(buf);
    Probe();
}

long StippleUpdate(void *data)
{

    return 1;
}

void StippleSet(long enabled, void *data)
{

    if (enabled) {
	glEnable(GL_LINE_STIPPLE);
	glEnable(GL_POLYGON_STIPPLE);
    } else {
	glDisable(GL_LINE_STIPPLE);
	glDisable(GL_POLYGON_STIPPLE);
    }
    Probe();
}

void StippleStatus(long enabled, void *data)
{

    if (enabled) {
	Output("Stipple on.\n");
    } else {
	Output("Stipple off.\n");
    }
}