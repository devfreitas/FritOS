#include <stdint.h>
#include <stddef.h>
#include "font.h"

extern void draw_pixel(int x, int y, uint32_t color);

void draw_char(char c, int x, int y, uint32_t color) {
    if (c < 32 || c > 126) return;

    const uint8_t *glyph = font_basic[(int)c];

    for (int cy = 0; cy < 8; cy++) {
        uint8_t line = glyph[cy];
        for (int cx = 0; cx < 8; cx++) {
            if ((line >> (7 - cx)) & 1) {
                draw_pixel(x + cx, y + cy, color);
            }
        }
    }
}
void draw_string(const char *str, int x, int y, uint32_t color) {
    int current_x = x;
    for (size_t i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            current_x = x;
            y += 10;
            continue;
        }

        draw_char(str[i], current_x, y, color);
        current_x += 8;
    }
}
