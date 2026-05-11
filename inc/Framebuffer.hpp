#pragma once

#include <vector>
#include <string>
#include <fstream>
#include "Vec3.hpp"

struct Color {
    unsigned char r,g,b; // 0-255
};

class Framebuffer {
    public:
        int width, height;
        std::vector<Color> pixels;

        Framebuffer(int w, int h);

        void setPixels(int x, int y, const Color& color);

        void clear(const Color &color = {0,0,0});

        void saveAsPPM(const std::string& filename);

};