#include <stdint.h>
#include <stddef.h>
#include "limine.h"

extern void draw_string(const char *str, int x, int y, uint32_t color);

static volatile struct limine_framebuffer_request fb_req = {
    .id = LIMINE_FRAMEBUFFER_REQUEST,
    .revision = 0
};

struct limine_framebuffer *fb;

void draw_pixel(int x, int y, uint32_t color) {
    if (x < 0 || x >= (int)fb->width || y < 0 || y >= (int)fb->height) return;
    uint32_t *fb_ptr = (uint32_t *)fb->address;
    fb_ptr[y * (fb->pitch / 4) + x] = color;
}

void clear_screen(uint32_t color) {
    for (uint32_t y = 0; y < fb->height; y++) {
        for (uint32_t x = 0; x < fb->width; x++) {
            draw_pixel(x, y, color);
        }
    }
}

void _start(void) {
    if (fb_req.response == NULL || fb_req.response->framebuffer_count < 1) {
        for (;;);
    }

    fb = fb_req.response->framebuffers[0];

    clear_screen(0x1a1a1a);
    draw_string("BEM-VINDO AO FritOS", fb->width/2 - 120, fb->height/2 - 10, 0x00FF00); 
    draw_string("Testando base gráfica", fb->width/2 - 110, fb->height/2 + 10, 0xFFFFFF); 

    for (;;);
}
