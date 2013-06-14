#include "libraries.h"


class ShaderCreator
{
public:
	ShaderCreator(void);
	~ShaderCreator(void);
	GLuint Create(ShaderType type,const std::string source);

};

