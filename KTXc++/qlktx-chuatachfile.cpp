//HEADER
#include<iostream>
#include<vector>
#include<string>
#include <dos.h>
#include <unistd.h>
#include<fstream>
#include <sstream>
#include <iomanip>
using namespace std;
bool CoDauCach(string chuoi);
//DATE
class Date{
	private:
   		int ngay;
    	int thang;
    	int nam;
	public:
    	Date();
    	Date(int ngay, int thang, int nam);

    	void setNgay(int ngay);
    	void setThang(int thang);
    	void setNam(int nam);

    	int getNgay();
    	int getThang();
    	int getNam();

    	void Nhap();
    	void Xuat();
};
Date::Date(){
    ngay = 0;
    thang = 0;
    nam = 0;
}
Date::Date(int n, int t, int y){
    ngay = n;
    thang = t;
    nam = y;
    
}

void Date::setNgay(int n){ngay = n;}
void Date::setThang(int t){thang = t;}
void Date::setNam(int y){nam = y;}

int Date::getNgay(){return ngay;}
int Date::getThang(){return thang;}
int Date::getNam(){return nam;}

void Date::Nhap(){
    int check=1;
	do{
		do{
			cout<<"Nhap ngay sinh: ";cin>>ngay;
			if (ngay<1 or ngay>31) cout<<"Nhap lai ngay!"<<endl;
		} while (ngay<1 or ngay>31);
		do{
			cout<<"Nhap thang: ";cin>>thang;
			if (thang<1 or thang>12) cout<<"Nhap lai thang!"<<endl;	
		} while (thang<1 or thang>12);
		do{
			cout<<"Nhap nam: ";cin>>nam;
			if (nam<1900 or nam>2025) cout<<"Nhap lai nam!"<<endl;
		} while (nam<1900 or nam>2025);
		if (nam%4==0 and thang==2 and ngay>29) check=0;
		else if (nam%4!=0 and thang == 2 and ngay>28) check=0;
		else if ((thang ==4 or thang ==6 or thang==9 or thang ==11) and ngay>30) check=0;
		else check=1;
		if (check==0) cout<<"Ngay da nhap khong hop le"<<"\nVui long nhap lai!"<<endl;
	}while (check==0);
}
void Date::Xuat(){
    if (ngay<10) cout<<"0"<<ngay;
    else cout<<ngay;
    cout<<" / ";
    if (thang<10) cout<<"0"<<thang;
    else cout<<thang;
    cout<<" / ";
    cout<<nam;
}



//SV
class SinhVien{
    private:
        string HoTen, MSSV, DiaChi, Lop, Khoa, GioiTinh, SDT;
        Date NgaySinh;
    public:
        SinhVien();
        SinhVien(string hoTen, string mssv, string diaChi, string lop, string khoa, string gioiTinh, string sdt, Date ngaySinh);

        void setHoTen(string hoTen);
        void setMSSV(string mssv);
        void setDiaChi(string diaChi);
        void setLop(string lop);
        void setKhoa(string khoa);
        void setGioiTinh(string gioiTinh);
        void setSDT(string sdt);
        void setNgaySinh(Date ngaySinh);

        string getHoTen();
        string getMSSV();
        string getDiaChi();
        string getLop();
        string getKhoa();
        string getGioiTinh();
        string getSDT();
        Date getNgaySinh();
		string getTen(); 
		
        void Nhap();
        void Xuat();
        void XuatBang();
        
        bool KiemTraKhoa();
		bool TimSinhVienTheoTen(string ten);
		friend bool CoDauCach(string chuoi);
        
};
SinhVien::SinhVien() {
    HoTen = "";
    MSSV = "";
    DiaChi = "";
    Lop = "";
    Khoa = "";
    GioiTinh = "";
    SDT = "";
    NgaySinh = Date();
}

SinhVien::SinhVien(string hoTen, string mssv, string diaChi, string lop, string khoa, string gioiTinh, string sdt, Date ngaySinh)
    : HoTen(hoTen), MSSV(mssv), DiaChi(diaChi), Lop(lop), Khoa(khoa), GioiTinh(gioiTinh), SDT(sdt), NgaySinh(ngaySinh) {}

void SinhVien::setHoTen(string hoTen) {HoTen = hoTen;}
void SinhVien::setMSSV(string mssv) {MSSV = mssv;}
void SinhVien::setDiaChi(string diaChi) {DiaChi = diaChi;}
void SinhVien::setLop(string lop) {Lop = lop;}
void SinhVien::setKhoa(string khoa) {Khoa = khoa;}
void SinhVien::setGioiTinh(string gioiTinh) {GioiTinh = gioiTinh;}
void SinhVien::setSDT(string sdt) {SDT = sdt;}
void SinhVien::setNgaySinh(Date ngaySinh) {NgaySinh = ngaySinh;}

string SinhVien::getHoTen() {return HoTen;}
string SinhVien::getMSSV() {return MSSV;}
string SinhVien::getDiaChi() {return DiaChi;}
string SinhVien::getLop() {return Lop;}
string SinhVien::getKhoa() {return Khoa;}
string SinhVien::getGioiTinh() {return GioiTinh;}
string SinhVien::getSDT() {return SDT;}
Date SinhVien::getNgaySinh() {return NgaySinh;}
string SinhVien::getTen(){
	stringstream ss(HoTen);
	string ten;
	vector<string> tenList;
	while (ss>>ten){
		tenList.push_back(ten);
	}
	return tenList.back();
}

void SinhVien::Nhap() {
    cout << "Nhap ho ten: ";
    getline(cin, HoTen);
    do{
    	cout << "Nhap MSSV: ";
    	getline(cin, MSSV);	
    	if (MSSV.size()!=10 or CoDauCach(MSSV)) cout<<"MSSV khong hop le!"<<endl<<"Vui long nhap lai!"<<endl<<endl;
	} while (MSSV.size()!=10 or CoDauCach(MSSV));
    
    cout << "Nhap dia chi: ";
    getline(cin, DiaChi);
    cout << "Nhap lop: ";
    getline(cin, Lop);
    
    cout << "Nhap khoa [Kxx]: ";
    getline(cin, Khoa);
    

	do{
		cout << "Nhap gioi tinh: ";
    	getline(cin, GioiTinh);	
    	if (GioiTinh!="Nam" and GioiTinh!="Nu") cout<<"Gioi tinh khong hop le!"<<endl<<"Vui long nhap lai! [Nam/Nu]"<<endl<<endl;
	}while(GioiTinh!="Nam" and GioiTinh!="Nu");
    
    do{
    	cout << "Nhap so dien thoai: ";
    	getline(cin, SDT);
	}while (SDT.size()!=10);
    NgaySinh.Nhap();
    cin.ignore();  // Để bỏ qua ký tự xuống dòng sau khi nhập số
}

