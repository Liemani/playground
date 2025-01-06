from tensorflow.keras.models import model_from_json

with open("model_config.json", "r") as f:
  model_config = f.read()
model = model_from_json(model_config)
model.save("compatible_model.h5")
