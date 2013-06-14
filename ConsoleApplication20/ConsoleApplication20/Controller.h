
#include "libraries.h"

class Controller
{
public:
	Controller(void);
	~Controller(void);
	void Run(const std::string VertexShaderSource, const std::string FragmentShaderSource, const float VertexPositions[], static const GLfloat Colors[]);
	void Render();
	static Controller* currentInstance;
private:
	GLuint VertexShader;
	GLuint FragmentShader;
	GLuint Program;
	GLuint VBO;
	GLuint VAO;
	GLuint MatrixID;
	GLuint colorBuffer;
	//static Controller* currentInstance;
	static void drawCallback()
  {
    currentInstance->Render();
  }

  void setupDrawCallback()
  {
    currentInstance = this;
    ::glutDisplayFunc(Controller::drawCallback);
  }
};