void SinhVien::Xuat() {
    cout << "Ho ten: " << HoTen << endl;
    cout << "MSSV: " << MSSV << endl;
    cout << "Dia chi: " << DiaChi << endl;
    cout << "Lop: " << Lop << endl;
    cout << "Khoa: " << Khoa << endl;
    cout << "Gioi tinh: " << GioiTinh << endl;
    cout << "So dien thoai: " << SDT << endl;
    cout << "Ngay sinh: ";
    NgaySinh.Xuat();
}

void SinhVien::XuatBang(){
	cout <<setw(18)<< HoTen <<" |"<<setw(13)<< MSSV << " |"<<setw(13)<< Lop << " |"<<setw(8)<< Khoa << " |" <<setw(8)<<GioiTinh << " |"<<setw(13)<< SDT << " |   ";
    NgaySinh.Xuat();
    cout <<" |"<< endl;
}
bool SinhVien::KiemTraKhoa(){
	if (!(Khoa=="K65" or Khoa=="K64" or Khoa=="K63" or Khoa=="K62")){
    	cout<<"Khoa da nhap khong hop le hoac vuot qua khoa quy dinh cua KTX";
    	return false;
	}
	return true;
}

bool SinhVien::TimSinhVienTheoTen(string ten){
	return getTen()==ten;
}
//PHONG
class Phong{
	private:
		string TenPhong;
		int ThuTuPhong;
		int SoNguoiToiDa;
		int SoNguoiHienTai;
		float SoDienCu, SoDienMoi;
		float TienDien;
		bool TrangThai;
		vector<SinhVien> DsSV;
	public:
    
    string getTenPhong();
    int getThuTuPhong();
    int getSoNguoiToiDa();
    int getSoNguoiHienTai();
    float getSoDienCu();
    float getSoDienMoi();
    float getTienDien();
    bool getTrangThai();
	vector<SinhVien> getDsSV();
	vector<SinhVien> *getDsSVPtr();
	
	void setTenPhong(string tenPhong);
	void setThuTuPhong(int thuTuPhong);
    void setSoNguoiToiDa(int soNguoi);
    void setSoNguoiHienTai(int soNguoi);
    void setSoDienCu(float soDienCu); 
    void setSoDienMoi(float SoDienMoi);
    void setTienDien(float tienDien);
    void setTrangThai(bool trangThai);

	void KhoiTaoPhong(int ThuTu);
	void NhapSinhVien(SinhVien sv);
	void XuatDsSinhVien(string tenDay);
	
    void XuatThongTinPhong();  // Xuất thông tin phòng
    
    bool KiemTraMSSV(string mssv);
    bool KiemTraPhongTrong();
    
    void TimSinhVienTheoTen(string ten, string tenDay, int thuTuPhong);
    void TinhTienDien();
};

string Phong::getTenPhong(){return TenPhong;}
int Phong::getThuTuPhong(){return ThuTuPhong;}
int Phong::getSoNguoiToiDa(){return SoNguoiToiDa;}
int Phong::getSoNguoiHienTai(){return SoNguoiHienTai;}
float Phong::getSoDienCu(){return SoDienCu;}
float Phong::getSoDienMoi(){return SoDienMoi;}
float Phong::getTienDien(){return TienDien;}
bool Phong::getTrangThai(){return TrangThai;}
vector<SinhVien> Phong::getDsSV(){return DsSV;}
vector<SinhVien> *Phong::getDsSVPtr(){return &DsSV;}
	
void Phong::setTenPhong(string tenPhong){TenPhong=tenPhong;}
void Phong::setSoNguoiToiDa(int soNguoi){SoNguoiToiDa=soNguoi;}
void Phong::setSoNguoiHienTai(int soNguoi){SoNguoiHienTai=soNguoi;}
void Phong::setSoDienCu(float soDienCu){SoDienCu=soDienCu;}
void Phong::setSoDienMoi(float soDienMoi){SoDienMoi=soDienMoi;}
void Phong::setTienDien(float tienDien){TienDien=tienDien;}
void Phong::setTrangThai(bool trangThai){TrangThai=trangThai;}

void Phong::KhoiTaoPhong(int ThuTu){
	SoNguoiToiDa=6;
	SoNguoiHienTai=0;
	SoDienCu=0;
	SoDienMoi=0;
	TrangThai=1;
	TienDien=0;
	switch (ThuTu){
		case 0:ThuTuPhong=0; TenPhong="P01"; break;
		case 1:ThuTuPhong=1; TenPhong="P02"; break;
		case 2:ThuTuPhong=2; TenPhong="P03"; break;
		case 3:ThuTuPhong=3; TenPhong="P04"; break;
		case 4:ThuTuPhong=4; TenPhong="P05"; break;
	}
}

void Phong::NhapSinhVien(SinhVien sv){
	DsSV.push_back(sv);
	SoNguoiHienTai=DsSV.size();
}
void Phong::XuatThongTinPhong() {
    cout << "Ten phong: " << TenPhong << endl;
    cout << "So nguoi toi da: " << SoNguoiToiDa << endl;
    cout << "So nguoi hien tai: " << SoNguoiHienTai << endl;
    cout << "So dien cu: " << SoDienCu << endl;
    cout << "So dien moi: " << SoDienMoi << endl;
}
void Phong::XuatDsSinhVien(string tenDay){
	if (DsSV.size() == 0) {
//        cout << "Phong " << TenPhong << " trong day " << tenDay << " hien khong co sinh vien nao.\n";
        return;
    }
    
    for (int i = 0; i < DsSV.size(); i++) {
//    	if (i==0) 
		cout <<setw(5)<< tenDay <<" |"<<setw(8)<< TenPhong<<" |";
        DsSV[i].XuatBang();
    }
}

bool Phong::KiemTraMSSV(string mssv){
	bool kt=true;
    for (int i=0; i<DsSV.size();i++){
    	if (DsSV[i].getMSSV()==mssv) kt=false;
    	if (kt==false) return kt;
	}
	return kt;
}
bool Phong::KiemTraPhongTrong(){
	return (SoNguoiHienTai<SoNguoiToiDa);
}
void Phong::TimSinhVienTheoTen(string ten, string tenDay, int thuTuPhong){
	for (int i=0; i<DsSV.size();i++){
		if (DsSV[i].TimSinhVienTheoTen(ten)){
			XuatDsSinhVien(tenDay);
		}
	}
}
void Phong::TinhTienDien(){
	TienDien=(SoDienMoi-SoDienCu)*1900;
}


//DAY
class Day{
	private:
		int ThuTuDay;
		static int ThuTuDayMoi;
		string TenDay;	
		string LoaiDay;
		vector<Phong> DsPhong;
		int SoLuongPhong;
	public:
		
		string getTenDay();
		string getLoaiDay();
		int getSoLuongPhong();
		vector<Phong> getDsPhong();
		vector<Phong> *getDsPhongPtr();
		
