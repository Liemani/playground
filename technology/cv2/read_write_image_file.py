import cv2

inputFile = "Screenshot 2024-12-18 at 17.04.00.jpeg"
outputFile = "output.jpeg"

image = cv2.imread(inputFile, cv2.IMREAD_COLOR)
print(image)
# print(dir(image))
print("Shape:", image.shape)
print("Size:", image.size)
print("Data type:", image.dtype)
print(type(image))
# cv2.imwrite(outputFile, image)
