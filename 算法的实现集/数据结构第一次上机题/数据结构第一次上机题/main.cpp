#include<iostream>
#include <algorithm>
using namespace std;
//顺序表的实现
template<class T,int MaxSize>
class SeqList {
private:
	T data[MaxSize];
	int length;
public:
	SeqList();
	SeqList(T a[], int n);
	void PrintSeqList();
    //归并两个有序（升序）顺序表（先判断是否是有序，若无序则先进行排序）
    friend SeqList<T, MaxSize> MergeSeqLists( SeqList<T, MaxSize>& list1,  SeqList<T, MaxSize>& list2)
    {
        // 检查顺序表是否已经有序，若无序则排序
        bool isList1Sorted = is_sorted(list1.data, list1.data + list1.length);
        bool isList2Sorted = is_sorted(list2.data, list2.data + list2.length);
        if (!isList1Sorted)
            sort(list1.data, list1.data + list1.length);
        if (!isList2Sorted)
            sort(list2.data, list2.data + list2.length);
        SeqList<T, MaxSize> mergedList;
        int i = 0; // 指向 list1 的指针
        int j = 0; // 指向 list2 的指针
        // 归并两个顺序表，直到其中一个顺序表遍历完
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
        // 将剩余未遍历的元素添加到合并后的顺序表中
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
//顺序表无参构造函数
template<class T,int MaxSize>
SeqList<T, MaxSize>::SeqList()
{
	length = 0;
}
//顺序表有参构造函数
template<class T, int MaxSize>
SeqList<T, MaxSize>::SeqList(T a[], int n)
{
	if (n > MaxSize)
	{
		cerr << "参数非法";
		exit(1);
	}
	for (int i = 0; i < n; i++)
	{
		data[i] = a[i];
	}
	length = n;
}
//顺序表的遍历打印
template<class T, int MaxSize>
void SeqList<T, MaxSize>::PrintSeqList()
{
	for (int i = 0; i < length; i++)
	{
		cout << data[i] << endl;
	}
}

//链表的实现
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
//链表的无参构造函数
template<class T>
LinkList<T>::LinkList() {
    head = new Node<T>;
    head->next = NULL;
}
//链表的有参构造函数
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
//链表的遍历打印
template<class T>
void LinkList<T>::PrintLinkList() {
    Node<T>* p = head->next;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
//链表是否有序的判断
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
//链表的析构函数
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
//合并
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
//main测试函数
int main() {
    int choice;
    cout << "菜单：" << endl;
    cout << "1. 测试顺序表（SeqList）" << endl;
    cout << "2. 测试链表（LinkList）" << endl;
    cout << "0. 退出" << endl;

    while (true) {
        cout << "请输入您的选择：";
        cin >> choice;

        if (choice == 0) {
            break;
        }
        else if (choice == 1) {
            int n;
            cout << "请输入顺序表元素的个数：";
            cin >> n;

            if (n > 0) {
                int* arr = new int[n];
                cout << "请输入元素：";
                for (int i = 0; i < n; i++) {
                    cin >> arr[i];
                }

                SeqList<int, 100> seqList(arr, n);
                delete[] arr;

                cout << "顺序表创建成功！" << endl;

                int subChoice;
                cout << "顺序表操作：" << endl;
                cout << "1. 打印顺序表" << endl;
                cout << "2. 合并顺序表（如果无序归并后也会有序）" << endl;
                cout << "0. 返回" << endl;

                while (true) {
                    cout << "请输入您的选择：";
                    cin >> subChoice;

                    if (subChoice == 0) {
                        break;
                    }
                    else if (subChoice == 1) {
                        cout << "顺序表元素（请有序）：" << endl;
                        seqList.PrintSeqList();
                    }
                    else if (subChoice == 2) {
                        int m;
                        cout << "请输入第二个顺序表的元素个数：";
                        cin >> m;

                        if (m > 0) {
                            int* arr2 = new int[m];
                            cout << "请输入元素（请有序）：";
                            for (int i = 0; i < m; i++) {
                                cin >> arr2[i];
                            }

                            SeqList<int, 100> seqList2(arr2, m);
                            delete[] arr2;

                            SeqList<int, 100> mergedList = MergeSeqLists(seqList, seqList2);

                            cout << "合并后的顺序表元素：" << endl;
                            mergedList.PrintSeqList();
                        }
                        else {
                            cout << "无效的元素个数！" << endl;
                        }
                    }
                    else {
                        cout << "无效的选择！请重试。" << endl;
                    }
                }
            }
            else {
                cout << "无效的元素个数！" << endl;
            }
        }
        else if (choice == 2) {
            int n;
            cout << "请输入链表元素的个数：";
            cin >> n;

            if (n > 0) {
                int* arr = new int[n];
                cout << "请输入元素（请有序）：";
                for (int i = 0; i < n; i++) {
                    cin >> arr[i];
                }

                LinkList<int> linkList(arr, n);
                delete[] arr;

                cout << "链表创建成功！" << endl;

                int subChoice;
                cout << "链表操作：" << endl;
                cout << "1. 打印链表" << endl;
                cout << "2. 合并链表" << endl;
                cout << "0. 返回" << endl;

                while (true) {
                    cout << "请输入您的选择：";
                    cin >> subChoice;

                    if (subChoice == 0) {
                        break;
                    }
                    else if (subChoice == 1) {
                        cout << "链表元素：";
                        linkList.PrintLinkList();
                    }
                    else if (subChoice == 2) {
                        int m;
                        cout << "请输入第二个链表的元素个数：";
                        cin >> m;

                        if (m > 0) {
                            int* arr2 = new int[m];
                            cout << "请输入元素（请有序）：";
                            for (int i = 0; i < m; i++) {
                                cin >> arr2[i];
                            }

                            LinkList<int> linkList2(arr2, m);
                            delete[] arr2;

                            MergeLinkLists(linkList, linkList2);

                            cout << "合并后的链表元素：";
                            linkList.PrintLinkList();
                        }
                        else {
                            cout << "无效的元素个数！" << endl;
                        }
                    }
                    else {
                        cout << "无效的选择！请重试。" << endl;
                    }
                }
            }
            else {
                cout << "无效的元素个数！" << endl;
            }
        }
        else {
            cout << "无效的选择！请重试。" << endl;
        }
    }

    return 0;
}