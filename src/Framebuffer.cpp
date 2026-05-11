#include "Framebuffer.hpp"

    Framebuffer::Framebuffer(int w, int h) : width(w), height(h) {
        pixels.resize(w*h, {0,0,0,0});
    }

    void Framebuffer::setPixels(int x, int y, const Color& color) {
        if
        ( 
            x >= 0 &&
            x < width &&
            y >= 0 &&
            y < height
        )
        {
            pixels[y * width + x] = color;
        }
    }

    void Framebuffer::clear(const Color &color) {
        std::fill(pixels.begin(), pixels.end(), color);
    }

    void Framebuffer::saveAsPPM(const std::string& filename) {
        std::ofstream ofs(filename, std::ios::binary);

        ofs << "P6\n" << width << " " << height << "\n255\n";

        for (const auto& p: pixels) {
            ofs << p.r << p.g << p.b << p.pad;
        }
        ofs.close();
    }