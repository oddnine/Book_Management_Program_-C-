//control.c
#include "std.h"
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#define DATAMAX	100

book g_booklist[DATAMAX];

int count = 0;

void savelist() {
    FILE* fp = fopen("list.txt", "w");
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s %s %d %d %d %s %s %s %s %s %s %d %d\n", g_booklist[i].classfirst, g_booklist[i].classsecond,g_booklist[i].classnum1, g_booklist[i].classnum2, g_booklist[i].classnum3, g_booklist[i].classpub, g_booklist[i].classauth, g_booklist[i].classname, g_booklist[i].name, g_booklist[i].auth, g_booklist[i].pub, g_booklist[i].flag1, g_booklist[i].flag);
        
    }
    fclose(fp);
}

void readlist() {
    FILE* in = fopen("list.txt", "r");
    int ccount = 0;
    fscanf(in, "\n");
    while (!feof(in)) {
        fscanf(in, "%s %s %d %d %d %s %s %s %s %s %s %d %d\n", g_booklist[ccount].classfirst, g_booklist[ccount].classsecond, &g_booklist[ccount].classnum1, &g_booklist[ccount].classnum2, &g_booklist[ccount].classnum3, g_booklist[ccount].classpub, g_booklist[ccount].classauth, g_booklist[ccount].classname, g_booklist[ccount].name, g_booklist[ccount].auth, g_booklist[ccount].pub, &g_booklist[ccount].flag1, &g_booklist[ccount].flag);
        ccount++;
    }
    
    count = ccount;
    fclose(in);
    return;
}

int random() {
    srand(time(NULL));
    int i = rand() % 100000;

    return i;
}

void Swap(book* arr, int a, int b)
{
    book temp;
    temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void Sort(book* arr, int m, int n)
{
        
        if (m < n) // 螃葷離牖
        {
            int key = m;
            int i = m + 1;
            int j = n;
            while (i <= j)
            {
                while (i <= n && arr[i].classnum1 <= arr[key].classnum1)
                    i++;
                while (j > m && arr[j].classnum1 >= arr[key].classnum1)
                    j--;
                if (i > j)
                    Swap(arr, j, key);
                else
                    Swap(arr, i, j);
            }
            Sort(arr, m, j - 1);
            Sort(arr, j + 1, n);
        }
}

void con_printall()
{
    system("cls");
    printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
    printf("弛                                  紫憮 跡煙                                  弛\n");
    printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
    printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
    printf("弛   碟盟廓�αt薯跡\t\t  盪濠  \t  轎っ餌  \t渠罹陛棟罹睡  弛\n");
    printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
    
    printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
   
    for (int i = 0; i <= count; i++)
    {
        char gar[10]; //渠轎陛棟罹睡
        if (g_booklist[i].flag1 == 1) {
            strcpy_s(gar, sizeof(gar), "陛  棟");
        }
        else {
            strcpy_s(gar, sizeof(gar), "碳陛棟");
        }
        if (g_booklist[i].flag == 1) {
            printf("弛 %-2s.%-8s                                                               弛\n", g_booklist[i].classfirst, g_booklist[i].classsecond);
            printf("弛  %d%d.%05d\t%-10s  \t  %-10s  \t  %-10s  \t   %-10s 弛\n", g_booklist[i].classnum1, g_booklist[i].classnum2, g_booklist[i].classnum3,g_booklist[i].name, g_booklist[i].auth, g_booklist[i].pub, gar);
            printf("弛 %-2s.%-2s.%-8s                                                              弛\n", g_booklist[i].classpub, g_booklist[i].classauth, g_booklist[i].classname);
        }
        printf("弛                                                                             弛\n");
    }
    printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
    printf("[1] 渠碟盟廓�� 螃葷離牖 薑溺 \n");
    printf("[2] 詭景 \n");
    char sel = _getch();
    if (sel == '1') {
        Sort(g_booklist, 0, count - 1);
        con_printall();
    }
    else {
        return;
    }
}

void con_printall1()
{
    system("cls");
    printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
    printf("弛   碟盟廓�αt薯跡\t\t  盪濠  \t  轎っ餌  \t渠罹陛棟罹睡  弛\n");
    printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");

    printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");

    for (int i = 0; i <= count; i++)
    {
        char gar[10]; //渠轎陛棟罹睡
        if (g_booklist[i].flag1 == 1) {
            strcpy_s(gar, sizeof(gar), "陛  棟");
        }
        else {
            strcpy_s(gar, sizeof(gar), "碳陛棟");
        }
        if (g_booklist[i].flag == 1) {
            printf("弛 %-2s.%-8s                                                               弛\n", g_booklist[i].classfirst, g_booklist[i].classsecond);
            printf("弛  %d%d.%05d\t%-10s  \t  %-10s  \t  %-10s  \t   %-10s 弛\n", g_booklist[i].classnum1, g_booklist[i].classnum2, g_booklist[i].classnum3, g_booklist[i].name, g_booklist[i].auth, g_booklist[i].pub, gar);
            printf("弛 %-2s.%-2s.%-8s                                                              弛\n", g_booklist[i].classpub, g_booklist[i].classauth, g_booklist[i].classname);
        }
        printf("弛                                                                             弛\n");
    }
    printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
}

void con_insert()
{

    system("cls");
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
    printf("\t\t\t\t弛                紫憮 蹺陛                弛\n");
    printf("\t\t\t\t戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
    char ch = menuprint2();
    switch (ch)
    {
    case '0':	con_insert0(ch); 		break;
    case '1':	con_insert1(ch); 		break;
    case '2':	con_insert2(ch);		break;
    case '3':	con_insert3(ch);		break;
    case '4':	con_insert4(ch);		break;
    case '5':	con_insert5(ch);		break;
    case '6':	con_insert6(ch);		break;
    case '7':	con_insert7(ch); 		break;
    case '8':	con_insert8(ch); 		break;
    case '9':	con_insert9(ch); 		break;
    case 'x':		break;
    }
}


char menuprint2() {
    printf("\t\t\t\t忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
    printf("\t\t\t\t弛            識盟(000~099): 0廓           弛\n");
    printf("\t\t\t\t弛            繹з(100~199): 1廓           弛\n");
    printf("\t\t\t\t弛            謙掖(200~299): 2廓           弛\n");
    printf("\t\t\t\t弛            餌�萼�з(300~399): 3廓       弛\n");
    printf("\t\t\t\t弛            濠翱婁з(400~499): 4廓       弛\n");
    printf("\t\t\t\t弛            晦獎婁з(500~599): 5廓       弛\n");
    printf("\t\t\t\t弛            蕨獎(600~699): 6廓           弛\n");
    printf("\t\t\t\t弛            樹橫(700~799): 7廓           弛\n");
    printf("\t\t\t\t弛            僥з(800~899): 8廓           弛\n");
    printf("\t\t\t\t弛            羲餌(900~999): 9廓           弛\n");
    printf("\t\t\t\t弛            給嬴陛晦: x酈                弛\n");
    printf("\t\t\t\t戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
    char ch = _getch();
    return ch;
}

void con_insert0(char temp)
{
    system("cls");
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
    printf("\t\t\t\t弛                紫憮 蹺陛                弛\n");
    printf("\t\t\t\t戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
    printf("\t\t\t\t忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
    printf("\t\t\t\t弛\t紫憮з, 憮雖з(000) \t\t  弛\n");
    printf("\t\t\t\t弛\t僥ь薑爾з(010) \t\t  弛\n");
    printf("\t\t\t\t弛\t寥婁餌瞪(020) \t\t\t  弛\n");
    printf("\t\t\t\t弛\t鬼翱餵,熱в餵,翱撲僥餵(030)       弛\n");
    printf("\t\t\t\t弛\t橾奩翱樓除ч僭(040) \t\t  弛\n");
    printf("\t\t\t\t弛\tз��,欽羹,⑺��,晦婦,翱掘晦婦(050) 弛 \n");
    printf("\t\t\t\t弛\t褐僥,盪割葬闈(060)\t \t  弛\n");
    printf("\t\t\t\t弛\t橾廓 瞪餵, 識憮(070)\t\t  弛\n");
    printf("\t\t\t\t弛\tщ饜濠猿(080)  \t\t\t  弛\n");
    printf("\t\t\t\t弛\t羲餌(090)\t\t\t  弛\n");
    printf("\t\t\t\t戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");


    int classnum = (int)temp - 48;

    int idx;
    classnum = 0;
    getchar();
    printf("\t\t\t\t盪濰й 模碟盟 廓�� 殮溘(00~99) : ");
    scanf_s("%d", &idx);
    if (idx < 0 && idx > 99) {
        printf("\t\t\t\t澀跤 殮溘腎歷蝗棲棻.\n");
        return;
    }
    if (idx >= 0 && idx <= 99)
    {
        char dummy = getchar();
        char name[20], auth[20], pub[20];

        printf("\t\t\t\t薯跡(嗥橫噙晦 衛 ) : ");        gets_s(name, sizeof(name));
        printf("\t\t\t\t盪濠 : ");    gets_s(auth, sizeof(auth));
        printf("\t\t\t\t轎っ餌 : ");    gets_s(pub, sizeof(pub));

        book bo;
        bo.flag = 1;
        bo.flag1 = 1;

        strcpy_s(bo.name, sizeof(bo.name), name);
        strcpy_s(bo.auth, sizeof(bo.auth), auth);
        strcpy_s(bo.pub, sizeof(bo.pub), pub);
        bo.classnum1 = classnum;
        bo.classnum2 = idx;

        int tempnum = random();
        for (int i = 0; i < count; i++) {
            if (g_booklist[i].classnum3 == tempnum) {
                tempnum = random();
            }
        }
        bo.classnum3 = tempnum;
        strncpy_s(bo.classpub, sizeof(bo.classpub), bo.pub, 2);
        bo.classpub[3] = '\0';
        strncpy_s(bo.classauth, sizeof(bo.classauth), bo.auth, 2);
        bo.classauth[3] = '\0';
        strncpy_s(bo.classname, sizeof(bo.classname), bo.name, 8);
        bo.classname[8] = '\0';
        strcpy_s(bo.classfirst, sizeof(bo.classfirst), "識盟");

        if (idx >= 0 && idx <= 9)   strcpy_s(bo.classsecond, sizeof(bo.classsecond), "紫憮憮雖");
        else if (idx >= 10 && idx <= 19) strcpy_s(bo.classsecond, sizeof(bo.classsecond), "僥ь薑爾");
        else if (idx >= 20 && idx <= 29)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "寥婁餌瞪");
        else if (idx >= 30 && idx <= 39)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "鬼熱翱餵");
        else if (idx >= 40 && idx <= 49)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "橾奩翱樓");
        else if (idx >= 50 && idx <= 59)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "з欽⑺晦");
        else if (idx >= 60 && idx <= 69)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "褐僥盪割");
        else if (idx >= 70 && idx <= 79)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "瞪餵識憮");
        else if (idx >= 80 && idx <= 89)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "щ饜濠猿");
        else if (idx >= 90 && idx <= 99)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "羲餌");
        else return;

        g_booklist[count++] = bo;
        printf("\t\t\t\t盪濰腎歷蝗棲棻.\n");

    }
    else
    {
        printf("\t\t\t\t彰嬪蒂 慇橫陬蝗棲棻..\n");

    }

}

