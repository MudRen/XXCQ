
inherit ROOM;
void create()
{
        set("short","��������");
        set("long",@LONG
�������������ˮ��������Ȼ���ж��졣������Ѫ����ǰ�ε�
ʮһλ���ŵ�����֮�أ�����Ѫ���ɵĴ�ͳ��Ϊ�˲���Ѫ���ɵ���ѧʧ
�������Ѿ������˶��������ĵش���
LONG );
        set("valid_startroom",1);
        set("class","Ѫ����");
        set("exits",([
                "west" : __DIR__"pubulei2",
                 "enter" : __DIR__"mimi",
        ]));
        set("objects",([
                "/kungfu/class/xuehepai/ouyang" : 1,
        ]));
//        set("no_clean_up"�� 0);
        setup();
        replace_program(ROOM);
}

