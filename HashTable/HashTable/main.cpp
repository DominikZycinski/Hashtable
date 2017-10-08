#include <iostream>
#include <string>
#include <fstream>

//Dominik Zycinski, Hashtable, 28.03.2017 

class Object
{
public:
	long key;
	std::string text;
	char flag = 'e';

	Object(long k, std::string s)
	{
		key = k;
		text = s;
	}
	Object()
	{}
	~Object()
	{}
};

class hashtable
{
public:
	long rozmiar;
	Object *tabela;
	Object *kopia;
	long n;
	long klucz;
	long index = 0;
	hashtable() {};
	~hashtable()
	{

		delete[] tabela;
		delete[] kopia;

	}
	void size(int x)
	{
		rozmiar = x;
		tabela = new Object[rozmiar];

		kopia = new Object[rozmiar];

		for (int i = 0; i < x; i++)
		{
			tabela[i].flag = 'E';
			tabela[i].key = NULL;
			kopia[i].key = NULL;
			kopia[i].flag = 'E';
			kopia[i].text = "NULL";
			tabela[i].text = "NULL";
		}

	}

	long hash(long k)
	{
		return n = k%rozmiar;
	}

	void add(Object &o)
	{


		for (int i = 0; i < rozmiar; i++)
		{

			if (kopia[i].key == NULL)
			{
				kopia[i].key = o.key;
				kopia[i].text = o.text;
				break;

			}
			n++;
		}

		hash(o.key);

		for (int i = 0; i < rozmiar; i++)
		{

			if (tabela[n].flag == 'E')
			{
				tabela[n].key = o.key;
				tabela[n].text = o.text;
				tabela[n].flag = 'F';


				break;
			}

			if (tabela[n].flag == 'F' || tabela[n].flag == 'C')
			{
				tabela[n].flag = 'C';

				if (n >= rozmiar)
				{
					n = -1;
				}
			}

			if (n >= rozmiar)
			{
				n = -1;
			}


			n++;
		}
	}

	void print()
	{

		for (int i = 0; i < rozmiar; i++)
		{

			if (tabela[i].flag != 'E')
			{
				std::cout << i << " " << tabela[i].key << "  " << tabela[i].text << std::endl;

			}

		}
	}


	void deletee(int k)
	{

		for (int i = 0; i < rozmiar; i++)
		{
			tabela[i].flag = 'E';
			tabela[i].key = NULL;
			tabela[i].text = "NULL";
		}



		for (int i = 0; i < rozmiar; i++)
		{
			if (kopia[i].key == k)
			{
				kopia[i].key = NULL;
			}
		}




		for (int i = 0; i < rozmiar; i++)
		{
			if (kopia[i].key != NULL)
			{
				klucz = kopia[i].key %rozmiar;


				for (int j = 0; j < rozmiar; j++)
				{

					if (tabela[klucz].flag == 'E')
					{

						tabela[klucz].key = kopia[i].key;
						tabela[klucz].text = kopia[i].text;
						tabela[klucz].flag = 'F';

						break;

					}

					if (tabela[klucz].flag == 'F' || tabela[klucz].flag == 'C')
					{

						tabela[klucz].flag = 'C';

						if (klucz >= rozmiar)
						{

							klucz = -1;
						}
					}

					if (klucz >= rozmiar)
					{
						klucz = -1;
					}

					klucz++;

				}

			}
		}

	}

};

int main()
{

	hashtable h;

	long n;
	std::cin >> n;

	std::string s;

	do {
		if (n>0) {
			std::cin >> s;

			int rozmiar;
			int klucz;
			int usun;
			std::string text;
			if (s == "size")
			{
				std::cin >> rozmiar;
				h.size(rozmiar);

			}
			else if (s == "add")

			{
				std::cin >> klucz;
				std::cin >> text;
				Object a(klucz, text);
				h.add(a);


			}
			else if (s == "print")
			{
				h.print();
				std::cout << std::endl;
			}
			else if (s == "delete")
			{
				std::cin >> usun;
				h.deletee(usun);
			}
			else if (s == "stop")
			{
				n--;

			}



		}
	} while (n > 0);



	return 0;



}