void con_insert1(char temp)
{
    system("cls");
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
    printf("\t\t\t\t弛                紫憮 蹺陛                弛\n");
    printf("\t\t\t\t戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
    printf("\t\t\t\t忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
    printf("\t\t\t\t弛\t繹з(100)\t\t\t  弛\n");
    printf("\t\t\t\t弛\t⑽檜鼻з(110)\t\t\t  弛\n");
    printf("\t\t\t\t弛\t檣衝煩(120)\t\t\t  弛\n");
    printf("\t\t\t\t弛\t蟾褕葬з,褐綠輿曖(130)\t\t  弛\n");
    printf("\t\t\t\t弛\t繹зだ(140)\t\t\t  弛\n");
    printf("\t\t\t\t弛\t褕葬з(150)\t\t\t  弛 \n");
    printf("\t\t\t\t弛\t喱葬з(160\t\t\t  弛\n");
    printf("\t\t\t\t弛\t彌葬з(170)\t\t\t  弛\n");
    printf("\t\t\t\t弛\t堅渠 繹з,醞撮 繹з, 翕曄繹з(180)弛\n");
    printf("\t\t\t\t弛\t⑷渠 憮曄繹з(190) \t\t  弛\n");
    printf("\t\t\t\t戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");


    int classnum = (int)temp - 48;

    int idx;
    classnum = 1;
    printf("\t\t\t\t盪濰й 模碟盟 廓�� 殮溘(00~99) : ");
    scanf_s("%d", &idx);
    if (idx < 0 && idx > 99) {
        printf("\t\t\t\t澀跤 殮溘腎歷蝗棲棻.\n");
        return;
    }
    if (idx >= 0 && idx <= 99)
    {
        char dummy = getchar();
        char name[20], auth[20], pub[20];

        printf("\t\t\t\t薯跡(嗥橫噙晦 衛 ) : ");        gets_s(name, sizeof(name));
        printf("\t\t\t\t盪濠 : ");    gets_s(auth, sizeof(auth));
        printf("\t\t\t\t轎っ餌 : ");    gets_s(pub, sizeof(pub));

        book bo;
        bo.flag = 1;
        bo.flag1 = 1;

        strcpy_s(bo.name, sizeof(bo.name), name);
        strcpy_s(bo.auth, sizeof(bo.auth), auth);
        strcpy_s(bo.pub, sizeof(bo.pub), pub);
        bo.classnum1 = classnum;
        bo.classnum2 = idx;

        int tempnum = random();
        for (int i = 0; i < count; i++) {
            if (g_booklist[i].classnum3 == tempnum) {
                tempnum = random();
            }
        }
        bo.classnum3 = tempnum;
        strncpy_s(bo.classpub, sizeof(bo.classpub), bo.pub, 2);
        bo.classpub[3] = '\0';
        strncpy_s(bo.classauth, sizeof(bo.classauth), bo.auth, 2);
        bo.classauth[3] = '\0';
        strncpy_s(bo.classname, sizeof(bo.classname), bo.name, 8);
        bo.classname[8] = '\0';
        strcpy_s(bo.classfirst, sizeof(bo.classfirst), "繹з");

        if (idx >= 0 && idx <= 9)   strcpy_s(bo.classsecond, sizeof(bo.classsecond), "繹з");
        else if (idx >= 10 && idx <= 19) strcpy_s(bo.classsecond, sizeof(bo.classsecond), "⑽檜鼻з");
        else if (idx >= 20 && idx <= 29)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "檣衝煩");
        else if (idx >= 30 && idx <= 39)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "褕葬褐綠");
        else if (idx >= 40 && idx <= 49)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "繹зだ");
        else if (idx >= 50 && idx <= 59)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "褕葬з");
        else if (idx >= 60 && idx <= 69)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "喱葬з");
        else if (idx >= 70 && idx <= 79)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "彌葬з");
        else if (idx >= 80 && idx <= 89)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "堅醞翕繹");
        else if (idx >= 90 && idx <= 99)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "⑷憮繹з");
        else return;

        g_booklist[count++] = bo;
        printf("\t\t\t\t盪濰腎歷蝗棲棻.\n");

    }
    else
    {
        printf("\t\t\t\t彰嬪蒂 慇橫陬蝗棲棻..\n");

    }

}

void con_insert2(char temp)
{
    system("cls");
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
    printf("\t\t\t\t弛                紫憮 蹺陛                弛\n");
    printf("\t\t\t\t戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
    printf("\t\t\t\t忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
    printf("\t\t\t\t弛\t謙掖(200) \t\t\t  弛\n");
    printf("\t\t\t\t弛\t謙掖曖 繹з 塽 檜煩(210)\t  弛\n");
    printf("\t\t\t\t弛\t撩唳(220) \t\t\t  弛\n");
    printf("\t\t\t\t弛\t掖葬褐з餵(230)\t\t\t  弛\n");
    printf("\t\t\t\t弛\t斜葬蝶紫掖 彌葬(240) \t\t  弛\n");
    printf("\t\t\t\t弛\t雖羲掖��(250)\t\t\t  弛 \n");
    printf("\t\t\t\t弛\t斜葬蝶紫掖 餌�蜇龔�(260)\t  弛\n");
    printf("\t\t\t\t弛\t斜葬蝶紫掖 掖�蜓�(270)\t\t  弛\n");
    printf("\t\t\t\t弛\t斜葬蝶紫掖 掖だ(280)  \t\t  弛\n");
    printf("\t\t\t\t弛\t晦顫 謙掖(290) \t\t\t  弛\n");
    printf("\t\t\t\t戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");



    int classnum = (int)temp - 48;

    int idx;
    classnum = 2;
    printf("\t\t\t\t盪濰й 模碟盟 廓�� 殮溘(00~99) : ");
    scanf_s("%d", &idx);
    if (idx < 0 && idx > 99) {
        printf("\t\t\t\t澀跤 殮溘腎歷蝗棲棻.\n");
        return;
    }
    if (idx >= 0 && idx <= 99)
    {
        char dummy = getchar();
        char name[20], auth[20], pub[20];

        printf("\t\t\t\t薯跡(嗥橫噙晦 衛 ) : ");        gets_s(name, sizeof(name));
        printf("\t\t\t\t盪濠 : ");    gets_s(auth, sizeof(auth));
        printf("\t\t\t\t轎っ餌 : ");    gets_s(pub, sizeof(pub));

        book bo;
        bo.flag = 1;
        bo.flag1 = 1;

        strcpy_s(bo.name, sizeof(bo.name), name);
        strcpy_s(bo.auth, sizeof(bo.auth), auth);
        strcpy_s(bo.pub, sizeof(bo.pub), pub);
        bo.classnum1 = classnum;
        bo.classnum2 = idx;

        int tempnum = random();
        for (int i = 0; i < count; i++) {
            if (g_booklist[i].classnum3 == tempnum) {
                tempnum = random();
            }
        }
        bo.classnum3 = tempnum;
        strncpy_s(bo.classpub, sizeof(bo.classpub), bo.pub, 2);
        bo.classpub[3] = '\0';
        strncpy_s(bo.classauth, sizeof(bo.classauth), bo.auth, 2);
        bo.classauth[3] = '\0';
        strncpy_s(bo.classname, sizeof(bo.classname), bo.name, 8);
        bo.classname[8] = '\0';
        strcpy_s(bo.classfirst, sizeof(bo.classfirst), "謙掖");

        if (idx >= 0 && idx <= 9)   strcpy_s(bo.classsecond, sizeof(bo.classsecond), "謙掖");
        else if (idx >= 10 && idx <= 19) strcpy_s(bo.classsecond, sizeof(bo.classsecond), "謙繹塽檜");
        else if (idx >= 20 && idx <= 29)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "撩唳");
        else if (idx >= 30 && idx <= 39)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "掖葬褐з");
        else if (idx >= 40 && idx <= 49)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "斜葬彌葬");
        else if (idx >= 50 && idx <= 59)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "雖羲掖��");
        else if (idx >= 60 && idx <= 69)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "斜葬餌褐");
        else if (idx >= 70 && idx <= 79)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "斜葬掖��");
        else if (idx >= 80 && idx <= 89)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "斜葬掖だ");
        else if (idx >= 90 && idx <= 99)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "晦顫謙掖");
        else return;

        g_booklist[count++] = bo;
        printf("\t\t\t\t盪濰腎歷蝗棲棻.\n");

    }
    else
    {
        printf("\t\t\t\t彰嬪蒂 慇橫陬蝗棲棻..\n");

    }

}

