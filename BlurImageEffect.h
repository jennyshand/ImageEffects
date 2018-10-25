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

//this image effect will blur the image
class BlurImageEffect : public ImageEffect
{
	virtual void processImage(PpmDocument &doc)
	{
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				int blue = 0;
				int green = 0;
				int red = 0;

				Pixel *u;
				Pixel *q;
				Pixel *r;
				Pixel *s;
				Pixel *t;

				Pixel *p = &doc.getPixel(i, j);
				blue += p->getBlue();
				red += p->getRed();
				green += p->getGreen();

				int total = 1;


				if ((i + 1) < doc.getHeight())
				{
					q = &doc.getPixel(i + 1, j);
					blue += q->getBlue();
					red += q->getRed();
					green += q->getGreen();

					total = total + 1;
				}



				if ((i - 1) > 0)
				{
					r = &doc.getPixel(i - 1, j);
					blue += r->getBlue();
					red += r->getRed();
					green += r->getGreen();

					total += 1;
				}

				if ((j + 1) < doc.getWidth())
				{
					t = &doc.getPixel(i, j + 1);
					blue += t->getBlue();
					red += t->getRed();
					green += t->getGreen();

					total += 1;
				}

				if ((j - 1) > 0)
				{
					u = &doc.getPixel(i, j - 1);
					blue += u->getBlue();
					red += u->getRed();
					green += u->getGreen();

					total += 1;
				}



				if ((i + 1) < doc.getHeight())
				{
					q->setBlue(blue / total);
					q->setGreen(green / total);
					q->setRed(red / total);
				}

				if ((i - 1) > 0)
				{
					r->setBlue(blue / total);
					r->setGreen(green / total);
					r->setRed(red / total);
				}



				p->setBlue(blue / total);
				p->setGreen(green / total);
				p->setRed(red / total);

				if ((j + 1) < doc.getWidth())
				{
					t->setBlue(blue / total);
					t->setGreen(green / total);
					t->setRed(red / total);
				}

				if ((j - 1) > 0)
				{
					u->setBlue(blue / total);
					u->setGreen(green / total);
					u->setRed(red / total);

				}

			}
		}
	}

};
