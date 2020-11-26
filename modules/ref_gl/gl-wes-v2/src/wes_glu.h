/*
gl-wes-v2:  OpenGL 2.0 to OGLESv2.0 wrapper
Contact:    lachlan.ts@gmail.com
Copyright (C) 2009  Lachlan Tychsen - Smith aka Adventus

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 3 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

extern GLvoid gluOrtho2D(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top);
extern GLvoid gluPerspective(GLfloat fovy, GLfloat aspect, GLfloat znear, GLfloat zfar);
extern GLvoid gluLookAt(GLfloat eyex, GLfloat eyey, GLfloat eyez, GLfloat centerx, GLfloat centery, GLfloat centerz, GLfloat upx, GLfloat upy,
			GLfloat upz);

extern GLvoid gluBuild2DMipmaps(GLenum target, GLint components, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid* pixels);
