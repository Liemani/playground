import tensorflow as tf
from tensorflow.keras.models import load_model
from tensorflow.keras.layers import DepthwiseConv2D

# Custom function to strip 'groups' argument
def compatible_depthwise_conv2d(*args, **kwargs):
    kwargs.pop("groups", None)  # Remove unsupported argument 'groups'
    return DepthwiseConv2D(*args, **kwargs)

model_path = "model2.h5"
# model_path = "saved_model.pb"

# Load the model using custom_objects
model = load_model(
    model_path,
    custom_objects={"DepthwiseConv2D": compatible_depthwise_conv2d},
)

print("Model loaded successfully")



import cv2
import tensorflow as tf
import numpy as np

# # Load the pre-trained model
# model_path = "keras_model.h5"  # Replace with your .h5 file path
# model = tf.keras.models.load_model(model_path)

# Define video capture using MacBook camera
cap = cv2.VideoCapture(0)  # '0' is the default camera

# Check if the camera opened successfully
if not cap.isOpened():
    print("Error: Cannot access camera")
    exit()

print("Press 'q' to exit the video stream")

# Real-time camera feed loop
while True:
    ret, frame = cap.read()  # Capture frame-by-frame
    if not ret:
        print("Error: Cannot read frame")

    # Preprocess the frame to match the input size of the model
    resized_frame = cv2.resize(frame, (224, 224))  # Adjust size as per your model
    input_frame = resized_frame / 255.0  # Normalize pixel values
    input_frame = np.expand_dims(input_frame, axis=0)  # Add batch dimension

    # Run prediction using the loaded model
    prediction = model.predict(input_frame)
    
    # Display the prediction on the frame
    cv2.putText(frame, f"Prediction: {prediction}", (10, 30),
                cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)

    # Show the current frame
    cv2.imshow('Camera Feed', frame)

    # Exit the loop when 'q' is pressed
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# Release the camera and close windows
cap.release()
cv2.destroyAllWindows()
