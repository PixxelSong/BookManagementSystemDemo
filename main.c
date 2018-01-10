#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 999
//����ͼ�鹹����
typedef struct bookInformation{
    int logInNum;//��¼��
    char bookName[N];//����
    char authorName[N];//������
    int sortNum;//�����
    char press[N];//���浥λ
    int publishedData;//����ʱ��
    int price;//�۸�
    struct bookInformation * next;
} books;

/*ͼ����Ϣ¼��
 *       ���
 *       ɾ��
 *       �޸�
 * ͼ����Ϣ��ѯ(��������ѯ �����߲�ѯ)*/

void initialize(books * p);
void output(books *p);
void input();
void searchByBookName(books * p);
void searchByAuthorName(books * p);
void savedInstance(books * p);
void change(books * p);
void delete();


int main(void){
    //����ͼ������
    books * p;
    p=malloc(sizeof(books));
    p->next=NULL;
    printf("      ------ͼ���������ɹ�------\n");
    initialize(p);p=p->next;    //��ʼ������
    printf("--- -------------------------------- ---\n"
                   "|   |*******ͼ����Ϣ����ϵͳ*******|   |\n"
                   "|   |------------------------------|   |\n"
                   "|           1  ͼ����Ϣ¼��            |\n"
                   "|           2  ͼ����Ϣ���            |\n"
                   "|           3  ��ͼ��������            |\n"
                   "|           4  ������������            |\n"
                   "|           5  ͼ����Ϣ�޸�            |\n"
                   "|           6  ͼ����Ϣɾ��            |\n"
                   "|           0  �˳�����ϵͳ            |\n"
                   "|--------------------------------------|\n");
    int a;
    printf("            �������ѡ���� ");
    scanf("%d",&a);
    switch (a){
        case 1:system("cls");input();
            break;
        case 2:  system("cls"); output(p);
            break;
        case 3:system("cls");searchByBookName(p);
            break;
        case 4:system("cls");searchByAuthorName(p);
            break;
        case 5: system("cls");change(p);
            break;
        case 6:system("cls");delete(p);
            break;
        case 0:
            return 0;
        default:printf("\n------------��������ȷ��ѡ��------------\n");
            printf("\n-----------��������ص����˵�-----------\n");
            getchar();getchar();
            system("cls");/*����*/
            main();
    }
}
//��ȡ�ļ���Ϣ ��ʼ��ͼ������
void initialize(books * p){
    books  temp;
    FILE *file;
    file=fopen("d:\\bookInformation.txt","r");
    while ((fscanf(file,"%d %s %s %d %s %d %d",&temp.logInNum,temp.bookName,temp.authorName,&temp.sortNum,temp.press,&temp.publishedData,&temp.price))!=EOF){
        books * q;
        q=malloc(sizeof(books));
        q->next=NULL;
        q->logInNum=temp.logInNum;
        strcpy(q->bookName,temp.bookName);
        strcpy(q->authorName,temp.authorName);
        q->sortNum=temp.sortNum;
        strcpy(q->press,temp.press);
        q->publishedData=temp.publishedData;
        q->price=temp.price;
        p->next=q;
        p=q;
    }
    fclose(file);
    printf("      ---------��ʼ���ɹ�---------\n");
}
//ͼ����Ϣ¼�빦��
void input(){
    books * a=NULL;
    a=malloc(sizeof(books));
    printf("�����¼��:");
    scanf("%d",&a->logInNum);
    printf("\n��������:");
    scanf("%s",a->bookName);
    printf("\n����������:");
    scanf("%s",a->authorName);
    printf("\n��������:");
    scanf("%d",&a->sortNum);
    printf("\n���������:");
    scanf("%s",a->press);
    printf("\n�������ʱ��:");
    scanf("%d",&a->publishedData);
    printf("\n����۸�:");
    scanf("%d",&a->price);
    FILE *file;
    file=fopen("d:\\bookInformation.txt","a");
    fprintf(file, "%d %s %s %d %s %d %d\n", a->logInNum, a->bookName, a->authorName, a->sortNum, a->press, a->publishedData, a->price);
    fclose(file);
    printf("\n��ӳɹ�\n\n");
    printf("��������ص����˵�");
    getchar();getchar();
    system("cls");
    main();
}
//ͼ����Ϣ�������
void output(books *p){
    while (p!=NULL){
        printf("��¼��:%d  ����:%s  ����:%s  �����:%d  ������:%s  ��������:%d  �۸�:%d\n", p->logInNum,p->bookName,p->authorName, p->sortNum,p->press, p->publishedData, p->price);
        p=p->next;
    }
    printf("\n-----------������-----------\n");
    printf("\n------��������ص����˵�------\n");
    getchar();getchar();
    system("cls");
    main();
}
//��������ѯ����
void searchByBookName(books * p){
    char name[N];
    printf("����Ҫ���ҵ�����:");
    scanf("%s",name);
    while (p!=NULL){
        if (strcmp(p->bookName,name)==0){
            printf("\n��¼��:%d  ����:%s  ����:%s  �����:%d  ������:%s  ��������:%d  �۸�:%d\n", p->logInNum,p->bookName,p->authorName, p->sortNum,p->press, p->publishedData, p->price);
            printf("\n------��������ص����˵�------\n");
            getchar();getchar();
            system("cls");
            main();
        }
        p=p->next;
    }
    printf("\n-------�Ҳ�����Ҫ�ҵ���-------\n");
    printf("\n------��������ص����˵�------\n");
    getchar();getchar();
    system("cls");
    main();
}
//�����߲�ѯ
void searchByAuthorName(books * p){
    char author[N];
    printf("����Ҫ���ҵ�����:");
    scanf("%s",author);
    int a=0;
    while (p!=NULL){
        if (strcmp(p->authorName,author)==0){
            a++;
            printf("\n��¼��:%d  ����:%s  ����:%s  �����:%d  ������:%s  ��������:%d  �۸�:%d\n", p->logInNum,p->bookName,p->authorName, p->sortNum,p->press, p->publishedData, p->price);
            printf("\n������\n");
            printf("\n��������ص����˵�\n");
            getchar();
            getchar();
            system("cls");
            main();
        }
        p=p->next;
    }
    if(a==0){
        printf("\n------�Ҳ����������������------\n");
        printf("\n-------��������ص����˵�-------\n");
        getchar();
        getchar();
        system("cls");
        main();
    }
}
//���浱ǰ�����е�ͼ������
void savedInstance(books * p){
    remove("d:\\bookInformation.txt");
    FILE *file;
    file=fopen("d:\\bookInformation.txt","w");
    while (p!=NULL){
        fprintf(file,"%d %s %s %d %s %d %d\n", p->logInNum,p->bookName,p->authorName, p->sortNum,p->press, p->publishedData, p->price);
        p=p->next;
    }
    fclose(file);
}
//ͼ����Ϣ�޸�
void change(books * p){
    char name[N];
    printf("����Ҫ�޸ĵ�ͼ����:");
    scanf("%s",name);
    books * a;
    int x=0;
    a=p;
    while (p!=NULL){
        if(strcmp(name,p->bookName)==0){
            printf("\n�����޸ĺ�ĵ�¼��:");
            scanf("%d",&p->logInNum);
            getchar();
            printf("\n�����޸ĺ��������:");
            gets(p->authorName);
            printf("\n�����޸ĺ�ķ����:");
            scanf("%d",&p->sortNum);
            getchar();
            printf("\n�����޸ĺ�ĳ�����:");
            gets(p->press);
            printf("\n�����޸ĺ�ĳ���ʱ��:");
            scanf("%d",&p->publishedData);
            printf("\n�����޸ĺ�ļ۸�:");
            scanf("%d",&p->price);
            x++;
        }
        p=p->next;
    }
    savedInstance(a);
    if (x==0){
        printf("\n�Ҳ��������������\n");
    } else {
        printf("\n�޸ĳɹ�\n");
    }
    printf("\n��������ص����˵�\n");
    getchar();
    getchar();
    system("cls");
    main();
}
//ͼ����Ϣɾ��
void delete(){
getchar();
char name[N];
printf("------����Ҫɾ��������------\n");
gets(name);
int a=0;
books p;
FILE *file;
FILE *file1;
file=fopen("d:\\bookInformation.txt","r");file1=fopen("d:\\bookInformation1.txt","a");
fscanf(file,"%d %s %s %d %s %d %d",&p.logInNum,p.bookName,p.authorName,&p.sortNum,p.press,&p.publishedData,&p.price);
while (!feof(file)){
if(!strcmp(p.bookName,name)){
a++;
}
if(strcmp(p.bookName,name)){
fprintf(file1,"%d %s %s %d %s %d %d\n", p.logInNum,p.bookName,p.authorName, p.sortNum,p.press, p.publishedData, p.price);
}
fscanf(file,"%d %s %s %d %s %d %d",&p.logInNum,p.bookName,p.authorName,&p.sortNum,p.press,&p.publishedData,&p.price);
}
fclose(file);fclose(file1);
remove("d:\\bookInformation.txt");
rename("d:\\bookInformation1.txt","d:\\bookInformation.txt");
if(a!=0) {
printf("------ɾ���ɹ�------\n");
} else{
printf("------�Ҳ��������������------\n");
}
printf("\n------��������ص����˵�------\n");
getchar();
system("cls");
main();
}