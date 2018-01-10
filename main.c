#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 999
//创建图书构造体
typedef struct bookInformation{
    int logInNum;//登录号
    char bookName[N];//书名
    char authorName[N];//作者名
    int sortNum;//分类号
    char press[N];//出版单位
    int publishedData;//出版时间
    int price;//价格
    struct bookInformation * next;
} books;

/*图书信息录入
 *       输出
 *       删除
 *       修改
 * 图书信息查询(按书名查询 按作者查询)*/

void initialize(books * p);
void output(books *p);
void input();
void searchByBookName(books * p);
void searchByAuthorName(books * p);
void savedInstance(books * p);
void change(books * p);
void delete();


int main(void){
    //创建图书链表
    books * p;
    p=malloc(sizeof(books));
    p->next=NULL;
    printf("      ------图书链表建立成功------\n");
    initialize(p);p=p->next;    //初始化链表
    printf("--- -------------------------------- ---\n"
                   "|   |*******图书信息管理系统*******|   |\n"
                   "|   |------------------------------|   |\n"
                   "|           1  图书信息录入            |\n"
                   "|           2  图书信息输出            |\n"
                   "|           3  按图书名查书            |\n"
                   "|           4  按作者名查书            |\n"
                   "|           5  图书信息修改            |\n"
                   "|           6  图书信息删除            |\n"
                   "|           0  退出管理系统            |\n"
                   "|--------------------------------------|\n");
    int a;
    printf("            你输入的选项是 ");
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
        default:printf("\n------------请输入正确的选项------------\n");
            printf("\n-----------按任意键回到主菜单-----------\n");
            getchar();getchar();
            system("cls");/*清屏*/
            main();
    }
}
//读取文件信息 初始化图书链表
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
    printf("      ---------初始化成功---------\n");
}
//图书信息录入功能
void input(){
    books * a=NULL;
    a=malloc(sizeof(books));
    printf("输入登录号:");
    scanf("%d",&a->logInNum);
    printf("\n输入书名:");
    scanf("%s",a->bookName);
    printf("\n输入作者名:");
    scanf("%s",a->authorName);
    printf("\n输入分类号:");
    scanf("%d",&a->sortNum);
    printf("\n输入出版社:");
    scanf("%s",a->press);
    printf("\n输入出版时间:");
    scanf("%d",&a->publishedData);
    printf("\n输入价格:");
    scanf("%d",&a->price);
    FILE *file;
    file=fopen("d:\\bookInformation.txt","a");
    fprintf(file, "%d %s %s %d %s %d %d\n", a->logInNum, a->bookName, a->authorName, a->sortNum, a->press, a->publishedData, a->price);
    fclose(file);
    printf("\n添加成功\n\n");
    printf("按任意键回到主菜单");
    getchar();getchar();
    system("cls");
    main();
}
//图书信息输出功能
void output(books *p){
    while (p!=NULL){
        printf("登录号:%d  书名:%s  作者:%s  分类号:%d  出版社:%s  出版日期:%d  价格:%d\n", p->logInNum,p->bookName,p->authorName, p->sortNum,p->press, p->publishedData, p->price);
        p=p->next;
    }
    printf("\n-----------输出完成-----------\n");
    printf("\n------按任意键回到主菜单------\n");
    getchar();getchar();
    system("cls");
    main();
}
//按书名查询功能
void searchByBookName(books * p){
    char name[N];
    printf("输入要查找的书名:");
    scanf("%s",name);
    while (p!=NULL){
        if (strcmp(p->bookName,name)==0){
            printf("\n登录号:%d  书名:%s  作者:%s  分类号:%d  出版社:%s  出版日期:%d  价格:%d\n", p->logInNum,p->bookName,p->authorName, p->sortNum,p->press, p->publishedData, p->price);
            printf("\n------按任意键回到主菜单------\n");
            getchar();getchar();
            system("cls");
            main();
        }
        p=p->next;
    }
    printf("\n-------找不到你要找的书-------\n");
    printf("\n------按任意键回到主菜单------\n");
    getchar();getchar();
    system("cls");
    main();
}
//按作者查询
void searchByAuthorName(books * p){
    char author[N];
    printf("输入要查找的作者:");
    scanf("%s",author);
    int a=0;
    while (p!=NULL){
        if (strcmp(p->authorName,author)==0){
            a++;
            printf("\n登录号:%d  书名:%s  作者:%s  分类号:%d  出版社:%s  出版日期:%d  价格:%d\n", p->logInNum,p->bookName,p->authorName, p->sortNum,p->press, p->publishedData, p->price);
            printf("\n输出完成\n");
            printf("\n按任意键回到主菜单\n");
            getchar();
            getchar();
            system("cls");
            main();
        }
        p=p->next;
    }
    if(a==0){
        printf("\n------找不到你输入的作者名------\n");
        printf("\n-------按任意键回到主菜单-------\n");
        getchar();
        getchar();
        system("cls");
        main();
    }
}
//保存当前链表中的图书数据
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
//图书信息修改
void change(books * p){
    char name[N];
    printf("输入要修改的图书名:");
    scanf("%s",name);
    books * a;
    int x=0;
    a=p;
    while (p!=NULL){
        if(strcmp(name,p->bookName)==0){
            printf("\n输入修改后的登录号:");
            scanf("%d",&p->logInNum);
            getchar();
            printf("\n输入修改后的作者名:");
            gets(p->authorName);
            printf("\n输入修改后的分类号:");
            scanf("%d",&p->sortNum);
            getchar();
            printf("\n输入修改后的出版社:");
            gets(p->press);
            printf("\n输入修改后的出版时间:");
            scanf("%d",&p->publishedData);
            printf("\n输入修改后的价格:");
            scanf("%d",&p->price);
            x++;
        }
        p=p->next;
    }
    savedInstance(a);
    if (x==0){
        printf("\n找不到你所输入的书\n");
    } else {
        printf("\n修改成功\n");
    }
    printf("\n按任意键回到主菜单\n");
    getchar();
    getchar();
    system("cls");
    main();
}
//图书信息删除
void delete(){
getchar();
char name[N];
printf("------输入要删除的书名------\n");
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
printf("------删除成功------\n");
} else{
printf("------找不到你所输入的书------\n");
}
printf("\n------按任意键回到主菜单------\n");
getchar();
system("cls");
main();
}