		void setTenDay(string tenDay);
		void setSoLuongPhong(int);
		
		void KhoiTaoDay(int ThuTu);
		void NhapSinhVien(SinhVien sv, int thuTuPhong);
		void XuatDsSinhVien();
		
		void XuatThongTinDay();
		void XuatTenPhong(int thuTuDay, int thuTuPhong);
		
		bool KiemTraMSSV(string mssv);
		bool KiemTraPhongTrong(int thuTuDay, int thuTuPhong, string gioiTinh);
		
		void TimSinhVienTheoTen(string ten, int thuTuDay);
		float TraCuuTienDien(int thuTuDay, int thuTuPhong);
		bool TraCuuTrangThaiTienDien(int thuTuDay,int thuTuPhong);
		void ThanhToanTienDien(int thuTuPhong);
};
int Day::ThuTuDayMoi=0;
string Day::getTenDay(){return TenDay;}
string Day::getLoaiDay(){return LoaiDay;}
int Day::getSoLuongPhong(){return SoLuongPhong;}
vector<Phong>Day::getDsPhong(){return DsPhong;}
vector<Phong> *Day::getDsPhongPtr(){return &DsPhong;}

void Day::setTenDay(string tenDay){ TenDay=tenDay;}
void Day::setSoLuongPhong(int soLuongPhong){
	SoLuongPhong=soLuongPhong;
}

void Day::KhoiTaoDay(int ThuTu){
	SoLuongPhong = 5;
	DsPhong.resize(SoLuongPhong);
	switch (ThuTu){
		case 0:ThuTuDay=0; TenDay="D1"; LoaiDay="Nam"; break;
		case 1:ThuTuDay=1; TenDay="D2"; LoaiDay="Nam"; break;
		case 2:ThuTuDay=2; TenDay="D3"; LoaiDay="Nam"; break;
		case 3:ThuTuDay=3; TenDay="N1"; LoaiDay="Nu"; break;
		case 4:ThuTuDay=4; TenDay="N2"; LoaiDay="Nu"; break;
	}
	for (int i=0; i<SoLuongPhong; i++){
		DsPhong[i].KhoiTaoPhong(i);
	}
}

void Day::NhapSinhVien(SinhVien sv, int thuTuPhong){
	DsPhong[thuTuPhong].NhapSinhVien(sv);
}

void Day::XuatDsSinhVien(){
	for (int i = 0; i < SoLuongPhong; i++) {
        DsPhong[i].XuatDsSinhVien(TenDay);  // Xuất thông tin sinh viên kèm theo tên dãy
    }
}

void Day::XuatTenPhong(int thuTuDay, int thuTuPhong){
	cout<<TenDay<<"-"<<DsPhong[thuTuPhong].getTenPhong();
}
bool Day::KiemTraMSSV(string mssv){
    bool kt=true;
    for (int i=0; i<DsPhong.size();i++){
    	kt=DsPhong[i].KiemTraMSSV(mssv);
    	if (kt==false) return kt;
	}
	return kt;
}
bool Day::KiemTraPhongTrong(int thuTuDay, int thuTuPhong, string gioiTinh){
	if (LoaiDay==gioiTinh)
		return DsPhong[thuTuPhong].KiemTraPhongTrong();
	return false;
}
float Day::TraCuuTienDien(int thuTuDay, int thuTuPhong){
	return DsPhong[thuTuPhong].getTienDien();
}
bool Day::TraCuuTrangThaiTienDien(int thuTuDay,int thuTuPhong){
	return DsPhong[thuTuPhong].getTrangThai();
}

void Day::ThanhToanTienDien(int thuTuPhong){
	DsPhong[thuTuPhong].setTrangThai(true);
}

//KTX
class KTX{
	private:
		vector <Day> DsDay;
		int SoLuongDay;
	public:
		
		int getSoLuongDay();
    	void setSoLuongDay(int soLuongDay);
	
		void KhoiTaoDsDay();
		void ThemSinhVien(SinhVien sv, int thuTuDay, int thuTuPhong);
		void NhapThongTinTuFile();
		void NhapSinhVien();
		void XuatDsSinhVien();
		void XuatDsSinhVienTheoBangChuCai();
		void XuatDsSinhVienTheoDayPhong();
		
    	void NhapDanhSachDay();
    	void XuatDsDay();
    	
    	void XuatDsPhongTrong(string gioiTinh);
    	
    	bool KiemTraMSSV(string mssv);
    	bool KiemTraPhongTrong(int thuTuDay, int thuTuPhong, string gioiTinh);
    	
    	int TenDayInt(string tenDay);
    	int TenPhongInt(string tenPhong);
    	
    	void TimSinhVienTheoTen(string ten);
    	void TimSinhVienTheoMSSV(string mssv);
    	void XoaSinhVien(string hoTen, string mssv, string tenDay, string tenPhong);
    	
    	void HienThiThongTinDay();
    	void HienPhongTrong();
    	void XemThongTinCacPhong();
    	void NhapSoDien();
    	void NhapSoDienFile();
    	void XemTinhTrangDongTienDien();
    	
    	void ThanhToanTienDien();
    	bool KiemTraTenPhong(string tenDay, string tenPhong);
    	float TraCuuTienDien(int thuTuDay, int thuTuPhong);
    	bool TraCuuTrangThaiTienDien(int thTuDay, int thuTuPhong);
    	
    	friend bool CoDauCach(string chuoi);
};

int KTX::getSoLuongDay(){return SoLuongDay;}
void KTX::setSoLuongDay(int soLuongDay){
	SoLuongDay=soLuongDay;
} 
void KTX::KhoiTaoDsDay(){
	SoLuongDay=5;
	DsDay.resize(SoLuongDay);
	for (int i=0; i<SoLuongDay; i++){
		DsDay[i].KhoiTaoDay(i);
	}
}
void KTX::ThemSinhVien(SinhVien sv, int thuTuDay, int thuTuPhong){
	DsDay[thuTuDay].NhapSinhVien(sv, thuTuPhong);
}

void KTX::NhapThongTinTuFile() {
    ifstream file("DanhSachSinhVien.txt");
    if (!file.is_open()) {
        cout << "Loi: Khong the mo file de doc!" << endl;
        return;
    }

    string line;
    while (getline(file, line)) { 
        stringstream ss(line);
        string hoTen, mssv, diaChi, lop, khoa, gioiTinh, sdt;
        int ngay, thang, nam;
        int thuTuDay, thuTuPhong;

        // Tách các phần tử từ dòng
        getline(ss, hoTen, ',');
        getline(ss, mssv, ',');
        getline(ss, diaChi, ',');
        getline(ss, lop, ',');
        getline(ss, khoa, ',');
        getline(ss, gioiTinh, ',');
        getline(ss, sdt, ',');
        ss >> ngay; ss.ignore();  
        ss >> thang; ss.ignore(); 
        ss >> nam; ss.ignore(); 
        ss >> thuTuDay; ss.ignore();
        ss >> thuTuPhong;

        // Khởi tạo đối tượng Date và SinhVien
        Date ngaySinh(ngay, thang, nam);
        SinhVien sv(hoTen, mssv, diaChi, lop, khoa, gioiTinh, sdt, ngaySinh);
		
        // Thêm sinh viên vào dãy và phòng
        ThemSinhVien(sv, thuTuDay, thuTuPhong);
    }
	cout<<"Da Nhap";
    file.close(); 
}

