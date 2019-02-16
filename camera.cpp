#include "camera.h"
#include <math.h>

const float PI_180 = 0.0174532925f;

Camera::Camera(
	GLfloat XPos, GLfloat YPos, GLfloat ZPos,
	GLfloat YRot, GLfloat XRot,
	bool FlyMode
)
	:	XPos(XPos), YPos(YPos), ZPos(ZPos), 
		YRot(YRot), XRot(XRot),
		FlyMode(FlyMode)
{}
void Camera::forward(GLfloat speed)
{
	XPos -= (GLfloat) sin(YRot*PI_180) * speed;
	ZPos += (GLfloat) cos(YRot*PI_180) * speed;
	if(FlyMode){
		YPos += (GLfloat) sin(XRot*PI_180) * speed;
	}
}
void Camera::backward(GLfloat speed)
{
	XPos += (GLfloat) sin(YRot*PI_180) * speed;
	ZPos -= (GLfloat) cos(YRot*PI_180) * speed;
	if(FlyMode){
		YPos -= (GLfloat) sin(XRot*PI_180) * speed;
	}
}
void Camera::upwards(GLfloat speed)
{
	YPos += speed;
}
void Camera::downwards(GLfloat speed)
{
	YPos -= speed;
}
void Camera::turnLeft(GLfloat speed)
{
	YRot -= speed;
}
void Camera::turnRight(GLfloat speed)
{
	YRot += speed;
}
void Camera::turnUp(GLfloat speed)
{
	XRot -= speed;
}
void Camera::turnDown(GLfloat speed)
{
	XRot += speed;
}

