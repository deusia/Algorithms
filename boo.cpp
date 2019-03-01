 #include <iostream>
#include <iomanip>
#include <string>
#include <fstream>//����/����ļ�����
using namespace std;
const int Maxr=100;//���Ķ���
const int Maxb=100;//����ͼ��
const int Maxzf=5;//ÿλ���������屾��
//������,ʵ�ֶԶ��ߵ���Ϣ������

class Reader       
{   
    private:
 int tag;  //ɾ����� 1:��ɾ 0:δɾ
 int no;   //���߱��
 char name[10];  //��������
 int zfbook[Maxzf];//����ͼ��
    public:
  Reader() {}
     char *getname() {return name;}      //��ȡ����
  int gettag() {return tag;}         //��ȡɾ�����
     int getno() {return no;}           //��ȡ���߱��
     void setname(char na[])            //��������
  { 
     strcpy(name,na);
  
  }
 void delbook(){  tag=1;  }//����ɾ����� 1:��ɾ 0:δɾ
 void addreader(int n,char *na)//���Ӷ���
 { 
  tag=0;
  no=n;
  strcpy(name,na);
  for(int i=0;i<Maxzf;i++)
   zfbook[i]=0;
 }
 void zfrowbook(int bookid)//�������
 {
  for(int i=0;i<Maxzf;i++)
  { 
   if (zfbook[i]==0)
   {
    zfbook[i]=bookid;
    return;
    
   }
  }
  
 }
 int retbook(int bookid)//�������
 { 
  for(int i=0;i<Maxzf;i++)
  { 
   if(zfbook[i]==bookid)
   {
   zfbook[i]=0;
   return 1;
   
   }
  }
  return 0;
 }
 void disp()//����������Ϣ
 { 
  cout << setw(5) << no <<setw(10) << name<<"�����ţ�[";
  for(int i=0;i<Maxzf;i++)
   if(zfbook[i]!=0)
    cout << zfbook[i] << "|";
  cout << "]"<<endl;
   
 }
};
 
//������⣬ʵ�ֽ������ߵĸ�������
 class RDatabase
{  
private:
   int top;       //���߼�¼ָ��
   Reader read[Maxr];//���߼�¼
public:
 RDatabase()   //���캯������reader.txt����read[]��
 {
  Reader s;
  top=-1;
  fstream file("reader.txt",ios::in);//��һ�������ļ�
  while (1)
  {
   file.read((char *)&s,sizeof(s));
   if (!file)break;
   top++;
   read[top]=s;
  }
  file.close();     //�ر� reader.txt
 }
    void clear()//ɾ�����ж�����Ϣ
 {
  top=-1;
 }
 int addreader(int n,char *na)//��Ӷ���ʱ�Ȳ����Ƿ����
 {
  Reader *p=query(n);
  if (p==NULL)
  {
    top++;
    read[top].addreader(n,na);
    return 1;
  }
  return 0;
 }
 Reader *query(int readerid)//����Ų���
 {
  for (int i=0;i<=top;i++)
   if (read[i].getno()==readerid && 
   read[i].gettag()==0)
   {
    return &read[i];
   }
   return NULL;
 }
 void disp()  //������ж�����Ϣ
 {
           for (int i=0;i<=top;i++)
      read[i].disp();
 }
 void readerdata();//���߿�ά��
 ~RDatabase()  //������������read[]д��reader.txt�ļ���
 {
  fstream file("reader.txt",ios::out);
        for (int i=0;i<=top;i++)
   if (read[i].gettag()==0)
    file.write((char *)&read[i],sizeof(read[i]));
   file.close();
 }
};
void RDatabase::readerdata()
{
    char choice;
 char rname[20];
 int readerid;
 Reader *r;
 while (choice!='0')
 {
        cout <<"\n\n\t\t\t��   ��   ά   ��\n\n\n\t\t 1   ��      ��\n\n\t\t 2   ��      ��\n\n\t\t 3   ɾ      ��\n\n\t\t 4   ��      ��\n\n\t\t 5   ��      ʾ\n\n\t\t 6   ȫ      ɾ\n\n\t\t 0   ��      ��"<<endl;
  cin >> choice;
  switch (choice)
  {
            case '1':
    cout << "������߱��:";
    cin >> readerid;
    cout << "�����������:";
    cin >> rname;
    addreader (readerid,rname);
    break;
            case '2':
    cout << "������߱��:";
    cin >> readerid;
    r=query(readerid);
    if (r==NULL)
    {
     cout << " �ö��߲�����  "<<endl;
        break;
    }
    cout << "�����µ�����:";
    cin >> rname;
    r->setname(rname);
     break;
            case '3':
        cout << " ������߱��:";
                    cin >> readerid;
     r=query(readerid);
     if (r==NULL)
     {
         cout <<" �ö��߲�����" << endl;
         break;
     }
     r->delbook();
     break;
   case '4':
    cout << "������߱��:";
    cin >> readerid;
    r=query(readerid);
    if (r==NULL)
    {
     cout <<"�ö��߲�����"<< endl;
     break;
    }
    r->disp();
    break;
   case '5':
    disp();
    break;
   case '6':
    clear();
    break;
   default:cout<<"���������������룺";break;
  }
 }
}
 
 

