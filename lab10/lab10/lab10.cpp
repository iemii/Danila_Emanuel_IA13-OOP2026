#include <iostream>
#include <exception>

using namespace std;

class IndexOutOfBoundsException : public exception {
public:
	virtual const char* what() const throw()
	{
		return "Exceptie: Indexul este in afara domeniului!";
	}
};

class Compare {
public:
	virtual int CompareElements(void* e1, void* e2) = 0;
};

template<class T>
class ArrayIterator {
private:
	int Current;
	T** List;
public:
	ArrayIterator() : Current(0), List(nullptr) {}
	ArrayIterator(T** list, int pos) : List(list), Current(pos){}
	
	ArrayIterator& operator ++ ()
	{
		Current++;
		return *this;
	}

	ArrayIterator& operator -- ()
	{
		Current--;
		return *this;
	}

	bool operator=(ArrayIterator <T>& other)
	{
		List = other.List;
		Current = other.Current;
		return true;
	}

	bool operator!=(ArrayIterator <T>& other)
	{
		return Current != other.Current;
	}

	T* GetElement()
	{
		return List[Current];
	}
};

template<class T>
class Array {
private:
	T** List;
	int Capacity;
	int Size;

	void resize()
	{
		Capacity = (Capacity == 0) ? 2 : Capacity * 2;
		T** newlist = new T * [Capacity];
		for (int i = 0; i < Size; i++)
			newlist[i] = List[i];
		delete[] List;
		List = newlist;
	}
public:
	Array() : List(nullptr), Capacity(0), Size(0) {}
	~Array()
	{
		for (int i = 0; i < Size; i++)
			delete List[i];
		delete[] List;
	}
	Array(int capacity) : Capacity(capacity), Size(0) {
		List = new T * [Capacity];
	}
	Array(const Array<T>& otherArray)
	{
		Capacity = otherArray.Capacity;
		Size = otherArray.Size;
		List = new T * [Capacity];
		for (int i = 0; i < Size; i++)
			List[i] = new T(*(otherArray.List[i]));//deep copy
	}

	T& operator[] (int index)
	{
		if (index < 0 || index >= Size)
			throw IndexOutOfBoundsException();
		return *(List[index]);
	}

	const Array<T>& operator+=(const T& newElem)
	{
		if (Size == Capacity)
			resize();
		List[Size] = new T(newElem);
		Size++;
		return *this;
	}

	const Array<T>& Insert(int index, const T& newElem)
	{
		if (index<0 || index>Size)
			throw IndexOutOfBoundsException();
		if (Size == Capacity)
			resize();
		for (int i = Size; i > index; i--)
			List[i] = List[i - 1];
		List[index] = new T(newElem);
		Size++;
		return *this;
	}

	const Array<T>& Insert(int index, const Array<T> otherArray)
	{
		if (index<0 || index>Size)
			throw IndexOutOfBoundsException();
		if (Size+otherArray.Size > Capacity)
			resize();
		for (int i = Size - 1; i >= index; i--)
			List[i + otherArray.Size] = List[i];
		for (int i = 0; i < otherArray.Size; i++)
			List[index + i] = new T(*(otherArray.List[i]));
		Size += otherArray.Size;
		return *this;
	}

	const Array<T>& Delete(int index)
	{
		if (index<0 || index>Size)
			throw IndexOutOfBoundsException();
		delete List[index];
		for (int i = index; i < Size - 1; i++)
			List[i] = List[i + 1];
		Size--;
		return *this;
	}

	bool operator=(const Array<T>& otherArray)
	{
		if (this == &otherArray)
			return true;
		for (int i = 0; i < Size; i++)
		{
			delete List[i];
		}
		delete[] List;

		Capacity = otherArray.Capacity;
		Size = otherArray.Size;
		List = new T * [Capacity];
		for (int i = 0; i < Size; i++)
			List[i] = new T(*(otherArray.List[i]));
		return true;
	}

	void Sort()
	{
		for (int i = 0; i < Size - 1; i++)
			for (int j = i + 1; j < Size; j++)
				if (*List[i] > *List[j])
					swap(List[i], List[j]);
	}

