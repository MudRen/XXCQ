
inherit ROOM;
void create()
{
        set("short","����");
        set("long",@LONG
�������������ˮ��������Ȼ���ж��졣������Ѫ����ǰ�ε�
ʮһλ���ŵ�����֮�أ�����Ѫ���ɵĴ�ͳ��Ϊ�˲���Ѫ���ɵ���ѧʧ
������ȥ���Ұɣ�˵��������ʲô������������
LONG );
        set("valid_startroom",1);
        set("class","Ѫ����");
       set("exits",([
                "south" : __DIR__"pubulei1",
                "east" : __DIR__"center",
        ]));
//        set("no_clean_up"�� 0);
        setup();
           replace_program(ROOM);
}


