
#include <iostream>
#include <string>
#include <cmath>
#include "AllClass.h"
using namespace std;
using std::pow;
using std::tan;
using std::acos;


Nokta:: Nokta(const Nokta& Nesne) {
        x = Nesne.getX();

        y = Nesne.getY();
    }

    Nokta::Nokta(const Nokta& Nesne, double ofset_x, double ofset_y) {
        x = Nesne.getX() + ofset_x;

        y = Nesne.getY() + ofset_y;
    }

    Nokta::Nokta() {
        setX(0);

        setY(0);
    }

    Nokta::Nokta(double xykordinat) {
        setX(xykordinat);

        setY(xykordinat);
    }

    Nokta::Nokta(double xkordinat, double ykordinat) {
        setX(xkordinat);

        setY(ykordinat);
    }

    void Nokta::setX(double xkordinat) {
        x = xkordinat;
    }

    void Nokta::setY(double ykordinat) {
        y = ykordinat;
    }

    void Nokta::set(double xkordinat, double ykordinat) {
        setX(xkordinat);

        setY(ykordinat);
    }

    double Nokta::getX() const {
        return x;
    }

    double Nokta::getY() const {
        return y;
    }
    
    std::string Nokta::toString() const {
        return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    }

    void Nokta::yazdir() const {
        std::cout << "Koordinatlar: " << toString() << std::endl;
    }




    DogruParcasi::DogruParcasi(Nokta dogrukordinatıortası, double dogruzunlugu, double egim) {

        setortaNokta(dogrukordinatıortası);

        setUzunluk(dogruzunlugu);

        double yariuzunluk = dogruzunlugu / 2.0;

        xy1.setX(ortaNokta().getX() - yariuzunluk * std::cos(std::atan(tan(egim))));

        xy1.setY(ortaNokta().getY() - yariuzunluk * std::sin(std::atan(tan(egim))));


        xy2.setX(ortaNokta().getX() + yariuzunluk * std::cos(std::atan(tan(egim))));

        xy2.setY(ortaNokta().getY() + yariuzunluk * std::sin(std::atan(tan(egim))));

    }

    DogruParcasi::DogruParcasi(const DogruParcasi& Nesne) {
        xy1 = Nesne.getP1();

        xy2 = Nesne.getP2();

        xy_orta = Nokta{ (xy1.getX() + xy2.getX()) / 2, (xy1.getY() + xy2.getY()) / 2 };

        uzaklik = uzunluk();
    }
                                                  
    DogruParcasi::DogruParcasi(Nokta xy11, Nokta xy22) {
        xy1 = xy11;

        xy2 = xy22;

        xy_orta = Nokta{ (xy1.getX() + xy2.getX()) / 2, (xy1.getY() + xy2.getY()) / 2 };

        uzaklik = uzunluk();
    }

   Nokta DogruParcasi:: getP1() const {
        return xy1;
    }

   Nokta DogruParcasi:: getP2() const {
        return xy2;
    }

    Nokta DogruParcasi::ortaNokta() const {
        return xy_orta;
    }

    void DogruParcasi::setP1(Nokta xy11) {
        xy1 = xy11;
    }

    void DogruParcasi::setP2(Nokta xy22) {
        xy2 = xy22;
    }

    void DogruParcasi::setortaNokta(Nokta x_orta1) {
        xy_orta = x_orta1;
    }

    void DogruParcasi::setUzunluk(double uzunluk) {

        uzaklik =uzunluk;

    }

    double DogruParcasi::uzunluk() const {
        double uzaklik = sqrt(pow(xy1.getX() - xy2.getX(), 2) + pow(xy1.getY() - xy2.getY(), 2));

        return uzaklik;
    }

    std::string DogruParcasi::toString() const {

        yazdir();

        return   "x1y1: " + std::to_string(getP1().getX()) + " " + std::to_string(getP1().getY()) + "\n"+ ""+ "x2y2: " + std::to_string(getP2().getX()) + " " + std::to_string(getP2().getY()) + "\n";


    }

    void DogruParcasi::yazdir() const {
        std::cout << "x1y1: " << getP1().getX() << " " << getP1().getY() << std::endl;
        std::cout << "x2y2: " << getP2().getX() << " " << getP2().getY() << std::endl;
    }

    Nokta DogruParcasi::KesisimNoktasi(const Nokta& verilenNokta) const {
        // Doğru parçasının vektörünü hesapla
        double dogruParcaX = xy2.getX() - xy1.getX();
        double dogruParcaY = xy2.getY() - xy1.getY();

        // Doğru parçasının birim vektörünü hesapla
        double dogruParcaUzunluk = sqrt(dogruParcaX * dogruParcaX + dogruParcaY * dogruParcaY);
        double birimDogruParcaX = dogruParcaX / dogruParcaUzunluk;
        double birimDogruParcaY = dogruParcaY / dogruParcaUzunluk;

        // Verilen noktanın doğru parçasına dik olan vektörünü hesapla
        double dikVektorX = verilenNokta.getX() - xy1.getX();
        double dikVektorY = verilenNokta.getY() - xy1.getY();

        // Verilen noktanın doğru parçasına dik olan uzaklığı hesapla
        double uzaklik = dikVektorX * birimDogruParcaX + dikVektorY * birimDogruParcaY;

        // Doğru parçasının üzerindeki kesişim noktasını hesapla
        double kesisimNoktasiX = xy1.getX() + uzaklik * birimDogruParcaX;
        double kesisimNoktasiY = xy1.getY() + uzaklik * birimDogruParcaY;

        // Yeni Nokta nesnesini oluştur ve döndür
        return Nokta(kesisimNoktasiX, kesisimNoktasiY);
    }





    Daire::Daire(Nokta merkezxy1, double yarıcap1) {

        merkezxy = merkezxy1;

        yarıcap = yarıcap1;
    }

    Daire::Daire(const Daire& Nesne) {

        merkezxy = Nesne.merkezxy;

        yarıcap = Nesne.yarıcap;

    }
    Daire::Daire(const Daire& Nesne,double carpılacak_x_degeri) {

        merkezxy = Nesne.merkezxy;
        yarıcap = Nesne.yarıcap*carpılacak_x_degeri;

    }

    double Daire::alan() {

        double Alan = 3.14 * pow(getYarıcap(), 2);

        return Alan;
    }

    double Daire::cevre() {

        double cevre = 2 * 3.14 * yarıcap;

        return cevre;

    }

    std::string Daire::toString() {


        return std::to_string(merkezxy.getX()) + "," + std::to_string(merkezxy.getY()) + "   " + std::to_string(yarıcap);



    }

    void Daire::setMerkezX(double x) {

        merkezxy.setX(x);

    }
    void Daire::setMerkezY(double y) {

        merkezxy.setY(y);

    }

    double Daire::getMerkezX() {

        return merkezxy.getX();
    }
    double Daire::getMerkezY() {

        return merkezxy.getY();
    }
    void Daire::yazdir() {

        std::cout << std::endl;

        std::cout << "merkez koordinatları " << "x: " << merkezxy.getX() << " y: " << merkezxy.getY() << std::endl;

        std::cout << "yarıcap: " << getYarıcap()<<std::endl;

        std::cout << "Alan: " << alan() << std::endl;

        std::cout << "cevre: " << cevre() << std::endl;




    }
    double Daire::getYarıcap() {

        return yarıcap;
    }
    void Daire::setYarıcap(double yarıcap1) {

        yarıcap = yarıcap1;
    }
    int Daire::kesisim(const Daire& KesisimNesnesi) {

        
         
       
        // İki çemberin tamamen örtüşüp örtüşmediğini kontrol et

        double distance = std::sqrt(std::pow(KesisimNesnesi.merkezxy.getX() - merkezxy.getX(), 2) + std::pow(KesisimNesnesi.merkezxy.getY() - merkezxy.getY(), 2));

        if ((distance == 0) && (getYarıcap() == KesisimNesnesi.yarıcap)) {
            return 1;
        }

        // İki çemberin kesişip kesişmediğini kontrol et
         distance = std::sqrt(std::pow(KesisimNesnesi.merkezxy.getX() - merkezxy.getX(), 2) + std::pow(KesisimNesnesi.merkezxy.getX() - merkezxy.getY(), 2));

        if (distance < (KesisimNesnesi.yarıcap + getYarıcap())) {
            return 0;

        }
       
         distance = std::sqrt(std::pow(getMerkezX() - KesisimNesnesi.merkezxy.getX(), 2) + std::pow(getMerkezY() - KesisimNesnesi.merkezxy.getY(), 2));

        if ((distance + getYarıcap()) < KesisimNesnesi.yarıcap) {

            return 2;
        }






    }






    Ucgen::Ucgen(Nokta xy11,Nokta xy22,Nokta xy33){

        xy1 = xy11;

        xy2 = xy22;

        xy3 = xy33;
    }

    Nokta Ucgen::getXY1() {

        return xy1;
    }

    Nokta Ucgen::getXY2() {

        return xy2;
    }

    Nokta Ucgen::getXY3() {

        return xy3;
    }


    void Ucgen::setXY1(Nokta xy11) {

        xy1 = xy11;

    }

    void Ucgen::setXY2(Nokta xy22) {

        xy2 = xy22;

    }

    void Ucgen::setXY3(Nokta xy33) {

        xy3 = xy33;

    }

    std::string Ucgen::toString() {
        
        std::string result;

        result += xy1.toString() + "\n";

        result += xy2.toString() + "\n";

        result += xy3.toString() + "\n";

        
        return result;
       


    }


    double Ucgen::alan() {

        double uzunluk1, uzunluk2, uzunluk3,uzunlukort;
        DogruParcasi kenar1{xy1,xy2};
        DogruParcasi kenar2{ xy2,xy3 };
        DogruParcasi kenar3{ xy3,xy1 };

        uzunluk1 = kenar1.uzunluk();
        uzunluk2 = kenar2.uzunluk();
        uzunluk3 = kenar3.uzunluk();

      uzunlukort = (uzunluk1 + uzunluk2 + uzunluk3) / 2;

    return std::sqrt(uzunlukort * (uzunlukort - uzunluk1) * (uzunlukort - uzunluk2) * (uzunlukort - uzunluk3));
    }

    double Ucgen::cevre() {
        
        DogruParcasi dogru1{ xy1,xy2 };

        DogruParcasi dogru2{ xy1,xy3 };

        DogruParcasi dogru3{ xy2,xy3 };
        return dogru1.uzunluk() + dogru2.uzunluk() + dogru3.uzunluk();
    }

    double *Ucgen::acilar() {
        double* dizi = new double[3];
        double acı1, acı2, acı3;
        DogruParcasi kenar1{ xy1,xy2 };

        DogruParcasi kenar2{ xy1,xy3 };

        DogruParcasi kenar3{ xy2,xy3 };

        acı1 = (acos((pow(kenar2.uzunluk(), 2) - pow(kenar1.uzunluk(), 2) - pow(kenar3.uzunluk(), 2)) / (-2 * kenar1.uzunluk() * kenar3.uzunluk()))/ 3.14159)*180;
        acı2 = (acos((pow(kenar1.uzunluk(), 2) - pow(kenar2.uzunluk(), 2) - pow(kenar3.uzunluk(), 2)) / (-2 * kenar2.uzunluk() * kenar3.uzunluk()))/ 3.14159)*180;
        acı3 = (acos((pow(kenar3.uzunluk(), 2) - pow(kenar2.uzunluk(), 2) - pow(kenar1.uzunluk(), 2)) / (-2 * kenar1.uzunluk() * kenar2.uzunluk()))/ 3.14159)*180;
        dizi[0] = acı1;
        dizi[1] = acı2;
        dizi[2] = acı3;
        return dizi;
    }

    

       