void con_insert3(char temp)
{
    system("cls");
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
    printf("\t\t\t\t弛                紫憮 蹺陛                弛\n");
    printf("\t\t\t\t戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
    printf("\t\t\t\t忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
    printf("\t\t\t\t弛\t餌�萼�з(300)\t\t\t  弛\n");
    printf("\t\t\t\t弛\t鱔啗(310) \t\t\t  弛\n");
    printf("\t\t\t\t弛\t薑纂з(320) \t\t\t  弛\n");
    printf("\t\t\t\t弛\t唳啗з(330) \t\t\t  弛\n");
    printf("\t\t\t\t弛\t徹睦(340) \t\t\t  弛\n");
    printf("\t\t\t\t弛\tч薑з,捱餌з(350) \t\t  弛 \n");
    printf("\t\t\t\t弛\t餌�號挨�,餌�蛹嘗�(360)\t\t  弛\n");
    printf("\t\t\t\t弛\t掖幫з(370) \t\t\t  弛\n");
    printf("\t\t\t\t弛\t鼻機,鱔褐,掖鱔(380) \t\t  弛\n");
    printf("\t\t\t\t弛\tЁ樓,團樓з(390)\t\t  弛\n");
    printf("\t\t\t\t戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");


    int classnum = (int)temp - 48;

    int idx;
    classnum = 3;
    printf("\t\t\t\t盪濰й 模碟盟 廓�� 殮溘(00~99) : ");
    scanf_s("%d", &idx);
    if (idx < 0 && idx > 99) {
        printf("\t\t\t\t澀跤 殮溘腎歷蝗棲棻.\n");
        return;
    }
    if (idx >= 0 && idx <= 99)
    {
        char dummy = getchar();
        char name[20], auth[20], pub[20];

        printf("\t\t\t\t薯跡(嗥橫噙晦 衛 ) : ");        gets_s(name, sizeof(name));
        printf("\t\t\t\t盪濠 : ");    gets_s(auth, sizeof(auth));
        printf("\t\t\t\t轎っ餌 : ");    gets_s(pub, sizeof(pub));

        book bo;
        bo.flag = 1;
        bo.flag1 = 1;

        strcpy_s(bo.name, sizeof(bo.name), name);
        strcpy_s(bo.auth, sizeof(bo.auth), auth);
        strcpy_s(bo.pub, sizeof(bo.pub), pub);
        bo.classnum1 = classnum;
        bo.classnum2 = idx;

        int tempnum = random();
        for (int i = 0; i < count; i++) {
            if (g_booklist[i].classnum3 == tempnum) {
                tempnum = random();
            }
        }
        bo.classnum3 = tempnum;
        strncpy_s(bo.classpub, sizeof(bo.classpub), bo.pub, 2);
        bo.classpub[3] = '\0';
        strncpy_s(bo.classauth, sizeof(bo.classauth), bo.auth, 2);
        bo.classauth[3] = '\0';
        strncpy_s(bo.classname, sizeof(bo.classname), bo.name, 8);
        bo.classname[8] = '\0';
        strcpy_s(bo.classfirst, sizeof(bo.classfirst), "餌婁");

        if (idx >= 0 && idx <= 9)   strcpy_s(bo.classsecond, sizeof(bo.classsecond), "餌�萼�з");
        else if (idx >= 10 && idx <= 19) strcpy_s(bo.classsecond, sizeof(bo.classsecond), "鱔啗");
        else if (idx >= 20 && idx <= 29)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "薑纂з");
        else if (idx >= 30 && idx <= 39)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "唳啗з");
        else if (idx >= 40 && idx <= 49)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "徹睦");
        else if (idx >= 50 && idx <= 59)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "ч薑捱餌");
        else if (idx >= 60 && idx <= 69)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "餌�號捏�");
        else if (idx >= 70 && idx <= 79)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "掖幫з");
        else if (idx >= 80 && idx <= 89)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "鼻鱔掖鱔");
        else if (idx >= 90 && idx <= 99)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "Ё樓團樓");
        else return;

        g_booklist[count++] = bo;
        printf("\t\t\t\t盪濰腎歷蝗棲棻.\n");

    }
    else
    {
        printf("\t\t\t\t彰嬪蒂 慇橫陬蝗棲棻..\n");

    }

}

void con_insert4(char temp)
{
    system("cls");
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
    printf("\t\t\t\t弛                紫憮 蹺陛                弛\n");
    printf("\t\t\t\t戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
    printf("\t\t\t\t忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
    printf("\t\t\t\t弛\t濠翱婁з(400) \t\t\t  弛\n");
    printf("\t\t\t\t弛\t熱з(410) \t\t\t  弛\n");
    printf("\t\t\t\t弛\t繭僥з(420) \t\t\t  弛\n");
    printf("\t\t\t\t弛\t僭葬з(430) \t\t\t  弛\n");
    printf("\t\t\t\t弛\t�倆�(440)  \t\t\t  弛 \n");
    printf("\t\t\t\t弛\t雖掘婁з(450)\t\t\t  弛 \n");
    printf("\t\t\t\t弛\t堅儅僭з(460) \t\t\t  弛\n");
    printf("\t\t\t\t弛\t儅僭з(470) \t\t\t  弛\n");
    printf("\t\t\t\t弛\t衝僭з(480) \t\t\t  弛\n");
    printf("\t\t\t\t弛\t翕僭з(490) \t\t\t  弛\n");
    printf("\t\t\t\t戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");


    int classnum = (int)temp - 48;

    int idx;
    classnum = 4;
    printf("\t\t\t\t盪濰й 模碟盟 廓�� 殮溘(00~99) : ");
    scanf_s("%d", &idx);
    if (idx < 0 && idx > 99) {
        printf("\t\t\t\t澀跤 殮溘腎歷蝗棲棻.\n");
        return;
    }
    if (idx >= 0 && idx <= 99)
    {
        char dummy = getchar();
        char name[20], auth[20], pub[20];

        printf("\t\t\t\t薯跡(嗥橫噙晦 衛 ) : ");        gets_s(name, sizeof(name));
        printf("\t\t\t\t盪濠 : ");    gets_s(auth, sizeof(auth));
        printf("\t\t\t\t轎っ餌 : ");    gets_s(pub, sizeof(pub));

        book bo;
        bo.flag = 1;
        bo.flag1 = 1;

        strcpy_s(bo.name, sizeof(bo.name), name);
        strcpy_s(bo.auth, sizeof(bo.auth), auth);
        strcpy_s(bo.pub, sizeof(bo.pub), pub);
        bo.classnum1 = classnum;
        bo.classnum2 = idx;

        int tempnum = random();
        for (int i = 0; i < count; i++) {
            if (g_booklist[i].classnum3 == tempnum) {
                tempnum = random();
            }
        }
        bo.classnum3 = tempnum;
        strncpy_s(bo.classpub, sizeof(bo.classpub), bo.pub, 2);
        bo.classpub[3] = '\0';
        strncpy_s(bo.classauth, sizeof(bo.classauth), bo.auth, 2);
        bo.classauth[3] = '\0';
        strncpy_s(bo.classname, sizeof(bo.classname), bo.name, 8);
        bo.classname[8] = '\0';
        strcpy_s(bo.classfirst, sizeof(bo.classfirst), "濠婁");

        if (idx >= 0 && idx <= 9)   strcpy_s(bo.classsecond, sizeof(bo.classsecond), "濠翱婁з");
        else if (idx >= 10 && idx <= 19) strcpy_s(bo.classsecond, sizeof(bo.classsecond), "熱з");
        else if (idx >= 20 && idx <= 29)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "繭僥з");
        else if (idx >= 30 && idx <= 39)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "僭葬з");
        else if (idx >= 40 && idx <= 49)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "�倆�");
        else if (idx >= 50 && idx <= 59)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "雖掘婁з");
        else if (idx >= 60 && idx <= 69)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "堅儅僭з");
        else if (idx >= 70 && idx <= 79)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "儅僭з");
        else if (idx >= 80 && idx <= 89)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "衝僭з");
        else if (idx >= 90 && idx <= 99)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "翕僭з");
        else return;

        g_booklist[count++] = bo;
        printf("\t\t\t\t盪濰腎歷蝗棲棻.\n");

    }
    else
    {
        printf("\t\t\t\t彰嬪蒂 慇橫陬蝗棲棻..\n");

    }

}

void con_insert5(char temp)
{
    system("cls");
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
    printf("\t\t\t\t弛                紫憮 蹺陛                弛\n");
    printf("\t\t\t\t戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
    printf("\t\t\t\t忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
    printf("\t\t\t\t弛\t晦獎婁з(500) \t\t\t  弛\n");
    printf("\t\t\t\t弛\t曖з(510) \t\t\t  弛\n");
    printf("\t\t\t\t弛\t奢з(520) \t\t\t  弛\n");
    printf("\t\t\t\t弛\t堯з(530) \t\t\t  弛\n");
    printf("\t\t\t\t弛\t陛薑з(540)  \t\t\t  弛 \n");
    printf("\t\t\t\t弛\t唳艙з(550)\t\t\t  弛 \n");
    printf("\t\t\t\t弛\t�倆訄醾�(560) \t\t\t  弛\n");
    printf("\t\t\t\t弛\t薯褻機(570) \t\t\t  弛\n");
    printf("\t\t\t\t弛\tか熱薯褻機(580) \t\t  弛\n");
    printf("\t\t\t\t弛\t勒蹴奢з(590) \t\t\t  弛\n");
    printf("\t\t\t\t戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");


    int classnum = (int)temp - 48;

    int idx;
    classnum = 5;
    printf("\t\t\t\t盪濰й 模碟盟 廓�� 殮溘(00~99) : ");
    scanf_s("%d", &idx);
    if (idx < 0 && idx > 99) {
        printf("\t\t\t\t澀跤 殮溘腎歷蝗棲棻.\n");
        return;
    }
    if (idx >= 0 && idx <= 99)
    {
        char dummy = getchar();
        char name[20], auth[20], pub[20];

        printf("\t\t\t\t薯跡(嗥橫噙晦 衛 ) : ");        gets_s(name, sizeof(name));
        printf("\t\t\t\t盪濠 : ");    gets_s(auth, sizeof(auth));
        printf("\t\t\t\t轎っ餌 : ");    gets_s(pub, sizeof(pub));

        book bo;
        bo.flag = 1;
        bo.flag1 = 1;

        strcpy_s(bo.name, sizeof(bo.name), name);
        strcpy_s(bo.auth, sizeof(bo.auth), auth);
        strcpy_s(bo.pub, sizeof(bo.pub), pub);
        bo.classnum1 = classnum;
        bo.classnum2 = idx;

        int tempnum = random();
        for (int i = 0; i < count; i++) {
            if (g_booklist[i].classnum3 == tempnum) {
                tempnum = random();
            }
        }
        bo.classnum3 = tempnum;
        strncpy_s(bo.classpub, sizeof(bo.classpub), bo.pub, 2);
        bo.classpub[3] = '\0';
        strncpy_s(bo.classauth, sizeof(bo.classauth), bo.auth, 2);
        bo.classauth[3] = '\0';
        strncpy_s(bo.classname, sizeof(bo.classname), bo.name, 8);
        bo.classname[8] = '\0';
        strcpy_s(bo.classfirst, sizeof(bo.classfirst), "晦婁");

        if (idx >= 0 && idx <= 9)   strcpy_s(bo.classsecond, sizeof(bo.classsecond), "濠翱婁з");
        else if (idx >= 10 && idx <= 19) strcpy_s(bo.classsecond, sizeof(bo.classsecond), "熱з");
        else if (idx >= 20 && idx <= 29)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "繭僥з");
        else if (idx >= 30 && idx <= 39)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "僭葬з");
        else if (idx >= 40 && idx <= 49)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "�倆�");
        else if (idx >= 50 && idx <= 59)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "雖掘婁з");
        else if (idx >= 60 && idx <= 69)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "堅儅僭з");
        else if (idx >= 70 && idx <= 79)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "儅僭з");
        else if (idx >= 80 && idx <= 89)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "衝僭з");
        else if (idx >= 90 && idx <= 99)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "翕僭з");
        else return;

        g_booklist[count++] = bo;
        printf("\t\t\t\t盪濰腎歷蝗棲棻.\n");

    }
    else
    {
        printf("\t\t\t\t彰嬪蒂 慇橫陬蝗棲棻..\n");

    }

}