void KTX::NhapSinhVien(){
	SinhVien sv;
	cout<<"<Luu y: Viet hoa chu cai dau>"<<endl<<endl;
	sv.Nhap();
	if (!(KiemTraMSSV(sv.getMSSV()))){
		cout<<"MSSV da nhap khong hop le hoac da trung!";
		return;
	}
	if (!(sv.KiemTraKhoa())){
		return;
	}
	int dem=0;
	cout<<"Danh sach phong con trong:"<<endl;
	XuatDsPhongTrong(sv.getGioiTinh());
	
	string thuTuDayStr, thuTuPhongStr;
	int thuTuPhong, thuTuDay;
	do{
		cout<<"\nNhap ten day: ";
		cin>>thuTuDayStr;cin.ignore();
		cout<<"Nhap ten phong: ";
		cin>>thuTuPhongStr;cin.ignore();
		thuTuDay=TenDayInt(thuTuDayStr);
		thuTuPhong=TenPhongInt(thuTuPhongStr);
		if ((thuTuDay<0 or thuTuDay>4) and (thuTuPhong<0 or thuTuPhong>4)) cout <<"Day va phong da nhap khong hop le!"<<endl<<"Vui long nhap lai!"<<endl<<endl;
	}while (((thuTuDay<0 or thuTuDay>4) and (thuTuPhong<0 or thuTuPhong>4)));
	
	if (KiemTraPhongTrong(thuTuDay,  thuTuPhong, sv.getGioiTinh())){
		ThemSinhVien(sv, thuTuDay, thuTuPhong);
		cout<<"Da them sinh vien"<<endl;
	}
	else {
		cout<<"Phong da day hoac thong tin nhap vao khong hop le!"<<endl<<endl;
	}

}

void KTX::XuatDsSinhVien(){
	 // Xuất tiêu đề bảng
	cout << "-------------------------------------------------------------------------------------------------------------------------\n";
    cout <<setw(7)<<"Day |"<<setw(10)<<"Phong |"<<setw(20)<<"Ho ten |"<<setw(15)<<"MSSV |"<<setw(15)<<"Lop |"<<setw(10)<<"Khoa |"<<setw(10)<<"GTinh |"<<setw(15)<<"SDT |"<<setw(20)<<"Ngay sinh |\n";
    cout << "-------------------------------------------------------------------------------------------------------------------------\n";

    // Xuất thông tin từng dãy
    for (int i = 0; i < SoLuongDay; i++) {
//    	if (i!=0)
//    		cout << "-------------------------------------------------------------------------------------------------------------------------\n";
        DsDay[i].XuatDsSinhVien();
        cout << "-------------------------------------------------------------------------------------------------------------------------\n";
    }
    
}
void KTX::XuatDsSinhVienTheoBangChuCai(){
	cout << "-------------------------------------------------------------------------------------------------------------------------\n";
    cout <<setw(7)<<"Day |"<<setw(10)<<"Phong |"<<setw(20)<<"Ho ten |"<<setw(15)<<"MSSV |"<<setw(15)<<"Lop |"<<setw(10)<<"Khoa |"<<setw(10)<<"GTinh |"<<setw(15)<<"SDT |"<<setw(20)<<"Ngay sinh |\n";
    cout << "-------------------------------------------------------------------------------------------------------------------------\n";
    string ten;
    for (char c='A'; c<='Z'; c++){
    	for (int i=0; i<DsDay.size(); i++){
    		vector<Phong> danhSachPhong=DsDay[i].getDsPhong();
    		for (int j=0;j<danhSachPhong.size();j++){
    			vector<SinhVien> danhSachSV=danhSachPhong[j].getDsSV();
    			for (int k=0; k<danhSachSV.size();k++){
    				ten=danhSachSV[k].getTen();
    				if (ten[0]==c){
    					cout <<setw(5)<< DsDay[i].getTenDay() <<" |"<<setw(8)<< danhSachPhong[j].getTenPhong()<<" |";
    					danhSachSV[k].XuatBang();
					}
				}
			}
		}
	}
    cout << "-------------------------------------------------------------------------------------------------------------------------\n";
}
void KTX::XuatDsSinhVienTheoDayPhong(){
	string tenDay, tenPhong;
	do{
		cout<<"->Nhap ten day: ";
		getline(cin, tenDay);
		if (tenDay!="D1" and tenDay!="D2" and tenDay!="D3" and tenDay!="N1" and tenDay!="N2"){
			cout<<"Ten day da nhap khong dung!"<<endl<<"Vui long nhap lai!"<<endl;
			cout<<"[D1, D2, D3, N1, N2]"<<endl;
		}
	}while (tenDay!="D1" and tenDay!="D2" and tenDay!="D3" and tenDay!="N1" and tenDay!="N2");
	
	do{
		cout<<"->Nhap ten phong: ";
		getline(cin, tenPhong);
		if (tenPhong!="P01" and tenPhong!="P02" and tenPhong!="P03" and tenPhong!="P04" and tenPhong!="P05") {
			cout<<"Ten phong da nhap khong dung!"<<endl<<"Vui long nhap lai!"<<endl;
			cout<<"[P01, P02, P03, P04, P05]"<<endl;
		}
	}while (tenPhong!="P01" and tenPhong!="P02" and tenPhong!="P03" and tenPhong!="P04" and tenPhong!="P05") ;
	
	for (int i=0; i<DsDay.size(); i++){
		if (DsDay[i].getTenDay()==tenDay){
			vector<Phong> danhSachPhong=  DsDay[i].getDsPhong();
			for (int j=0; j<danhSachPhong.size();j++){
				if (danhSachPhong[j].getTenPhong()==tenPhong){
					cout << "-------------------------------------------------------------------------------------------------------------------------\n";
    				cout <<setw(7)<<"Day |"<<setw(10)<<"Phong |"<<setw(20)<<"Ho ten |"<<setw(15)<<"MSSV |"<<setw(15)<<"Lop |"<<setw(10)<<"Khoa |"<<setw(10)<<"GTinh |"<<setw(15)<<"SDT |"<<setw(20)<<"Ngay sinh |\n";
    				cout << "-------------------------------------------------------------------------------------------------------------------------\n";
    		
					vector<SinhVien> danhSachSV=danhSachPhong[j].getDsSV();
					for (int k=0; k<danhSachSV.size(); k++){
						cout <<setw(5)<< DsDay[i].getTenDay() <<" |"<<setw(8)<< danhSachPhong[j].getTenPhong()<<" |";
    					danhSachSV[k].XuatBang();
					}
				}
			}
			cout << "-------------------------------------------------------------------------------------------------------------------------\n";
    		return;
		}
	}
}
void KTX::XuatDsPhongTrong(string gioiTinh){
	int dem=0;
	for (int i=0; i<DsDay.size(); i++){
		for (int j=0; j<DsDay[i].getSoLuongPhong(); j++){
			if (KiemTraPhongTrong(i,j, gioiTinh)){
				cout<<"|"; DsDay[i].XuatTenPhong(i,j); cout<<"|   ";
				dem++;
			} 
		}
	}
	if (dem==0) cout<<"KTX khong con phong trong";
}

