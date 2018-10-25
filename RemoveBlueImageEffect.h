/*
Name: Jenny Shand
Student ID: 012820857
Last modified: 9/10/17
*/

#pragma once
#include "ImageEffect.h"

//this image effect will remove all blue from a picture
class RemoveBlueImageEffect : public ImageEffect
{
	virtual void processImage(PpmDocument &doc)
	{
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				Pixel *p = &doc.getPixel(i, j);
				p->setBlue(0);
			}
		}
	}

};