// Room: ������
// Date: by godzilla 1999.11.18


inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���߽����СС������, �����������һ����̴ľ�輸��
�������������ӣ���̴ľ�Ĳ輸�ϰڷ��Ų���ͼ�ֻ���񱭣�
ר���������á����̲�ס�����������ϣ���ƣ�������ĵõ���
�ֵ���Ϣ��
LONG );
	set("exits", ([
	        "east" : __DIR__"dating", 
		"west" : __DIR__"xuant",
		]));
	set("objects",([
	        __DIR__"npc/xiaohe" : 1,
	        ]));
	setup();
	
}
int valid_leave(object me, string dir)
{
	if (me->query("family/family_name") != "������" && dir == "west" )
	{
		if(objectp(present("xiao he", environment(me))))
		return notify_fail("����������ס�㣬˵�����������������صأ����˲��ý��롣��Ϊ"+RANK_D->query_respect(me)+"������ذɣ�\n");
	}
	return ::valid_leave(me, dir);
}