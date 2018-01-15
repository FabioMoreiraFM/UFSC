import cv2
import numpy as np

# Structuring element default
kernel = cv2.getStructuringElement(cv2.MORPH_ELLIPSE,(5,5))

# Methods declaration
def kernelOption(x):
	global kernel
	pos = cv2.getTrackbarPos('Kernel','image')
	if (pos == 1):
		kernel = cv2.getStructuringElement(cv2.MORPH_RECT,(5,5))
	elif (pos == 2):
		kernel = cv2.getStructuringElement(cv2.MORPH_ELLIPSE,(5,5))
	elif (pos == 3):
		kernel = cv2.getStructuringElement(cv2.MORPH_CROSS,(5,5))

# I don't know if there is a direct way to do this with few lines
def setTrackbars(e,d,o,c,g):
	cv2.setTrackbarPos('Erosion','image',e)
	cv2.setTrackbarPos('Dilation','image',d)
	cv2.setTrackbarPos('Opening','image',o)
	cv2.setTrackbarPos('Closing','image',c)
	cv2.setTrackbarPos('Gradient','image',g)

def erosion(x):
	pos = cv2.getTrackbarPos('Erosion','image')
	setTrackbars(pos,0,0,0,0)
	erosion = cv2.erode(img,kernel,iterations = pos)
	cv2.imshow("image",erosion)

def dilation(x):
	pos = cv2.getTrackbarPos('Dilation','image')
	setTrackbars(0,pos,0,0,0)
	dilation = cv2.dilate(img,kernel,iterations = pos)
	cv2.imshow("image",dilation)

def opening(x):
	pos = cv2.getTrackbarPos('Opening','image')
	setTrackbars(0,0,pos,0,0)
	opening = cv2.morphologyEx(img, cv2.MORPH_OPEN, kernel)
	cv2.imshow("image",opening)
	if (not pos): cv2.imshow("image",img)

def closing(x):
	pos = cv2.getTrackbarPos('Closing','image')
	setTrackbars(0,0,0,pos,0)
	closing = cv2.morphologyEx(img, cv2.MORPH_CLOSE, kernel)
	cv2.imshow("image",closing)
	if (not pos): cv2.imshow("image",img)

def gradient(x):
	pos = cv2.getTrackbarPos('Gradient','image')
	setTrackbars(0,0,0,0,pos)
	gradient = cv2.morphologyEx(img, cv2.MORPH_GRADIENT, kernel)
	cv2.imshow("image",gradient)
	if (not pos): cv2.imshow("image",img)

# Create a black image, a window
cv2.namedWindow('image')

# Create trackbars for each morphological transformation
cv2.createTrackbar('Kernel','image',0,3,kernelOption)
cv2.createTrackbar('Dilation','image',0,5,dilation)
cv2.createTrackbar('Erosion','image',0,5,erosion)
cv2.createTrackbar('Opening','image',0,1,opening)
cv2.createTrackbar('Closing','image',0,1,closing)
cv2.createTrackbar('Gradient','image',0,1,gradient)

# Open image
img = cv2.imread('cinza.jpg',0)

# Put image into screen
cv2.imshow('image',img)

while(1):
    k = cv2.waitKey(1) & 0xFF 
    if k == 27: # Esc key in ASCII
        break

cv2.destroyAllWindows()
