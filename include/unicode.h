/*
 * Unicode to CP437 translation support for SSH2DOS
 *
 * Based on mTCP Unicode support by Michael B. Brutman (mbbrutman@gmail.com)
 * Ported from C++ to C for use with SSH2DOS.
 *
 * Original mTCP code is GPLv3. This port maintains the same license.
 */

#ifndef _UNICODE_H
#define _UNICODE_H

#define XLATE_TABLE_LEN 512
#define UNICODE_TOFU    0xfe  /* displayed when no glyph is available */

typedef unsigned long  unicode_cp_t;  /* full Unicode codepoint */
typedef unsigned short small_cp_t;    /* Plane 0 only, saves space */

typedef struct {
    small_cp_t codepoint;
    unsigned char display;
} codepoint_mapping_t;

/* Initialize the built-in CP437 Unicode mapping table.
 * Called at startup; enabled by default. */
void unicode_init(void);

/* Returns nonzero if Unicode translation is active */
int unicode_xlate_loaded(void);

/* Disable Unicode translation (for -U switch) */
void unicode_disable(void);

/* Decode a UTF-8 sequence starting at s, store codepoint in *cp.
 * Returns number of bytes consumed (1-4). On error, *cp = 0xFFFFFFFF, returns 1. */
unsigned char unicode_decode_utf8(const unsigned char *s, unicode_cp_t *cp);

/* Look up a Unicode codepoint and return the CP437 character to display.
 * Returns UNICODE_TOFU (0xFE) if no mapping exists. */
unsigned char unicode_find_display_char(small_cp_t u);

#endif