//ͼ���࣬ʵ�ֶ�ͼ���������ͼ��ı�ţ�����������������
class Book
{
private:
    int tag;//ɾ����� 1:��ɾ 0:δɾ
 int no;//ͼ����
 char name[20];//����
 int onshelf;//�Ƿ��ټ� 1:�ټ� 2:�ѽ�
public:
 Book(){}
 char *getname() { return name; }//��ȡ����
 int getno(){ return no; }//��ȡͼ����
 int gettag(){ return tag; }//��ȡɾ�����
 void setname(char na[])//��������
 {
  strcpy(name,na);
 }
 void delbook(){ tag=1;}//ɾ��ͼ��
 void addbook(int n,char *na)//����ͼ��
 {
  tag=0;
  no=n;
  strcpy(name,na);
  onshelf=1;
 }
 int zfrowbook()//�������
 {
  if (onshelf==1)
  {
   onshelf=0;
   return 1;
  }
  return 0;
 }
 void retbook()//�������
 {
  onshelf=1;
 }
 void disp()//���ͼ��
 {
  cout << setw(6) << no << setw(18) << name << setw(10)
   <<(onshelf==1? "�ڼ�":"�ѽ�") <<endl;
 }
};
 
 

//ͼ����࣬ʵ�ֶ�ͼ���ά�������ң�ɾ����
class BDatabase
{
private:
    int top;         //ͼ���¼ָ��
 Book book[Maxb]; //ͼ���¼
public:
 BDatabase()//���캯������book.txt����book[]��
 { 
   Book b;
   top=-1;
   fstream file("book.txt",ios::in);
   while (1)
   {
    file.read((char *)&b,sizeof(b));
    if (!file) break;
    top++;
    book[top]=b;
   }
   file.close();
 }
    void clear()//ȫɾ
 {
  top=-1;
 }
    int addbook(int n,char *na)//����ͼ��
 {
  Book *p=query(n);
  if (NULL==p)
  {
   top++;
   book[top].addbook(n,na);
   return 1;
  }
  return 0;
 }
 Book *query(int bookid)//����ͼ��
 {
  for (int i=0;i<=top;i++)
   if (book[i].getno()==bookid &&book[i].gettag()==0)
   { 
    return &book[i];
   }
   return NULL;
 }
 void bookdata();//ͼ���ά��
 void disp()
 {
   for (int i=0;i<=top;i++)
    if (book[i].gettag()==0)
     book[i].disp();
 }
 ~BDatabase()//������������book[]д��book.txt�ļ���
 {
  fstream file("book.txt",ios::out);
        for (int i=0;i<=top;i++)
   if (book[i].gettag()==0)
    file.write((char *)&book[i],sizeof(book[i]));
   file.close();
 }
};
void BDatabase::bookdata()
{
    char choice;
 char bname[40];
 int bookid;
 Book *b;
 while (choice!='0')
 {
  cout <<"\n\n\n\t\t\tͼ  ��  ά  �� "<<endl<<endl;
  cout<<"\t\t1   ��     ��\n \t\t2   ��     ��\n\t\t3   ɾ     ��\n\t\t4   ��     ��\n\t\t5   ��     ʾ\n\t\t6   ȫ     ɾ\n\t\t0   ��     ��"<<endl;
  cin >> choice;
  switch (choice)
  {
            case '1':
    cout << "����ͼ����:"<<endl;
    cin >> bookid;
                cout << "����ͼ������:"<<endl;
    cin >> bname;
    addbook(bookid,bname);
    break;
            case '2':
    cout << "����ͼ����:"<<endl;
    cin >> bookid;
    b=query(bookid);
    if (b==NULL)
    {
     cout << " ��ͼ�鲻����  "<<endl;
        break;
    }
    cout << "�����µ�����:"<<endl;
    cin >> bname;
    b->setname(bname);
     break;
            case '3':
        cout <<" ����ͼ����:"<<endl;
                    cin >> bookid;
     b=query(bookid);
     if (b==NULL)
     {
         cout <<" ��ͼ�鲻����" << endl;
         break;
     }
     b->delbook();
     break;
   case '4':
    cout << "  ����ͼ����:"<<endl;
    cin >> bookid;
    b=query(bookid);
    if (b==NULL)
    {
     cout <<"  ��ͼ�鲻����"<< endl;
     break;
    }
    b->disp();
    break;
   case '5':
    disp();
    break;
   case '6':
    clear();
    break;
   default:cout<<"����������������:";
  }
 }
}
 
