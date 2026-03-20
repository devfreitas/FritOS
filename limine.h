#ifndef LIMINE_H
#define LIMINE_H
#include <stdint.h>

#define LIMINE_FRAMEBUFFER_REQUEST { { 0x674ab110b2d49453, 0x173190335b5465e3 }, 0 }

struct limine_framebuffer {
    uint64_t address;
    uint32_t width;
    uint32_t height;
    uint32_t pitch;
    uint16_t bpp;
};

struct limine_framebuffer_response {
    uint64_t revision;
    uint64_t framebuffer_count;
    struct limine_framebuffer **framebuffers;
};

struct limine_framebuffer_request {
    uint64_t id[2];
    uint64_t revision;
    struct limine_framebuffer_response *response;
};
#endif
