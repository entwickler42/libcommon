#include "MemImage.h"
#include "libcommon.h"

MemTexture::MemTexture()
{
	initialize();
}

MemTexture::MemTexture(const char* filename)
{
	initialize();
	GLCommon::loadImageTGA(filename,this);
}

void MemTexture::initialize()
{
	data		= NULL;
	width		= 0;
	height	= 0;
	bbp		= 0;
}

MemTexture::~MemTexture()
{
	free();
}

void MemTexture::free()
{
	if(data != NULL){
		delete [] data;
	}
	initialize();
}

size_t MemTexture::size()
{
	return width*height*bbp/8;
}
