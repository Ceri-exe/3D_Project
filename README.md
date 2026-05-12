# Simple C++ CPU Rasterizer & Simulation Engine

A performance-oriented software renderer built from the ground up in modern C++. This project deliberately avoids high-level graphics APIs (like OpenGL or Vulcan) to achieve a deep understanding of the underlying mathematics and hardware-level interaction.

## Current Focus: Low-Level Graphics Pipeline
The project is under active development. The current focus lies on the mathematical foundation and direct display interfacing under Linux.

### Core Features (Status: Step 1 Completed)
* **Custom Linear Algebra Library:** Self-implemented `Vec3` and `Mat4` classes, including mathematical operations such as dot product, cross product, normalization, and matrix transformations.
* **Native X11 Integration:** Direct communication with the X-Server via `Xlib.h`. Mapping a custom framebuffer to an `XImage` for real-time visualization.
* **Memory Management:** Manual management of the framebuffer as a contiguous memory block (`std::vector<Color>`).

### Step 1: Foundations & Output (Complete)
* **Goal:** Establish mathematical primitives and initial pixel output.
* **Result:** Successful rendering of a wireframe cube via the X11 interface.

### Step 2: Transformation Pipeline (Current Work in Progress)
* **Challenge:** Projecting 3D poits onto a 2D screen coordinate system.
* **Solution:** Implementing Model-View-Projection (MVP) matrices and a LookAt function for camera control.

### Step 3: Rasterization & Shading (TODO)
* **Problem:** Displaying filled surfaces instead of wireframes.
* **Solution:** Implementing **Barycentric Coordinates** to determine fragment inclusion within primitives.

### Step 4: Depth Handling (TODO)
* **Problem:** Handling "Z-fighting" and incorrect object overlapping.
* **Solution:** Implementing a **Depth Buffer (Z-buffer)** for correct geometry occlusion.

## 🛠 Tech Stack
* **Language:** Modern C++ 
* **OS Interface:** X11 (Linux Native)
* **Build System:** CMake
* **Mathematics:** Custom-built (no external libraries like GLM for now)

## Build & Run
Prerequisite: `libx11-dev` must be installed on your system.

```bash
mkdir build && cd build
cmake ..
./rasterizer