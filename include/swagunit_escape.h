/**
 * Source code taken from
 * https://github.com/tatsoku/hamon/blob/main/include/hamon_escape.h and
 * modified in accordance with the BSD-3-Clause license (see original comment
 * and details below)
 *
 * https://github.com/SwagSilver/swagunit/issues/1#issuecomment-2544605592
 *
 * Copyright (c) 2024, tatsoku
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef SWAGUNIT_ESCAPE_H
#define SWAGUNIT_ESCAPE_H

#define BASE "\033["
#define END "m"

/*
 * Foreground colors
 */

#define BLACK_CODE "30"
#define RED_CODE "31"
#define GREEN_CODE "32"
#define YELLOW_CODE "33"
#define BLUE_CODE "34"
#define MAGENTA_CODE "35"
#define CYAN_CODE "36"

#define BLACK BASE BLACK_CODE END
#define RED BASE RED_CODE END
#define GREEN BASE GREEN_CODE END
#define YELLOW BASE YELLOW_CODE END
#define BLUE BASE BLUE_CODE END
#define MAGENTA BASE MAGENTA_CODE END
#define CYAN BASE CYAN_CODE END

/*
 * Graphics such as bold, strike through, italics, dim, blink, underline, etc.
 */

#define BOLD_CODE "1"
#define DIM_CODE "2"
#define ITALIC_CODE "3"
#define UNDERLINE_CODE "4"
#define BLINK_CODE "5"
#define REVERSE_CODE "7"
#define INVISIBLE_CODE "8"
#define STRIKETHROUGH_CODE "9"

#define BOLD BASE BOLD_CODE END
#define DIM BASE DIM_CODE END
#define ITALIC BASE ITALIC_CODE END
#define UNDERLINE BASE UNDERLINE_CODE END
#define BLINK BASE BLINK_CODE END
#define REVERSE BASE REVERSE_CODE END
#define INVISIBLE BASE INVISIBLE_CODE END
#define STRIKETHROUGH BASE STRIKETHROUGH_CODE END

/*
 * Special CLEARS for graphics, possibly not needed but can be useful in the
 * future
 */
#define BOLD_CLEAR BASE "22" END
#define DIM_CLEAR BOLD_CLEAR
#define ITALIC_CLEAR BASE "23" END
#define UNDERLINE_CLEAR BASE "24" END
#define BLINK_CLEAR BASE "25" END
#define REVERSE_CLEAR BASE "27" END
#define INVISIBLE_CLEAR BASE "28" END
#define STRIKETHROUGH_CLEAR BASE "29" END

/*
 * Global clear color/graphics mode string.
 */
#define CLEAR "\033[0m"

#endif // SWAGUNIT_ESCAPE_H
