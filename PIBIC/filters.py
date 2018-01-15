import cv2
import numpy as np

def gradientFilters():
	# Sobel
	sobelx = cv2.Sobel(img,cv2.CV_64F,1,0,ksize=1)
	sobely = cv2.Sobel(img,cv2.CV_64F,0,1,ksize=5)

	# Scharr
	scharr = cv2.Sobel(img,cv2.CV_64F,1,0,ksize=-1)

	# Laplacian
	laplacian = cv2.Laplacian(img,cv2.CV_64F)

	res = np.hstack((sobelx,sobely))
	res2 = np.hstack((scharr,laplacian))
	resFinal = np.vstack((res,res2))
	cv2.imshow('original/sobelX/scharr/laplacian',resFinal)

img = cv2.imread('cinza.jpg',0)

gradientFilters()

# Press a key while the window with the image is open and the program closes.
cv2.waitKey(0)

# Close all windows
cv2.destroyAllWindows()