#include<iostream>
#include<cstdlib> //new ve delete/malloc ve free i�in
using namespace std; 
struct kitapDugum //kitaplar� d���mde saklayaca��z
{
	int id; //kitap numaras�, arama ve silmeyi bununla yap�lacak
	string adi;
	string turu;
	string yazarAdi;
	string tarihi;
	int baskiNo;
	kitapDugum *previous; //onceki d���m� g�sterecek
	kitapDugum *next; //sonraki d���m� g�sterecek	
};

class CiftYonluBagliListe
{
	public:
			kitapDugum *ilk; //listenin ba��n� kontrol edecek
			kitapDugum *son; //listenin sonunu kontrol edecek
			//Yap�c�
			CiftYonluBagliListe()
			{
				ilk=NULL; //ilk de�er atamas� yapt�k
				son=NULL;
			}
			//Ekleme Fonksiyonu
			void ekleKitap(int no,string ad,string y,string t,string ta,int bn)
			{
				//Dugumu olu�turuyoruz
				kitapDugum *d;
				d=new kitapDugum;
				d->id=no;
				d->adi=ad;
				d->yazarAdi=y;
				d->turu=t;
				d->tarihi=ta;
				d->baskiNo=bn;
				//d->next=NULL;
				if(ilk==NULL) //liste bo�sa ve ilk eleman ekleniyor ise
				{
					ilk=d;
					son=ilk; //d de atanabilir
					ilk->previous=NULL; //tek yonl�den tek fark�
					ilk->next=NULL;
				}
				else //listede kitap varsa 
				{
					son->next=d;
					d->previous=son; //tek y�nl�den tek fark�
					son=d;
					son->next=NULL;					
				}
			}
			
			//listeleme yapacak
			void listele()
			{
				kitapDugum *p;
				p=ilk;
				if(p==NULL) cout<<"Liste bos"<<endl;
				while(p!=NULL) //listede son eleman NULL oluncaya kadar d���mler aras�na gezecek
				{
					cout<<"**************"<<endl;
					cout<<"Kitap Id="<<p->id<<endl;
					cout<<"Kitap Adi="<<p->adi<<endl;
					cout<<"Kitap Yazar Adi="<<p->yazarAdi<<endl;
					cout<<"Kitap Turu="<<p->turu<<endl;
					cout<<"Kitap Tarihi="<<p->tarihi<<endl;
					cout<<"Kitap Baski Sayisi="<<p->baskiNo<<endl;					
					p=p->next; //bir sonraki d���me ge�iyoruz, demezsek sonsuz d�ng�ye girer.
				}				
			}
			
			kitapDugum * araKitap(int  no)
			{
				kitapDugum *p;
				p=ilk;
				while(p!=NULL)
				{
					if(p->id==no)
					{
						return p; //kitab� bulduysak d���m� g�nderiyoruz
					}
					p=p->next;	
				}
				
				return NULL; //bulamad�ksay NULL g�nderiyoruz				
			}
};

int main()
{
	/*kitapDugum *ilk; //k�k d���m ilk adresi tutacak
	ilk=new kitapDugum;
	ilk->id=1;
	ilk->adi="Don Ki�ot";
	ilk->turu="D�nya Klasikleri";
	ilk->yazarAdi="Cervantes";
	ilk->tarihi="10/10/2015";
	ilk->baskiNo=5;
	ilk->previous=NULL;//ilk eleman�n �ncesi NULL;
	ilk->next=NULL;
	
	//2. kitab� ekliyoruz..
	kitapDugum *kitap2; //k�k d���m ilk adresi tutacak
	kitap2=new kitapDugum;
	kitap2->id=2;
	kitap2->adi="�kiz Bedenler";
	kitap2->turu="Macera";
	kitap2->yazarAdi="Tess Gerritsen";
	kitap2->tarihi="10/10/2017";	
	kitap2->baskiNo=20;
	kitap2->previous=ilk;//ilk eleman�n �ncesi NULL;
	kitap2->next=NULL;
	ilk->next=kitap2;//listeye kitab� ekliyoruz
	*/
	
	CiftYonluBagliListe cbliste;
	cbliste.ekleKitap(1,"Don Kisot","Cervantes","Klasik","10/10/2015",20);
	cbliste.ekleKitap(2,"Ikiz Bedenler","Tess Gerritsen","Macera","10/10/2017",5);
	cbliste.ekleKitap(3,"Tutunamayanlar","Oguz Atay","Roman","10/10/2016",10);
	
	//cout<<"kitap adi:"<<cbliste.ilk->adi<<endl;
	//Ba�l� liste elemanlar� ekranda yazd�r�l�yor
	
	cbliste.listele();
	// Arama Yap�yoruz
	kitapDugum *p=NULL;
	p=cbliste.araKitap(2);
	if(p==NULL)
	 cout<<endl<<"***Kitap bulunamadi***"<<endl;
	else
	{
		cout<<endl<<"****Aradiginiz Kitap Bilgileri****"<<endl;
		cout<<"Kitap Id="<<p->id<<endl;
		cout<<"Kitap Adi="<<p->adi<<endl;
		cout<<"Kitap Yazar Adi="<<p->yazarAdi<<endl;
		cout<<"Kitap Turu="<<p->turu<<endl;
		cout<<"Kitap Tarihi="<<p->tarihi<<endl;
		cout<<"Kitap Baski Sayisi="<<p->baskiNo<<endl;	
	}
	return 0;
}