bool KTX::KiemTraMSSV(string mssv){
	bool kt=true;
    for (int i=0; i<DsDay.size();i++){
    	kt=DsDay[i].KiemTraMSSV(mssv);
    	if (kt==false) return kt;
	}
	return kt;
}
bool KTX::KiemTraPhongTrong(int thuTuDay, int thuTuPhong, string gioiTinh){
    return DsDay[thuTuDay].KiemTraPhongTrong(thuTuDay, thuTuPhong, gioiTinh);
}

int KTX::TenDayInt(string tenDay){
	
	if (tenDay=="D1") return 0;
	else if (tenDay=="D2") return 1;
	else if (tenDay=="D3") return 2;
	else if (tenDay=="N1") return 3;
	else  return 4;
}

int KTX::TenPhongInt(string tenPhong){
	if (tenPhong=="P01") return 0;
	else if (tenPhong=="P02") return 1;
	else if (tenPhong=="P03") return 2;
	else if (tenPhong=="P04") return 3;
	else  return 4;
}
void KTX::TimSinhVienTheoTen(string ten){
	bool found=false;
	for (int i=0; i<DsDay.size();i++){
		vector<Phong> danhSachPhong= DsDay[i].getDsPhong();
		for (int j=0; j<danhSachPhong.size(); j++){
			vector<SinhVien> danhSachSV= danhSachPhong[j].getDsSV();
			for (int k=0; k<danhSachSV.size(); k++){
				if (danhSachSV[k].getTen()==ten){
					if (found==false){
						cout << "-------------------------------------------------------------------------------------------------------------------------\n";
						cout <<setw(7)<<"Day |"<<setw(10)<<"Phong |"<<setw(20)<<"Ho ten |"<<setw(15)<<"MSSV |"<<setw(15)<<"Lop |"<<setw(10)<<"Khoa |"<<setw(10)<<"GTinh |"<<setw(15)<<"SDT |"<<setw(20)<<"Ngay sinh |\n";
    					cout << "-------------------------------------------------------------------------------------------------------------------------\n";
					}		
					cout <<setw(5)<< DsDay[i].getTenDay() <<" |"<<setw(8)<< danhSachPhong[j].getTenPhong()<<" |";
					danhSachSV[k].XuatBang();
					found=true;
				}
			}
		}
	}
	if (found) cout << "-------------------------------------------------------------------------------------------------------------------------\n";
			else cout<<"Khong tim thay sinh vien"<<endl;
}
void KTX::TimSinhVienTheoMSSV(string mssv){
	bool found=false;
	for (int i=0; i<DsDay.size();i++){
		vector<Phong> danhSachPhong= DsDay[i].getDsPhong();
		for (int j=0; j<danhSachPhong.size(); j++){
			vector<SinhVien> danhSachSV= danhSachPhong[j].getDsSV();
			for (int k=0; k<danhSachSV.size(); k++){
				if (danhSachSV[k].getMSSV()==mssv){
					if (found==false){
						cout << "-------------------------------------------------------------------------------------------------------------------------\n";
						cout <<setw(7)<<"Day |"<<setw(10)<<"Phong |"<<setw(20)<<"Ho ten |"<<setw(15)<<"MSSV |"<<setw(10)<<"Lop |"<<setw(10)<<"Khoa |"<<setw(15)<<"Gioi tinh |"<<setw(15)<<"SDT |"<<setw(20)<<"Ngay sinh |\n";
    					cout << "-------------------------------------------------------------------------------------------------------------------------\n";
					}		
					cout <<setw(5)<< DsDay[i].getTenDay() <<" |"<<setw(8)<< danhSachPhong[j].getTenPhong()<<" |";
					danhSachSV[k].XuatBang();
					found=true;
				}
			}
		}
	}
	if (found) cout << "-------------------------------------------------------------------------------------------------------------------------\n";
			else cout<<"Khong tim thay sinh vien"<<endl;
}
void KTX::XoaSinhVien(string hoTen, string mssv, string tenDay, string tenPhong){
	bool kt=false;
	for (int i=0; i<DsDay.size();i++){
		if (DsDay[i].getTenDay()==tenDay){
			vector<Phong> *danhSachPhongPtr = DsDay[i].getDsPhongPtr();
			for (int j=0; j<danhSachPhongPtr->size();j++){
				if (danhSachPhongPtr->at(j).getTenPhong()==tenPhong){
					vector<SinhVien> *danhSachSVPtr = danhSachPhongPtr->at(j).getDsSVPtr();
					for (int k=0; k<danhSachSVPtr->size(); k++){
						if (danhSachSVPtr->at(k).getHoTen()==hoTen and danhSachSVPtr->at(k).getMSSV()==mssv){
							danhSachSVPtr->erase(danhSachSVPtr->begin()+k);
							kt=true;
							danhSachPhongPtr->at(j).setSoNguoiHienTai(danhSachPhongPtr->at(j).getSoNguoiHienTai()-1);
						}
					}
				}
			}
		}
	}
	if (!kt) cout<<"Khong tim thay sinh vien!"<<endl<<endl;
	else cout<<"Xoa sinh vien thanh cong!"<<endl<<endl;
}
void KTX::HienThiThongTinDay(){
	for (int i=0; i<DsDay.size(); i++){
		cout<<"----------------------\t";
	}
	cout<<endl;
	for (int i=0; i<DsDay.size(); i++){
		cout<<"|       Day "<<DsDay[i].getTenDay()<<"       |\t";
	}
	cout<<endl;
	for (int i=0; i<DsDay.size(); i++){
//		vector<Phong> danhSachPhong = DsDay[i].getDsPhong();
		cout<<"| So luong phong: "<<DsDay[i].getSoLuongPhong()<<"  |\t";
	}
	cout<<endl;
	for (int i=0; i<DsDay.size(); i++){
		vector<Phong> danhSachPhong = DsDay[i].getDsPhong();
		cout<<"|    Loai day: "<<setw(3)<<DsDay[i].getLoaiDay()<<"   |\t";
	}
	cout<<endl;
	for (int i=0; i<DsDay.size(); i++){
		vector<Phong> danhSachPhong = DsDay[i].getDsPhong();
		int dem=0;
		for (int i=0; i<danhSachPhong.size();i++){
			if (danhSachPhong[i].KiemTraPhongTrong()) dem++;
		}
		cout<<"| TTrang: ";
		if (dem!=0) cout<<"Con phong  |\t";
		else cout<<"Het phong  |\t";
	}
	cout<<endl;
	
	for (int i=0; i<DsDay.size(); i++){
		cout<<"----------------------\t";
	}
}
void KTX::HienPhongTrong(){
	bool kt=false,ktDay=false, ktPhong=false;
	for (int i=0; i<DsDay.size();i++){
		ktDay=false;
		vector<Phong> danhSachPhong = DsDay[i].getDsPhong();
		ktPhong=false;
		for (int j=0; j<danhSachPhong.size(); j++){
			if (danhSachPhong[j].KiemTraPhongTrong()){
				if (kt==false) cout<<"\n--- Danh sach cac phong con trong ---"<<endl;
				if (ktDay==false) cout<<endl<<DsDay[i].getTenDay()<<": ";
				cout<<danhSachPhong[j].getTenPhong()<<"  ";
				kt=ktDay=true;
			}
		}
	}
	if (!kt) cout<<"Khong con phong trong"<<endl<<endl;
	else cout<<endl<<endl;
}
void KTX::XemThongTinCacPhong(){
	cout<<"-----------------------------------------------------------------------------"<<endl;
	cout<<setw(5)<<"Day |"<<setw(7)<<"Ten |"<<setw(12)<<"So nguoi |"<<setw(14)<<"So dien cu |"<<setw(14)<<"So dien moi |"<<setw(12)<<"Tien dien |"<<setw(10)<<" Trang thai |"<<endl;
	cout<<"-----------------------------------------------------------------------------"<<endl;
	for (int j=0; j<DsDay.size(); j++){
		vector<Phong> danhSachPhong= DsDay[j].getDsPhong();	
		
		for (int i=0; i< danhSachPhong.size(); i++){
			cout<<setw(3)<<DsDay[j].getTenDay()<<" |"<<setw(5)<<danhSachPhong[i].getTenPhong()<<" |"<<setw(8)<<danhSachPhong[i].getSoNguoiHienTai()<<"/"<<danhSachPhong[i].getSoNguoiToiDa()<<" |"<<setw(12)<<danhSachPhong[i].getSoDienCu()<<" |"<<setw(12)<<danhSachPhong[i].getSoDienMoi()<<" |"<<setw(10)<<danhSachPhong[i].getTienDien()<<" |";
			if (danhSachPhong[i].getTrangThai()==0) cout<<setw(13)<<"Chua dong |"<<endl;
			else cout<<setw(13)<<"Da dong |"<<endl;
		}
		cout<<"-----------------------------------------------------------------------------"<<endl;
	}
}
void KTX::NhapSoDien(){
	float soDienMoi;
	cout<<"--- Nhap so dien ---"<<endl;
	for (int i=0; i<DsDay.size(); i++){
		vector<Phong> *danhSachPhongPtr = DsDay[i].getDsPhongPtr();
		for (int j=0; j<danhSachPhongPtr->size();j++){
			cout<<endl<<DsDay[i].getTenDay()<<"-"<<danhSachPhongPtr->at(j).getTenPhong();
			danhSachPhongPtr->at(j).setSoDienCu(danhSachPhongPtr->at(j).getSoDienMoi());
			cout<<"\tSo dien cu: "<<danhSachPhongPtr->at(j).getSoDienCu()<<endl;
			do{
				cout<<"->Nhap so dien moi: ";
				cin>>soDienMoi;cin.ignore();
				if (soDienMoi <danhSachPhongPtr->at(j).getSoDienCu()) cout<<"So dien da nhap khong duoc nho hon so dien cu!"<<"Vui long nhap lai!"<<endl<<endl;
			}while (soDienMoi <danhSachPhongPtr->at(j).getSoDienCu());

			danhSachPhongPtr->at(j).setSoDienMoi(soDienMoi);
			danhSachPhongPtr->at(j).setTrangThai(false);
			danhSachPhongPtr->at(j).TinhTienDien();
		}
	}
}

