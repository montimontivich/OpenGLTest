#include "Controller.h"
#include "ShaderCreator.h"
#include "ProgramCreator.h"
#include "Camera.h"

Controller::Controller(void)
{
}


Controller::~Controller(void)
{
}

void Controller::Run(const std::string VertexShaderSource, const std::string FragmentShaderSource, const float VertexPositions[], static const GLfloat Colors[])
{
	ShaderCreator test;
	VertexShader = test.Create(VERTEX,VertexShaderSource);
	FragmentShader = test.Create(FRAGMENT,FragmentShaderSource);
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(VertexPositions), VertexPositions, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);


		
	glGenBuffers(1, &colorBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Colors), Colors, GL_STATIC_DRAW);
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	ProgramCreator ProgTest;
	ProgTest.Attach(VertexShader);
	ProgTest.Attach(FragmentShader);
	Program = ProgTest.GetProgram();
}

void Controller::Render()
{

	glClearColor(1.0f, 1.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	MatrixID = glGetUniformLocation(Program, "MVP");
	glUseProgram(Program);
	Camera Lol;
	Lol.Set(MatrixID);
	Lol.Transform(MatrixID);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glEnableVertexAttribArray(0);
	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);




glEnableVertexAttribArray(1);
glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
glVertexAttribPointer(1, 3, GL_FLOAT,GL_FALSE, 0, 0);


	
	glDrawArrays(GL_TRIANGLES, 0, 4*3);

	//glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(0);
	glUseProgram(0);
	glutSwapBuffers();
	//glutPostRedisplay();
}
