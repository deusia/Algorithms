#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
using namespace std;     //用命名空间中的std定义
class CData              //定义结点基类           
{
public:
	CData(){};
	virtual int Compare(CData &)=0;
	virtual void Show()=0;
    virtual ~CData(){};
};
class CNode              //定义结点基类
{
private:
	CData *pData;        //用于指向数据类的指针
	CNode *pNext;        //用于指向链表的后向指针
public:
	CNode(){pData=0;pNext=0;};      //结点构造函数
    CNode(CNode &node)              //用于拷贝的构造函数
	{
		pData=node.pData;
		pNext=node.pNext;
	}
	void InputData(CData *pdata){pData=pdata;}      //输入数据
	void ShowNode(){pData->Show();}
	CData *GetData(){return pData;}
	friend class CList;             //定义链表类为友元类
};
class CList
{
		CNode *pHead;               //链表头结点指针
public:
	CList(){pHead=0;}
	~CList(){DeleStudentist();}
	void AddNode(CNode * pnode);    //在首部添加结点
	CNode *DeleteNode(CNode *);     //删除一个指定的结点，返回该结点的指针
	CNode *LookUp(CData &);         //查找一个指定的数据，返回该数据所在结点在链表中的指针，若未找到返回0
	void ShowList();                //打印整个链表
	void DeleStudentist();              //删除整个链表
	CNode *GetListHead(){return pHead;}          //返回链表首结点
	CNode *GetListNextNode(CNode *pnode);        //返回链表指定结点的下一个结点
};
CNode *CList::GetListNextNode(CNode *pnode)       //返回链表指定结点的下一个结点
{
	CNode *p1=pnode;
	return p1->pNext;
};
void CList::AddNode(CNode *pnode)       //在首部添加结点
{
	if(pHead==0)         //如果是空链表，插入的结点是唯一的结点
	{
		pHead=pnode;
		pnode->pNext=0;
		return;
	}
	else             //否则，插入到链表首部
	{
		pnode->pNext=pHead;
		pHead=pnode;
	}
};
CNode *CList::DeleteNode(CNode *pnode)         //删除一个指定的结点，返回该结点的指针
{
	CNode *p1,*p2;
	p1=pHead;               //指向首结点
	while(p1!=pnode&&p1->pNext!=0)        //寻找要删除的结点
	{
		p2=p1;              //结点指针p2始终在p1的后面
		p1=p1->pNext;
	}
	if(p1==pHead)          //如果要删除的是首结点
	{
		pHead=pHead->pNext;      //将首结点后移
		return pnode;
	}
	p2->pNext=p1->pNext;       //p1指向被删除的结点，将p2结点与p1后面的结点连接起来
	return pnode;
}
CNode *CList::LookUp(CData &data)      //查找一个指定的数据，返回该数据所在结点在链表中的指针，若未找到返回0
{
	CNode *p1=pHead;
	while(p1)         //从头结点开始查找
	{
		if(p1->pData->Compare(data)==0)
			return p1;               //找到后返回结点指针
		p1=p1->pNext;
	}
	return 0;              //搜索完整个链表之后，如果找不到，返回空指针0
}
void CList::ShowList()     //打印整个链表数据
{
	CNode *p1=pHead;
	while(p1)
	{
		p1->pData->Show();
		p1=p1->pNext;
	}
}
void CList::DeleStudentist()       //删除整个链表结点
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
class CStudentRecord:public CData       //学生信息记录，为数据基类的共有派生类
{
private:
	char szName[20];     //学生信息数据，学号、姓名、性别、成绩
	char szNumber[20];
	char szSex[20];
	char szChengji[20];
public:
	CStudentRecord(){strcpy(szName,"\0");strcpy(szNumber,"\0");strcpy(szSex,"\0");strcpy(szChengji,"\0");}    //构造函数
    CStudentRecord(char *name ,char *number,char *sex,char *chengji)   //构造函数
	{ 
		strcpy(szName,name);
		strcpy(szNumber,number);
		strcpy(szSex,sex);
		strcpy(szChengji,chengji);
	}
	void SetRecord(char * name,char *number,char *sex,char *chengji)    //输入数据函数
	{	
		strcpy(szName,name);
		strcpy(szNumber,number);
		strcpy(szSex,sex);
		strcpy(szChengji,chengji);
	}
	int Compare (CData &);    //比较函数，比较学号
		void Show();          //打印数据函数
};
int CStudentRecord::Compare(CData &data)     //比较学号，供查找用，比较结果为1、0、-1
{
	 CStudentRecord &temp=( CStudentRecord &)data;
	 return strcmp(szName,temp.szName);
}
void  CStudentRecord::Show()       //打印一个结点的数据
{
	cout<<setw(15)<<szName<<setw(15)<<szNumber<<setw(15)<<szSex<<setw(15)<<szChengji<<endl;
}
void AddRecord(CList &StudentList)     //将记录添加到链表中
{
	CNode *pNode;
	CStudentRecord *pStudent;
	char szName[20],szNumber[20],szSex[20],szChengji[20];
	cout<<"输入姓名（输入0结束）： ";
	//cin.ignore();
	cin.getline(szName,20);
	while(strcmp(szName,"0"))
	{
		cout<<"输入学号： ";
		cin.getline(szNumber,20);
		cout<<"输入成绩: ";
        cin.getline(szChengji,20);
        cout<<"输入性别: ";
		cin.getline(szSex,20);
		pStudent=new CStudentRecord;                 //生成新的数据类对象
		pStudent->SetRecord(szName,szNumber,szSex,szChengji);    //数据类对象赋值
		pNode=new CNode;                  //生成新的结点
		pNode->InputData(pStudent);         //结点赋值                         
		StudentList.AddNode(pNode);        //结点加入链表
		cout<<"输入姓名（输入0结束）： ";		
		cin.getline(szName,20);
	}
	cout<<endl<<endl;
}
void DisplayRecord(CList &StudentList)       //显示全部链表数据
{
	cout<<setw(15)<<"姓名"<<setw(15)<<"学号"<<setw(15)<<"性别"<<setw(15)<<"成绩"<<endl;
	StudentList.ShowList();
	cout<<endl<<endl;
}
void LookUpRecord(CList &StudentList)        //按照学号查找学生数据
{
	CNode *pLook;
	char szName[20];
	cout<<"输入您需要查找的姓名（输入0结束）";
	cin.getline(szName,20);
	while(strcmp(szName,"0"))
	{
		CStudentRecord Studente(szName,"0","0","0");    //生成结点
		
		pLook=StudentList.LookUp(Studente);        //查找指定结点数据 
		if(pLook)
		{
			cout<<"在系统中找到"<<szName<<",内容是: "<<endl;
			pLook->ShowNode();
		}
		else
			cout<<"在系统中查找不到"<<szName<<"."<<endl;
		cout<<"输入您要查找的姓名（输入0结束）";
			cin.getline(szName,20);
	}
	cout<<endl<<endl;
	system("pause");
}
void DeleteRecord(CList &StudentList)      //在链表中删除指定结点数据
{
	CNode *pLook;
	char szName[20];
	cout<<"输入您要删除的姓名（输入0结束）";
	cin.getline(szName,20);
	while(strcmp(szName,"0"))
	{
		CStudentRecord Studente(szName,"0","0","0");
		pLook=StudentList.LookUp(Studente);
		if(pLook)        //删除时应先查找出结点
		{
			cout<<"在系统中找到"<<szName<<",内容是: "<<endl;
			pLook->ShowNode();
			StudentList.DeleteNode(pLook);
			cout<<szName<<"的资料已删除"<<endl;
			delete pLook;
		}
		else
			cout<<"在系统中找不到"<<szName<<"."<<endl;
		cout<<"输入您需要删除的姓名（输入0结束）"<<endl;
		cin.getline(szName,20);
	}
	cout<<endl<<endl;
}
void AlterRecord (CList &StudentList)
{
	CNode *pLook;
	char szName[20];
	cout<<"输入您需要修改的学生姓名（输入0结束）";
	cin.getline(szName,20);
	while(strcmp(szName,"0"))
	{
		CStudentRecord Studente(szName,"0","0","0");
		pLook=StudentList.LookUp(Studente);
		if(pLook)
		{
			cout<<"在系统中找到"<<szName<<",内容是: "<<endl;
			pLook->ShowNode();
			StudentList.DeleteNode(pLook);
			cout<<szName<<"的资料已删除"<<endl;
			delete pLook;
			{
	CNode *pNode;
	CStudentRecord *pStudent;
	char szName[20],szNumber[20],szSex[20],szChengji[20];
	cout<<"输入姓名（输入0结束）： ";
	//cin.ignore();
	cin.getline(szName,20);
	while(strcmp(szName,"0"))
	{
		cout<<"输入学号： ";
		cin.getline(szNumber,20);
		cout<<"输入成绩: ";
        cin.getline(szChengji,20);
        cout<<"输入性别: ";
		cin.getline(szSex,20);
		pStudent=new CStudentRecord;                 //生成新的数据类对象
		pStudent->SetRecord(szName,szNumber,szSex,szChengji);    //数据类对象赋值
		pNode=new CNode;                  //生成新的结点
		pNode->InputData(pStudent);         //结点赋值                         
		StudentList.AddNode(pNode);        //结点加入链表
		cout<<"输入姓名（输入0结束）： ";		
		cin.getline(szName,20);
	}
	cout<<endl<<endl;
}
		}
		else
			cout<<"在系统中找不到"<<szName<<"."<<endl;
		cout<<"重新输入学生学号（输入0结束）"<<endl;
		cin.getline(szName,20);
	}
	cout<<endl<<endl;
}
void StoreFile(CList &StudentList)         //将链表中的数据保存在文件中
{
	ofstream outfile("StudentEOHONE.DAT",ios::binary);
	if(! outfile)
	{
		cout<<"数据文件打开错误，没有将数据存入文件！\n";
		return;
	}
	CNode *pnode;
	CStudentRecord *pStudent;
	string strName,strNumber;
	pnode=StudentList.GetListHead();        //取出链表首结点指针
	while(pnode)
	{
		pStudent=(CStudentRecord *)pnode->GetData();       //返回结点指向的数据域指针
		outfile.write((char *)pStudent,sizeof(CStudentRecord));    //将数据域写入文件
		pnode=StudentList.GetListNextNode(pnode);       //取下一结点指针
	}
	outfile.close();
}
void Operate(string &strChoice,CList &StudentList)       //根据主菜单选项进行操作
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
			cout<<"输入错误，请重新输入你的选择：";
}
void LoadFile(CList &StudentList)           //在程序开始首先查找有无数据文件,找到后读取文件数据
{
	ifstream infile("StudentEOHONE.DAT",ios::binary);
	if(!infile)
	{
		cout<<"没有数据文件！\n\n";
		return ;
	}
	CNode *pNode;
	CStudentRecord *pStudent;
	while(! infile.eof())
	{
		pStudent=new CStudentRecord;    //定义数据域对象
		infile.read ((char *)pStudent,sizeof(CStudentRecord));
		pNode=new CNode;
		pNode->InputData(pStudent);      //数据域对象内容生成结点
		StudentList.AddNode(pNode);      //将结点加入链表
	}
	StudentList.DeleteNode(pNode);        //由于文件的关系,多读了一次,所以将首结点删除
	infile.close();
}
int main(void)
{
	CList StudentList;        //定义链表类的对象
	system("cls");
	cout<<"\t欢迎进学生成绩管理系统\n";
	LoadFile(StudentList);     //从文件中输入数据
	string strChoice;      //接受主菜单选项
	do
	{
		cout<<"\t1. 添加学生成绩纪录\n";
	    cout<<"\t2. 显示学生成绩记录\n";
	    cout<<"\t3. 查找学生成绩记录\n";
	    cout<<"\t4. 删除学生成绩记录\n";
		cout<<"\t5. 修改学生成绩记录\n";
	    cout<<"\t0. 退出学生成绩管理系统\n";
		cout<<"请输入你的选择：";
		cin>>strChoice;
		cin.ignore();
		Operate(strChoice,StudentList);
	}while(strChoice!="0");
	cout<<"\n\n\t欢迎再次使用学生成绩管理系统\n\n";
	return 0;
}


