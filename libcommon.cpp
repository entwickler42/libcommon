#include "libcommon.h"

#include <stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>

bool GLCommon::loadImageRAW(const char* filename, MemTexture* texture)
{
	FILE* f = fopen(filename,"r");
	if(f != NULL){
		long fs = getFileSize(f);
		if(fs > 0){
			texture->data = new char[fs];
			if(fread(texture->data,1,fs,f) != fs){
				delete [] texture->data;
				texture->data = NULL;
			}
		}
		fclose(f);
	}	
	return texture->data ? true : false;
}

bool GLCommon::loadImageTGA(const char* filename, MemTexture* texture)
{
	FILE* f = fopen(filename,"rb");
	if(f != NULL){
		struct TGA_HEADER hdr;
		fread(&hdr,sizeof(hdr),1,f);
		texture->free();
		texture->width  = hdr.width;
		texture->height = hdr.height;
		texture->bbp	= hdr.bits;		
		texture->data	= new char[texture->size()];
		fread(texture->data,1,texture->size(),f);		
		fclose(f);
	}
	return texture->data ? true : false;
}

long GLCommon::getFileSize(FILE* file)
{
	long size = -1;
	long origin = ftell(file);

	fseek(file,0,SEEK_END);
	size = ftell(file);
	fseek(file,origin,SEEK_SET);

	return size;
}
