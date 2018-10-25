/*
Name: Jenny Shand
Student ID: 012820857
Last modified: 9/10/17
*/

#pragma once
#include "ImageEffect.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

//this image effect will make the image gray scale
class GrayScaleImageEffect : public ImageEffect
{
	virtual void processImage(PpmDocument &doc)
	{
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				int current_red;
				int current_blue;
				int current_green;
				Pixel *p = &doc.getPixel(i, j);
				current_red = p->getRed();
				current_blue = p->getBlue();
				current_green = p->getGreen();

				int new_val = ((current_red + current_blue + current_green) / 3);

				p->setRed(new_val);
				p->setBlue(new_val);
				p->setGreen(new_val);
			}
		}
	}

};
