#ifndef __CAMERA_H
#define __CAMERA_H

#include <GL/gl.h>

class Camera
{
	public:
		Camera(
			GLfloat XPos=0, GLfloat YPos=0, GLfloat ZPos=0,
			GLfloat YRot=0, GLfloat XRot=0,
			bool FlyMode = true
		);

		GLfloat XPos, YPos, ZPos;
		GLfloat YRot, XRot;
		bool FlyMode;

		void forward(GLfloat speed);
		void backward(GLfloat speed);
		void upwards(GLfloat speed);
		void downwards(GLfloat speed);
		void turnLeft(GLfloat speed);
		void turnRight(GLfloat speed);
		void turnUp(GLfloat speed);
		void turnDown(GLfloat speed);
};

#endif