void KTX::NhapSoDienFile(){
	ifstream file("SoDien.txt");
	float soDien;
	if (!file.is_open()) {
		cout<<"Khong the mo file SoDien.txt";	
		return;
	}
	for (int i=0; i<DsDay.size();i++){
		vector<Phong> *danhSachPhongPtr=DsDay[i].getDsPhongPtr();
		for (int j=0; j<danhSachPhongPtr->size(); j++){
			danhSachPhongPtr->at(j).setSoDienCu(danhSachPhongPtr->at(j).getSoDienMoi());
			file>>soDien;
			danhSachPhongPtr->at(j).setSoDienMoi(soDien);
			danhSachPhongPtr->at(j).setTrangThai(false);
			danhSachPhongPtr->at(j).TinhTienDien();
		}
	}
	cout<<"Da nhap so dien tu file thanh cong!"<<endl;
	file.close();
}
void KTX::XemTinhTrangDongTienDien(){
	bool kt=false;
	for (int i=0; i<DsDay.size();i++){
		vector <Phong> danhSachPhong= DsDay[i].getDsPhong();
		for (int j=0; j<danhSachPhong.size(); j++){
			if (danhSachPhong[j].getTrangThai()==false){
				if (kt==false){
					cout<<"-----------------------------------------------------------------------------"<<endl;
					cout<<setw(5)<<"Day |"<<setw(7)<<"Ten |"<<setw(12)<<"So nguoi |"<<setw(14)<<"So dien cu |"<<setw(14)<<"So dien moi |"<<setw(12)<<"Tien dien |"<<setw(10)<<" Trang thai |"<<endl;
					cout<<"-----------------------------------------------------------------------------"<<endl;
				}
				cout<<setw(3)<<DsDay[i].getTenDay()<<" |"<<setw(5)<<danhSachPhong[j].getTenPhong()<<" |"<<setw(8)<<danhSachPhong[j].getSoNguoiHienTai()<<"/"<<danhSachPhong[j].getSoNguoiToiDa()<<" |"<<setw(12)<<danhSachPhong[j].getSoDienCu()<<" |"<<setw(12)<<danhSachPhong[j].getSoDienMoi()<<" |"<<setw(10)<<danhSachPhong[j].getTienDien()<<" |";
				if (danhSachPhong[j].getTrangThai()==0) cout<<setw(13)<<"Chua dong |"<<endl;
				else cout<<setw(13)<<"Da dong |"<<endl;
				kt=true;
			}
		}
	}
	if (kt) cout<<"-----------------------------------------------------------------------------"<<endl;
	else cout<<"Tat ca cac phong da dong tien dien!"<<endl;
}

