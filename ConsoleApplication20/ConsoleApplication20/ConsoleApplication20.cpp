#include "ShaderCreator.h"
#include "ProgramCreator.h"
#include "Camera.h"

GLuint VertexShader = 0;
GLuint FragmentShader = 0;
GLuint Program = 0;
GLuint VBO = 0;
GLuint VAO = 0;
GLuint MatrixID = 0;
GLuint ColorBuffer = 0;

const std::string strVertexShader(
	"#version 400\n"
	"layout (location = 0) in vec3 position;\n"
	"layout (location = 1) in vec3 color;\n"
	"out vec3 fragmentColor;\n"
	"uniform mat4 MVP;\n"
	"void main()\n"
	"{\n"
		"gl_Position = MVP * vec4(position,1) ;\n"
		"fragmentColor = color;\n"
	"}\n"
);

const std::string strFragmentShader(
"#version 330\n"
"in vec3 fragmentColor;\n"
"out vec3 outputColor;\n"
"void main()\n"
"{\n"
	"outputColor = fragmentColor;\n"
"}\n");



const float vertexPositions[] = {
     1.0f, -1.0f, 0.0f, 
    -1.0f, -1.0f, 0.0f,
     0.0f, 0.0f, 1.0f, 
    -1.0f, -1.0f, 0.0f, 
    -1.0f, 1.0f, 0.0f,
     0.0f, 0.0f, 1.0f,
    -1.0f, 1.0f, 0.0f,
     1.0f, 1.0f, 0.0f,
     0.0f, 0.0f, 1.0f,
     1.0f, 1.0f, 0.0f,
     1.0f, -1.0f, 0.0f,
     0.0f, 0.0f, 1.0f,
    

};

const float Colors[] = {
    0.583f,  0.771f,  0.014f,
    0.609f,  0.115f,  0.436f,
    0.327f,  0.483f,  0.844f,
    0.822f,  0.569f,  0.201f,
    0.435f,  0.602f,  0.223f,
    0.310f,  0.747f,  0.185f,
    0.597f,  0.770f,  0.761f,
    0.559f,  0.436f,  0.730f,
    0.359f,  0.583f,  0.152f,
    0.483f,  0.596f,  0.789f,
    0.559f,  0.861f,  0.639f,
    0.195f,  0.548f,  0.859f,
    
};
void CreateVertexBuffer(){
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions), vertexPositions, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glGenBuffers(1, &ColorBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, ColorBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Colors), Colors, GL_STATIC_DRAW);
}
void CreateVertexArray(){
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	
}
void Render(){
glClearColor(1.0f, 1.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	MatrixID = glGetUniformLocation(Program, "MVP");
	glUseProgram(Program);
	Camera Cam;
	Cam.Set(MatrixID);
	//Cam.Transform(MatrixID);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, ColorBuffer);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0,0);
	glDrawArrays(GL_TRIANGLES, 0, 4*3);
	glDisableVertexAttribArray(0);
	glUseProgram(0);
	glutSwapBuffers();
}

unsigned int defaults(unsigned int displayMode, int &width, int &height) {return displayMode;}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	int width = 500;
	int height = 500;
	unsigned int displayMode = GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH | GLUT_STENCIL;
	displayMode = defaults(displayMode, width, height);
	glutInitDisplayMode (displayMode);
	glutInitWindowSize (width, height); 
	glutInitWindowPosition (300, 200);
	int window = glutCreateWindow (argv[0]);
	GLenum err = glewInit();
	/*++++++++++++++++++++++++++++++++++++++Shaders+++++++++++++++++++++++++++++++++++*/

	//CreateShaders();
	ShaderCreator Shader;
	VertexShader = Shader.Create(VERTEX,strVertexShader);
	FragmentShader = Shader.Create(FRAGMENT,strFragmentShader);
	/*+++++++++++++++++++++++++++++++++++++Program++++++++++++++++++++++++++++++++++++++++++*/

	//CreateProgram();
	ProgramCreator ProgTest;
	ProgTest.Attach(VertexShader);
	ProgTest.Attach(FragmentShader);
	Program = ProgTest.GetProgram();
	/**************************************VertexBufferGenerating***************************************/

	CreateVertexBuffer();
	/**************************************VertexArraysGenerating**************************************/

	CreateVertexArray();
	/********************************************Render************************************/
	glutDisplayFunc(Render);
	glutMainLoop();
	return 0;
}