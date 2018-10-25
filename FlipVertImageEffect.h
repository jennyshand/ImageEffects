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

//this image effect will flip the image vertically
class FlipVertImageEffect : public ImageEffect
{
	virtual void processImage(PpmDocument &doc)
	{
		for (int i = 0; i < doc.getHeight() - i; i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				Pixel *p = &doc.getPixel(i, j);
				int blue = p->getBlue();
				int red = p->getRed();
				int green = p->getGreen();
				Pixel *k = &doc.getPixel(doc.getHeight() - 1 - i, j);
				int blue2 = k->getBlue();
				int red2 = k->getRed();
				int green2 = k->getGreen();

				k->setBlue(blue);
				k->setRed(red);
				k->setGreen(green);

				p->setBlue(blue2);
				p->setRed(red2);
				p->setGreen(green2);

			}
		}
	}

};

