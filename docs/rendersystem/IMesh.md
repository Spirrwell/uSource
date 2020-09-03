# class IMesh

*Defined at line 18 of ./rendersystem/imesh.h*

 Simple mesh class. Contains both an index buffer and vertex buffer



## Functions

### IndexBuffer

*public class rendersystem::IIndexBuffer * IndexBuffer()*

 Returns the index buffer used by this shader

**return**

### VertexBuffer

*public class rendersystem::IVertexBuffer * VertexBuffer()*

 Returns the vertex buffer used by this shader

**return**

### Draw

*public void Draw(class IShaderProgram * pShader)*

 Internally, this will lookup the corresponding shader backend and call those funcs

**pShader**

### Flags

*public enum rendersystem::EMeshFlags Flags()*

 Returns all set mesh flags

**return**