//main() ������ʵ�֣�����������������
void main()
{    
 char choice;
 int bookid,readerid;
 RDatabase ReaderDB;
 Reader *r;
 BDatabase BookDB;
 Book *b;
 while(choice!='0')
 {       
   cout <<endl<<endl<<"\t\t\t�� �� �� ѧ ͼ �� �� �� ϵ ͳ\n\n\n";
      
   cout <<"\t\t\t1    ��       ��\n\n\t\t\t2    ��       �� \n\n\t\t\t3    ͼ �� ά ��\n\n\t\t\t4    �� �� ά ��\n\n\t\t\t0    ��       ��"<<endl;
   cin >> choice;
   switch (choice)
   {
   case '1':
    cout <<"  ���� ���߱��:";
    cin >>readerid;
    cout <<"  ͼ���ţ� ";
    cin >>bookid;
    r=ReaderDB.query(readerid);//����Ų���
    if (NULL==r)
    {
     cout <<"  �����ڸö��ߣ����ܽ���"<< endl;
     break;
    }
    b=BookDB.query(bookid);
    if (b==NULL)
    {
     cout <<"  �����ڸ�ͼ�飬���ܽ���"<< endl;
     break;
    }
    if (b->zfrowbook()==0)
    {
     cout << "  ��ͼ���ѽ�������ܽ���"<< endl;
     break;
    }
    r->zfrowbook(b->getno());
    break;
   case '2':
    cout<<"����\n ���߱��:";
    cin >>readerid;
    cout << "   ͼ����:";
    cin >>bookid;
    r=ReaderDB.query(readerid);
    if (r==NULL)
    {
     cout <<" �����ڸö��ߣ����ܻ���" << endl;
     break;
    }
    b=BookDB.query(bookid);
    if (b==NULL)
    {
     cout <<"  �����ڸ�ͼ�飬���ܻ���" <<endl;
     break;
    }
    b->retbook();
    r->retbook(b->getno());
    break;
   case '3':
     BookDB.bookdata();
     break;
   case '4':
        ReaderDB.readerdata();
        break;
   default:cout<<"���������������룺";
   }
 }
}
   



