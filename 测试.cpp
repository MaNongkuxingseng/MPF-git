
#if 0

#include<stdio.h>
#include <iostream>
using namespace std;
int add(int x=5,int y=6);
int main()
{
	printf("hello world!\n");
	add();
	// 	int a=1;
	// 	int b=2;
	// 	const int *p=&a;
	// 	int * const q=&b;
	// 	*p = 3;
	// 	*q = 3;
	int a[] = {1,2,3,4};
	int *p = &a[0];
	int *q = &a[4];
// 	p = reinterpret_cast<char*>(p);
// 	q = reinterpret_cast<char*>(q);
// 	p = (char*)p;
// 	q = (char*)q;
	cout<<sizeof(int)<<endl;
	printf("%x\n",q-p);
	cout<<(q-p)<<endl;
	cout<<(q-p)/sizeof(int)<<endl;
	p = a;
	q = &a[0];
	cout<<sizeof(p)/sizeof(q)<<endl;

	int *pn = new int;
	*p = 3;
	cout<<*p<<endl;

	 return 0;
}

int add(int x/* =5 */,int y/* =6 */)	//��������Ҳ�����������ɶ��Ѵ�Ĭ�ϲ����ĺ����ظ�����Ĭ�ϲ���.
//int add(int x=5,int y=6)
{
	return x+y;
}
#endif




#if 0

#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> INTVECTOR;//�Զ�������INTVECTOR

//����vector�����Ĺ���
void main(void)
{
	//vec1�����ʼΪ��
	INTVECTOR vec1;

	//vec2���������10��ֵΪ6��Ԫ��
	INTVECTOR vec2(10,6);

	//vec3���������3��ֵΪ6��Ԫ�أ���������
	INTVECTOR vec3(vec2.begin(),vec2.begin()+3);

	//����һ����Ϊi��˫�������
	INTVECTOR::iterator i;

	//��ǰ�����ʾvec1�е�����
	cout<<"vec1.begin()--vec1.end():"<<endl;
	for (i =vec1.begin(); i !=vec1.end(); ++i)
		cout << *i << " ";
	cout << endl;

	//��ǰ�����ʾvec2�е�����
		cout<<"vec2.begin()--vec2.end():"<<endl;
	for (i =vec2.begin(); i !=vec2.end(); ++i)
		cout << *i << " ";
	cout << endl;

	//��ǰ�����ʾvec3�е�����
	cout<<"vec3.begin()--vec3.end():"<<endl;
	for (i =vec3.begin(); i !=vec3.end(); ++i)
		cout << *i << " ";
	cout << endl;

	//������ӺͲ����Ա������vector��֧�ִ�ǰ����
	vec1.push_back(2);//�Ӻ������һ����Ա
	vec1.push_back(4);
	vec1.insert(vec1.begin()+1,5);//��vec1��һ����λ���ϲ����Ա5

	//��vec1��һ��λ�ÿ�ʼ����vec3�����г�Ա
	vec1.insert(vec1.begin()+1,vec3.begin(),vec3.end());
	cout<<"after push() and insert() now the vec1 is:" <<endl;
	for (i =vec1.begin(); i !=vec1.end(); ++i)
		cout << *i << " ";
	cout << endl;

	//���Ը�ֵ��Ա����
	vec2.assign(8,1); // ���¸�vec2��ֵ��8����Ա�ĳ�ʼֵ��Ϊ1
	cout<<"vec2.assign(8,1):" <<endl;
	for (i =vec2.begin(); i !=vec2.end(); ++i)
	cout << *i << " ";
	cout << endl;

	//���������ຯ��
	cout<<"vec1.front()="<<vec1.front()<<endl;//vec1�������Ա
	cout<<"vec1.back()="<<vec1.back()<<endl;//vec1�����һ����Ա
	cout<<"vec1. at(4)="<<vec1. at(4)<<endl;//vec1�ĵ������Ա
	cout<<"vec1[4]="<<vec1[4]<<endl;

	//�����Ƴ���ɾ��
	vec1.pop_back();//�����һ����Ա�Ƴ�vec1
	vec1.erase(vec1.begin()+1,vec1.end()-2);//ɾ����Ա
	cout<<"vec1.pop_back() and vec1.erase():" <<endl;
	for (i =vec1.begin(); i !=vec1.end(); ++i)
		cout << *i << " ";
	cout << endl;

	//��ʾ���е�״̬��Ϣ
	cout<<"vec1.size(): "<<vec1.size()<<endl;//��ӡ��Ա����
	cout<<"vec1.empty(): "<<vec1.empty()<<endl;//�ж�vec1�Ƿ�Ϊ�գ����򷵻�1�����շ���0
}
#endif

#if 1
#include <iostream>
#include <IOMANIP>
using namespace std;
int main()
{
	int Num ;
	cin>>Num;
	while (Num<2)
	{
		cout<<"Please enter an integer greater than 2"<<endl;
		cin>>Num;
	}
	
	const int N = Num*Num;
	int index = 0;
	int Row_Max = Num-1;
	int Colunm_Max = Num-1;
	int Row_Min = 0;
	int Column_Min = 0;	
	int** ppn = new int*[Num];
	for(int k = 0; k < Num; k++)
		ppn[k] = new int[Num];
// 	cout<<sizeof(ppn)<<endl;
	int r = 0;
	int c = 0;
	while ((Colunm_Max > Column_Min) || Colunm_Max == Column_Min)
	{
		for (r=Row_Min,c=Column_Min;c<Colunm_Max+1;c++)
		{
			ppn[r][c] = ++index;
		}
		Row_Min++;
		for (r=Row_Min,c=Colunm_Max;r<Row_Max+1;r++)
		{
			ppn[r][c] = ++index;
		}
		Colunm_Max--;
		for (r=Row_Max,c=Colunm_Max;c+1>Column_Min;c--)
		{
			ppn[r][c] = ++index;
		}
		Row_Max--;
		for (r=Row_Max,c=Column_Min;r+1>Row_Min;r--)
		{
			ppn[r][c] = ++index;
		}
		Column_Min++;
		cout<<index<<endl;
	}
	
	for (int i=0;i<Num;i++)
	{
		for (int j=0;j<Num;j++)
		{
			//cout<<left;
			cout<<setw(5)<<ppn[i][j];
		}
		cout<<endl;
	}
	

	return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;
int** SnakeArry(const int Integer)
{
	while (Integer<2)
	{
		cout<<"Please enter an integer greater than 2"<<endl;
		cin>>Integer;
	}
	static int** ppn = new int*[Integer];
	for (int k=0;k<Integer;k++)
	{
		ppn[k] = new int[Integer];
	}
	int* pn = &ppn[0][0];
	int row=0,column=0;
	int row_max = Integer-1;
	int column_max = Integer-1;
	int row_min = 0;
	int column_min = 0;
	int columns = Integer;
	int index = 0;
	while (column_max != column_min)
	{
		for (row=row_min;column=column_min;column<Integer+1;column++)
		{
			*(pn+row*columns+column) = ++index;
		}
		for ()
		{
		}
	}
	return ppn;
}
int main()
{
	int Num;
	cin>>Num;
	SnakeArry(Num);

	return 0;
	
// 	enum N{PHALANX};
// 	N size;
// 	size = static_cast<N> (Num);
// 	int arry[size][size];
}
#endif
