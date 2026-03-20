#include <stdint.h>
#include <stddef.h>
#include "limine.h"

static volatile struct limine_framebuffer_request framebuffer_request = {
    .id = LIMINE_FRAMEBUFFER_REQUEST,
    .revision = 0
};

// Função principal
void _start(void) {
    if (framebuffer_request.response == NULL || framebuffer_request.response->framebuffer_count < 1) {
        for (;;);
    }
    struct limine_framebuffer *fb = framebuffer_request.response->framebuffers[0];
    uint32_t *dest = (uint32_t *)fb->address;
    for (size_t i = 0; i < 500; i++) {
        dest[i] = 0xFFFFFF;
    }
    for (;;);
}
