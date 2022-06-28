#include"bagliliste.hpp"
#include <iostream>
#include<iomanip>
using namespace std;
struct eleman {
	int veri;
	eleman *ileri;

};
struct liste
{
	eleman* bas;
	eleman* son;
	liste() { bas = NULL; son = NULL; }
	void elemanekle(eleman* e)
	{
		if (bas == NULL)
			bas == e;
		else
			son->ileri = e;
		son = e;
	}
	int elemans()
	{
		int s = 0;
		eleman* p = bas;
		while (p != NULL) {
			s++;
			p = p->ileri;

		}
		return s;

	}
	void arayaekle(eleman* yeni, int sira)
	{
		int kactane = elemans();
		if (sira == 0) {
			yeni->ileri = bas;
			bas = yeni;

		}
		else if (sira == kactane - 1) {
			son->ileri = yeni;
			son = yeni;


		}
		else {
			eleman* p = bas;
			for (int i = 0; i < sira; i++)
				p = p->ileri;
			yeni->ileri = p->ileri;
			p->ileri = yeni;

		}
	}
	void sil(int sira) {
		int kactane = elemans();
		if (sira == 0) {
			eleman* gecici = bas;
			bas = bas->ileri;
			delete gecici;

		}
		else
		{
			eleman* p = bas;
			for (int i = 0; i < sira - 1; i++)
				p = p->ileri;
			eleman *silenecek = p->ileri;
			p->ileri = silinecek->ileri;
			if (silenecek->ileri == NULL) son = p;
			delete silinecek;
		}
	}

		int elemanver(int sira) {
			eleman* p = bas;
			for (int i = 0; i < sira; i++)
				p = p->ileri;
			return p->veri;
		}
		void tumelemanlar() {
			eleman* p = bas;
			while (p != NULL) {
				cout << p->veri << " ";
				p = p->ileri;

			}
			cout << endl;

		
	}

};
int main()
{
	liste li;
	for (int i = 0; i < 5; i++) {
		//eleman e;
		//e.veri = i;
		//li.elemanekle(&e)
		eleman* e = new eleman;
		e->veri = i * 2;
		li.elemanekle(e);

	}
	eleman* yeni = new  eleman; yeni->veri = 9;
	li.arayaekle(yeni, 2);
	li.sil(1);
	li.tumelemanlar();
}




