#include <iostream>
#include <vector>
using namespace std;

class penerbit;
class pengarang {
public:
	string nama;
	vector<penerbit*> daftar_penerbit;
	pengarang(string pNama) : nama(pNama) {
		cout << "Pengarang \"" ;
	}
	~pengarang() {
		cout << "Pengarang \"" ;
	}
	void tambahanPenerbit(penerbit*);
	void cetakPenerbit();
};

class penerbit {
public:
	string nama;
	vector<pengarang*> daftar_pengarang;

	penerbit(string pNama) :nama(pNama) {
		cout << "Penerbit \"" ;
	}
	void tambahanPengarang(pengarang*);
	void cetakPengarang();
};

void pengarang::tambahanPenerbit(penerbit* pPenerbit) {
	daftar_penerbit.push_back(pPenerbit);
}
void pengarang::cetakPenerbit() {
	cout << "Daftar Pengarang pada penerbit 'game press' \"" << this->nama << "\":\n";
	for (auto& a : daftar_penerbit) {
		cout << a->nama << "\n";
	}
	cout << endl;
}
void penerbit::tambahanPengarang(pengarang* pPengarang) {
	daftar_pengarang.push_back(pPengarang);
	pPengarang->tambahanPenerbit(this);
}
void penerbit::cetakPengarang() {
	cout << "Daftar pengarang pada penerbit 'intan pariwara' \"" << this->nama << "\":\n";
	for (auto& a : daftar_pengarang) {
		cout << a->nama << "\n";
	}
	cout << endl;
}

int main() {
	penerbit* varPenerbit1 = new penerbit("joko");
	penerbit* varPenerbit2 = new penerbit("Asroni");
	pengarang* varPengarang1 = new pengarang("Giga");
	pengarang* varPengarang2 = new pengarang("Lia");

	varPenerbit1->tambahanPengarang(varPengarang1);
	varPenerbit2->tambahanPengarang(varPengarang2);
	varPenerbit2->tambahanPengarang(varPengarang1);

	varPenerbit1->cetakPengarang();
	varPenerbit2->cetakPengarang();
	varPengarang1->cetakPenerbit();
	varPengarang2->cetakPenerbit();

	delete varPengarang1;
	delete varPengarang2;
	delete varPenerbit1;
	delete varPenerbit2;

	return 0;
}