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

//this image effect will make the image high contrast
class HighContrastImageEffect : public ImageEffect
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

				if (current_red > (255 / 2))
				{
					p->setRed(255);
				}
				else
				{
					p->setRed(0);
				}

				if (current_blue > (255 / 2))
				{
					p->setBlue(255);
				}
				else
				{
					p->setBlue(0);
				}

				if (current_green > (255 / 2))
				{
					p->setGreen(255);
				}
				else
				{
					p->setGreen(0);
				}
			}
		}
	}

};

