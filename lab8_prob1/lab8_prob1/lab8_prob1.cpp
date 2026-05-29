#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <cctype> //tolower

struct wordcompare {
	bool operator()(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) const 
	{
		if (a.second != b.second)
			return a.second < b.second;//frecventa mai mica este impinsa mai jos in coada
		return a.first > b.first;
	}
};

int main()
{
	std::ifstream file("input.txt");
	if (!file.is_open())
	{
		std::cerr << "Eroare la deschiderea fisierului .txt\n";
		return 1;
	}

	std::string s;
	std::getline(file, s, '\0');
	file.close();

	std::map<std::string, int> word_count;
	std::string separators = " ,.!?";

	size_t start = s.find_first_not_of(separators);//inceputul primului cuvant

	while (start != std::string::npos)
	{
		size_t end = s.find_first_of(separators,start);
		std::string word = s.substr(start, end - start);//substract cuvant
		for (char& c : word)
			c = std::tolower(c);
		word_count[word]++;
		start = s.find_first_not_of(separators, end);//inceputul urmatorului cuvant
	}

	std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, wordcompare> sorted_words;
	//def coada specificand: tipul de date, containerul intern, logica de comparare
	for (const auto& pair : word_count)
		sorted_words.push(pair);//mutarea datelor din dictionar in coada

	while (!sorted_words.empty())
	{
		auto top_element = sorted_words.top();
		std::cout << top_element.first << " => " << top_element.second << '\n';
		sorted_words.pop();
	}
	return 0;
}