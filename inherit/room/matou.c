// bank.c

inherit ROOM;

void init()
{
	add_action("do_gu", "gu");
	add_action("do_qu", "qu");
}

void check_trigger(object me)
{
	object room;
	if( !(room = find_object("/clone/room/chuan")) )
		room = load_object("/clone/room/chuan");
	if( room = find_object("/clone/room/chuan") )
	{
		if((int)room->query("chuan_trigger")==0 )
		{
			message_vision("һ�����꺺�ӴӴ��������˳��ˣ��������´�����$N��\n", me);
			message_vision("���ӵ������͹�ȥ��ѽ(type qu XX)�����ǿ�ֻ��ȥ佻�(hh)������(zg)������ͷ����\n\n", me);
			me->set_temp("guchuan", 1);
		}
		else
		message_vision("�������˰���ȴû���˳��������������ǳ�ȥ�ˡ�\n", me);
        }
        else
            message("vision", "ERROR: chuan not found\n", this_object() );
}

int do_gu(string arg)
{
	object me;
	me = this_player();

	if(!arg || arg != "chuan")
		return notify_fail("��Ҫ��ʲô������ֻ������(chuan)���Թ͡�\n");
	
	message_vision("$N������һ��ͣ����ͷ�����񴬵����ӣ��������������𣿹ʹ�����\n", me);
        check_trigger(me);
        return 1;
}

int do_qu(string arg, int num)
{
	object room, me;
	me = this_player();

	if (!me->query_temp("guchuan"))
		return notify_fail("����û�������㣬������Լ���ɵ��\n");

	if (!arg)
		return notify_fail("�㵹��˵ȥ��ѽ��\n");

	if( !(room = find_object("/clone/room/chuan")) )
		room = load_object("/clone/room/chuan");
	if( room = find_object("/clone/room/chuan") )
	{
		if ( arg == "huanhua" || arg == "hh" )
		{
			message_vision("������$N���˴����ߺ�һ���������ã�����ȥ佻��ޣ���\n\n", me);
			me->set_temp("chuan", "huanhua");
		}
		else if ( arg == "zigui" || arg == "zg" )
		{
			message_vision("������$N���˴����ߺ�һ���������ã�����ȥ�����ޣ���\n\n", me);
			me->set_temp("chuan", "zigui");
		}
		else
		{
			message_vision("�󺺱�Ǹ��Ц��Ц��������ˮ·ֻͨ佻�(hh)������(zg)���汧Ǹ��\n", me);
			return 1;
		}
		message_vision("��һ�ᣬ����ҡ��ҡ�Ļ���������\n\n", me);
		call_out("arrived", 25, me);
		me->move("/clone/room/chuan");
		room->set("chuan_trigger", 1);
		return 1;
	}
}

int arrived(object me)
{
	object room;
	if( room = find_object("/clone/room/chuan") )
	{
		if (me->query_temp("chuan") == "huanhua")
		{
			me->move("/d/huayang/hhmatou");
		}
		else if (me->query_temp("chuan") == "zigui")
		{
			me->move("/d/xiangyang/zgmatou");
		}
		me->delete_temp("chuan");
		me->delete_temp("guchuan");
		message_vision("\n���񴬽���ͣ������������߽�һ�������ˣ�\n\n", me);
		message_vision("�������Ŀ�����$N����������������\n\n", me);
	        room->delete("chuan_trigger"); 
		return 1;
	}
}

void reset()
{
    object room;

    ::reset();
    if( room = find_object("/clone/room/chuan") )
        room->delete("chuan_trigger"); 
}
