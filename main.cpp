#include "Image.h"
#include <math.h>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  GrayscaleImage imgInput, imgInputGr, imgNegative, imgBlur, imgFinal;
  imgInput.Load("read.png");
  imgInputGr = GrayscaleImage(imgInput);
  imgInputGr.Save("Grayscale.png");
  imgNegative = imgInput;
  for (int y = 0; y < imgNegative.GetHeight(); y++)
  {
    for (int x = 0; x < imgNegative.GetWidth(); x++)
    {
      imgNegative(x, y) = 255 - imgInput(x, y);
    }
  }
  imgNegative.Save("imgNegative.png");

  imgBlur = imgNegative;
  auto getValues = [&](int x, int y) { return imgNegative(x > -1 && x < imgNegative.GetWidth() ? x : 1, y > -1 && x < imgNegative.GetHeight() ? y : 1);};
  for (int i = 0; i < 10; i++)
  {
    for (int y = 0; y < imgBlur.GetHeight() - 1; y++)
    {
      for (int x = 0; x < imgBlur.GetWidth() - 1; x++)
      {
        imgBlur(x, y) = (getValues(x - 1, y - 1) + getValues(x, y - 1) + getValues(x + 1, y - 1) +
        getValues(x - 1, y) + getValues(x, y) + getValues(x + 1, y) +
        getValues(x - 1, y + 1) + getValues(x, y + 1) + getValues(x + 1, y + 1)) / 9;
      }
    }
    imgNegative = imgBlur;
  }
  imgBlur.Save("imgBlur.png");

  imgFinal = imgInput;
  for (int y = 0; y < imgFinal.GetHeight(); y++)
  {
    for (int x = 0; x < imgFinal.GetWidth(); x++)
    {
      if (imgBlur(x, y) >= 0 && imgBlur(x, y) < 10 )
      {
        imgFinal(x, y) = 255;
      }
      else if (imgBlur(x, y) >= 100 && imgBlur(x,y) < 255 )
      {
        imgFinal(x, y) = 255;
      }
      else
      {
        imgFinal(x, y) = imgBlur(x, y);
      }
    }
  }
  imgFinal.Save("imgFinal.png");
  return 0;
}