float KTX::TraCuuTienDien(int thuTuDay, int thuTuPhong){
	return DsDay[thuTuDay].TraCuuTienDien(thuTuDay, thuTuPhong);
}
bool KTX::TraCuuTrangThaiTienDien(int thuTuDay,int thuTuPhong){
	return DsDay[thuTuDay].TraCuuTrangThaiTienDien(thuTuDay, thuTuPhong);
}

void KTX::ThanhToanTienDien(){
	string mssv, tenDay, tenPhong, choice;
	float soTien;
	cout<<"\n---Nhap thong tin---"<<endl;
	do{
		cout<<"->Nhap MSSV: ";
		getline(cin, mssv);
		if (mssv.size()!=10 or CoDauCach(mssv)) cout<<"MSSV khong hop le!"<<endl<<"Vui long nhap lai!"<<endl<<endl;
	}while(mssv.size()!=10 or CoDauCach(mssv));
	do{
		cout<<"->Nhap ten day: ";
		getline(cin, tenDay);
		if (tenDay!="D1" and tenDay!="D2" and tenDay!="D3" and tenDay!="N1" and tenDay!="N2"){
			cout<<"Ten day da nhap khong dung!"<<endl<<"Vui long nhap lai!"<<endl;
			cout<<"[D1, D2, D3, N1, N2]"<<endl;
		}
	}while (tenDay!="D1" and tenDay!="D2" and tenDay!="D3" and tenDay!="N1" and tenDay!="N2");
	
	do{
		cout<<"->Nhap ten phong: ";
		getline(cin, tenPhong);
		if (tenPhong!="P01" and tenPhong!="P02" and tenPhong!="P03" and tenPhong!="P04" and tenPhong!="P05") {
			cout<<"Ten phong da nhap khong dung!"<<endl<<"Vui long nhap lai!"<<endl;
			cout<<"[P01, P02, P03, P04, P05]"<<endl;
		}
	}while (tenPhong!="P01" and tenPhong!="P02" and tenPhong!="P03" and tenPhong!="P04" and tenPhong!="P05") ;
	cout<<endl<<tenDay<<"-"<<tenPhong<<"\t Tien dien: "<< TraCuuTienDien(TenDayInt(tenDay), TenPhongInt(tenPhong))<<"\tTrang thai: ";
	if (TraCuuTrangThaiTienDien(TenDayInt(tenDay), TenPhongInt(tenPhong))==0){
		cout<<"Chua dong"<<endl;
	}
	else {
		cout<<"Da dong"<<endl;
		cout<<"Phong cua ban da dong tien roi"<<endl;
		return;
	}
	
	do {
		cout<<"->Nhap so tien: ";
		cin>>soTien;cin.ignore();
		if (soTien!=TraCuuTienDien(TenDayInt(tenDay), TenPhongInt(tenPhong))) 
			cout<<"So tien da nhap khong dung!"<<endl<<"Vui long nhap lai!"<<endl<<endl;
	}while (soTien!=TraCuuTienDien(TenDayInt(tenDay), TenPhongInt(tenPhong)));
	
	do{
		cout<<"Nhan [y] de xac nhan giao dich hoac [n] de huy: ";
		getline(cin, choice);
		if (choice!="y" and choice!="n") cout<<"Cu phap khong dung!"<<endl<<"Vui long nhap lai!"<<endl<<endl;
	}while (choice!="y" and choice!="n");
	
	if (choice=="n") {
		cout<<"Da huy giao dich"<<endl;
		return;
	};
	
	DsDay[TenDayInt(tenDay)].ThanhToanTienDien(TenPhongInt(tenPhong));
	cout<<"Thanh toan thanh cong!"<<endl<<endl;
}
//MAIN
void XoaManHinh();
void Begin(KTX &ktx);
void menu(KTX &ktx);
void menuSV(KTX &ktx);
void menuSV1(KTX &ktx);
void menuSV2(KTX &ktx);
void menuSV3(KTX &ktx);
void menuDayPhong(KTX &ktx);
void menuDayPhong4(KTX &ktx);

bool CoDauCach(string chuoi) {
    for (char kyTu : chuoi) {
        if (kyTu == ' ') {
            return true; 
        }
    }
    return false;
}

void Begin(KTX &ktx){
	ktx.KhoiTaoDsDay();
	string c;
	do{
		cout<<"\n\n----------------------------------------------------------"<<endl;
		cout<<"| Ban co muon nhap du lieu sinh vien tu file khong [y/n] |"<<endl;;
		cout<<"----------------------------------------------------------"<<endl;
		cout<<"-> Nhap lua chon: ";
		getline(cin,c);
		if (!(c=="y" or c=="n")) cout<<"Lua chon khong hop le!"<<endl<<"Vui long nhap lai!"<<endl<<endl;
	} while (!(c=="y" or c=="n"));
	if (c=="y") ktx.NhapThongTinTuFile();
	XoaManHinh();
}

void menu(KTX &ktx) {
    int choice;
    do {
        cout << "\n--- CHON DOI TUONG THUC HIEN ---" << endl;
        cout << "\t1. Sinh vien" << endl;
        cout << "\t2. Day/phong" << endl;
        cout << "\t0. Thoat" << endl;
        cout << "->Nhap lua chon: ";
        cin >> choice;
        cin.ignore();  

        switch (choice) {
        	case 0:
                cout << "Thoat chuong trinh.\n";
                break;
            case 1:
            	XoaManHinh();
                menuSV(ktx);  
                break;
            case 2:
            	XoaManHinh();
            	menuDayPhong(ktx);
                break;
            default:
				cout<<"Lua chon khong hop le!"<<endl<<endl;
        }
    } while (choice != 0);
}

