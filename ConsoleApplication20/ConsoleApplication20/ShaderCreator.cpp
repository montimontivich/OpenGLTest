#include "ShaderCreator.h"


ShaderCreator::ShaderCreator(void)
{
}


ShaderCreator::~ShaderCreator(void)
{
}

 GLuint ShaderCreator::Create(ShaderType type,const std::string source)
{
	GLuint ReturnedShader;
	const GLchar* CharShader;
	
	switch(type){
		case VERTEX:
			ReturnedShader = glCreateShader(GL_VERTEX_SHADER);
			CharShader = source.c_str();
			glShaderSource(ReturnedShader,1,&CharShader,NULL);
			glCompileShader(ReturnedShader);
			break;
		case FRAGMENT:
			ReturnedShader = glCreateShader(GL_FRAGMENT_SHADER);
			CharShader = source.c_str();
			glShaderSource(ReturnedShader,1,&CharShader,NULL);
			glCompileShader(ReturnedShader);
			break;
	}
	return ReturnedShader;
}
