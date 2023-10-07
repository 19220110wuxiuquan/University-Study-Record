#include<iostream>
#include <algorithm>
using namespace std;
//˳����ʵ��
template<class T,int MaxSize>
class SeqList {
private:
	T data[MaxSize];
	int length;
public:
	SeqList();
	SeqList(T a[], int n);
	void PrintSeqList();
    //�鲢������������˳������ж��Ƿ����������������Ƚ�������
    friend SeqList<T, MaxSize> MergeSeqLists( SeqList<T, MaxSize>& list1,  SeqList<T, MaxSize>& list2)
    {
        // ���˳����Ƿ��Ѿ�����������������
        bool isList1Sorted = is_sorted(list1.data, list1.data + list1.length);
        bool isList2Sorted = is_sorted(list2.data, list2.data + list2.length);
        if (!isList1Sorted)
            sort(list1.data, list1.data + list1.length);
        if (!isList2Sorted)
            sort(list2.data, list2.data + list2.length);
        SeqList<T, MaxSize> mergedList;
        int i = 0; // ָ�� list1 ��ָ��
        int j = 0; // ָ�� list2 ��ָ��
        // �鲢����˳���ֱ������һ��˳��������
        while (i < list1.length && j < list2.length)
        {
            if (list1.data[i] <= list2.data[j])
            {
                mergedList.data[mergedList.length++] = list1.data[i++];
            }
            else
            {
                mergedList.data[mergedList.length++] = list2.data[j++];
            }
        }
        // ��ʣ��δ������Ԫ����ӵ��ϲ����˳�����
        while (i < list1.length)
        {
            mergedList.data[mergedList.length++] = list1.data[i++];
        }
        while (j < list2.length)
        {
            mergedList.data[mergedList.length++] = list2.data[j++];
        }
        return mergedList;
    };
};
//˳����޲ι��캯��
template<class T,int MaxSize>
SeqList<T, MaxSize>::SeqList()
{
	length = 0;
}
//˳����вι��캯��
template<class T, int MaxSize>
SeqList<T, MaxSize>::SeqList(T a[], int n)
{
	if (n > MaxSize)
	{
		cerr << "�����Ƿ�";
		exit(1);
	}
	for (int i = 0; i < n; i++)
	{
		data[i] = a[i];
	}
	length = n;
}
//˳���ı�����ӡ
template<class T, int MaxSize>
void SeqList<T, MaxSize>::PrintSeqList()
{
	for (int i = 0; i < length; i++)
	{
		cout << data[i] << endl;
	}
}

//�����ʵ��
template<class T>
struct Node {
    T data;
    Node<T>* next;
};