void menuSV(KTX &ktx) {
    int choice;
    do {
        cout << "\n--- Menu Sinh Vien ---\n";
        cout << "\t1. Nhap sinh vien" << endl;
        cout << "\t2. Xuat danh sach sinh vien" << endl;
        cout << "\t3. Tim sinh vien" << endl;
        cout << "\t4. Xoa sinh vien" << endl;
        cout << "\t0. Quay lai" << endl;
        cout << "->Nhap lua chon: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
        	case 0:
        		XoaManHinh();
//                cout << "Quay lai menu chinh." << endl;
                break;
            case 1:
            	XoaManHinh();
            	cout<<"--- Nhap sinh vien ---"<<endl;
                ktx.NhapSinhVien();  
                break;
            case 2:
            	XoaManHinh();
                menuSV2(ktx); 
                break;
            case 3:
            	XoaManHinh();
            	menuSV3(ktx);
            	break;
            case 4:
            {
            	XoaManHinh();
            	string hoTen, mssv, tenPhong, tenDay;
				cout<<"Nhap thong tin sinh vien can xoa"<<endl;
            	do{
            		cout<<"Nhap Ho Ten: "; getline(cin, hoTen);
            		if (!(CoDauCach(hoTen))) cout<<"Ho ten da nhap khong hop le!"<<endl<<"Vui long nhap lai!"<<endl<<endl;
				}while (!(CoDauCach(hoTen)));
				do{
            		cout<<"Nhap MSSV: "; getline(cin, mssv);
            		if (CoDauCach(mssv) or mssv.size()!=10) cout<<"MSSV da nhap khong hop le!"<<endl<<"Vui long nhap lai!"<<endl<<endl;
				}while (CoDauCach(mssv) or mssv.size()!=10);
				do{
            		cout<<"Nhap ten day: "; getline(cin, tenDay);
            		if (CoDauCach(tenDay) or ktx.TenDayInt(tenDay)<0 or ktx.TenPhongInt(tenPhong)>4) cout<<"Ten day da nhap khong hop le!"<<endl<<"Vui long nhap lai!"<<endl<<endl;
				}while (CoDauCach(tenDay) or ktx.TenDayInt(tenDay)<0 or ktx.TenPhongInt(tenDay)>4);
				do{
            		cout<<"Nhap ten phong: "; getline(cin, tenPhong);
            		if (CoDauCach(tenPhong) or ktx.TenPhongInt(tenPhong)<0 or ktx.TenPhongInt(tenPhong)>4) cout<<"Ten phong da nhap khong hop le!"<<endl<<"Vui long nhap lai!"<<endl<<endl;
				}while (CoDauCach(tenPhong) or ktx.TenPhongInt(tenPhong)<0 or ktx.TenPhongInt(tenPhong)>4);
                ktx.XoaSinhVien(hoTen, mssv, tenDay, tenPhong);
                break;
			}
            default:
				cout<<"Lua chon khong hop le!"<<endl<<endl;
        }
    } while (choice != 0); 
}
void menuSV2(KTX &ktx){
	int choice;
	do{
		cout<<"--- Xuat sinh vien ---"<<endl;
		cout<<"\t1. Xuat sinh vien theo bang chu cai"<<endl;
		cout<<"\t2. Xuat sinh vien theo bang day phong"<<endl;
		cout<<"\t3. Mac dinh"<<endl;
		cout<<"\t0. Quay lai"<<endl;
		cout<<"->Nhap lua chon: ";
		cin>>choice;cin.ignore();
		
		switch (choice){
			case 0: XoaManHinh(); break;
			case 1:
				XoaManHinh();
				ktx.XuatDsSinhVienTheoBangChuCai();
				break;
			case 2:
				XoaManHinh();
				ktx.XuatDsSinhVienTheoDayPhong();
				break;
			case 3:
				XoaManHinh();
				ktx.XuatDsSinhVien();
				break;
			default:
				cout<<"Lua chon khong hop le!"<<endl<<endl;
		}
	}while(choice!=0);
}

void menuSV3(KTX &ktx){
	int choice;
	do{
		cout<<"--- Tim sinh vien ---"<<endl;
		cout<<"\t1. Tim sinh vien theo Ten"<<endl;
		cout<<"\t2. Tim sinh vien theo MSSV"<<endl;
		cout<<"\t0. Quay lai"<<endl;
		cout<<"->Nhap lua chon: ";
		cin>>choice;cin.ignore();
		
		switch (choice){
			case 0: XoaManHinh(); break;
			case 1:
			{
            	string ten;
            	do{
            		cout<<"\n\t->Nhap ten sinh vien can tim: ";
					getline(cin, ten);
            		if (CoDauCach(ten))
					cout<<"Ten khong duoc chua khoang cach!"<<endl<<"Vui long nhap lai!"<<endl<<endl;
				}while (CoDauCach(ten));
                ktx.TimSinhVienTheoTen(ten); 
                choice =0;
                break;
            }
			case 2:
			{
				string mssv;
				do{
					cout<<"\n\t->Nhap MSSV can tim: ";
					getline(cin, mssv);
					if (mssv.size()!=10 or CoDauCach(mssv)) cout<<"MSSV vua nhap khong hop le!"<<endl<<"Vui long nhap lai!"<<endl<<endl;
				}while (mssv.size()!=10 or CoDauCach(mssv));
				ktx.TimSinhVienTheoMSSV(mssv);
				choice =0;
				break;
			}
			default:
				cout<<"Lua chon khong hop le!"<<endl<<endl;
		}
	}while(choice!=0);
}
void menuDayPhong(KTX &ktx){
	int choice;
	do{
		cout<<"\n\n--- MENU DAY/PHONG ---"<<endl;
		cout<<"\t1. Hien thong tin day"<<endl;
		cout<<"\t2. Hien danh sach phong con trong"<<endl;
		cout<<"\t3. Xem thong tin phong"<<endl;
		cout<<"\t4. Nhap so dien"<<endl;
		cout<<"\t5. Xem tinh trang dong tien dien"<<endl;
		cout<<"\t6. Thanh toan tien dien"<<endl;
		cout<<"\t0. Quay lai"<<endl;
		cout<<"->Nhap lua chon: "; cin>>choice; cin.ignore();
		
		switch (choice){
			case 0:
				XoaManHinh();
				break;
			case 1:
				XoaManHinh();
				ktx.HienThiThongTinDay();
				break;				
			case 2:
				XoaManHinh();
				ktx.HienPhongTrong();
				break;
			case 3:
				XoaManHinh();
				ktx.XemThongTinCacPhong();
				break;
			case 4:
				XoaManHinh();
				menuDayPhong4(ktx);
				break;
			case 5:
				XoaManHinh();
				ktx.XemTinhTrangDongTienDien();
				break;
			case 6:
				XoaManHinh();
				ktx.ThanhToanTienDien();
				break;
			default:
				cout<<"Lua chon khong hop le!"<<endl<<endl;
		}
	}while (choice!=0);
}
void menuDayPhong4(KTX &ktx){
	int choice;
	do{
		cout<<"\n--- Nhap tien dien---"<<endl;
		cout<<"\t1. Nhap thu cong"<<endl;
		cout<<"\t2. Nhap tu file"<<endl;
		cout<<"\t0. Quay lai"<<endl;
		cout<<"-> Nhap lua chon: ";
		
		cin>>choice; cin.ignore();
		switch (choice){
			case 0:
				XoaManHinh();
				break;
			case 1:
				ktx.NhapSoDien();
				choice=0;
				break;
			case 2:
				ktx.NhapSoDienFile();
				choice=0;
				break;
			default:
				cout<<"Lua chon khong hop le! Vui long nhap lai!"<<endl<<endl;
		}
	}while (choice!=0);
}
void XoaManHinh(){system("cls");}
int main(){
	KTX ktx;
	Begin(ktx);
	XoaManHinh();
	menu(ktx);
}