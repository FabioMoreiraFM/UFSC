import cv2
import numpy as np

def setTrackbars(s,a,ag,o,og):
	cv2.setTrackbarPos('Simple','image',s)
	cv2.setTrackbarPos('AdaptMean','image',a)
	cv2.setTrackbarPos('AdaptGauss','image',ag)
	cv2.setTrackbarPos('Otsu','image',o)
	cv2.setTrackbarPos('OtsuGauss','image',og)

def simpleThresholding(x): 
	pos = cv2.getTrackbarPos('Simple','image')
	setTrackbars(pos,0,0,0,0)
	ret,thresh1 = cv2.threshold(img,pos,255,cv2.THRESH_BINARY)
	cv2.imshow("image",thresh1)

def adaptiveMeanThresholding(x):
	pos = cv2.getTrackbarPos('AdaptMean','image')
	setTrackbars(0,pos,0,0,0)
	thresh2 = cv2.adaptiveThreshold(img,255,cv2.ADAPTIVE_THRESH_MEAN_C,cv2.THRESH_BINARY,11,2)
	cv2.imshow("image",thresh2)
	if (not pos): cv2.imshow("image",img)

def adaptiveGaussianThresholding(x):
	pos = cv2.getTrackbarPos('AdaptGauss','image')
	setTrackbars(0,0,pos,0,0)
	thresh3 = cv2.adaptiveThreshold(img,255,cv2.ADAPTIVE_THRESH_GAUSSIAN_C,cv2.THRESH_BINARY,11,2)
	cv2.imshow("image",thresh3)
	if (not pos): cv2.imshow("image",img)

def otsuThresholding(x):
	pos = cv2.getTrackbarPos('Otsu','image')
	setTrackbars(0,0,0,pos,0)
	ret2,th2 = cv2.threshold(img,0,255,cv2.THRESH_BINARY+cv2.THRESH_OTSU)
	cv2.imshow("image",th2)
	if (not pos): cv2.imshow("image",img)

def otsuGaussianThresholding(x):
	pos = cv2.getTrackbarPos('OtsuGauss','image')
	setTrackbars(0,0,0,0,pos)
	blur = cv2.GaussianBlur(img,(5,5),0)
	ret3,th3 = cv2.threshold(blur,0,255,cv2.THRESH_BINARY+cv2.THRESH_OTSU)
	cv2.imshow("image",th3)
	if (not pos): cv2.imshow("image",img)

# Create a window
cv2.namedWindow('image')

# Create trackbars for each morphological transformation
cv2.createTrackbar('Simple','image',0,255,simpleThresholding)
cv2.createTrackbar('AdaptMean','image',0,1,adaptiveMeanThresholding)
cv2.createTrackbar('AdaptGauss','image',0,1,adaptiveGaussianThresholding)
cv2.createTrackbar('Otsu','image',0,1,otsuThresholding)
cv2.createTrackbar('OtsuGauss','image',0,1,otsuGaussianThresholding)

# Open image
img = cv2.imread('cinza.jpg',0)

# Put image into screen
cv2.imshow('image',img)

while(1):
    k = cv2.waitKey(1) & 0xFF 
    if k == 27: # Esc key in ASCII
        break

cv2.destroyAllWindows()