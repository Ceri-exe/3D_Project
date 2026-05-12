#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <iostream>
#include <Vec3.hpp>

#include "Framebuffer.hpp"
#include "Renderer.hpp"

Vec3 drawWireframeCube();

int main() {

    std::cout <<"Starting rasterizer..." << std::endl;
    int w = 800;
    int h = 600;
    Framebuffer fb(w, h);
    Renderer renderer(fb);

    Mat4 transform(0.0f); // Initialize to zero
    transform[0][0] = 1.0f; transform[1][1] = 1.0f; transform[2][2] = 1.0f; transform[3][3] = 1.0f; // Identity
    transform[2][3] = 4.0f; // Set Z translation

    //Color white = {255 , 255, 255, 255};
    Color green = {0, 255, 0, 0};
    Color black = {0, 0, 0, 0};

    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            //float blue = static_cast<float>(x) / w * 255.0f;
            //float green = static_cast<float>(y) / h * 255.0f;
            fb.setPixels
            (
                x, y, 
                {
                    //static_cast<unsigned char>(blue), // b
                    //static_cast<unsigned char>(green), //g
                    0,
                    0,
                    0, // r 
                    0 // padding for xlib                    
                }
            );
        }
    }

    Display* display = XOpenDisplay(nullptr);

    if(!display)
    {
        std::cerr << "Cannot open display\n";
        return 1;
    }

    int screen = DefaultScreen(display);

    Window window = XCreateSimpleWindow(
        display,
        RootWindow(display, screen),
        0,0, w,h,
        1,
        BlackPixel(display,screen),
        WhitePixel(display,screen)
    );

    XSelectInput(display, window, ExposureMask | KeyPressMask);
    XMapWindow(display,window);

    // Graphics context
    GC gc = DefaultGC(display,screen);

    XImage* image = XCreateImage(
        display,
        DefaultVisual(display,screen),
        24,
        ZPixmap,
        0,
        (char*)fb.pixels.data(),
        w,h,
        32,
        w*4
    );

    bool running = true;
    while(running)
    {
        XEvent event;
        
        while(XPending(display))
        {
            XNextEvent(display, &event);

            if(event.type == KeyPress)
                running = false;
        }

        fb.clear(black);
        renderer.drawWireframeCube(transform, green);

        XPutImage(
            display,window,gc,
            image,
            0,0,
            0,0,
            w,h
        );

        XFlush(display);
    }

    image->data = nullptr;
    XDestroyImage(image);
    XDestroyWindow(display, window);
    XCloseDisplay(display);

    std::cout << "Exiting program." <<std::endl;

    //fb.saveAsPPM("test_output.ppm");
    return 0;
}