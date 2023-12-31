#include <iostream>
#include <vector>
using namespace std;

class buku;
class pengarang;
class penerbit {
public :
	string nama;
	vector<pengarang*> daftar_pengarang;
	penerbit(string pNama) :nama(pNama) {
	}
	~penerbit() {
	}
	void tambahPengarang(pengarang*);
	void cetakPengarang();
};

class pengarang {
public:
	string nama;
	vector<penerbit*> daftar_penerbit;

	pengarang(string pNama) :nama(pNama) {
	}
	~pengarang() {
	}

	void tambahPenerbit(penerbit*);
	void cetakPenerbit();
};

class buku {
public:
	string nama;
	vector<pengarang*> daftar_pengarang;

	buku(string pNama) :nama(pNama) {
		cout << "buku \"" << nama << "\" ada\n";
	}
	~buku() {
		cout << "buku \"" << nama << "\" tidak ada\n";
	}

	void tambahPenerbit(penerbit*);
	void cetakPenerbit();
};
void penerbit::tambahPengarang(pengarang* pPengarang) {
	daftar_pengarang.push_back(pPengarang);
}

void penerbit::cetakPengarang() {
	cout << "Daftar pengarang pada penerbit \"" << this->nama << "\":\n";
	for (auto& a : daftar_pengarang) {
		cout << a->nama << "\n";
	}
	cout << endl;
}

void pengarang::tambahPenerbit(penerbit* pPenerbit) {
	daftar_penerbit.push_back(pPenerbit);
	pPenerbit->tambahPengarang(this);
}

void pengarang::cetakPenerbit() {
	cout << "Daftar Penerbit yang diikuti \"" << this->nama << "\":\n";
	for (auto& a : daftar_penerbit) {
		cout << a->nama << "\n";
	}
	cout << endl;
}

int main() {
	pengarang* varPengarang1 = new pengarang("Joko");
	pengarang* varPengarang2 = new pengarang("Lia");
	pengarang* varPengarang3 = new pengarang("Asroni");
	pengarang* varPengarang4 = new pengarang("Giga");
	penerbit* varPenerbit1 = new penerbit("Game Press");
	penerbit* varPenerbit2 = new penerbit("Intan Pariwara");

	varPenerbit1->tambahPengarang(varPengarang1);
	varPenerbit1->tambahPengarang(varPengarang2);
	varPenerbit1->tambahPengarang(varPengarang4);
	varPenerbit2->tambahPengarang(varPengarang3);
	varPenerbit2->tambahPengarang(varPengarang4);
	varPengarang4->tambahPenerbit(varPenerbit1);
	varPengarang4->tambahPenerbit(varPenerbit2);

	varPenerbit1->cetakPengarang();
	varPenerbit2->cetakPengarang();
	varPengarang4->cetakPenerbit();

	delete varPengarang1;
	delete varPengarang2;
	delete varPengarang3;
	delete varPengarang4;
	delete varPenerbit1;
	delete varPenerbit2;

	return 0;
}