void con_insert6(char temp)
{
    system("cls");
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
    printf("\t\t\t\t弛                紫憮 蹺陛                弛\n");
    printf("\t\t\t\t戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
    printf("\t\t\t\t忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
    printf("\t\t\t\t弛\t蕨獎(600) \t\t\t  弛\n");
    printf("\t\t\t\t弛\t紫衛蕨獎,褻唳蕨獎(610) \t\t  弛\n");
    printf("\t\t\t\t弛\t勒蹴獎(620) \t\t\t  弛\n");
    printf("\t\t\t\t弛\t褻陝獎(630) \t\t\t  弛\n");
    printf("\t\t\t\t弛\t斜楚а嬴お,濰衝蕨獎(640)  \t  弛 \n");
    printf("\t\t\t\t弛\t�裙�(650)\t\t\t  弛 \n");
    printf("\t\t\t\t弛\tっ��(660) \t\t\t  弛\n");
    printf("\t\t\t\t弛\t餌霞獎,艙�倍匱�(670)\t\t  弛\n");
    printf("\t\t\t\t弛\t擠學(680) \t\t\t  弛\n");
    printf("\t\t\t\t弛\t奢翱蕨獎,螃塊,蝶ん隴(690)\t  弛\n");
    printf("\t\t\t\t戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");



    int classnum = (int)temp - 48;

    int idx;
    classnum = 6;
    printf("\t\t\t\t盪濰й 模碟盟 廓�� 殮溘(00~99) : ");
    scanf_s("%d", &idx);
    if (idx < 0 && idx > 99) {
        printf("\t\t\t\t澀跤 殮溘腎歷蝗棲棻.\n");
        return;
    }
    if (idx >= 0 && idx <= 99)
    {
        char dummy = getchar();
        char name[20], auth[20], pub[20];

        printf("\t\t\t\t薯跡(嗥橫噙晦 衛 ) : ");        gets_s(name, sizeof(name));
        printf("\t\t\t\t盪濠 : ");    gets_s(auth, sizeof(auth));
        printf("\t\t\t\t轎っ餌 : ");    gets_s(pub, sizeof(pub));

        book bo;
        bo.flag = 1;
        bo.flag1 = 1;

        strcpy_s(bo.name, sizeof(bo.name), name);
        strcpy_s(bo.auth, sizeof(bo.auth), auth);
        strcpy_s(bo.pub, sizeof(bo.pub), pub);
        bo.classnum1 = classnum;
        bo.classnum2 = idx;

        int tempnum = random();
        for (int i = 0; i < count; i++) {
            if (g_booklist[i].classnum3 == tempnum) {
                tempnum = random();
            }
        }
        bo.classnum3 = tempnum;
        strncpy_s(bo.classpub, sizeof(bo.classpub), bo.pub, 2);
        bo.classpub[3] = '\0';
        strncpy_s(bo.classauth, sizeof(bo.classauth), bo.auth, 2);
        bo.classauth[3] = '\0';
        strncpy_s(bo.classname, sizeof(bo.classname), bo.name, 8);
        bo.classname[8] = '\0';
        strcpy_s(bo.classfirst, sizeof(bo.classfirst), "僥з");

        if (idx >= 0 && idx <= 9)   strcpy_s(bo.classsecond, sizeof(bo.classsecond), "晦獎婁з");
        else if (idx >= 10 && idx <= 19) strcpy_s(bo.classsecond, sizeof(bo.classsecond), "曖з");
        else if (idx >= 20 && idx <= 29)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "奢з");
        else if (idx >= 30 && idx <= 39)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "堯з");
        else if (idx >= 40 && idx <= 49)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "陛薑з");
        else if (idx >= 50 && idx <= 59)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "唳艙з");
        else if (idx >= 60 && idx <= 69)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "�倆訄醾�");
        else if (idx >= 70 && idx <= 79)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "薯褻機");
        else if (idx >= 80 && idx <= 89)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "か熱薯褻");
        else if (idx >= 90 && idx <= 99)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "勒蹴奢з");
        else return;

        g_booklist[count++] = bo;
        printf("\t\t\t\t盪濰腎歷蝗棲棻.\n");

    }
    else
    {
        printf("\t\t\t\t彰嬪蒂 慇橫陬蝗棲棻..\n");

    }

}

void con_insert7(char temp)
{
    system("cls");
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
    printf("\t\t\t\t弛                紫憮 蹺陛                弛\n");
    printf("\t\t\t\t戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
    printf("\t\t\t\t忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
    printf("\t\t\t\t弛\t樹橫(700) \t\t\t  弛\n");
    printf("\t\t\t\t弛\t樹橫з(710) \t\t\t  弛\n");
    printf("\t\t\t\t弛\t艙橫(720) \t\t\t  弛\n");
    printf("\t\t\t\t弛\t絮橾橫(730) \t\t\t  弛\n");
    printf("\t\t\t\t弛\tЩ嫌蝶橫(740)  \t\t\t  弛 \n");
    printf("\t\t\t\t弛\t檜驍葬嬴橫(750)\t\t\t  弛 \n");
    printf("\t\t\t\t弛\t蝶む檣橫(760) \t\t\t  弛\n");
    printf("\t\t\t\t弛\t塭ず橫,檜鷓葬橫(770)\t\t  弛\n");
    printf("\t\t\t\t弛\t斜葬蝶橫(780) \t\t\t  弛\n");
    printf("\t\t\t\t弛\t晦顫樹橫(790) \t\t\t  弛\n");
    printf("\t\t\t\t戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");

    int classnum = (int)temp - 48;

    int idx;
    classnum = 7;
    printf("\t\t\t\t盪濰й 模碟盟 廓�� 殮溘(00~99) : ");
    scanf_s("%d", &idx);
    if (idx < 0 && idx > 99) {
        printf("\t\t\t\t澀跤 殮溘腎歷蝗棲棻.\n");
        return;
    }
    if (idx >= 0 && idx <= 99)
    {
        char dummy = getchar();
        char name[20], auth[20], pub[20];

        printf("\t\t\t\t薯跡(嗥橫噙晦 衛 ) : ");        gets_s(name, sizeof(name));
        printf("\t\t\t\t盪濠 : ");    gets_s(auth, sizeof(auth));
        printf("\t\t\t\t轎っ餌 : ");    gets_s(pub, sizeof(pub));

        book bo;
        bo.flag = 1;
        bo.flag1 = 1;

        strcpy_s(bo.name, sizeof(bo.name), name);
        strcpy_s(bo.auth, sizeof(bo.auth), auth);
        strcpy_s(bo.pub, sizeof(bo.pub), pub);
        bo.classnum1 = classnum;
        bo.classnum2 = idx;

        int tempnum = random();
        for (int i = 0; i < count; i++) {
            if (g_booklist[i].classnum3 == tempnum) {
                tempnum = random();
            }
        }
        bo.classnum3 = tempnum;
        strncpy_s(bo.classpub, sizeof(bo.classpub), bo.pub, 2);
        bo.classpub[3] = '\0';
        strncpy_s(bo.classauth, sizeof(bo.classauth), bo.auth, 2);
        bo.classauth[3] = '\0';
        strncpy_s(bo.classname, sizeof(bo.classname), bo.name, 8);
        bo.classname[8] = '\0';
        strcpy_s(bo.classfirst, sizeof(bo.classfirst), "僥з");

        if (idx >= 0 && idx <= 9)   strcpy_s(bo.classsecond, sizeof(bo.classsecond), "蕨獎");
        else if (idx >= 10 && idx <= 19) strcpy_s(bo.classsecond, sizeof(bo.classsecond), "紫衛褻唳");
        else if (idx >= 20 && idx <= 29)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "勒蹴獎");
        else if (idx >= 30 && idx <= 39)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "褻陝獎");
        else if (idx >= 40 && idx <= 49)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "斜楚濰衝");
        else if (idx >= 50 && idx <= 59)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "�裙�");
        else if (idx >= 60 && idx <= 69)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "っ��");
        else if (idx >= 70 && idx <= 79)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "餌霞艙��");
        else if (idx >= 80 && idx <= 89)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "擠學");
        else if (idx >= 90 && idx <= 99)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "奢翱螃塊");
        else return;

        g_booklist[count++] = bo;
        printf("\t\t\t\t盪濰腎歷蝗棲棻.\n");

    }
    else
    {
        printf("\t\t\t\t彰嬪蒂 慇橫陬蝗棲棻..\n");

    }

}

