#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

typedef std::string String;
typedef std::vector<String> StringArray;
typedef std::pair<String, int> WordCountPair;
typedef std::map<String, int> WordCountMap;
typedef std::vector<WordCountPair> WordCountArray;

class countWord {
private:
	WordCountMap& map;
public:
	countWord(WordCountMap& map): map(map) {};
	void operator()(String& word);
};

void countWord::operator()(String& word) {
	const WordCountMap::iterator& wordPairIter = this->map.find(word);
	if (wordPairIter == this->map.end())
		this->map.insert(WordCountPair(word, 1));
	else
		++wordPairIter->second;
};

String WordCountPairDescription(WordCountPair& pair) {
	return "{ \"" + pair.first + "\": " + std::to_string(pair.second) + " }";
}

String WordCountArrayDescription(WordCountArray& array) {
	String string = "[\n\t" + WordCountPairDescription(array[0]);
	for (WordCountArray::iterator it = array.begin() + 1; it != array.end(); ++it)
		string += ",\n\t" + WordCountPairDescription(*it);
	string += "\n]";

	return string;
}

bool compareWordCountPairWithCount(const WordCountPair& lhs, const WordCountPair& rhs) {
	return (lhs.second > rhs.second);
}

int main(int argc, char** argv) {
	if (argc != 2)
	{
		std::cout << "error: invalid argc" << std::endl;
		return -1;
	}

	std::ifstream target;
	target.open(argv[1]);
	if (!target.is_open()) {
		std::cout << "error: no file [" << argv[1] << "]" << std::endl;
		return -1;
	}

	StringArray wordArray;
	copy(std::istream_iterator<String, char>(target),
			std::istream_iterator<String, char>(),
			std::insert_iterator<StringArray>(wordArray, wordArray.begin()));

	WordCountMap wordCountMap;
	for_each(wordArray.begin(), wordArray.end(), countWord(wordCountMap));

	WordCountArray wordCountArray;
	copy(wordCountMap.begin(),
			wordCountMap.end(),
			std::insert_iterator<WordCountArray>(wordCountArray, wordCountArray.begin()));
	sort(wordCountArray.begin(), wordCountArray.end(), compareWordCountPairWithCount);
	std::cout << WordCountArrayDescription(wordCountArray) << std::endl;


// 	for_each(wordCountArray.begin(), wordCountArray.end(), describePair<String, int>);

// 	std::set<String> wordSet;
// 	copy(wordArray.begin(),
// 			wordArray.end(),
// 			std::insert_iterator<std::set<String> >(wordSet, wordSet.begin()));
// 	copy(wordSet.begin(),
// 			wordSet.end(),
// 			std::ostream_iterator<String, char>(std::cout, "\n"));

	target.close();

	return 0;
}
