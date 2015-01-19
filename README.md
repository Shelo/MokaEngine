# Moka Engine

## Steps
Updated: 18-01-2015

* [**Done**] Create Core Engine.
* [**Done**] Create Display. 
* [**Done**] Create BaseGame interface. 
* [**Done**] Create GameObject. 
* [**Done**] Create Component abstract class. 
* [**Done**] Create Mesh and been able to draw something. 
* [**Done**] Add texture support. 
* [**Done**] Add texture mapping to the Mesh. 
* [**Done**] Create GameLoop and sample Entity framework. 
* [**Done**] Create Transform. 
* [**Done**] Create Shader. 
* [**Done**] Been able to draw a textured mesh with the Shader. 
* [**Done**] Create rendering engine. 
* [**Done**] Been able to send uniforms. 
* [**Done**] Create orthogonal and perspective views. 
* [**Done**: apply rotations and stuff..] Create camera component. 
* [**Done**] Relate camera with the rendering engine. 
* [**Done**] Get translation, rotation and scale matrices from the transform. 
* [**Done**] Been able to translate, scale and rotate a simple image.
* [**Done**] Create an advanced Game Loop. 
* [**Done**] Set a default Orthographic Camera in case user doesn't needs other.
* [**Done**] Use indices when defining the mesh.
* [**Done**] Enable Keyboard Input.
* [**Done**] Enable Mouse Input.
* [**Done**] Create the material class.
* [**Done**] Have a way to import mesh. (Probably with Assimp).
* [**Done**] Add normals to the vertices.
* [**Done**] Add tangents to the vertices.
* [**Done**] Send vertex normals to shader.
* [**Done**] Automatic Uniforms.
* [**Done**] Take material color in consideration.
* [**Done**] Enable texture tiling.
* [**Done**] Implement Normal Mapping.
* Create framework for Forward Rendering.
* Create framework for light system.
* Create the "TRANSFORM HIERARCHY".
* Implement Parallax Displacement Mapping.
* Change "mvp" to "viewProjection", because the matrix doesn't include the model matrix.

## Historical bugs

Do not repeat these again.

* 12-01-2015: **glm::quat** definition is: w, x, y, z. NOT x, y, z, w as commonly is.