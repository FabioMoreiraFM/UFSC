import cv2
import numpy as np
from matplotlib import pyplot as plt

def histogramsGraphic():
	plt.hist(img.ravel(),256,[0,256]); plt.show() # Original Image
	plt.hist(equ.ravel(),256,[0,256]); plt.show() # Image with histogram equalization
	plt.hist(cl1.ravel(),256,[0,256]); plt.show() # Original Image equalized with CLAHE	

def histogramResult():
	res = np.hstack((img,equ,cl1))
	cv2.imshow('original/equalizado/clahe',res)

img = cv2.imread('cinza.jpg',0)

# Histogram Equalization
equ = cv2.equalizeHist(img)

# CLAHE equalization
clahe = cv2.createCLAHE(clipLimit=2.0, tileGridSize=(8,8))
cl1 = clahe.apply(img)

histogramsGraphic()
histogramResult()

# Press a key while the window with the image is open and the program closes.
cv2.waitKey(0)

# Close all windows
cv2.destroyAllWindows()