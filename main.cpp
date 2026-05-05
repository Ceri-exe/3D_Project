#include "Framebuffer.hpp"

int main() {
    int w = 800;
    int h = 600;
    Framebuffer fb(w, h);

    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            float blue = static_cast<float>(x) / w * 255.0f;
            float green = static_cast<float>(y) / h * 255.0f;
            fb.setPixels(x, y, {0, static_cast<unsigned char>(green), static_cast<unsigned char>(blue)});
        }
    }

    fb.saveAsPPM("test_output.ppm");
    return 0;
}