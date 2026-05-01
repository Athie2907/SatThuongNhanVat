#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>
#include <typeinfo>
using namespace std;

// Ham doi mau chu trong console (Windows)
void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

// ================== Lop co so ==================
class VuKhi {
protected:
    string ten;
    int satThuongCB;
    double tocDoRaDon;
public:
    VuKhi(string t = "", int st = 0, double td = 0.0)
        : ten(t), satThuongCB(st), tocDoRaDon(td) {}

    VuKhi(const VuKhi& v) {
        ten = v.ten;
        satThuongCB = v.satThuongCB;
        tocDoRaDon = v.tocDoRaDon;
    }

    void setTen(string t) { ten = t; }
    string getTen() const { return ten; }

    void setSatThuongCB(int st) { satThuongCB = st; }
    int getSatThuongCB() const { return satThuongCB; }

    void setTocDoRaDon(double td) { tocDoRaDon = td; }
    double getTocDoRaDon() const { return tocDoRaDon; }

    void setThongSoCoBan(string t, int st, double td) {
        ten = t; satThuongCB = st; tocDoRaDon = td;
    }

    virtual void TanCong() = 0;
    virtual double SatThuong(int t) = 0;
};

// ================== Lop Sung ==================
class Sung : public VuKhi {
private:
    int soDan;
    double tocDoThayBang;
public:
    Sung(string t = "", int st = 0, double td = 0.0, int sd = 0, double tdtb = 0.0)
        : VuKhi(t, st, td), soDan(sd), tocDoThayBang(tdtb) {}

    Sung(const Sung& s) : VuKhi(s) {
        soDan = s.soDan;
        tocDoThayBang = s.tocDoThayBang;
    }

    void setSoDan(int sd) { soDan = sd; }
    int getSoDan() const { return soDan; }

    void setTocDoThayBang(double tocdo) { tocDoThayBang = tocdo; }
    double getTocDoThayBang() const { return tocDoThayBang; }

    void TanCong() override {
        setColor(12); // do
        cout << "[Sung] " << ten << " dang ban voi " << soDan << " vien dan!\n";
        setColor(7); //trang
    }

    double SatThuong(int t) override {
        return (getSatThuongCB() * getTocDoRaDon() * t) / (1 + tocDoThayBang);
    }

    friend istream& operator>>(istream& is, Sung& s) {
        cout << "Nhap ten sung: "; 
		getline(is, s.ten );
		
        cout << "Nhap sat thuong co ban: "; is >> s.satThuongCB;
        cout << "Nhap toc do ra don: "; is >> s.tocDoRaDon;
        cout << "Nhap so dan: "; is >> s.soDan;
        cout << "Nhap toc do thay bang: "; is >> s.tocDoThayBang;
        return is;
    }

    friend ostream& operator<<(ostream& os, const Sung& s) {
        os << "[Sung] " << s.ten << " | Sat thuong: " << s.satThuongCB
           << " | Toc do: " << s.tocDoRaDon
           << " | So dan: " << s.soDan
           << " | Toc do thay bang: " << s.tocDoThayBang;
        return os;
    }
};

// ================== Lop Kiem ==================
class Kiem : public VuKhi {
private:
    int doBen;
public:
    Kiem(string t = "", int st = 0, double td = 0.0, int db = 100)
        : VuKhi(t, st, td), doBen(db) {}

    Kiem(const Kiem& k) : VuKhi(k) {
        doBen = k.doBen;
    }

    void setDoBen(int db) { doBen = db; }
    int getDoBen() const { return doBen; }

    void TanCong() override {
        setColor(10); // xanh lá
        cout << "[Kiem] " << ten << " dang chem voi do ben " << doBen << "%!\n";
        setColor(7);
    }

    double SatThuong(int t) override {
        return getSatThuongCB() * (doBen / 100.0) * t;
    }

    friend istream& operator>>(istream& is, Kiem& k) {
        cout << "Nhap ten kiem: ";
		getline(is, k.ten);
		
        cout << "Nhap sat thuong co ban: "; is >> k.satThuongCB;
        cout << "Nhap toc do ra don: "; is >> k.tocDoRaDon;
        cout << "Nhap do ben (%): "; is >> k.doBen;
        return is;
    }

    friend ostream& operator<<(ostream& os, const Kiem& k) {
        os << "[Kiem] " << k.ten << " | Sat thuong: " << k.satThuongCB
           << " | Toc do: " << k.tocDoRaDon
           << " | Do ben: " << k.doBen << "%";
        return os;
    }
};

// ================== Lop PhepThuat ==================
class PhepThuat : public VuKhi {
private:
    string loaiPhep;
    int manaTieuThuTrenGiay;
    int manaHienTai;
    int manaMoiGiay;
public:
    PhepThuat(string t = "", int st = 0, double td = 0.0, string lp = "", int mtt = 0)
        : VuKhi(t, st, td), loaiPhep(lp), manaTieuThuTrenGiay(mtt), manaHienTai(100), manaMoiGiay(5) {}

