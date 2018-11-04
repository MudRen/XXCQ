// Item zhinan.c  
// Created by Zeus 1999.8.1
// Modified by Zeus 1999.8.1
// 
// 

inherit ITEM;

string* medrooms = ({
        "/d/wenjia/caodi",
        "/d/wenjia/dayuan",
        "/d/wenjia/houyuan",
        "/d/wenjia/huoroad1",
        "/d/wenjia/huoroad2",
        "/d/wenjia/huoroad3",
        "/d/wenjia/huoroad4",
        "/d/wenjia/huoroad5",
        "/d/wenjia/huoroad6",
        "/d/wenjia/huoroad7",
        "/d/wenjia/huoroad8",
        "/d/wenjia/shulin1",
        "/d/wenjia/shulin2",
        "/d/wenjia/shanlu1",
        "/d/wenjia/shanlu2",
        "/d/wenjia/shanlu3",
        "/d/wenjia/shanlu4",
        "/d/wenjia/siroad1",
        "/d/wenjia/siroad2",
        "/d/wenjia/siroad3",
        "/d/wenjia/siroad4",
        "/d/wenjia/siroad5",
        "/d/wenjia/siroad6",
        "/d/wenjia/yaotian1",
        "/d/wenjia/yaotian2",
        "/d/wenjia/yaotian3",
        "/d/wenjia/yaotian4",
        "/d/wenjia/yaotian5",
        "/d/wenjia/yaotian6",
        "/d/wenjia/yaotian7",
});

string* medsources = ({
        "chihuohe",
        "mushugen",
        "fanmubie",
        "chiaisu", 
        "duanchangcao", 
        "hedinghong", 
        "kongquedan", 
});

string* chinesemedsources = ({
        "���Ы",
        "ľ���",
        "��ľ��",
        "�ఫ��",
        "�ϳ���",
        "�׶���",
        "��ȸ��",
});

void init();
int do_yanjiu(string arg);

void create()
{
        set_name( "��ҩָ��",({ "zhi nan"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ����ҩָ�ϡ�\n");
                set("value", 100);
                set("material", "iron");
        }
}

void init()
{
        add_action("do_yanjiu", "yanjiu");
}

int do_yanjiu(string arg)
{
        object fd,room;
		int i;
        string now_place;

        fd = LOGIN_D->find_body(arg);
        room=environment(fd);
        now_place=file_name(room);
        message_vision("���εص���"+medrooms[fd->query_temp("taskxiao/medroom1")]
                              +"��"+medrooms[fd->query_temp("taskxiao/medroom2")]
                              +"��"+medrooms[fd->query_temp("taskxiao/medroom3")]+"\n",fd);
        message_vision("��������"+now_place+"��\n",fd);
		return 1;
}
