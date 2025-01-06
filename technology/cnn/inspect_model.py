import tensorflow as tf
from tensorflow.keras.models import load_model
from tensorflow.keras.layers import DepthwiseConv2D

# Load the model in the newer TensorFlow version
# Custom function to strip 'groups' argument
def compatible_depthwise_conv2d(*args, **kwargs):
    kwargs.pop("groups", None)  # Remove unsupported argument 'groups'
    return DepthwiseConv2D(*args, **kwargs)

model_path = "keras_model.h5"
# model_path = "saved_model.pb"

# Load the model using custom_objects
model = load_model(
    model_path,
    custom_objects={"DepthwiseConv2D": compatible_depthwise_conv2d},
)
model_json = model.to_json()

with open("model_architecture.json", "w") as json_file:
    json_file.write(model_json)

from tensorflow.keras.models import model_from_json

with open("model_config.json", "r") as f:
  model_config = f.read()
model = model_from_json(model_config)
model.save("compatible_model.h5")
