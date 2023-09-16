dictionary = { "first_key": "first_value",
    "second_key": "second_value", }

dictionary = {}
dictionary["key1"] = "value1"
dictionary["key2"] = "value2"
dictionary["key3"] = "value3"

[print(key) for key in dictionary.keys()]
[print(value) for value in dictionary.values()]

for key in dictionary.keys():
    print("\"{} : {}\"".format(key, dictionary[key]))

[print("\"{} : {}\"".format(key, dictionary[key])) for key in dictionary.keys()]
print(len(dictionary))

print("-")
dictionary.clear()
[print(key) for key in dictionary]
print(len(dictionary))
