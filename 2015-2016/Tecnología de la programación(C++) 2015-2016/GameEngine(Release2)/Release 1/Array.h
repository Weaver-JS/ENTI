#pragma once
template <class data>
class Array
{

	/*
	Clase template que nos permitirá utilizar arrays dinámicos
	sin necesidad de gestionar la memoria, ya que se realizará internamente.
	*/
private:
	
	int length;
	int actualPosition;
	void resizeArray()
	{
		data* copyArray = new data[length * 2];
		for (int i = 0; i < length;i++)
		{
			copyArray[i] = dataArray[i];
		}
		delete[] dataArray;
		dataArray = copyArray;
		length *= 2;
		if (actualPosition >= length)
		{
			resizeArray();
		}


	}
public:
	data* dataArray;
	Array() {
		length = 10;
		allocateMatrixMemory();
	}
	int getLenght()
	{
		return length;
	}

	void setActualPosition(int i)
	{
		actualPosition = i;
		if (actualPosition >= length)
			resizeArray();
	}
	int getActualPosition()
	{
		return actualPosition;
	}

	Array(int length)
	{
		dataArray = 0;
		this->length = length;
		actualPosition = 0;
		allocateMatrixMemory();
	}
	Array(Array &arrCopy)
	{
		length = arrCopy.length;
		actualPosition = arrCopy.actualPosition;
		dataArray = arrCopy.dataArray;
	}
	~Array()
	{
		//PREGUNTAR A ALBERT.
		//std::cout << "NO PROBLEM";
		//if(dataArray != 0)
		//delete[] dataArray;
	}

	void allocateMatrixMemory()
	{
		dataArray = new data[length];
		
	}

	void addData(data p)
	{
		if (actualPosition >= length)
		{
			resizeArray();
		}
		dataArray[actualPosition] = p;
		actualPosition++;
	}
	void addDataWithoutInf()
	{
		if (actualPosition == length)
		{
			resizeArray();
		}
		actualPosition++;
		
	}
	void removeData(int id)
	{
		if (dataArray[id] != 0)
		{
			for (int i = id; i < actualPosition;i++)
			{
				dataArray[i] = dataArray[i + 1];
			}
			actualPosition--;
		}
	}

	void removeDataWithoutInf()
	{
		if (actualPosition > 0)
		{
			actualPosition--;
		}
	}

	
};

