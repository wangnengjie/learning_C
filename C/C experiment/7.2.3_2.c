#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct item
{
    char studentID[20];
    char name[20];
    float English;
    float math;
    float physics;
    float C;
    float average;
    float sum;
} Item;
typedef struct node
{
    Item stuMsg;
    struct node *next;
} Node;
typedef Node *List;
Node *createList(List *plist);
void addNode(List *plist, Item t);
void outPutEveryThing(List *plist);
void changeData(List *plist);
void outPutAverage(List *plist);
void outPutTotalAndAverage(List *plist);
void emptyList(List *plist);
void sort(List *plist);
int main(void)
{
    Node *student;
    Item t;
    char choose;
    student = createList(&student);
    printf("请输入\n学号\t姓名\t英语成绩\t高数成绩\t物理成绩\tC语言成绩\n");
    while (scanf("%s", t.studentID) == 1 && t.studentID[0] != '#')
    {
        scanf("%s%f%f%f%f", t.name, &t.English, &t.math, &t.physics, &t.C);
        t.sum = t.C + t.English + t.math + t.physics;
        t.average = t.sum / 4;
        addNode(&student, t);
        printf("请输入\n学号\t姓名\t英语成绩\t高数成绩\t物理成绩\tC语言成绩\n");
    }
    sort(&student);
    printf("请问要使用哪些功能\n"
           "1)输出学生信息              2)修改数据\n"
           "3)统计平均成绩              4)输出总成绩和平均成绩\n");
    while (getchar() != '\n')
        continue;
    while (scanf("%c", &choose) == 1 && choose > '0' && choose < '5')
    {
        switch (choose)
        {
        case '1':
            outPutEveryThing(&student);
            break;
        case '2':
            changeData(&student);
            break;
        case '3':
            outPutAverage(&student);
            break;
        case '4':
            outPutTotalAndAverage(&student);
            break;
        default:
            return 0;
        }
        printf("请问要使用哪些功能\n"
               "1)输出学生信息              2)修改数据\n"
               "3)统计平均成绩              4)输出总成绩和平均成绩\n");
        while (getchar() != '\n')
            continue;
    }
    emptyList(&student);
    return 0;
}

Node *createList(List *plist)
{
    *plist = NULL;
    return *plist;
}

void addNode(List *plist, Item t)
{
    Node *point;
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->stuMsg = t;
    temp->next = NULL;
    if (*plist == NULL)
    {
        *plist = temp;
    }
    else
    {
        point = *plist;
        while (point->next != NULL)
        {
            point = point->next;
        }
        point->next = temp;
    }
}

void outPutEveryThing(List *plist)
{
    Node *point = *plist;
    printf("学号%16c姓名%16c英语%6c数学%6c物理%6cC语言%5c\n", ' ', ' ', ' ', ' ', ' ', ' ');

    while (point != NULL)
    {
        printf("%-20s%-20s%-10.2f%-10.2f%-10.2f%-10.2f\n", point->stuMsg.studentID, point->stuMsg.name, point->stuMsg.English, point->stuMsg.math, point->stuMsg.physics, point->stuMsg.C);
        point = point->next;
    }
}

void changeData(List *plist)
{
    Node *point = *plist;
    char stuId[20];
    char ID[20];
    char tname[20];
    char choose;
    float grade;
    printf("请输入学生学号:");
    scanf("%s", stuId);
    while (strcmp(point->stuMsg.studentID, stuId))
    {
        if (point->next == NULL)
        {
            printf("未找到学生\n");
            return;
        }
        else
        {
            point = point->next;
        }
    }
    printf("更改什么数据？作何修改\n1)学号  \t2)姓名  \t3)英语成绩\t4)数学成绩\t5)物理成绩\t6)C语言成绩\n");

    while (getchar() != '\n')
        continue;
    if (scanf("%c", &choose) == 1)
    {
        switch (choose)
        {
        case '1':
            scanf("%s", ID);
            strcpy(point->stuMsg.studentID, ID);
            break;
        case '2':
            scanf("%s", tname);
            strcpy(point->stuMsg.name, tname);
            break;
        case '3':
            scanf("%f", &grade);
            point->stuMsg.English = grade;
            point->stuMsg.sum = point->stuMsg.C + point->stuMsg.English + point->stuMsg.math + point->stuMsg.physics;
            point->stuMsg.average = (point->stuMsg.sum) / 4;
            break;
        case '4':
            scanf("%f", &grade);
            point->stuMsg.math = grade;
            point->stuMsg.sum = point->stuMsg.C + point->stuMsg.English + point->stuMsg.math + point->stuMsg.physics;
            point->stuMsg.average = (point->stuMsg.sum) / 4;
            break;
        case '5':
            scanf("%f", &grade);
            point->stuMsg.physics = grade;
            point->stuMsg.sum = point->stuMsg.C + point->stuMsg.English + point->stuMsg.math + point->stuMsg.physics;
            point->stuMsg.average = (point->stuMsg.sum) / 4;
            break;
        case '6':
            scanf("%f", &grade);
            point->stuMsg.C = grade;
            point->stuMsg.sum = point->stuMsg.C + point->stuMsg.English + point->stuMsg.math + point->stuMsg.physics;
            point->stuMsg.average = (point->stuMsg.sum) / 4;
            break;
        default:
            break;
        }
    }
    if (choose >= '3' && choose <= '6')
        sort(plist);
}

void outPutAverage(List *plist)
{
    Node *point = *plist;
    printf("姓名%16c平均分%4c\n", ' ', ' ');
    while (point != NULL)
    {
        printf("%-20s%-10.2f\n", point->stuMsg.name, point->stuMsg.average);
        point = point->next;
    }
}

void outPutTotalAndAverage(List *plist)
{
    Node *point = *plist;
    printf("学号%16c姓名%16c总成绩%4c平均分%4c\n", ' ', ' ', ' ', ' ');
    while (point != NULL)
    {
        printf("%-20s%-20s%-10.2f%-10.2f\n", point->stuMsg.studentID, point->stuMsg.name, point->stuMsg.sum, point->stuMsg.average);
        point = point->next;
    }
}

void emptyList(List *plist)
{
    Node *point = *plist;
    while (*plist != NULL)
    {
        point = (*plist)->next;
        free(*plist);
        *plist = point;
    }
}

void sort(List *plist)
{
    Node *point = *plist;
    Node *nPoint;
    Item temp;
    if (point == NULL)
        return;
    for (; point != NULL; point = point->next)
        for (nPoint = point->next; nPoint != NULL; nPoint = nPoint->next)
        {
            if (point->stuMsg.average > nPoint->stuMsg.average)
            {
                temp = point->stuMsg;
                point->stuMsg = nPoint->stuMsg;
                nPoint->stuMsg = temp;
            }
        }
}