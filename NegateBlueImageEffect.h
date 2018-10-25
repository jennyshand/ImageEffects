/*
Name: Jenny Shand
Student ID: 012820857
Last modified: 9/10/17
*/

#pragma once
#include "ImageEffect.h"

//this image effect will negate all blue from a picture
class NegateBlueImageEffect : public ImageEffect
{
	virtual void processImage(PpmDocument &doc)
	{
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				int current_blue;
				Pixel *p = &doc.getPixel(i, j);
				current_blue = p->getBlue();
				p->setBlue(255 - current_blue);
			}
		}
	}

};
