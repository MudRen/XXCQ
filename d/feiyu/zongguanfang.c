// Room: zongguanfang.c 
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.23
// 
// 

inherit ROOM;

void init();
int do_task(string arg);
void delete_served(object);


void create ()
{
        set ("short", "�ܹܷ�");
        set ("long", @LONG
�ܹܷ�����費�࣬���Ա�����һ�����ˡ���ϸ��ȥ�������߾��Ƿ�
�����������ˡ�֮һ���ܹ���ѩ�ߡ����Ӻ���ĺ�ľ��������һ��һ
��ļ�¼�������϶����˾��ڣ���Ȼ�ٲ������ķ��ı����ܹܵ��ֲ�ͣ��
д�Ŷ�����
LONG);
        set("area","����");
        set("valid_startroom", 1);
        set("no_fight", 1);

        set("objects", ([
               "/d/feiyu/npc/zhang" : 1,
        ]));
          set("exits", ([
                "north" : __DIR__"dongyuan",
        ]));
        
        setup();
        replace_program(ROOM);
}
