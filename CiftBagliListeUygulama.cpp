#include<iostream>
#include<cstdlib> //new ve delete/malloc ve free için
using namespace std; 
struct kitapDugum //kitaplarý düðümde saklayacaðýz
{
	int id; //kitap numarasý, arama ve silmeyi bununla yapýlacak
	string adi;
	string turu;
	string yazarAdi;
	string tarihi;
	int baskiNo;
	kitapDugum *previous; //onceki düðümü gösterecek
	kitapDugum *next; //sonraki düðümü gösterecek	
};

class CiftYonluBagliListe
{
	public:
			kitapDugum *ilk; //listenin baþýný kontrol edecek
			kitapDugum *son; //listenin sonunu kontrol edecek
			//Yapýcý
			CiftYonluBagliListe()
			{
				ilk=NULL; //ilk deðer atamasý yaptýk
				son=NULL;
			}
			//Ekleme Fonksiyonu
			void ekleKitap(int no,string ad,string y,string t,string ta,int bn)
			{
				//Dugumu oluþturuyoruz
				kitapDugum *d;
				d=new kitapDugum;
				d->id=no;
				d->adi=ad;
				d->yazarAdi=y;
				d->turu=t;
				d->tarihi=ta;
				d->baskiNo=bn;
				//d->next=NULL;
				if(ilk==NULL) //liste boþsa ve ilk eleman ekleniyor ise
				{
					ilk=d;
					son=ilk; //d de atanabilir
					ilk->previous=NULL; //tek yonlüden tek farký
					ilk->next=NULL;
				}
				else //listede kitap varsa 
				{
					son->next=d;
					d->previous=son; //tek yönlüden tek farký
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
				while(p!=NULL) //listede son eleman NULL oluncaya kadar düðümler arasýna gezecek
				{
					cout<<"**************"<<endl;
					cout<<"Kitap Id="<<p->id<<endl;
					cout<<"Kitap Adi="<<p->adi<<endl;
					cout<<"Kitap Yazar Adi="<<p->yazarAdi<<endl;
					cout<<"Kitap Turu="<<p->turu<<endl;
					cout<<"Kitap Tarihi="<<p->tarihi<<endl;
					cout<<"Kitap Baski Sayisi="<<p->baskiNo<<endl;					
					p=p->next; //bir sonraki düðüme geçiyoruz, demezsek sonsuz döngüye girer.
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
						return p; //kitabý bulduysak düðümü gönderiyoruz
					}
					p=p->next;	
				}
				
				return NULL; //bulamadýksay NULL gönderiyoruz				
			}
};

int main()
{
	/*kitapDugum *ilk; //kök düðüm ilk adresi tutacak
	ilk=new kitapDugum;
	ilk->id=1;
	ilk->adi="Don Kiþot";
	ilk->turu="Dünya Klasikleri";
	ilk->yazarAdi="Cervantes";
	ilk->tarihi="10/10/2015";
	ilk->baskiNo=5;
	ilk->previous=NULL;//ilk elemanýn öncesi NULL;
	ilk->next=NULL;
	
	//2. kitabý ekliyoruz..
	kitapDugum *kitap2; //kök düðüm ilk adresi tutacak
	kitap2=new kitapDugum;
	kitap2->id=2;
	kitap2->adi="Ýkiz Bedenler";
	kitap2->turu="Macera";
	kitap2->yazarAdi="Tess Gerritsen";
	kitap2->tarihi="10/10/2017";	
	kitap2->baskiNo=20;
	kitap2->previous=ilk;//ilk elemanýn öncesi NULL;
	kitap2->next=NULL;
	ilk->next=kitap2;//listeye kitabý ekliyoruz
	*/
	
	CiftYonluBagliListe cbliste;
	cbliste.ekleKitap(1,"Don Kisot","Cervantes","Klasik","10/10/2015",20);
	cbliste.ekleKitap(2,"Ikiz Bedenler","Tess Gerritsen","Macera","10/10/2017",5);
	cbliste.ekleKitap(3,"Tutunamayanlar","Oguz Atay","Roman","10/10/2016",10);
	
	//cout<<"kitap adi:"<<cbliste.ilk->adi<<endl;
	//Baðlý liste elemanlarý ekranda yazdýrýlýyor
	
	cbliste.listele();
	// Arama Yapýyoruz
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







