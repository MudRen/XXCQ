// Room: ������
// Date: by godzilla 1999.11.18


inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
�����ɵĽ�������Ҫ�Ǹ����֣�һ��ʦ�����޷��Դ�����Ҫ����
��������չۿ��Լ�̽���������еİ��أ�������𳤱��������޽�
��������Ϊ�����űչ����á�
LONG );
	set("exits", ([
	        "west" : __DIR__"neitang",
		]));
	set("objects",([
	        __DIR__"npc/dizi" : 1,
	        ]));
	setup();
	replace_program(ROOM);

}