void con_insert8(char temp)
{
    system("cls");
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
    printf("\t\t\t\t弛                紫憮 蹺陛                弛\n");
    printf("\t\t\t\t戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
    printf("\t\t\t\t忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
    printf("\t\t\t\t弛\t僥з(800) \t\t\t  弛\n");
    printf("\t\t\t\t弛\t嘐措僥з(810) \t\t\t  弛\n");
    printf("\t\t\t\t弛\t艙措僥з(820) \t\t\t  弛\n");
    printf("\t\t\t\t弛\t絮橾僥з(830) \t\t\t  弛\n");
    printf("\t\t\t\t弛\tЩ嫌蝶僥з(840)  \t\t  弛 \n");
    printf("\t\t\t\t弛\t檜驍葬嬴僥з(850)\t\t  弛 \n");
    printf("\t\t\t\t弛\t蝶む檣僥з(860) \t\t  弛\n");
    printf("\t\t\t\t弛\t塭ず 塽 檜鷓葬僥з(870)\t\t  弛\n");
    printf("\t\t\t\t弛\t斜葬蝶僥з(880) \t\t  弛\n");
    printf("\t\t\t\t弛\t晦顫樹橫 僥з(890) \t\t  弛\n");
    printf("\t\t\t\t戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");

    int classnum = (int)temp - 48;

    int idx;
    classnum = 8;
    printf("\t\t\t\t盪濰й 模碟盟 廓�� 殮溘(00~99) : ");
    scanf_s("%d", &idx);
    if (idx < 0 && idx > 99) {
        printf("\t\t\t\t澀跤 殮溘腎歷蝗棲棻.\n");
        return;
    }
    if (idx >= 0 && idx <= 99)
    {
        char dummy = getchar();
        char name[20], auth[20], pub[20];

        printf("\t\t\t\t薯跡(嗥橫噙晦 衛 ) : ");        gets_s(name, sizeof(name));
        printf("\t\t\t\t盪濠 : ");    gets_s(auth, sizeof(auth));
        printf("\t\t\t\t轎っ餌 : ");    gets_s(pub, sizeof(pub));

        book bo;
        bo.flag = 1;
        bo.flag1 = 1;

        strcpy_s(bo.name, sizeof(bo.name), name);
        strcpy_s(bo.auth, sizeof(bo.auth), auth);
        strcpy_s(bo.pub, sizeof(bo.pub), pub);
        bo.classnum1 = classnum;
        bo.classnum2 = idx;

        int tempnum = random();
        for (int i = 0; i < count; i++) {
            if (g_booklist[i].classnum3 == tempnum) {
                tempnum = random();
            }
        }
        bo.classnum3 = tempnum;
        strncpy_s(bo.classpub, sizeof(bo.classpub), bo.pub, 2);
        bo.classpub[3] = '\0';
        strncpy_s(bo.classauth, sizeof(bo.classauth), bo.auth, 2);
        bo.classauth[3] = '\0';
        strncpy_s(bo.classname, sizeof(bo.classname), bo.name, 8);
        bo.classname[8] = '\0';
        strcpy_s(bo.classfirst, sizeof(bo.classfirst), "僥з");

        if (idx >= 0 && idx <= 9)   strcpy_s(bo.classsecond, sizeof(bo.classsecond), "僥з");
        else if (idx >= 10 && idx <= 19) strcpy_s(bo.classsecond, sizeof(bo.classsecond), "嘐措僥з");
        else if (idx >= 20 && idx <= 29)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "艙措僥з");
        else if (idx >= 30 && idx <= 39)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "絮橾僥з");
        else if (idx >= 40 && idx <= 49)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "Щ嫌蝶僥");
        else if (idx >= 50 && idx <= 59)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "檜驍葬嬴");
        else if (idx >= 60 && idx <= 69)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "蝶む檣僥");
        else if (idx >= 70 && idx <= 79)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "塭ず塽檜");
        else if (idx >= 80 && idx <= 89)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "斜葬蝶僥");
        else if (idx >= 90 && idx <= 99)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "晦顫樹橫");
        else return;

        g_booklist[count++] = bo;
        printf("\t\t\t\t盪濰腎歷蝗棲棻.\n");

    }
    else
    {
        printf("\t\t\t\t彰嬪蒂 慇橫陬蝗棲棻..\n");

    }
}

void con_insert9(char temp)
{
    system("cls");
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
    printf("\t\t\t\t弛                紫憮 蹺陛                弛\n");
    printf("\t\t\t\t戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
    printf("\t\t\t\t忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
    printf("\t\t\t\t弛\t羲餌(900) \t\t\t  弛\n");
    printf("\t\t\t\t弛\t雖葬,晦ч(910) \t\t\t  弛\n");
    printf("\t\t\t\t弛\t瞪晦,啗爾з(920) \t\t  弛\n");
    printf("\t\t\t\t弛\t堅渠撮啗 羲餌(930) \t\t  弛\n");
    printf("\t\t\t\t弛\t嶸毀羲餌(940)  \t\t\t  弛 \n");
    printf("\t\t\t\t弛\t嬴衛嬴羲餌(950)\t\t\t  弛 \n");
    printf("\t\t\t\t弛\t嬴Щ葬蘋羲餌(960) \t\t  弛\n");
    printf("\t\t\t\t弛\t磁嘐羲餌(970) \t\t\t  弛\n");
    printf("\t\t\t\t弛\t陴嘐羲餌(980) \t\t\t  弛\n");
    printf("\t\t\t\t弛\t晦顫雖羲 羲餌(990) \t\t  弛\n");
    printf("\t\t\t\t戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");



    int classnum = (int)temp - 48;

    int idx;
    classnum = 9;
    printf("\t\t\t\t盪濰й 模碟盟 廓�� 殮溘(00~99) : ");
    scanf_s("%d", &idx);
    if (idx < 0 && idx > 99) {
        printf("\t\t\t\t澀跤 殮溘腎歷蝗棲棻.\n");
        return;
    }
    if (idx >= 0 && idx <= 99)
    {
        char dummy = getchar();
        char name[20], auth[20], pub[20];

        printf("\t\t\t\t薯跡(嗥橫噙晦 衛 ) : ");        gets_s(name, sizeof(name));
        printf("\t\t\t\t盪濠 : ");    gets_s(auth, sizeof(auth));
        printf("\t\t\t\t轎っ餌 : ");    gets_s(pub, sizeof(pub));

        book bo;
        bo.flag = 1;
        bo.flag1 = 1;

        strcpy_s(bo.name, sizeof(bo.name), name);
        strcpy_s(bo.auth, sizeof(bo.auth), auth);
        strcpy_s(bo.pub, sizeof(bo.pub), pub);
        bo.classnum1 = classnum;
        bo.classnum2 = idx;

        int tempnum = random();
        for (int i = 0; i < count; i++) {
            if (g_booklist[i].classnum3 == tempnum) {
                tempnum = random();
            }
        }
        bo.classnum3 = tempnum;
        strncpy_s(bo.classpub, sizeof(bo.classpub), bo.pub, 2);
        bo.classpub[3] = '\0';
        strncpy_s(bo.classauth, sizeof(bo.classauth), bo.auth, 2);
        bo.classauth[3] = '\0';
        strncpy_s(bo.classname, sizeof(bo.classname), bo.name, 8);
        bo.classname[8] = '\0';
        strcpy_s(bo.classfirst, sizeof(bo.classfirst), "僥з");

        if (idx >= 0 && idx <= 9)   strcpy_s(bo.classsecond, sizeof(bo.classsecond), "羲餌");
        else if (idx >= 10 && idx <= 19) strcpy_s(bo.classsecond, sizeof(bo.classsecond), "雖葬晦ч");
        else if (idx >= 20 && idx <= 29)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "瞪晦啗爾");
        else if (idx >= 30 && idx <= 39)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "堅渠羲餌");
        else if (idx >= 40 && idx <= 49)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "嶸毀羲餌");
        else if (idx >= 50 && idx <= 59)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "嬴衛羲餌");
        else if (idx >= 60 && idx <= 69)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "嬴Щ羲餌");
        else if (idx >= 70 && idx <= 79)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "磁嘐羲餌");
        else if (idx >= 80 && idx <= 89)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "陴嘐羲餌");
        else if (idx >= 90 && idx <= 99)strcpy_s(bo.classsecond, sizeof(bo.classsecond), "晦顫羲餌");
        else return;

        g_booklist[count++] = bo;
        printf("\t\t\t\t盪濰腎歷蝗棲棻.\n");

    }
    else
    {
        printf("\t\t\t\t彰嬪蒂 慇橫陬蝗棲棻..\n");

    }

}


int searchsn(int serialnum) //橾溼廓�� 匐儀
{
    for (int i = 0; i <= count; i++) {
        if (g_booklist[i].classnum3 == serialnum) {
            return i;
        }
    }
    return -1;
}

