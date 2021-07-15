
# ImageProcessing-Basic-DrawingEffect

1. Give the Dinosaur picture a drawing effect.
In this study, it is aimed to make the read.png image look like drawing by passing it through
several filters. Below are the steps followed.

A) Converting the image to grayscale

I converted our image to Gray scale.

B) Inverting the image

Black and white image inversion, I converted the light areas to dark and dark areas to light.

C) Box Filtering that blurs the inverted image

Using the average filter, I have blurred the image, is to replace each pixel value of an image
with the average value including its neighbors and itself. This results in the disappearance of pixel
values that are not representative of their surroundings. I used the kernel size as 3×3 square. 

D) Decomposition by pixel’s intensity of the blurred image

I changed the pixels with high values to white pixels, then I changed the pixels with density 0 to white
(255) to change the background to white. Then, to highlight the lines that make up the outer surface of
the picture, I synced the pixels with a certain value range to ImgFinal.

![Screenshot_3](https://user-images.githubusercontent.com/55910759/125819085-29cdfb21-fd6f-4755-8e78-8c24a6b9cd6f.png)
