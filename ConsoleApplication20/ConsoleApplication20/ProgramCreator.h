
#include "libraries.h"
class ProgramCreator
{
public:
	ProgramCreator(void);
	~ProgramCreator(void);
	void Attach(GLuint Shader);
	GLuint GetProgram();
private:
	GLuint Program;
};