1��������
Book�����ƣ�
Book
Name[strNum]:char
number[strNum]:char
kind[type]:char
int tag;int num;int add
Book() {}
getkind():char
getname():char
getnum():int
gettag():int
setnumber(char num[]):void
setname(char na[]):void
setkind(char kin[]):void
delbook():void
addbook(int n,char *na,char *kin):void
disp():void
(1)���ݳ�Ա
char name[StrNum];   �������������
char number[StrNum];  �������ͼ��ı�š�
char kind[Type];  �������ͼ������͡�
int tag;  ����ɾ����ǡ�
int num;  ����ͼ����Ϊ���Ρ�
int add;  ���ӱ�ǡ�
(2)������Ա
Book(){}          �޲ι��캯��������Ϊ������������������Ĭ��ֵ��
char getkind()      ���ڻ�ȡͼ�����͡�                      
char getname()	 ���ڻ�ȡ������
int getnum()       ���ڻ�ȡͼ���š�           
int gettag()        ���ڻ�ȡɾ����ǡ�
void setname(char na[])       ��������������
void setkind(char kin[])       �����������͡�
void delbook()               ����ɾ��ͼ�顣
void addbook(int n,char *na,char *kin)   ��������ͼ�顣
void disp()        �������ͼ�顣
2.���������ƣ�
(1)��������ƣ�
class BDatabase{}  ͼ�����������ã�ʵ�ֶ�ͼ�����ӣ����ң�ɾ���ȡ�
int top;           ����ͼ���¼ָ�롣
Book book[Maxb];   ����ͼ���¼��Maxb����Ϊ���ɴ洢��ͼ����������Ϊ���Σ���
void clear()         ���ͼ���¼��
int addbook(int n,char *na,char *kin)    ����ͼ���¼��
Book *query(int bookid)       ����ͼ���¼��
void bookdata();              ����ͼ��⡣
void disp()                   �����
~BDatabase()                ����������������book[]д��book.txt�ļ���
void BDatabase::bookdata()     �ɴ˺�����ʼ��ͼ�����ϵͳ�����˵����е����빦�ܵ�ʵ�֡�������ο�ִ�н��沿�֣�
�����main() ������ʵ�֣�����������������
3. Դ���������
/*****************************************************************************************/
#define StrNum 20
#define Type 20
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>                  //����/����ļ�����
using namespace std;
const int Maxb=100;                 //���ɴ洢��ͼ��
class Book
{
private:
    int tag;                        //ɾ�����
	int num;                        //ͼ����
	int add;                        //���ӱ��
	char number[StrNum];            //���
	char name[StrNum];              //����
	char kind[Type];                //ͼ������

public:
	Book(){}
	char getkind()                  //��ȡͼ������
	{
		return kind[Type];
	}                                
	char getname()	                //��ȡ����
	{ 
		return name[StrNum]; 
	}
	int getnum()                     //��ȡͼ����
	{ 
		return num; 
	}                  
	int gettag()                    //��ȡɾ�����
	{ 
		return tag;
	}
	void setname(char na[])         //��������
	{
		strcpy(name,na);
	}
	void setkind(char kin[])        //��������
	{
		strcpy(kind,kin);
	}
	void delbook()                  //ɾ��ͼ��
	{
		tag=1;
	}
	void addbook(int n,char *na,char *kin)    //����ͼ��
	{
		tag=0;
		num=n;
		strcpy(name,na);
		strcpy(kind,kin);
	}
	void disp()                     //���ͼ��		
	{
		cout.flags (ios::left);     //���ö���ı�־λΪ��
		cout<<setw(15)<<num<<setw(20)<<name<<setw(15)<<kind<<endl;		
	}		
};
/*****************************************************************************************/
class BDatabase
{
private:
    int top;                        //ͼ���¼ָ��
	Book book[Maxb];                //ͼ���¼
public:
	BDatabase()                     //���캯������book.txt����book[]��
	{ 
			Book b;
			top=-1;
			fstream file("book.txt",ios::in);
			while (1)
			{
				file.read((char *)&b,sizeof(b));
				if (!file) break;
				top++;
				book[top]=b;
			}
			file.close();
	} 
	void clear()                    //ȫɾ
	{
		top=-1;
	}
    int addbook(int n,char *na,char *kin)     //����ͼ��
	{
		Book *p=query(n);
		if(NULL==p)
		{
			top++;
			book[top].addbook(n,na,kin);
			return 1;
		}
		return 0;
	}
	Book *query(int bookid)         //����ͼ��
	{
		for (int i=0;i<=top;i++)
			if (book[i].getnum()==bookid &&book[i].gettag()==0)
			{	
				return &book[i];
			}
			return NULL;
	}
	void bookdata();                //ͼ���
	void disp()
	{
	  for (int i=0;i<=top;i++)
		  if (book[i].gettag()==0)
			  book[i].disp();
	}
	~BDatabase()                    //������������book[]д��book.txt�ļ���
	{
		fstream file("book.txt",ios::out);
        for (int i=0;i<=top;i++)
			if (book[i].gettag()==0)
				file.write((char *)&book[i],sizeof(book[i]));
			file.close();
	}
};
void BDatabase::bookdata()
{
    char choice;
	char bname[40];
	char bkind[40];
	char newType[20];
	int bookid;
	Book *b;
	while (choice!='0')
	{   
	    cout<<"\t******************************************************************\n";
		cout<<"                                           \n\n";
		cout<<"\t\t\tͼ  ��  ��  ��  ϵ  ͳ\n\n";
		cout<<"\t\t\t1    ����ͼ���¼\n";
        cout<<"\t\t\t2    ����ͼ���¼\n";
        cout<<"\t\t\t3    ɾ��ͼ���¼\n";
		cout<<"\t\t\t4    ����ͼ���¼\n";
		cout<<"\t\t\t5    ��ʾͼ���¼\n";
		cout<<"\t\t\t6    ���ȫ����¼�����ã�\n";
		cout<<"\t\t\t0    �˳�ϵͳ\n";
		cout<<"                                           \n\n";
		cout<<"\t******************************************************************\n";
        cout<<"��ѡ��(1,2,3,4,5,6,0):";
		cin>>choice;
		switch (choice)
		{
            case '1':
				cout<<"����ͼ����:"<<endl;
				cin>>bookid;
				cout<<"����ͼ������:"<<endl;
				cin>>newType;
                cout<<"����ͼ������:"<<endl;
				cin>>bname;
				addbook(bookid,bname,newType);
				break;
            case '2':
				cout<<"����ͼ����:"<<endl;
				cin>>bookid;
				b=query(bookid);
				if(b==NULL)
				{
					cout<<"��ͼ�鲻����"<<endl;
				    break;
				}
				cout<<"�����µ�����:"<<endl;
				cin>>bname;
				b->setname(bname);
				cout<<"�����µ�����:"<<endl;
				cin>>bkind;
				b->setkind(bkind);
			 	break;
            case '3':
				   	cout<<"����ͼ����:"<<endl;
					cin>>bookid;
					b=query(bookid);
					if(b==NULL)
					{
					    cout<<"��ͼ�鲻����"<<endl;
					    break;
					}
					char tg1;
					cout<<"ȷ��Ҫɾ���˼�¼��?(Y/N)"<<endl;
					cin>>tg1;
					if(tg1!='n'&&tg1!='N')
					{
					b->delbook();
					cout<<"�ѳɹ�ɾ�������¼��"<<endl;
					break;
					}		
			case '4':
				cout<<"����ͼ����:"<<endl;
				cin>>bookid;
				b=query(bookid);
				if (b==NULL)
				{
					cout<<"��ͼ�鲻����"<<endl;
					break;
				}	
				cout<<"ͼ����      ͼ������            ͼ������         \n";
				b->disp();
				break;
			case '5':
				cout<<"ͼ����      ͼ������            ͼ������         \n";
				disp();
				break;
			case '6':
				    char tg2;
					cout<<"ȷ��Ҫ������м�¼��?(Y/N)"<<endl;
					cin>>tg2;
					if(tg2!='n'&&tg2!='N')
					{
					clear();
				    cout<<"�ѳɹ���ռ�¼��"<<endl;
					break;
					}
			case '0':
				break;
			default:cout<<"����������������(����Ϊ0~6):";
		}
	}
}
//main() ������ʵ�֣�����������������
void main()
{    
	char choice;
	BDatabase BookDB;
	while(choice!='0')
	{       cout<<"\t******************************************************************\n";
	        cout<<"                                           \n\n";
		    cout<<"\n\n\t\t\t��ӭʹ��ͼ�����ϵͳ\n\n";
			cout<<endl<<endl<<"\t\t\tͼ  ��  ��  ��  ϵ  ͳ\n\n\n\n";
			cout<<setw(83)<<"by ������������\n\n\n\n";
			cout<<"                                           \n\n";
			cout<<"\t******************************************************************\n";

		    
			cout<<"\t\t\t1    ��  ��  ϵ  ͳ\n\n\t\t\t0    ��       ��"<<endl;
			cout<<"��ѡ��:";
			cin>>choice;
			switch(choice)
			{
			case '1':
					BookDB.bookdata();
					break; 
            case '0':
				 cout<<"\n\n\t\t\t��ӭ�ٴ�ʹ��ͼ�����ϵͳ\n\n";
				 break;
			default:cout<<"���������������룺";
			}
	}
}