	void sort(int(*compare)(const T&, const T&))
	{
		for (int i = 0; i < Size - 1; i++)
			for (int j = i + 1; j < Size; j++)
				if (compare(*List[i], *List[j]) > 0)
					swap(List[i], List[j]);
	}

	void sort(Compare* comparator)
	{
		for (int i = 0; i < Size - 1; i++)
			for (int j = i + 1; j < Size; j++)
				if (comparator->CompareElements((void*)List[i], (void*)List[j]) > 0)
					swap(List[i], List[j]);
	}

	int BinarySearch(const T& elem)
	{
		int left = 0, right = Size - 1;
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			if (*List[mid] == elem)
				return mid;
			if (*List[mid] < elem)
				left = mid + 1;
			else
				right = mid - 1;
		}
		return -1;
	}

	int BinarySearch(const T& elem, int(*compare)(const T&, const T&))
	{
		int left = 0, right = Size - 1;
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			int compresult = compare(*List[mid], elem);
			if (compresult == 0)
				return mid;
			if (compresult < 0)
				left = mid + 1;
			else
				right = mid - 1;
		}
		return -1;
	}

	int BinarySearch(const T& elem, Compare* comparator)
	{
		int left = 0, right = Size - 1;
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			T elementToSearch = elem;
			int compresult = comparator->CompareElements((void*)List[mid], (void*)&elementToSearch);
			if (compresult == 0)
				return mid;
			if (compresult < 0)
				left = mid + 1;
			else
				right = mid - 1;
		}
		return -1;
	}

	int Find(const T& elem)
	{
		for (int i = 0; i < Size; i++)
			if (*List[i] == elem)
				return i;
		return -1;
	}

	int Find(const T& elem, int(*compare)(const T&, const T&))
	{
		for (int i = 0; i < Size; i++)
			if (compare(*List[i], elem) == 0)
				return i;
		return -1;
	}

	int Find(const T& elem, Compare* comparator)
	{
		T elementToSearch = elem;
		for (int i = 0; i < Size; i++)
			if (comparator->CompareElements((void*)List[i], (void*)&elementToSearch) == 0)
				return i;
		return -1;
	}

	int GetSize()
	{
		return Size;
	}
	int GetCapacity()
	{
		return Capacity;
	}
	ArrayIterator<T> GetBeginIterator() {
		return ArrayIterator<T>(List, 0);
	}

	ArrayIterator<T> GetEndIterator() {
		return ArrayIterator<T>(List, Size);
	}
};

int functieComparare(const int& a, const int& b) {
	if (a < b) return -1;
	if (a > b) return 1;
	return 0;
}

class MyComparator : public Compare {
public:
	int CompareElements(void* e1, void* e2) override {
		int* a = (int*)e1;
		int* b = (int*)e2;
		if (*a < *b) return -1;
		if (*a > *b) return 1;
		return 0;
	}
};

int main() {
	Array<int> arr;

	//testam inserarea si operatorul +=
	arr += 10;
	arr += 20;
	arr.Insert(1, 15); //lista devine: 10, 15, 20

	cout << "Elemente curente:" << endl;
	for (int i = 0; i < arr.GetSize(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	//testam exceptiile (try-catch)
	try {
		cout << "Incercam accesul la indexul 100: ";
		cout << arr[100] << endl;
	}
	catch (exception& e) {
		cout << e.what() << endl; //va prinde IndexOutOfBoundsException
	}

	try {
		cout << "Incercam stergerea de la indexul -1: ";
		arr.Delete(-1);
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}

	//testam iterarea si stergerea corecta
	arr.Delete(1); //sterge valoarea 15
	cout << "\nElemente dupa stergere, afisate folosind iteratorul:" << endl;

	ArrayIterator<int> it = arr.GetBeginIterator();
	ArrayIterator<int> endIt = arr.GetEndIterator();

	while (it != endIt) {
		cout << *(it.GetElement()) << " ";
		++it;
	}
	cout << endl;

	return 0;
}