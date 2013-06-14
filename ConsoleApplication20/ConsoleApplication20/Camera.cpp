#include "Camera.h"


Camera::Camera(void)
{
}


Camera::~Camera(void)
{
}

void Camera::Set(GLuint UniformMatrix)
{
	glm::mat4 Projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
    glm::mat4 View = glm::lookAt(glm::vec3(9,3,3), glm::vec3(0,0,0),glm::vec3(0,1,0));
    glm::mat4 Model = glm::mat4(1.0f);
	glm::mat4 MVP = Projection * View * Model; 
	glUniformMatrix4fv(UniformMatrix, 1, GL_FALSE, &MVP[0][0]);
}
void Camera::Transform(GLuint UniformMatrix)
{
	glm::mat4 Projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.f);
  glm::mat4 ViewTranslate = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -1.0f));
  glm::mat4 ViewRotateX = glm::rotate(ViewTranslate, 10.0f, glm::vec3(-1.0f, 0.0f, 0.0f));
  glm::mat4 View = glm::rotate(ViewRotateX, 0.0f, glm::vec3(0.0f, 1.0f, 0.0f));
  glm::mat4 Model = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f));
  glm::mat4 MVP = Projection * View * Model;
  glUniformMatrix4fv(UniformMatrix, 1, GL_FALSE, glm::value_ptr(MVP));
}