    PhepThuat(const PhepThuat& pt) : VuKhi(pt) {
        loaiPhep = pt.loaiPhep;
        manaTieuThuTrenGiay = pt.manaTieuThuTrenGiay;
        manaHienTai = pt.manaHienTai;
        manaMoiGiay = pt.manaMoiGiay;
    }

    void setLoaiPhep(string lp) { loaiPhep = lp; }
    string getLoaiPhep() const { return loaiPhep; }

    void setManaTieuThuTrenGiay(int mana) { manaTieuThuTrenGiay = mana; }
    int getManaTieuThuTrenGiay() const { return manaTieuThuTrenGiay; }

    void setManaHienTai(int manaht) { manaHienTai = manaht; }
    int getManaHienTai() const { return manaHienTai; }

    void setManaMoiGiay(int manamg) { manaMoiGiay = manamg; }
    int getManaMoiGiay() const { return manaMoiGiay; }

    bool KiemTraMana(int t) {
        return manaHienTai >= manaTieuThuTrenGiay * t;
    }

    void TanCong() override {
        setColor(9); // xanh duong
        cout << "[PhepThuat] " << ten << " tung ra " << loaiPhep << "!\n";
        setColor(7);
    }

    double SatThuong(int t) override {
        if (KiemTraMana(t)) {
            manaHienTai -= manaTieuThuTrenGiay * t;
            return (satThuongCB + manaMoiGiay) * t;
        }
        return 0;
    }

    friend istream& operator>>(istream& is, PhepThuat& p) {
        cout << "Nhap ten phep: "; 
		getline(is, p.ten);
		
        cout << "Nhap sat thuong co ban: "; is >> p.satThuongCB;
        cout << "Nhap toc do ra don: "; is >> p.tocDoRaDon;
        cout << "Nhap loai phep: "; is >> p.loaiPhep;
        cout << "Nhap mana tieu thu moi giay: "; is >> p.manaTieuThuTrenGiay;
        return is;
    }

    friend ostream& operator<<(ostream& os, const PhepThuat& p) {
        os << "[PhepThuat] " << p.ten << " | Loai: " << p.loaiPhep
           << " | Sat thuong: " << p.satThuongCB;
        return os;
	}  
};

void menu() {
    setColor(14);
    cout << "\n===== MENU =====\n";
    setColor(7);
    cout << "1. Them vu khi\n";
    cout << "2. Xuat danh sach\n";
    cout << "3. Tan cong\n";
    cout << "0. Thoat\n";
    cout << "Chon: ";
}

int main() {
    VuKhi* ds[100];
    int dem = 0, chon;
    
    do{
    	menu();
    	cin >> chon;
    	cin.ignore();
    	
    	if(chon == 1){
    		int loai;
    		cout << "Chon (1-Sung, 2-Kiem, 3-PhepThuat): ";
    		cin >> loai;
    		cin.ignore();
    		
    		if(loai == 1){
    			Sung* s = new Sung();
    			cin >> *s;
    			ds[dem++] = s;
			}
			else if(loai == 2){
				Kiem* k = new Kiem();
				cin >> *k;
				ds[dem++] = k;
			}
			else{
				PhepThuat* p = new PhepThuat();
				cin >> *p;
				ds[dem++] = p;
			}
		}
		else if (chon == 2) {

            setColor(14); // vàng
            cout << left
                << setw(12) << "Loai"
                << setw(20) << "Ten"
                << setw(15) << "STCB"
                << setw(15) << "TocDo"
                << setw(15) << "ThongSo"
                << endl;

            setColor(7);
            cout << string(75, '-') << endl;

            for (int i = 0; i < dem; i++) {
                // SUNG
                if (Sung* s = dynamic_cast<Sung*>(ds[i])) {
                    setColor(12); // d?

                    cout << left
                         << setw(12) << "Sung"
                         << setw(20) << s->getTen()
                         << setw(15) << s->getSatThuongCB()
                         << setw(15) << s->getTocDoRaDon()
                         << setw(15) << s->getSoDan();
                }     

                // KIEM
                else if (Kiem* k = dynamic_cast<Kiem*>(ds[i])) {
                    setColor(10); // xanh lá

                    cout << left
                         << setw(12) << "Kiem"
                         << setw(20) << k->getTen()
                         << setw(15) << k->getSatThuongCB()
                         << setw(15) << k->getTocDoRaDon()
                         << setw(15) << k->getDoBen();
                }

                // PHEP THUAT
                else if (PhepThuat* p = dynamic_cast<PhepThuat*>(ds[i])) {
                    setColor(9); // xanh duong

                    cout << left
                         << setw(12) << "Phep"
                         << setw(20) << p->getTen()
                         << setw(15) << p->getSatThuongCB()
                         << setw(15) << p->getTocDoRaDon()
                         << setw(15) << p->getLoaiPhep();
                }
                setColor(7);
                cout << endl;
            }
        }
		else if(chon == 3){
			int t;
            cout << "Nhap thoi gian tan cong: ";
            cin >> t;

            for (int i = 0; i < dem; i++) {
              ds[i]->TanCong();
              cout << "Sat thuong: " << ds[i]->SatThuong(t) << endl;
            }
		}
	}while (chon != 0);

    for (int i = 0; i < dem; i++) delete ds[i];
    return 0;
}