template<class T>
class LinkList {
    Node<T>* head;
public:
    LinkList();
    LinkList(T a[], int n);
    void PrintLinkList();
    template<class U> friend void MergeLinkLists(LinkList<U>& L1, LinkList<U>& L2);
    bool IsSorted();
    ~LinkList();
};
//������޲ι��캯��
template<class T>
LinkList<T>::LinkList() {
    head = new Node<T>;
    head->next = NULL;
}
//������вι��캯��
template<class T>
LinkList<T>::LinkList(T a[], int n) {
    head = new Node<T>;
    Node<T>* rear = head;
    for (int i = 0; i < n; i++) {
        Node<T>* s = new Node<T>;
        s->data = a[i];
        rear->next = s;
        rear = s;
    }
    rear->next = NULL;
}
//����ı�����ӡ
template<class T>
void LinkList<T>::PrintLinkList() {
    Node<T>* p = head->next;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
//�����Ƿ�������ж�
template<class T>
bool LinkList<T>::IsSorted() {
    Node<T>* p = head->next;
    while (p && p->next) {
        if (p->data > p->next->data) {
            return false;
        }
        p = p->next;
    }
    return true;
}
//�������������
template<class T>
LinkList<T>::~LinkList() {
    Node<T>* p = head;
    while (p) {
        Node<T>* q = p;
        p = p->next;
        delete q;
    }
    head = NULL;
}
//�ϲ�
template<class T>
void MergeLinkLists(LinkList<T>& L1, LinkList<T>& L2) {
    Node<T>* p1 = L1.head->next;
    Node<T>* p2 = L2.head->next;
    Node<T>* p3 = L1.head;

    while (p1 != NULL && p2 != NULL) {
        if (p1->data < p2->data) {
            p3->next = p1;
            p1 = p1->next;
        }
        else {
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }

    if (p1 != NULL)
        p3->next = p1;
    if (p2 != NULL)
        p3->next = p2;

    L2.head->next = NULL;
}
//main���Ժ���
int main() {
    int choice;
    cout << "�˵���" << endl;
    cout << "1. ����˳���SeqList��" << endl;
    cout << "2. ��������LinkList��" << endl;
    cout << "0. �˳�" << endl;

    while (true) {
        cout << "����������ѡ��";
        cin >> choice;

        if (choice == 0) {
            break;
        }
        else if (choice == 1) {
            int n;
            cout << "������˳���Ԫ�صĸ�����";
            cin >> n;

            if (n > 0) {
                int* arr = new int[n];
                cout << "������Ԫ�أ�";
                for (int i = 0; i < n; i++) {
                    cin >> arr[i];
                }

                SeqList<int, 100> seqList(arr, n);
                delete[] arr;

                cout << "˳������ɹ���" << endl;

                int subChoice;
                cout << "˳��������" << endl;
                cout << "1. ��ӡ˳���" << endl;
                cout << "2. �ϲ�˳����������鲢��Ҳ������" << endl;
                cout << "0. ����" << endl;

                while (true) {
                    cout << "����������ѡ��";
                    cin >> subChoice;

                    if (subChoice == 0) {
                        break;
                    }
                    else if (subChoice == 1) {
                        cout << "˳���Ԫ�أ������򣩣�" << endl;
                        seqList.PrintSeqList();
                    }
                    else if (subChoice == 2) {
                        int m;
                        cout << "������ڶ���˳����Ԫ�ظ�����";
                        cin >> m;

                        if (m > 0) {
                            int* arr2 = new int[m];
                            cout << "������Ԫ�أ������򣩣�";
                            for (int i = 0; i < m; i++) {
                                cin >> arr2[i];
                            }

                            SeqList<int, 100> seqList2(arr2, m);
                            delete[] arr2;

                            SeqList<int, 100> mergedList = MergeSeqLists(seqList, seqList2);

                            cout << "�ϲ����˳���Ԫ�أ�" << endl;
                            mergedList.PrintSeqList();
                        }
                        else {
                            cout << "��Ч��Ԫ�ظ�����" << endl;
                        }
                    }
                    else {
                        cout << "��Ч��ѡ�������ԡ�" << endl;
                    }
                }
            }
            else {
                cout << "��Ч��Ԫ�ظ�����" << endl;
            }
        }
        else if (choice == 2) {
            int n;
            cout << "����������Ԫ�صĸ�����";
            cin >> n;

            if (n > 0) {
                int* arr = new int[n];
                cout << "������Ԫ�أ������򣩣�";
                for (int i = 0; i < n; i++) {
                    cin >> arr[i];
                }

                LinkList<int> linkList(arr, n);
                delete[] arr;

                cout << "�������ɹ���" << endl;

                int subChoice;
                cout << "���������" << endl;
                cout << "1. ��ӡ����" << endl;
                cout << "2. �ϲ�����" << endl;
                cout << "0. ����" << endl;

                while (true) {
                    cout << "����������ѡ��";
                    cin >> subChoice;

                    if (subChoice == 0) {
                        break;
                    }
                    else if (subChoice == 1) {
                        cout << "����Ԫ�أ�";
                        linkList.PrintLinkList();
                    }
                    else if (subChoice == 2) {
                        int m;
                        cout << "������ڶ��������Ԫ�ظ�����";
                        cin >> m;

                        if (m > 0) {
                            int* arr2 = new int[m];
                            cout << "������Ԫ�أ������򣩣�";
                            for (int i = 0; i < m; i++) {
                                cin >> arr2[i];
                            }

                            LinkList<int> linkList2(arr2, m);
                            delete[] arr2;

                            MergeLinkLists(linkList, linkList2);

                            cout << "�ϲ��������Ԫ�أ�";
                            linkList.PrintLinkList();
                        }
                        else {
                            cout << "��Ч��Ԫ�ظ�����" << endl;
                        }
                    }
                    else {
                        cout << "��Ч��ѡ�������ԡ�" << endl;
                    }
                }
            }
            else {
                cout << "��Ч��Ԫ�ظ�����" << endl;
            }
        }
        else {
            cout << "��Ч��ѡ�������ԡ�" << endl;
        }
    }

    return 0;
}