#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
using namespace std;     //�������ռ��е�std����
class CData              //���������           
{
public:
	CData(){};
	virtual int Compare(CData &)=0;
	virtual void Show()=0;
    virtual ~CData(){};
};
class CNode              //���������
{
private:
	CData *pData;        //����ָ���������ָ��
	CNode *pNext;        //����ָ������ĺ���ָ��
public:
	CNode(){pData=0;pNext=0;};      //��㹹�캯��
    CNode(CNode &node)              //���ڿ����Ĺ��캯��
	{
		pData=node.pData;
		pNext=node.pNext;
	}
	void InputData(CData *pdata){pData=pdata;}      //��������
	void ShowNode(){pData->Show();}
	CData *GetData(){return pData;}
	friend class CList;             //����������Ϊ��Ԫ��
};
class CList
{
		CNode *pHead;               //����ͷ���ָ��
public:
	CList(){pHead=0;}
	~CList(){DeleStudentist();}
	void AddNode(CNode * pnode);    //���ײ���ӽ��
	CNode *DeleteNode(CNode *);     //ɾ��һ��ָ���Ľ�㣬���ظý���ָ��
	CNode *LookUp(CData &);         //����һ��ָ�������ݣ����ظ��������ڽ���������е�ָ�룬��δ�ҵ�����0
	void ShowList();                //��ӡ��������
	void DeleStudentist();              //ɾ����������
	CNode *GetListHead(){return pHead;}          //���������׽��
	CNode *GetListNextNode(CNode *pnode);        //��������ָ��������һ�����
};
CNode *CList::GetListNextNode(CNode *pnode)       //��������ָ��������һ�����
{
	CNode *p1=pnode;
	return p1->pNext;
};
void CList::AddNode(CNode *pnode)       //���ײ���ӽ��
{
	if(pHead==0)         //����ǿ���������Ľ����Ψһ�Ľ��
	{
		pHead=pnode;
		pnode->pNext=0;
		return;
	}
	else             //���򣬲��뵽�����ײ�
	{
		pnode->pNext=pHead;
		pHead=pnode;
	}
};
CNode *CList::DeleteNode(CNode *pnode)         //ɾ��һ��ָ���Ľ�㣬���ظý���ָ��
{
	CNode *p1,*p2;
	p1=pHead;               //ָ���׽��
	while(p1!=pnode&&p1->pNext!=0)        //Ѱ��Ҫɾ���Ľ��
	{
		p2=p1;              //���ָ��p2ʼ����p1�ĺ���
		p1=p1->pNext;
	}
	if(p1==pHead)          //���Ҫɾ�������׽��
	{
		pHead=pHead->pNext;      //���׽�����
		return pnode;
	}
	p2->pNext=p1->pNext;       //p1ָ��ɾ���Ľ�㣬��p2�����p1����Ľ����������
	return pnode;
}
CNode *CList::LookUp(CData &data)      //����һ��ָ�������ݣ����ظ��������ڽ���������е�ָ�룬��δ�ҵ�����0
{
	CNode *p1=pHead;
	while(p1)         //��ͷ��㿪ʼ����
	{
		if(p1->pData->Compare(data)==0)
			return p1;               //�ҵ��󷵻ؽ��ָ��
		p1=p1->pNext;
	}
	return 0;              //��������������֮������Ҳ��������ؿ�ָ��0
}
void CList::ShowList()     //��ӡ������������
{
	CNode *p1=pHead;
	while(p1)
	{
		p1->pData->Show();
		p1=p1->pNext;
	}
}
void CList::DeleStudentist()       //ɾ������������
{
	CNode *p1,*p2;
	p1=pHead;
	while(p1)
	{
		delete p1->pData;
		p2=p1;
		p1=p1->pNext;
		delete p2;
	}
}
class CStudentRecord:public CData       //ѧ����Ϣ��¼��Ϊ���ݻ���Ĺ���������
{
private:
	char szName[20];     //ѧ����Ϣ���ݣ�ѧ�š��������Ա𡢳ɼ�
	char szNumber[20];
	char szSex[20];
	char szChengji[20];
public:
	CStudentRecord(){strcpy(szName,"\0");strcpy(szNumber,"\0");strcpy(szSex,"\0");strcpy(szChengji,"\0");}    //���캯��
    CStudentRecord(char *name ,char *number,char *sex,char *chengji)   //���캯��
	{ 
		strcpy(szName,name);
		strcpy(szNumber,number);
		strcpy(szSex,sex);
		strcpy(szChengji,chengji);
	}
	void SetRecord(char * name,char *number,char *sex,char *chengji)    //�������ݺ���
	{	
		strcpy(szName,name);
		strcpy(szNumber,number);
		strcpy(szSex,sex);
		strcpy(szChengji,chengji);
	}
	int Compare (CData &);    //�ȽϺ������Ƚ�ѧ��
		void Show();          //��ӡ���ݺ���
};
int CStudentRecord::Compare(CData &data)     //�Ƚ�ѧ�ţ��������ã��ȽϽ��Ϊ1��0��-1
{
	 CStudentRecord &temp=( CStudentRecord &)data;
	 return strcmp(szName,temp.szName);
}
void  CStudentRecord::Show()       //��ӡһ����������
{
	cout<<setw(15)<<szName<<setw(15)<<szNumber<<setw(15)<<szSex<<setw(15)<<szChengji<<endl;
}
void AddRecord(CList &StudentList)     //����¼��ӵ�������
{
	CNode *pNode;
	CStudentRecord *pStudent;
	char szName[20],szNumber[20],szSex[20],szChengji[20];
	cout<<"��������������0�������� ";
	//cin.ignore();
	cin.getline(szName,20);
	while(strcmp(szName,"0"))
	{
		cout<<"����ѧ�ţ� ";
		cin.getline(szNumber,20);
		cout<<"����ɼ�: ";
        cin.getline(szChengji,20);
        cout<<"�����Ա�: ";
		cin.getline(szSex,20);
		pStudent=new CStudentRecord;                 //�����µ����������
		pStudent->SetRecord(szName,szNumber,szSex,szChengji);    //���������ֵ
		pNode=new CNode;                  //�����µĽ��
		pNode->InputData(pStudent);         //��㸳ֵ                         
		StudentList.AddNode(pNode);        //����������
		cout<<"��������������0�������� ";		
		cin.getline(szName,20);
	}
	cout<<endl<<endl;
}
void DisplayRecord(CList &StudentList)       //��ʾȫ����������
{
	cout<<setw(15)<<"����"<<setw(15)<<"ѧ��"<<setw(15)<<"�Ա�"<<setw(15)<<"�ɼ�"<<endl;
	StudentList.ShowList();
	cout<<endl<<endl;
}
void LookUpRecord(CList &StudentList)        //����ѧ�Ų���ѧ������
{
	CNode *pLook;
	char szName[20];
	cout<<"��������Ҫ���ҵ�����������0������";
	cin.getline(szName,20);
	while(strcmp(szName,"0"))
	{
		CStudentRecord Studente(szName,"0","0","0");    //���ɽ��
		
		pLook=StudentList.LookUp(Studente);        //����ָ��������� 
		if(pLook)
		{
			cout<<"��ϵͳ���ҵ�"<<szName<<",������: "<<endl;
			pLook->ShowNode();
		}
		else
			cout<<"��ϵͳ�в��Ҳ���"<<szName<<"."<<endl;
		cout<<"������Ҫ���ҵ�����������0������";
			cin.getline(szName,20);
	}
	cout<<endl<<endl;
	system("pause");
}
void DeleteRecord(CList &StudentList)      //��������ɾ��ָ���������
{
	CNode *pLook;
	char szName[20];
	cout<<"������Ҫɾ��������������0������";
	cin.getline(szName,20);
	while(strcmp(szName,"0"))
	{
		CStudentRecord Studente(szName,"0","0","0");
		pLook=StudentList.LookUp(Studente);
		if(pLook)        //ɾ��ʱӦ�Ȳ��ҳ����
		{
			cout<<"��ϵͳ���ҵ�"<<szName<<",������: "<<endl;
			pLook->ShowNode();
			StudentList.DeleteNode(pLook);
			cout<<szName<<"��������ɾ��"<<endl;
			delete pLook;
		}
		else
			cout<<"��ϵͳ���Ҳ���"<<szName<<"."<<endl;
		cout<<"��������Ҫɾ��������������0������"<<endl;
		cin.getline(szName,20);
	}
	cout<<endl<<endl;
}
void AlterRecord (CList &StudentList)
{
	CNode *pLook;
	char szName[20];
	cout<<"��������Ҫ�޸ĵ�ѧ������������0������";
	cin.getline(szName,20);
	while(strcmp(szName,"0"))
	{
		CStudentRecord Studente(szName,"0","0","0");
		pLook=StudentList.LookUp(Studente);
		if(pLook)
		{
			cout<<"��ϵͳ���ҵ�"<<szName<<",������: "<<endl;
			pLook->ShowNode();
			StudentList.DeleteNode(pLook);
			cout<<szName<<"��������ɾ��"<<endl;
			delete pLook;
			{
	CNode *pNode;
	CStudentRecord *pStudent;
	char szName[20],szNumber[20],szSex[20],szChengji[20];
	cout<<"��������������0�������� ";
	//cin.ignore();
	cin.getline(szName,20);
	while(strcmp(szName,"0"))
	{
		cout<<"����ѧ�ţ� ";
		cin.getline(szNumber,20);
		cout<<"����ɼ�: ";
        cin.getline(szChengji,20);
        cout<<"�����Ա�: ";
		cin.getline(szSex,20);
		pStudent=new CStudentRecord;                 //�����µ����������
		pStudent->SetRecord(szName,szNumber,szSex,szChengji);    //���������ֵ
		pNode=new CNode;                  //�����µĽ��
		pNode->InputData(pStudent);         //��㸳ֵ                         
		StudentList.AddNode(pNode);        //����������
		cout<<"��������������0�������� ";		
		cin.getline(szName,20);
	}
	cout<<endl<<endl;
}
		}
		else
			cout<<"��ϵͳ���Ҳ���"<<szName<<"."<<endl;
		cout<<"��������ѧ��ѧ�ţ�����0������"<<endl;
		cin.getline(szName,20);
	}
	cout<<endl<<endl;
}
void StoreFile(CList &StudentList)         //�������е����ݱ������ļ���
{
	ofstream outfile("StudentEOHONE.DAT",ios::binary);
	if(! outfile)
	{
		cout<<"�����ļ��򿪴���û�н����ݴ����ļ���\n";
		return;
	}
	CNode *pnode;
	CStudentRecord *pStudent;
	string strName,strNumber;
	pnode=StudentList.GetListHead();        //ȡ�������׽��ָ��
	while(pnode)
	{
		pStudent=(CStudentRecord *)pnode->GetData();       //���ؽ��ָ���������ָ��
		outfile.write((char *)pStudent,sizeof(CStudentRecord));    //��������д���ļ�
		pnode=StudentList.GetListNextNode(pnode);       //ȡ��һ���ָ��
	}
	outfile.close();
}
void Operate(string &strChoice,CList &StudentList)       //�������˵�ѡ����в���
{
	if(strChoice=="1")
		AddRecord(StudentList);
	else if(strChoice=="2")
		DisplayRecord(StudentList);
	else if(strChoice=="3")
		LookUpRecord(StudentList);
	else if(strChoice=="4")
		DeleteRecord(StudentList);
    else if(strChoice=="5")
        AlterRecord(StudentList);
	else if(strChoice=="0")
	    StoreFile(StudentList);
		else
			cout<<"��������������������ѡ��";
}
void LoadFile(CList &StudentList)           //�ڳ���ʼ���Ȳ������������ļ�,�ҵ����ȡ�ļ�����
{
	ifstream infile("StudentEOHONE.DAT",ios::binary);
	if(!infile)
	{
		cout<<"û�������ļ���\n\n";
		return ;
	}
	CNode *pNode;
	CStudentRecord *pStudent;
	while(! infile.eof())
	{
		pStudent=new CStudentRecord;    //�������������
		infile.read ((char *)pStudent,sizeof(CStudentRecord));
		pNode=new CNode;
		pNode->InputData(pStudent);      //����������������ɽ��
		StudentList.AddNode(pNode);      //������������
	}
	StudentList.DeleteNode(pNode);        //�����ļ��Ĺ�ϵ,�����һ��,���Խ��׽��ɾ��
	infile.close();
}
int main(void)
{
	CList StudentList;        //����������Ķ���
	system("cls");
	cout<<"\t��ӭ��ѧ���ɼ�����ϵͳ\n";
	LoadFile(StudentList);     //���ļ�����������
	string strChoice;      //�������˵�ѡ��
	do
	{
		cout<<"\t1. ���ѧ���ɼ���¼\n";
	    cout<<"\t2. ��ʾѧ���ɼ���¼\n";
	    cout<<"\t3. ����ѧ���ɼ���¼\n";
	    cout<<"\t4. ɾ��ѧ���ɼ���¼\n";
		cout<<"\t5. �޸�ѧ���ɼ���¼\n";
	    cout<<"\t0. �˳�ѧ���ɼ�����ϵͳ\n";
		cout<<"���������ѡ��";
		cin>>strChoice;
		cin.ignore();
		Operate(strChoice,StudentList);
	}while(strChoice!="0");
	cout<<"\n\n\t��ӭ�ٴ�ʹ��ѧ���ɼ�����ϵͳ\n\n";
	return 0;
}


