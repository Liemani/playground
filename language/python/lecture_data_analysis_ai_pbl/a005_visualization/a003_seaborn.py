import seaborn as sns
import warnings

warnings.filterwarnings(action = "ignore")
# warnings.filterwarnings(action = "default")

tips = sns.load_dataset("tips")

# deep, muted, pastel, bright, dark, colorblind
sns.set_palette("pastel")

sns.stripplot(x = "day", y = "total_bill", data = tips)
matplotlib.pyplot.show()

sns.barplot(x = "sex", y = "tip", data = tips)
matplotlib.pyplot.show()

sns.barplot(x = "sex", y = "tip", hue= "day", data = tips)
matplotlib.pyplot.show()

sns.barplot(x = "day", y = "tip", hue= "sex", data = tips)
matplotlib.pyplot.show()

sns.boxplot(x = "sex", y = "tip", data = tips)
matplotlib.pyplot.show()

sns.boxplot(data = tips, orient = "horisontal")
matplotlib.pyplot.show()

sns.kdeplot(tips["tip"])
matplotlib.pyplot.show()

sns.distplot(tips["tip"])
matplotlib.pyplot.show()

sns.countplot(x = "day", data = tips)
matplotlib.pyplot.show()

sns.jointplot(x = "total_bill", y = "tip", data = tips, kind = "scatter")
matplotlib.pyplot.show()

sns.jointplot(x = "total_bill", y = "tip", data = tips, kind = "kde")
matplotlib.pyplot.show()

sns.violinplot(x = "day", y = "total_bill", data = tips)
matplotlib.pyplot.show()

sns.pairplot(tips)
matplotlib.pyplot.show()

sns.pairplot(tips, hue = "sex")
matplotlib.pyplot.show()