void con_select()
{
    system("cls");
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
    printf("\t\t\t\t弛                紫憮 匐儀                弛\n");
    printf("\t\t\t\t戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
    printf("\t\t\t\t忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
    printf("\t\t\t\t弛                                         弛\n");
    printf("\t\t\t\t弛             [1] 薯跡 匐儀               弛\n");
    printf("\t\t\t\t弛             [2] 盪濠 匐儀               弛\n");
    printf("\t\t\t\t弛             [3] 轎っ餌 匐儀             弛\n");
    printf("\t\t\t\t弛             [4] 碟盟滌 匐儀             弛\n");
    printf("\t\t\t\t弛             [5] 橾溼廓�� 匐儀           弛\n");
    printf("\t\t\t\t弛                                         弛\n");
    printf("\t\t\t\t戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
    char temp;
    temp = _getch();
    if (temp == '1') {
        system("cls");
        char name[20];
        printf("\n\n\n\n\n\n");
        printf("\t\t\t\t忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
        printf("\t\t\t\t弛                紫憮 匐儀                弛\n");
        printf("\t\t\t\t戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
        printf("\t\t\t\t薯跡 殮溘) ");
        gets_s(name, sizeof(name));

        int i = nametoidx(name);
        system("cls");
        
        if (i != -1) {
            printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
            printf("弛                                  匐儀 唸婁                                  弛\n");
            printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
            printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
            printf("弛   碟盟廓�αt薯跡\t\t  盪濠  \t  轎っ餌  \t渠罹陛棟罹睡  弛\n");
            printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");

            printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");

            char gar[10]; //渠轎陛棟罹睡
            if (g_booklist[i].flag1 == 1) {
                strcpy_s(gar, sizeof(gar), "陛  棟");
            }
            else {
                strcpy_s(gar, sizeof(gar), "碳陛棟");
            }
            if (g_booklist[i].flag == 1) {
                printf("弛 %-2s.%-8s                                                               弛\n", g_booklist[i].classfirst, g_booklist[i].classsecond);
                printf("弛  %d%d.%05d\t%-10s  \t  %-10s  \t  %-10s  \t   %-10s 弛\n", g_booklist[i].classnum1, g_booklist[i].classnum2, g_booklist[i].classnum3, g_booklist[i].name, g_booklist[i].auth, g_booklist[i].pub, gar);
                printf("弛 %-2s.%-2s.%-8s                                                              弛\n", g_booklist[i].classpub, g_booklist[i].classauth, g_booklist[i].classname);
            }
            printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
            printf("\n");
        }
        else
        {
            printf("\t\t\t\t橈蝗棲棻\n");
        }
    }
    else if (temp == '2') {
        system("cls");
        char name[20];
        printf("\n\n\n\n\n\n");
        printf("\t\t\t\t忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
        printf("\t\t\t\t弛                紫憮 匐儀                弛\n");
        printf("\t\t\t\t戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
        printf("\t\t\t\t盪濠 殮溘) ");
        gets_s(name, sizeof(name));

        int i = authtoidx(name);
        system("cls");
        
        if (i != -1) {
            printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
            printf("弛                                  匐儀 唸婁                                  弛\n");
            printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
            printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
            printf("弛   碟盟廓�αt薯跡\t\t  盪濠  \t  轎っ餌  \t渠罹陛棟罹睡  弛\n");
            printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");

            printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");

            char gar[10]; //渠轎陛棟罹睡
            if (g_booklist[i].flag1 == 1) {
                strcpy_s(gar, sizeof(gar), "陛  棟");
            }
            else {
                strcpy_s(gar, sizeof(gar), "碳陛棟");
            }
            if (g_booklist[i].flag == 1) {
                printf("弛 %-2s.%-8s                                                               弛\n", g_booklist[i].classfirst, g_booklist[i].classsecond);
                printf("弛  %d%d.%05d\t%-10s  \t  %-10s  \t  %-10s  \t   %-10s 弛\n", g_booklist[i].classnum1, g_booklist[i].classnum2, g_booklist[i].classnum3, g_booklist[i].name, g_booklist[i].auth, g_booklist[i].pub, gar);
                printf("弛 %-2s.%-2s.%-8s                                                              弛\n", g_booklist[i].classpub, g_booklist[i].classauth, g_booklist[i].classname);
            }
            printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
            printf("\n");
        }
        else
        {
            printf("\t\t\t\t橈蝗棲棻\n");
        }
    }
    else if (temp == '3') {
        system("cls");
        char name[20];
        printf("\n\n\n\n\n\n");
        printf("\t\t\t\t忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
        printf("\t\t\t\t弛                紫憮 匐儀                弛\n");
        printf("\t\t\t\t戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
        printf("\t\t\t\t轎っ餌 殮溘) ");
        gets_s(name, sizeof(name));

        int i = pubtoidx(name);
        
        if (i != -1) {
            system("cls");
            printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
            printf("弛                                  匐儀 唸婁                                  弛\n");
            printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
            printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
            printf("弛   碟盟廓�αt薯跡\t\t  盪濠  \t  轎っ餌  \t渠罹陛棟罹睡  弛\n");
            printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");

            printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");

            char gar[10]; //渠轎陛棟罹睡
            if (g_booklist[i].flag1 == 1) {
                strcpy_s(gar, sizeof(gar), "陛  棟");
            }
            else {
                strcpy_s(gar, sizeof(gar), "碳陛棟");
            }
            if (g_booklist[i].flag == 1) {
                printf("弛 %-2s.%-8s                                                               弛\n", g_booklist[i].classfirst, g_booklist[i].classsecond);
                printf("弛  %d%d.%05d\t%-10s  \t  %-10s  \t  %-10s  \t   %-10s 弛\n", g_booklist[i].classnum1, g_booklist[i].classnum2, g_booklist[i].classnum3, g_booklist[i].name, g_booklist[i].auth, g_booklist[i].pub, gar);
                printf("弛 %-2s.%-2s.%-8s                                                              弛\n", g_booklist[i].classpub, g_booklist[i].classauth, g_booklist[i].classname);
            }
            printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
            printf("\n");
        }
        else
        {
            printf("\t\t\t\t橈蝗棲棻\n");
        }
    }
    else if (temp == '4') {
        system("cls");
        printf("\n\n\n\n\n\n");
        printf("\t\t\t\t忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
        printf("\t\t\t\t弛                紫憮 匐儀                弛\n");
        printf("\t\t\t\t戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
        printf("\t\t\t\t忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
        printf("\t\t\t\t弛            識盟(000~099): 0廓           弛\n");
        printf("\t\t\t\t弛            繹з(100~199): 1廓           弛\n");
        printf("\t\t\t\t弛            謙掖(200~299): 2廓           弛\n");
        printf("\t\t\t\t弛            餌�萼�з(300~399): 3廓       弛\n");
        printf("\t\t\t\t弛            濠翱婁з(400~499): 4廓       弛\n");
        printf("\t\t\t\t弛            晦獎婁з(500~599): 5廓       弛\n");
        printf("\t\t\t\t弛            蕨獎(600~699): 6廓           弛\n");
        printf("\t\t\t\t弛            樹橫(700~799): 7廓           弛\n");
        printf("\t\t\t\t弛            僥з(800~899): 8廓           弛\n");
        printf("\t\t\t\t弛            羲餌(900~999): 9廓           弛\n");
        printf("\t\t\t\t弛            給嬴陛晦: x酈                弛\n");
        printf("\t\t\t\t戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
        char ch = _getch();

        if (ch == 'x') {
            printf("\t\t\t\t澀跤脹 高殮棲棻.\n");
        }
        else {
            system("cls");
            printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
            printf("弛                                  匐儀 唸婁                                  弛\n");
            printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
            int classnum = (int)ch - 48;
            printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
            printf("弛   碟盟廓�αt薯跡\t\t  盪濠  \t  轎っ餌  \t渠罹陛棟罹睡  弛\n");
            printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");

            printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");

            for (int i = 0; i <= count; i++)
            {
                char gar[10]; //渠轎陛棟罹睡
                if (g_booklist[i].flag1 == 1) {
                    strcpy_s(gar, sizeof(gar), "陛  棟");
                }
                else {
                    strcpy_s(gar, sizeof(gar), "碳陛棟");
                }
                if (g_booklist[i].flag == 1 && g_booklist[i].classnum1 == classnum) {
                    printf("弛 %-2s.%-8s                                                               弛\n", g_booklist[i].classfirst, g_booklist[i].classsecond);
                    printf("弛  %d%d.%05d\t%-10s  \t  %-10s  \t  %-10s  \t   %-10s 弛\n", g_booklist[i].classnum1, g_booklist[i].classnum2, g_booklist[i].classnum3, g_booklist[i].name, g_booklist[i].auth, g_booklist[i].pub, gar);
                    printf("弛 %-2s.%-2s.%-8s                                                              弛\n", g_booklist[i].classpub, g_booklist[i].classauth, g_booklist[i].classname);
                }
                printf("弛                                                                             弛\n");
            }
            printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
            printf("\n");
        }
    }
    else if (temp == '5') {
        system("cls");
        int sn;
        printf("\n\n\n\n\n\n");
        printf("\t\t\t\t忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
        printf("\t\t\t\t弛                紫憮 匐儀                弛\n");
        printf("\t\t\t\t戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
        printf("\t\t\t\t橾溼廓�� 殮溘) ");
        scanf_s("%d", &sn);
        int i = searchsn(sn);
        if (i == -1) {
            printf("\t\t\t\t澀跤脹 高殮棲棻.\n");
        }
        else {
            system("cls");
            printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
            printf("弛                                  匐儀 唸婁                                  弛\n");
            printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
            printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
            printf("弛   碟盟廓�αt薯跡\t\t  盪濠  \t  轎っ餌  \t渠罹陛棟罹睡  弛\n");
            printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");

            printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");

            char gar[10]; //渠轎陛棟罹睡
            if (g_booklist[i].flag1 == 1) {
                strcpy_s(gar, sizeof(gar), "陛  棟");
            }
            else {
                strcpy_s(gar, sizeof(gar), "碳陛棟");
            }
            if (g_booklist[i].flag == 1) {
                printf("弛 %-2s.%-8s                                                               弛\n", g_booklist[i].classfirst, g_booklist[i].classsecond);
                printf("弛  %d%d.%05d\t%-10s  \t  %-10s  \t  %-10s  \t   %-10s 弛\n", g_booklist[i].classnum1, g_booklist[i].classnum2, g_booklist[i].classnum3, g_booklist[i].name, g_booklist[i].auth, g_booklist[i].pub, gar);
                printf("弛 %-2s.%-2s.%-8s                                                              弛\n", g_booklist[i].classpub, g_booklist[i].classauth, g_booklist[i].classname);
            }
            printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
            printf("\n");
        }
    }
}
void con_update()
{
    system("cls");
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
    printf("\t\t\t\t弛                紫憮 渠罹                弛\n");
    printf("\t\t\t\t戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
    printf("\t\t\t\t忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
    printf("\t\t\t\t弛         [1] 薯跡 匐儀 �� 渠罹           弛\n");
    printf("\t\t\t\t弛         [2] 橾溼廓�� 匐儀 �� 渠罹       弛\n");
    printf("\t\t\t\t戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");

    char temp;
    temp = _getch();
    if (temp == '1') {
        char name[20];
        printf("\t\t\t\t薯跡 殮溘 : ");
        gets_s(name, sizeof(name));

        int idx = nametoidx(name);

        if (idx != -1)
        {
            if (g_booklist[idx].flag1 == 1) {
                g_booklist[idx].flag1 = 0;

                printf("\t\t\t\t渠罹腎歷蝗棲棻.\n");
            }
            else
                printf("\t\t\t\t檜嘐 渠罹腎橫氈蝗棲棻.\n");
        }
        else
        {
            printf("\t\t\t\t橈蝗棲棻\n");
        }
    }
    else if (temp == '2') {
        int sn;
        printf("\t\t\t\t橾溼廓�� 殮溘) ");
        scanf_s("%d", &sn);
        int temp = searchsn(sn);
        if (temp == -1) {
            printf("\t\t\t\t橈蝗棲棻\n");
        }
        else {
            if (g_booklist[temp].flag1 == 1) {
                g_booklist[temp].flag1 = 0;

                printf("\t\t\t\t渠罹腎歷蝗棲棻.\n");
            }
            else {
                printf("\t\t\t\t檜嘐 渠罹腎橫氈蝗棲棻.\n");
            }
        }
    }
    else {
        return;
    }
}
void con_update1()
{
    system("cls"); 
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
    printf("\t\t\t\t弛                紫憮 奩陶                弛\n");
    printf("\t\t\t\t戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
    printf("\t\t\t\t忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
    printf("\t\t\t\t弛         [1] 薯跡 匐儀 �� 奩陶           弛\n");
    printf("\t\t\t\t弛         [2] 橾溼廓�� 匐儀 �� 奩陶       弛\n");
    printf("\t\t\t\t戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");

    char temp;
    temp = _getch();
    if (temp == '1') {
        char name[20];
        printf("\t\t\t\t薯跡 殮溘 : ");
        gets_s(name, sizeof(name));

        int idx = nametoidx(name);

        if (idx != -1)
        {
            if (g_booklist[idx].flag1 == 0) {
                g_booklist[idx].flag1 = 1;

                printf("\t\t\t\t奩陶腎歷蝗棲棻.\n");
            }
            else
                printf("\t\t\t\t檜嘐 奩陶腎橫氈蝗棲棻.\n");
        }
        else
        {
            printf("\t\t\t\t橈蝗棲棻\n");
        }
    }
    else if(temp == '2') {
        int sn;
        printf("\t\t\t\t橾溼廓�� 殮溘) ");
        scanf_s("%d", &sn);

        int idx = searchsn(sn);
        if (idx != -1) {
            if (g_booklist[idx].flag1 == 0) {
                g_booklist[idx].flag1 = 1;

                printf("\t\t\t\t奩陶腎歷蝗棲棻.\n");
            }
            else
                printf("\t\t\t\t檜嘐 奩陶腎橫氈蝗棲棻.\n");
        }
        else {
            printf("\t\t\t\t橈蝗棲棻.\n");
        }
    }
}
void con_update2()
{
    system("cls");
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
    printf("\t\t\t\t弛                紫憮 熱薑                弛\n");
    printf("\t\t\t\t戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
    printf("\t\t\t\t忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
    printf("\t\t\t\t弛         [1] 薯跡 匐儀 �� 熱薑           弛\n");
    printf("\t\t\t\t弛         [2] 橾溼廓�� 匐儀 �� 熱薑       弛\n");
    printf("\t\t\t\t戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
    char temp;
    temp = _getch();
    if (temp == '1') {
        system("cls");
        char name[20];
        printf("\n\n\n\n\n\n");
        printf("\t\t\t\t忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
        printf("\t\t\t\t弛                紫憮 熱薑                弛\n");
        printf("\t\t\t\t戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
        printf("\t\t\t\t薯跡 殮溘 : ");
        gets_s(name, sizeof(name));

        int idx = nametoidx(name);

        if (idx != -1)
        {
            char auth[20];
            char pub[20];
            char name[20];
            int cn1;
            int cn2;

            printf("\t\t\t\t熱薑й 渠碟盟 廓�� 殮溘(0~9) : ");
            scanf_s("%d", &cn1);
            if (cn1 < 0 && cn1 > 9) {
                printf("\t\t\t\t澀跤 殮溘腎歷蝗棲棻.\n");
                return;
            }
            if (cn1 == 0)  	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "識盟");
            else if (cn1 == 1) 	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "繹з");
            else if (cn1 == 2)	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "謙掖");
            else if (cn1 == 3)	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "餌婁");
            else if (cn1 == 4)	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "濠婁");
            else if (cn1 == 5)	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "晦婁");
            else if (cn1 == 6)	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "蕨獎");
            else if (cn1 == 7)	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "樹橫");
            else if (cn1 == 8)	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "僥з");
            else if (cn1 == 9)	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "羲餌");


            printf("\t\t\t\t熱薑й 模碟盟 廓�� 殮溘(00~99) : ");
            scanf_s("%d", &cn2);
            if (cn2 < 0 && cn2 > 99) {
                printf("\t\t\t\t澀跤 殮溘腎歷蝗棲棻.\n");
                return;
            }
            if (cn1 == 0)
            {
                if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "紫憮憮雖");
                else if (cn2 >= 10 && cn2 <= 19)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "僥ь薑爾");
                else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "寥婁餌瞪");
                else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "鬼熱翱餵");
                else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "橾奩翱樓");
                else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "з欽⑺晦");
                else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "褐僥盪割");
                else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "瞪餵識憮");
                else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "щ饜濠猿");
                else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "羲餌");
            }
            if (cn1 == 1)
            {
                if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "繹з");
                else if (cn2 >= 10 && cn2 <= 19) strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "⑽檜鼻з");
                else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "檣衝煩");
                else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "褕葬褐綠");
                else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "繹зだ");
                else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "褕葬з");
                else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "喱葬з");
                else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "彌葬з");
                else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "堅醞翕繹");
                else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "⑷憮繹з");
            }
            if (cn1 == 2)
            {
                if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "謙掖");
                else if (cn2 >= 10 && cn2 <= 19) strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "謙繹塽檜");
                else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "撩唳");
                else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "掖葬褐з");
                else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "斜葬彌葬");
                else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "雖羲掖��");
                else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "斜葬餌褐");
                else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "斜葬掖��");
                else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "斜葬掖だ");
                else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "晦顫謙掖");
            }
            if (cn1 == 3)
            {
                if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "餌�萼�з");
                else if (cn2 >= 10 && cn2 <= 19) strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "鱔啗");
                else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "薑纂з");
                else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "唳啗з");
                else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "滷睦");
                else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "ч薑捱餌");
                else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "餌�號捏�");
                else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "掖幫з");
                else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "鼻鱔掖鱔");
                else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "Ё樓團樓");
            }
            if (cn1 == 4)
            {
                if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "濠翱婁з");
                else if (cn2 >= 10 && cn2 <= 19) strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "熱з");
                else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "繭僥з");
                else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "僭葬з");
                else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�倆�");
                else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "雖掘婁з");
                else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "堅儅僭з");
                else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "儅僭з");
                else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "衝僭з");
                else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "翕僭з");
            }
            if (cn1 == 5)
            {
                if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "晦獎婁з");
                else if (cn2 >= 10 && cn2 <= 19) strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "曖з");
                else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "奢з");
                else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "堯з");
                else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "陛薑з");
                else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "唳艙з");
                else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�倆訄醾�");
                else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "薯褻機");
                else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "か熱薯褻");
                else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "勒蹴奢з");
            }
            if (cn1 == 6)
            {
                if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "蕨獎");
                else if (cn2 >= 10 && cn2 <= 19) strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "紫衛褻唳");
                else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "勒蹴獎");
                else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "褻陝獎");
                else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "斜楚濰衝");
                else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�裙�");
                else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "っ��");
                else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "餌霞艙��");
                else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "擠學");
                else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "奢翱螃塊");
            }
            if (cn1 == 7)
            {
                if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "樹橫");
                else if (cn2 >= 10 && cn2 <= 19) strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "樹橫з");
                else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "艙橫");
                else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "絮橾橫");
                else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "Щ嫌蝶橫");
                else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "檜鷓葬橫");
                else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "蝶む檣橫");
                else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "塭ず檜鷓");
                else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "斜葬蝶橫");
                else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "晦顫樹橫");
            }
            if (cn1 == 8)
            {
                if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "僥з");
                else if (cn2 >= 10 && cn2 <= 19) strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "嘐措僥з");
                else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "艙措僥з");
                else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "絮橾僥з");
                else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "Щ嫌蝶僥");
                else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "檜驍葬嬴");
                else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "蝶む檣僥");
                else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "塭ず塽檜");
                else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "斜葬蝶僥");
                else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "晦顫樹橫");
            }
            if (cn1 == 9)
            {
                if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "羲餌");
                else if (cn2 >= 10 && cn2 <= 19) strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "雖葬晦ч");
                else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "瞪晦啗爾");
                else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "堅渠羲餌");
                else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "嶸毀羲餌");
                else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "嬴衛羲餌");
                else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "嬴Щ羲餌");
                else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "磁嘐羲餌");
                else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "陴嘐羲餌");
                else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "晦顫羲餌");
            }

            getchar();
            printf("\t\t\t\t熱薑й 薯跡 殮溘 : ");
            gets_s(name, sizeof(name));
            printf("\t\t\t\t熱薑й 濛陛 殮溘 : ");
            gets_s(auth, sizeof(auth));
            printf("\t\t\t\t熱薑й 轎っ餌 殮溘 : ");
            gets_s(pub, sizeof(pub));
            g_booklist[idx].classnum1 = cn1;
            g_booklist[idx].classnum2 = cn2;
            strcpy_s(g_booklist[idx].name, sizeof(g_booklist[idx].name), name);
            strcpy_s(g_booklist[idx].auth, sizeof(g_booklist[idx].pub), auth);
            strcpy_s(g_booklist[idx].pub, sizeof(g_booklist[idx].pub), pub);

            strncpy_s(g_booklist[idx].classpub, sizeof(g_booklist[idx].classpub), g_booklist[idx].pub, 2);
            g_booklist[idx].classpub[3] = '\0';
            strncpy_s(g_booklist[idx].classauth, sizeof(g_booklist[idx].classauth), g_booklist[idx].auth, 2);
            g_booklist[idx].classauth[3] = '\0';
            strncpy_s(g_booklist[idx].classname, sizeof(g_booklist[idx].classname), g_booklist[idx].name, 8);
            g_booklist[idx].classname[8] = '\0';


            printf("\t\t\t\t熱薑腎歷蝗棲棻.\n");
        }
        else
        {
            printf("\t\t\t\t橈蝗棲棻\n");
        }
    }
    else if (temp == '2') {
        system("cls");
        int sn;
        printf("\n\n\n\n\n\n");
        printf("\t\t\t\t忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
        printf("\t\t\t\t弛                紫憮 熱薑                弛\n");
        printf("\t\t\t\t戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
        printf("\t\t\t\t橾溼廓�� 殮溘) ");
        scanf_s("%d", &sn);
        int idx = searchsn(sn);
        if (idx == -1) {
            printf("\t\t\t\t澀跤脹 高殮棲棻.\n");
        }
        else {
            if (sn != -1)
            {
                char auth[20];
                char pub[20];
                char name[20];
                int cn1;
                int cn2;

                printf("\t\t\t\t熱薑й 渠碟盟 廓�� 殮溘(0~9) : ");
                scanf_s("%d", &cn1);
                if (cn1 < 0 && cn1 > 9) {
                    printf("\t\t\t\t澀跤 殮溘腎歷蝗棲棻.\n");
                    return;
                }
                if (cn1 == 0)  	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "識盟");
                else if (cn1 == 1) 	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "繹з");
                else if (cn1 == 2)	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "謙掖");
                else if (cn1 == 3)	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "餌婁");
                else if (cn1 == 4)	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "濠婁");
                else if (cn1 == 5)	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "晦婁");
                else if (cn1 == 6)	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "蕨獎");
                else if (cn1 == 7)	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "樹橫");
                else if (cn1 == 8)	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "僥з");
                else if (cn1 == 9)	 strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "羲餌");


                printf("\t\t\t\t熱薑й 模碟盟 廓�� 殮溘(00~99) : ");
                scanf_s("%d", &cn2);
                if (cn2 < 0 && cn2 > 99) {
                    printf("\t\t\t\t澀跤 殮溘腎歷蝗棲棻.\n");
                    return;
                }
                if (cn1 == 0)
                {
                    if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "紫憮憮雖");
                    else if (cn2 >= 10 && cn2 <= 19)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "僥ь薑爾");
                    else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "寥婁餌瞪");
                    else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "鬼熱翱餵");
                    else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "橾奩翱樓");
                    else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "з欽⑺晦");
                    else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "褐僥盪割");
                    else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "瞪餵識憮");
                    else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "щ饜濠猿");
                    else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "羲餌");
                }
                if (cn1 == 1)
                {
                    if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "繹з");
                    else if (cn2 >= 10 && cn2 <= 19) strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "⑽檜鼻з");
                    else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "檣衝煩");
                    else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "褕葬褐綠");
                    else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "繹зだ");
                    else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "褕葬з");
                    else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "喱葬з");
                    else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "彌葬з");
                    else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "堅醞翕繹");
                    else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "⑷憮繹з");
                }
                if (cn1 == 2)
                {
                    if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "謙掖");
                    else if (cn2 >= 10 && cn2 <= 19) strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "謙繹塽檜");
                    else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "撩唳");
                    else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "掖葬褐з");
                    else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "斜葬彌葬");
                    else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "雖羲掖��");
                    else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "斜葬餌褐");
                    else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "斜葬掖��");
                    else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "斜葬掖だ");
                    else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "晦顫謙掖");
                }
                if (cn1 == 3)
                {
                    if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "餌�萼�з");
                    else if (cn2 >= 10 && cn2 <= 19) strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "鱔啗");
                    else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "薑纂з");
                    else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "唳啗з");
                    else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "滷睦");
                    else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "ч薑捱餌");
                    else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "餌�號捏�");
                    else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "掖幫з");
                    else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "鼻鱔掖鱔");
                    else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "Ё樓團樓");
                }
                if (cn1 == 4)
                {
                    if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "濠翱婁з");
                    else if (cn2 >= 10 && cn2 <= 19) strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "熱з");
                    else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "繭僥з");
                    else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "僭葬з");
                    else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�倆�");
                    else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "雖掘婁з");
                    else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "堅儅僭з");
                    else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "儅僭з");
                    else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "衝僭з");
                    else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "翕僭з");
                }
                if (cn1 == 5)
                {
                    if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "晦獎婁з");
                    else if (cn2 >= 10 && cn2 <= 19) strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "曖з");
                    else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "奢з");
                    else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "堯з");
                    else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "陛薑з");
                    else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "唳艙з");
                    else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�倆訄醾�");
                    else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "薯褻機");
                    else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "か熱薯褻");
                    else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "勒蹴奢з");
                }
                if (cn1 == 6)
                {
                    if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "蕨獎");
                    else if (cn2 >= 10 && cn2 <= 19) strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "紫衛褻唳");
                    else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "勒蹴獎");
                    else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "褻陝獎");
                    else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "斜楚濰衝");
                    else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "�裙�");
                    else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "っ��");
                    else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "餌霞艙��");
                    else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "擠學");
                    else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "奢翱螃塊");
                }
                if (cn1 == 7)
                {
                    if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "樹橫");
                    else if (cn2 >= 10 && cn2 <= 19) strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "樹橫з");
                    else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "艙橫");
                    else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "絮橾橫");
                    else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "Щ嫌蝶橫");
                    else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "檜鷓葬橫");
                    else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "蝶む檣橫");
                    else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "塭ず檜鷓");
                    else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "斜葬蝶橫");
                    else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "晦顫樹橫");
                }
                if (cn1 == 8)
                {
                    if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "僥з");
                    else if (cn2 >= 10 && cn2 <= 19) strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "嘐措僥з");
                    else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "艙措僥з");
                    else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "絮橾僥з");
                    else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "Щ嫌蝶僥");
                    else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "檜驍葬嬴");
                    else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "蝶む檣僥");
                    else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "塭ず塽檜");
                    else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "斜葬蝶僥");
                    else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "晦顫樹橫");
                }
                if (cn1 == 9)
                {
                    if (cn2 >= 0 && cn2 <= 9)   strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "羲餌");
                    else if (cn2 >= 10 && cn2 <= 19) strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "雖葬晦ч");
                    else if (cn2 >= 20 && cn2 <= 29)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "瞪晦啗爾");
                    else if (cn2 >= 30 && cn2 <= 39)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "堅渠羲餌");
                    else if (cn2 >= 40 && cn2 <= 49)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "嶸毀羲餌");
                    else if (cn2 >= 50 && cn2 <= 59)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "嬴衛羲餌");
                    else if (cn2 >= 60 && cn2 <= 69)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "嬴Щ羲餌");
                    else if (cn2 >= 70 && cn2 <= 79)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "磁嘐羲餌");
                    else if (cn2 >= 80 && cn2 <= 89)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "陴嘐羲餌");
                    else if (cn2 >= 90 && cn2 <= 99)strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "晦顫羲餌");
                }

                getchar();
                printf("\t\t\t\t熱薑й 薯跡 殮溘 : ");
                gets_s(name, sizeof(name));
                printf("\t\t\t\t熱薑й 濛陛 殮溘 : ");
                gets_s(auth, sizeof(auth));
                printf("\t\t\t\t熱薑й 轎っ餌 殮溘 : ");
                gets_s(pub, sizeof(pub));
                g_booklist[idx].classnum1 = cn1;
                g_booklist[idx].classnum2 = cn2;
                strcpy_s(g_booklist[idx].name, sizeof(g_booklist[idx].name), name);
                strcpy_s(g_booklist[idx].auth, sizeof(g_booklist[idx].pub), auth);
                strcpy_s(g_booklist[idx].pub, sizeof(g_booklist[idx].pub), pub);

                strncpy_s(g_booklist[idx].classpub, sizeof(g_booklist[idx].classpub), g_booklist[idx].pub, 2);
                g_booklist[idx].classpub[3] = '\0';
                strncpy_s(g_booklist[idx].classauth, sizeof(g_booklist[idx].classauth), g_booklist[idx].auth, 2);
                g_booklist[idx].classauth[3] = '\0';
                strncpy_s(g_booklist[idx].classname, sizeof(g_booklist[idx].classname), g_booklist[idx].name, 8);
                g_booklist[idx].classname[8] = '\0';


                printf("\t\t\t\t熱薑腎歷蝗棲棻.\n");
            }
            else
            {
                printf("\t\t\t\t橈蝗棲棻\n");
            }
        }
    }
}

