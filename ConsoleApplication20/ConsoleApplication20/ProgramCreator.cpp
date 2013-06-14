#include "ProgramCreator.h"


ProgramCreator::ProgramCreator(void)
{
	Program = glCreateProgram();
}


ProgramCreator::~ProgramCreator(void)
{
}

void ProgramCreator::Attach(GLuint Shader)
{
	glAttachShader(Program,Shader);
}

GLuint ProgramCreator::GetProgram()
{
	glLinkProgram(Program);
	return Program;
}
