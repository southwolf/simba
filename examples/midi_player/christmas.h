/**
 * @file staffan.h
 * @version 0.1.0
 *
 * @section License
 * Copyright (C) 2015-2016, Erik Moqvist
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * This file is part of the Simba project.
 */

#ifndef __SONG_H__
#define __SONG_H__

static const FAR struct operation_t song[] = {
    /* Staffan var en stalledrang. */

    { PACE, 200 },

    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_E3, 0x45 } },
    { DELAY, 2 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_E3, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_E3, 0x45 } },
    { DELAY, 2 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_E3, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_E3, 0x45 } },
    { DELAY, 2 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_E3, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_D3 + 1, 0x45 } },
    { DELAY, 2 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_D3 + 1, 0 } },

    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_E3, 0x45 } },
    { DELAY, 2 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_E3, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_G3, 0x45 } },
    { DELAY, 2 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_G3, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_B3, 0x45 } },
    { DELAY, 2 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_B3, 0 } },
    { DELAY, 1 },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_G3, 0x45 } },
    { DELAY, 1 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_G3, 0 } },
    { SPACING },

    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_E3, 0x45 } },
    { DELAY, 2 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_E3, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_E3, 0x45 } },
    { DELAY, 2 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_E3, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_G3, 0x45 } },
    { DELAY, 2 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_G3, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_E3, 0x45 } },
    { DELAY, 2 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_E3, 0 } },
    { SPACING },

    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_E3, 0x45 } },
    { DELAY, 4 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_E3, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_D3 + 1, 0x45 } },
    { DELAY, 2 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_D3 + 1, 0 } },
    { DELAY, 1 },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_D3 + 1, 0x45 } },
    { DELAY, 1 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_D3 + 1, 0 } },
    { SPACING },

    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_F3 + 1, 0x45 } },
    { DELAY, 2 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_F3 + 1, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_F3 + 1, 0x45 } },
    { DELAY, 2 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_F3 + 1, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_A3, 0x45 } },
    { DELAY, 2 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_A3, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_A3, 0x45 } },
    { DELAY, 2 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_A3, 0 } },
    { SPACING },

    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_F3 + 1, 0x45 } },
    { DELAY, 2 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_F3 + 1, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_F3 + 1, 0x45 } },
    { DELAY, 2 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_F3 + 1, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_G3, 0x45 } },
    { DELAY, 2 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_G3, 0 } },
    { DELAY, 1 },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_G3, 0x45 } },
    { DELAY, 1 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_G3, 0 } },
    { SPACING },

    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_E3, 0x45 } },
    { DELAY, 2 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_E3, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_E3, 0x45 } },
    { DELAY, 2 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_E3, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_G3, 0x45 } },
    { DELAY, 2 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_G3, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_E3, 0x45 } },
    { DELAY, 2 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_E3, 0 } },
    { SPACING },

    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_E3, 0x45 } },
    { DELAY, 4 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_E3, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_D3 + 1, 0x45 } },
    { DELAY, 4 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_D3 + 1, 0 } },
    { SPACING },

    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_E3, 0x45 } },
    { DELAY, 2 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_E3, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_E3, 0x45 } },
    { DELAY, 2 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_E3, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_E3, 0x45 } },
    { DELAY, 2 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_E3, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_D3, 0x45 } },
    { DELAY, 2 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_D3, 0 } },
    { SPACING },

    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_G3, 0x45 } },
    { DELAY, 2 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_G3, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_A3, 0x45 } },
    { DELAY, 2 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_A3, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_B3, 0x45 } },
    { DELAY, 4 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_B3, 0 } },
    { SPACING },

    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_C4, 0x45 } },
    { DELAY, 2 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_C4, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_B3, 0x45 } },
    { DELAY, 2 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_B3, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_A3, 0x45 } },
    { DELAY, 2 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_A3, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_G3, 0x45 } },
    { DELAY, 2 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_G3, 0 } },
    { SPACING },

    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_F3 + 1, 0x45 } },
    { DELAY, 2 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_F3 + 1, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_E3, 0x45 } },
    { DELAY, 2 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_E3, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_G3, 0x45 } },
    { DELAY, 2 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_G3, 0 } },
    { DELAY, 1 },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_F3 + 1, 0x45 } },
    { DELAY, 1 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_F3 + 1, 0 } },
    { SPACING },

    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_F3 + 1, 0x45 } },
    { DELAY, 4 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_F3 + 1, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_E3, 0x45 } },
    { DELAY, 4 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_E3, 0 } },

    { DELAY, 8 },

    /* Hej, tomtegubbar. */

    { PACE, 100 },

    /* 1. */
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_C4, 0x45 } },
    { DELAY, 4 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_C4, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_G3, 0x45 } },
    { DELAY, 3 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_G3, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_A3, 0x45 } },
    { DELAY, 1 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_A3, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_G3, 0x45 } },
    { DELAY, 3 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_G3, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_F3, 0x45 } },
    { DELAY, 1 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_F3, 0 } },
    { SPACING },

    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_E3, 0x45 } },
    { DELAY, 3 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_E3, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_F3, 0x45 } },
    { DELAY, 1 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_F3, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_G3, 0x45 } },
    { DELAY, 4 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_G3, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_C4, 0x45 } },
    { DELAY, 3 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_C4, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_C4, 0x45 } },
    { DELAY, 1 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_C4, 0 } },
    { SPACING },

    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_B3, 0x45 } },
    { DELAY, 3 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_B3, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_C4, 0x45 } },
    { DELAY, 1 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_C4, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_D4, 0x45 } },
    { DELAY, 4 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_D4, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_C4, 0x45 } },
    { DELAY, 3 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_C4, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_B3, 0x45 } },
    { DELAY, 1 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_B3, 0 } },
    { SPACING },

    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_C4, 0x45 } },
    { DELAY, 4 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_C4, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_C4, 0x45 } },
    { DELAY, 4 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_C4, 0 } },
    { DELAY, 4 },

    /* 2. */
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_C4, 0x45 } },
    { DELAY, 4 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_C4, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_G3, 0x45 } },
    { DELAY, 3 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_G3, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_A3, 0x45 } },
    { DELAY, 1 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_A3, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_G3, 0x45 } },
    { DELAY, 3 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_G3, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_F3, 0x45 } },
    { DELAY, 1 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_F3, 0 } },
    { SPACING },

    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_E3, 0x45 } },
    { DELAY, 3 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_E3, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_F3, 0x45 } },
    { DELAY, 1 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_F3, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_G3, 0x45 } },
    { DELAY, 4 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_G3, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_C4, 0x45 } },
    { DELAY, 3 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_C4, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_C4, 0x45 } },
    { DELAY, 1 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_C4, 0 } },
    { SPACING },

    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_B3, 0x45 } },
    { DELAY, 3 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_B3, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_C4, 0x45 } },
    { DELAY, 1 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_C4, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_D4, 0x45 } },
    { DELAY, 4 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_D4, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_C4, 0x45 } },
    { DELAY, 3 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_C4, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_B3, 0x45 } },
    { DELAY, 1 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_B3, 0 } },
    { SPACING },

    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_C4, 0x45 } },
    { DELAY, 4 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_C4, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_C4, 0x45 } },
    { DELAY, 4 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_C4, 0 } },
    { DELAY, 2 },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_B3, 0x45 } },
    { DELAY, 2 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_B3, 0 } },
    { SPACING },

    /* 3. */
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_C4, 0x45 } },
    { DELAY, 3 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_C4, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_E4, 0x45 } },
    { DELAY, 1 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_E4, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_D4, 0x45 } },
    { DELAY, 6 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_D4, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_B3, 0x45 } },
    { DELAY, 2 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_B3, 0 } },
    { SPACING },

    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_C4, 0x45 } },
    { DELAY, 3 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_C4, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_E4, 0x45 } },
    { DELAY, 1 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_E4, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_D4, 0x45 } },
    { DELAY, 6 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_D4, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_B3, 0x45 } },
    { DELAY, 2 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_B3, 0 } },
    { SPACING },

    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_C4, 0x45 } },
    { DELAY, 3 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_C4, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_E4, 0x45 } },
    { DELAY, 1 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_E4, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_D4, 0x45 } },
    { DELAY, 4 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_D4, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_D4, 0x45 } },
    { DELAY, 3 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_D4, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_B3, 0x45 } },
    { DELAY, 1 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_B3, 0 } },
    { SPACING },

    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_B3, 0x45 } },
    { DELAY, 3 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_B3, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_A3, 0x45 } },
    { DELAY, 1 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_A3, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_G3, 0x45 } },
    { DELAY, 4 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_G3, 0 } },
    { DELAY, 4 },

    /* 4. */
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_C4, 0x45 } },
    { DELAY, 4 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_C4, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_G3, 0x45 } },
    { DELAY, 3 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_G3, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_A3, 0x45 } },
    { DELAY, 1 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_A3, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_G3, 0x45 } },
    { DELAY, 3 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_G3, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_F3, 0x45 } },
    { DELAY, 1 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_F3, 0 } },
    { SPACING },

    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_E3, 0x45 } },
    { DELAY, 3 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_E3, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_F3, 0x45 } },
    { DELAY, 1 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_F3, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_G3, 0x45 } },
    { DELAY, 4 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_G3, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_C4, 0x45 } },
    { DELAY, 3 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_C4, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_C4, 0x45 } },
    { DELAY, 1 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_C4, 0 } },
    { SPACING },

    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_B3, 0x45 } },
    { DELAY, 3 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_B3, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_C4, 0x45 } },
    { DELAY, 1 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_C4, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_D4, 0x45 } },
    { DELAY, 4 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_D4, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_C4, 0x45 } },
    { DELAY, 3 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_C4, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_B3, 0x45 } },
    { DELAY, 1 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_B3, 0 } },
    { SPACING },

    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_C4, 0x45 } },
    { DELAY, 4 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_C4, 0 } },
    { SPACING },
    { COMMAND, 3, { MIDI_NOTE_ON, MIDI_NOTE_C4, 0x45 } },
    { DELAY, 4 },
    { COMMAND, 3, { MIDI_NOTE_OFF, MIDI_NOTE_C4, 0 } },
    { DELAY, 4 },

    { DELAY, 8 }
};

#endif