void con_delete()
{
    system("cls");
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
    printf("\t\t\t\t弛                紫憮 餉薯                弛\n");
    printf("\t\t\t\t戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
    printf("\t\t\t\t忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
    printf("\t\t\t\t弛         [1] 薯跡 匐儀 �� 餉薯           弛\n");
    printf("\t\t\t\t弛         [2] 橾溼廓�� 匐儀 �� 餉薯       弛\n");
    printf("\t\t\t\t戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");

    char temp;
    temp = _getch();
    if (temp == '1') {
        system("cls");
        printf("\n\n\n\n\n\n");
        printf("\t\t\t\t忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
        printf("\t\t\t\t弛                紫憮 餉薯                弛\n");
        printf("\t\t\t\t戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
        char name[20];
        printf("\t\t\t\t薯跡 殮溘 : ");
        gets_s(name, sizeof(name));

        int idx = nametoidx(name);

        if (idx != -1) {
            g_booklist[idx].classnum1 = 0;
            g_booklist[idx].classnum2 = 0;
            g_booklist[idx].classnum3 = 0;
            g_booklist[idx].flag = 0;
            g_booklist[idx].flag1 = 0;
            strcpy_s(g_booklist[idx].name, sizeof(g_booklist[idx]).name, "");
            strcpy_s(g_booklist[idx].auth, sizeof(g_booklist[idx]).auth, "");
            strcpy_s(g_booklist[idx].pub, sizeof(g_booklist[idx]).pub, "");
            strcpy_s(g_booklist[idx].classpub, sizeof(g_booklist[idx].classpub), "");
            strcpy_s(g_booklist[idx].classauth, sizeof(g_booklist[idx].classauth), "");
            strcpy_s(g_booklist[idx].classname, sizeof(g_booklist[idx].classname), "");
            strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "");
            strcpy_s(g_booklist[idx].classsecond, sizeof(g_booklist[idx].classsecond), "");


            printf("\t\t\t\t餉薯腎歷蝗棲棻.\n\n");

        }
        else
        {
            printf("\t\t\t\t橈蝗棲棻\n\n");
        }
    }
    else if (temp == '2') {
        system("cls");
        printf("\n\n\n\n\n\n");
        printf("\t\t\t\t忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
        printf("\t\t\t\t弛                紫憮 餉薯                弛\n");
        printf("\t\t\t\t戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
        int sn;
        printf("\t\t\t\t橾溼廓�� 殮溘) ");
        scanf_s("%d", &sn);
        int idx = searchsn(sn);
        if (idx != -1) {
            g_booklist[idx].classnum1 = 0;
            g_booklist[idx].classnum2 = 0;
            g_booklist[idx].flag = 0;
            g_booklist[idx].flag1 = 0;
            strcpy_s(g_booklist[idx].name, sizeof(g_booklist[idx]).name, "");
            strcpy_s(g_booklist[idx].auth, sizeof(g_booklist[idx]).auth, "");
            strcpy_s(g_booklist[idx].pub, sizeof(g_booklist[idx]).pub, "");
            strcpy_s(g_booklist[idx].classpub, sizeof(g_booklist[idx].classpub), "");
            strcpy_s(g_booklist[idx].classauth, sizeof(g_booklist[idx].classauth), "");
            strcpy_s(g_booklist[idx].classname, sizeof(g_booklist[idx].classname), "");
            strcpy_s(g_booklist[idx].classfirst, sizeof(g_booklist[idx].classfirst), "");


            printf("\t\t\t\t餉薯腎歷蝗棲棻.\n\n");

        }
        else
        {
            printf("\t\t\t\t澀跤脹 高殮棲棻.\n\n");
        }
    }
}

int nametoidx(const char* name)
{
    for (int i = 0; i < DATAMAX; i++)
    {
        if (strcmp(g_booklist[i].name, name) == 0)
            return i;
    }
    return -1;
}

int authtoidx(const char* name)
{
    for (int i = 0; i < DATAMAX; i++)
    {
        if (strcmp(g_booklist[i].auth, name) == 0)
            return i;
    }
    return -1;
}
int pubtoidx(const char* name)
{
    for (int i = 0; i < DATAMAX; i++)
    {
        if (strcmp(g_booklist[i].pub, name) == 0)
            return i;
    }
    return -1;
}