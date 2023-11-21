import pandas as pd
import seaborn as sns

tips = sns.load_dataset("tips")
tips

tips.plot(kind = "line")
matplotlib.pyplot.show()

tips.plot(kind = "hist")
matplotlib.pyplot.show()

tips.plot(kind = "box")
matplotlib.pyplot.show()

matplotlib.pyplot.plot(tips["total_bill"])
matplotlib.pyplot.show()

matplotlib.pyplot.bar(tips["sex"], tips["total_bill"])
matplotlib.pyplot.show()

matplotlib.pyplot.scatter(tips["total_bill"], tips["tip"])
matplotlib.pyplot.show()

matplotlib.pyplot.hist(tips["total_bill"])
matplotlib.pyplot.show()

matplotlib.pyplot.hist(tips["day"])
matplotlib.pyplot.show()
