#include <iostream>
#include <stdlib.h>//malloc ve free fonksiyonları için eklendi 
using namespace std;
struct dugum
{
	string numara;
	string adsoyad;
	int vize;
	int final;
	double ortalama;
	dugum *next;	
};
class TekYonluBagliListe
{
	public:
			dugum *ilk;//ilk dugumun adresi
			dugum *son;//son dugumun adresi
			TekYonluBagliListe()//yapıcımız
			{
				ilk=NULL;
				son=NULL;
			}
			
			void ekleDugum(string n,string ad,int v,int f)
			{
				dugum *d;
				d=new dugum;
				d->adsoyad=ad;
				d->numara=n;
				d->vize=v;
				d->final=f;
				d->ortalama=(double)(d->vize*0.4+d->final*0.6);
				//d->next=NULL;
				if(ilk==NULL)//listede eleman yoksa
				{
					ilk=d; 
					son=ilk;
					ilk->next=NULL;
				}
				else //listede eleman varsa
				{
					son->next=d;
					son=d;
					son->next=NULL;
				}
				
			}
			
		void listele() //listeyi yazdırıyor
		{
			dugum *p;
			p=ilk;
			if(p==NULL) cout<<"Liste boş"<<endl;
			while(p!=NULL)
			{
				cout<<"*******************"<<endl;
				cout<<"Ogrencinin adi:"<<p->adsoyad<<endl;
				cout<<"Ogrencinin numarasi:"<<p->numara<<endl;
				cout<<"Ogrencinin vize:"<<p->vize<<endl;
				cout<<"Ogrencinin finali:"<<p->final<<endl;
				cout<<"Ogrencinin ortalamasi:"<<p->ortalama<<endl<<endl;
				p=p->next;				
			}			
		}
	//arama işlemi yapılıyor		
	dugum * araDugum(string no)
	{
		dugum *p;
		p=ilk;
		while(p!=NULL)
		{
			if(p->numara==no)
				return p;
			p=p->next;			
		}		
		return NULL;
	}
};

int main()
{
	/*dugum *ilk;
	//ilk=(dugum*)malloc(sizeof(dugum)); //bellekten yer tahsis ediliyor
	ilk=new dugum;
	ilk->adsoyad="Muhammed Enes Alpler";
	ilk->numara="1003";
	ilk->vize=90;
	ilk->final=95;
	ilk->ortalama=(double)(ilk->vize*0.4+ilk->final*0.6);
	
	cout<<"Numara:"<<ilk->numara;
	cout<<" Ortalamasi:"<<ilk->ortalama<<endl;
	
	// 2. düğüm oluşturuyoruz
	ilk->next=new dugum;
	ilk->next->adsoyad="Batuhan Yerlikaya";
	ilk->next->numara="1004";
	ilk->next->vize=60;
	ilk->next->final=70;
	ilk->next->ortalama=(double)(ilk->next->vize*0.4+ilk->next->final*0.6);	
	cout<<"Numara:"<<ilk->next->numara;
	cout<<" Ortalamasi:"<<ilk->next->ortalama<<endl;
	// 3. düğümü oluşturuyoruz
	dugum *d3;
	d3=new dugum;
	d3->adsoyad="Umit Gelener";
	d3->numara="1005";
	d3->vize=78;
	d3->final=80;
	d3->ortalama=(double)(d3->vize*0.4+d3->final*0.6);	
	ilk->next->next=d3;
	//free(d3);
	cout<<"Numara:"<<ilk->next->next->numara;
	cout<<" Ortalamasi:"<<ilk->next->next->ortalama<<endl;
	*/
	TekYonluBagliListe bliste;
	bliste.ekleDugum("1001","Ahmet",50,60);
	bliste.ekleDugum("1002","Ayse",70,80);
	bliste.ekleDugum("1003","Ali",90,100);
	bliste.listele();
	//arama işlemi 
	dugum *ara;
	ara=bliste.araDugum("1002");
	if(ara==NULL) 
		cout<<"aranan numara yok"<<endl;
	else
	{
		cout<<"****Aranan ogrenci****"<<endl;
		cout<<"Ogrencinin adi:"<<ara->adsoyad<<endl;
		cout<<"Ogrencinin numarasi:"<<ara->numara<<endl;
		cout<<"Ogrencinin vize:"<<ara->vize<<endl;
		cout<<"Ogrencinin finali:"<<ara->final<<endl;
		cout<<"Ogrencinin ortalamasi:"<<ara->ortalama<<endl<<endl;
	}
	return 0;
}
