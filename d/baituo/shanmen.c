// ɽ��
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIW "����ɽׯɽ��" NOR);
        set("long", @LONG
�����������ŷ����ľ���������ɽׯ�������Դ�ŷ����ʧ���Ժ�
�Ҷ������˶��߹��ˡ��������￴��ȥ�Ѿ���Ϊ�����ˣ�ɽׯ��������
�����Ļҳ���
LONG);
        set("exits", ([
              "northup" : __DIR__"kongdi",
              "eastdown" : __DIR__"btshan",
        ]));
        set("outdoors", "����ɽ");
        setup(); 
      replace_program(ROOM);
}
