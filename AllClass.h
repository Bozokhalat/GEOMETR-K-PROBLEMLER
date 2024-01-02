#pragma once
#include <iostream>
#include<string>

class Nokta {

private:

	double x, y;

public:
	Nokta(const Nokta& Nesne);

	Nokta(const Nokta& Nesne, double ofset_x, double ofset_y);

	Nokta();

	Nokta(double xykordinat);

	Nokta(double xkordinat, double ykordinat);

	void setX(double xkordinat);

	void setY(double ykordinat);

	void set(double xkordinat, double ykordinat);

	double getX() const;

	double getY() const;

	std::string toString() const;

	void yazdir() const;




};

class DogruParcasi {

private:
	Nokta xy1, xy2, xy_orta;

	double uzaklik;

public:

	DogruParcasi(Nokta dogrukordinatýortasý, double dogruzunlugu, double egim);

	DogruParcasi(const DogruParcasi& Nesne);

	DogruParcasi(Nokta xy1, Nokta xy2);

	Nokta getP1() const;

	Nokta getP2() const;

	Nokta ortaNokta() const;

	void setP1(Nokta xy1);

	void setP2(Nokta xy2);

	void setortaNokta(Nokta x_orta);

	void setUzunluk(double uzunluk);

	double uzunluk() const;

	std::string toString() const;

	void yazdir() const;

	Nokta KesisimNoktasi(const Nokta& verilenNokta) const;


};

class Daire {

private:

	Nokta merkezxy;
	double yarýcap;


public:

	Daire(Nokta merkezxy, double yarýcap);

	Daire(const Daire& Nesne);

	Daire(const Daire& Nesne, double carpýlacak_x_degeri);
	
	double getMerkezX(); 

	double getMerkezY(); 
	double getYarýcap();

	void setYarýcap(double yarýcapp);
	void setMerkezX(double x);
	
	void setMerkezY(double y);

	double alan();

	double cevre();

	std::string toString();

	void yazdir();

	int kesisim(const Daire& KesisimNesnesi);



};


class Ucgen {


private:
	Nokta xy1, xy2, xy3;

public:

	Ucgen(Nokta xy1, Nokta xy2, Nokta xy3);

	Nokta getXY1();

	Nokta getXY2();

	Nokta getXY3();

	void setXY1(Nokta xy1);

	void setXY2(Nokta xy2);

	void setXY3(Nokta xy3);

	std::string toString();

	double alan();

	double cevre();

	double* acilar();






};