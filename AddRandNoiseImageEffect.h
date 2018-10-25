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

//this image effect will add random noise to a picture
class AddRandNoiseImageEffect : public ImageEffect
{
	virtual void processImage(PpmDocument &doc)
	{
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				int random_number = rand() % (10 - (-10)) + (-10);
				int current_red;
				int current_blue;
				int current_green;
				Pixel *p = &doc.getPixel(i, j);
				current_red = p->getRed();
				current_blue = p->getBlue();
				current_green = p->getGreen();

				int new_red = current_red + (random_number);
				int new_blue = current_blue + (random_number);
				int new_green = current_green + (random_number);

				if (new_red < 0)
				{
					p->setRed(0);
				}
				else if (new_red > 255)
				{
					p->setRed(255);
				}
				else
				{
					p->setRed(current_red + (random_number));
				}

				if (new_blue < 0)
				{
					p->setBlue(0);
				}
				else if (new_blue > 255)
				{
					p->setBlue(255);
				}
				else
				{
					p->setBlue(current_blue + (random_number));
				}

				if (new_green < 0)
				{
					p->setGreen(0);
				}
				else if (new_green > 255)
				{
					p->setGreen(255);
				}
				else
				{
					p->setGreen(current_green + (random_number));
				}
			}
		}
	}

};

