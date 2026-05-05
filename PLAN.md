• Step 1: Linear Algebra
	- Task: Implement Vecs and Matrix
		○ Features: Dot product, Cross product and normalization.
		○ Matrix Multiplication -> Matrix x Matrix, Matrix x Vector.

• Step 2: Transformation Pipeline

 Translate a point from 3D-Space to 2d Screen.

	- Task: Implement Vecs and Matrix
		○ Model: Translate or Rotate object in a specific way.
		○ View: Similar to https://learn.microsoft.com/en-us/previous-versions/windows/desktop/bb281710(v=vs.85) 
						https://www.scratchapixel.com/lessons/mathematics-physics-for-computer-graphics/lookat-function/framing-lookat-function.html
		○ 3D Projection: Adjust perspective (TODO: Research this more.)

• Step 3
 
 Problem: Currently mostly wireframes.
 Solution: Barycentric Coordinates. https://courses.cms.caltech.edu/cs171/assignments/hw2/hw2-notes/notes-hw2.html

	- Task: Find every pixel that lies inside thre 2D points.

		☻ Success Criteria: Render a basic shape.

 New Problem: How to differentiate triangles that lie behind one another?
 Solution to overlapping: Depth Buffer -> Step 4

• Step 4
	- Task: Create DepthBuffer
		☻ Success Criteria: Render a cube and check if the faces of the cube bleed through the front.


