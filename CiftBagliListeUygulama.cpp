#include<iostream>
#include<cstdlib> //new ve delete/malloc ve free için
using namespace std; 
struct kitapDugum //kitapları düğümde saklayacağız
{
	int id; //kitap numarası, arama ve silmeyi bununla yapılacak
	string adi;
	string turu;
	string yazarAdi;
	string tarihi;
	int baskiNo;
	kitapDugum *previous; //onceki düğümü gösterecek
	kitapDugum *next; //sonraki düğümü gösterecek	
};

class CiftYonluBagliListe
{
	public:
			kitapDugum *ilk; //listenin başını kontrol edecek
			kitapDugum *son; //listenin sonunu kontrol edecek
			//Yapıcı
			CiftYonluBagliListe()
			{
				ilk=NULL; //ilk değer ataması yaptık
				son=NULL;
			}
			//Ekleme Fonksiyonu
			void ekleKitap(int no,string ad,string y,string t,string ta,int bn)
			{
				//Dugumu oluşturuyoruz
				kitapDugum *d;
				d=new kitapDugum;
				d->id=no;
				d->adi=ad;
				d->yazarAdi=y;
				d->turu=t;
				d->tarihi=ta;
				d->baskiNo=bn;
				//d->next=NULL;
				if(ilk==NULL) //liste boşsa ve ilk eleman ekleniyor ise
				{
					ilk=d;
					son=ilk; //d de atanabilir
					ilk->previous=NULL; //tek yonlüden tek farkı
					ilk->next=NULL;
				}
				else //listede kitap varsa 
				{
					son->next=d;
					d->previous=son; //tek yönlüden tek farkı
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
				while(p!=NULL) //listede son eleman NULL oluncaya kadar düğümler arasına gezecek
				{
					cout<<"**************"<<endl;
					cout<<"Kitap Id="<<p->id<<endl;
					cout<<"Kitap Adi="<<p->adi<<endl;
					cout<<"Kitap Yazar Adi="<<p->yazarAdi<<endl;
					cout<<"Kitap Turu="<<p->turu<<endl;
					cout<<"Kitap Tarihi="<<p->tarihi<<endl;
					cout<<"Kitap Baski Sayisi="<<p->baskiNo<<endl;					
					p=p->next; //bir sonraki düğüme geçiyoruz, demezsek sonsuz döngüye girer.
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
						return p; //kitabı bulduysak düğümü gönderiyoruz
					}
					p=p->next;	
				}
				
				return NULL; //bulamadıksay NULL gönderiyoruz				
			}
};

int main()
{
	/*kitapDugum *ilk; //kök düğüm ilk adresi tutacak
	ilk=new kitapDugum;
	ilk->id=1;
	ilk->adi="Don Kişot";
	ilk->turu="Dünya Klasikleri";
	ilk->yazarAdi="Cervantes";
	ilk->tarihi="10/10/2015";
	ilk->baskiNo=5;
	ilk->previous=NULL;//ilk elemanın öncesi NULL;
	ilk->next=NULL;
	
	//2. kitabı ekliyoruz..
	kitapDugum *kitap2; //kök düğüm ilk adresi tutacak
	kitap2=new kitapDugum;
	kitap2->id=2;
	kitap2->adi="İkiz Bedenler";
	kitap2->turu="Macera";
	kitap2->yazarAdi="Tess Gerritsen";
	kitap2->tarihi="10/10/2017";	
	kitap2->baskiNo=20;
	kitap2->previous=ilk;//ilk elemanın öncesi NULL;
	kitap2->next=NULL;
	ilk->next=kitap2;//listeye kitabı ekliyoruz
	*/
	
	CiftYonluBagliListe cbliste;
	cbliste.ekleKitap(1,"Don Kisot","Cervantes","Klasik","10/10/2015",20);
	cbliste.ekleKitap(2,"Ikiz Bedenler","Tess Gerritsen","Macera","10/10/2017",5);
	cbliste.ekleKitap(3,"Tutunamayanlar","Oguz Atay","Roman","10/10/2016",10);
	
	//cout<<"kitap adi:"<<cbliste.ilk->adi<<endl;
	//Bağlı liste elemanları ekranda yazdırılıyor
	
	cbliste.listele();
	// Arama Yapıyoruz
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
