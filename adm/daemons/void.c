// void.c (re-created after Elon screwed it up on 07-24-95)

inherit ROOM;

int sid;

void create()
{
	set("short","��ɱ");
	set("long",@LONG	
��ɱɱɱ��
LONG
	);
	setup();
}

void init()
{
	add_action("do_test","t");
}

int do_test(string arg)
{
	"/adm/daemons/socketd"->add_session("��ɱ��",this_object());
	write("/adm/daemons/socketd"->show_session());
	return notify_fail("�����Ѿ�����\n");
}

int incoming(string sid,string msg)
{
	CHANNEL_D->do_channel(this_object(),"chat","�յ����Ϊ"+sid+"����Ϣ���أ�"+msg);
	tell_room(this_object(),"hi!"+sid);//δִ��
	return 1;
}
