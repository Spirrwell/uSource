#include <GL/glew.h>
#include "rendersystemgl.h"

using namespace GL;

unsigned int GetParam(unsigned long param)
{
	GLint out;
	glGetIntegerv(param, &out);
	return out;
}