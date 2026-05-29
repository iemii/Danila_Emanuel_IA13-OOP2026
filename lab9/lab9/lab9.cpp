#include <iostream>

template <typename K, typename V>
class Map {
public:
	//structura interna pentru "Structured Binding"
	struct element {
		K key;
		V value;
		int index;
	};
private:
	element* elements;
	int current_count;
	int max_cap;

	void resize()
	{
		max_cap = (max_cap == 0) ? 2 : max_cap * 2;
		element* new_elements = new element[max_cap];
		for (int i = 0; i < current_count; i++)
			new_elements[i] = elements[i];
		delete[] elements;
		elements = new_elements;
	}
public:
	Map():elements(nullptr),current_count(0),max_cap(0){}
	~Map() {
		delete[] elements;
	}

	V& operator[](const K& key)//supraincarcarea operatorului []
	{
		//daca cheia exista deja, returnam prin referinta pt a putea fi modificata
		for (int i = 0; i < current_count; i++)
			if (elements[i].key == key)
				return elements[i].value;
		//daca nu, facem loc pt element nou
		if (current_count == max_cap)
			resize();
		elements[current_count].key = key;
		elements[current_count].index = current_count;
		return elements[current_count++].value;
	}

	void Set(const K& key, const V& value)
	{
		(*this)[key] = value;
	}

	bool Get(const K& key, V& value) const
	{
		for(int i=0;i<current_count;i++)
			if (elements[i].key == key)
			{
				value = elements[i].value;
				return true;
			}
		return false;
	}

	int Count() const
	{
		return current_count;
	}

	void Clear()
	{
		current_count = 0;
	}

	bool Delete(const K& key)
	{
		for (int i = 0; i < current_count; i++)
		{
			if (elements[i].key == key)
			{
				for (int j = i; j < current_count - 1; j++)
				{
					elements[j] = elements[j + 1];
					elements[j].index = j;
				}
				current_count--;
				return true;
			}
		}
		return false;
	}

	bool Includes(const Map<K, V>& map) const
	{
		for (int i = 0; i < map.current_count; i++)
		{
			bool found = false;
			for(int j=0;j<current_count;j++)
				if (elements[j].key == map.elements[i].key)
				{
					found = true;
					break;
				}
			if (!found)
				return false;
		}
		return true;
	}

	//mecanisme pt range based loop
	//un pointer brut actioneaza perfect pe post de iterator pt un array continuu
	element* begin()
	{
		return elements;
	}
	element* end()
	{
		return elements + current_count;
	}

	const element* begin() const
	{
		return elements;
	}
	const element* end() const
	{
		return elements + current_count;
	}
};

int main()
{
	Map<int, const char*> m;
	m[10] = "C++";
	m[20] = "test";
	m[30] = "Poo";
	for (auto [key, value, index] : m)
	{
		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
	}
	m[20] = "result";
	for (auto [key, value, index] : m)
	{
		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
	}
	return 0;
}