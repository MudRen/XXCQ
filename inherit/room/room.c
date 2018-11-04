// room.c
// netplay@CCTX

#include <dbase.h>
#include <room.h>

inherit F_DBASE;
inherit F_CLEAN_UP;

static mapping doors;

int query_max_encumbrance() { return 100000000000; }

object make_inventory(string file,int j)
{
    object *obj,ob;
    int i;
    obj=children(file);
    for (i=0;i<sizeof(obj);i++){
        if (obj[i]->is_character() && environment(obj[i])){
            if (obj[i]->query("startroom")==base_name(this_object()))
                if( j==0)
                    return obj[i];
                else j--;
        }
    }
    ob = new(file);
    ob->move(this_object());
    if(ob->is_character())//�������"�����ȼ���ææ���뿪��"������Ц����by jackyboy 1999/11/2
    {
    	message("vision",ob->name()+"����ææ���뿪��\n", environment(ob));
    }
    ob->set("startroom", base_name(this_object()));
    return ob;
}
void new_clean_up(mapping obj_list)
{
    object *obj;
    int i;
    if( !mapp(obj_list) ) obj_list=([ ]);
    obj=all_inventory(this_object());
    if (!sizeof(obj))   return;
    for (i=0;i<sizeof(obj);i++)
        {       if (interactive(obj[i])) return;
//      if( obj[i]->query("no_clean_up")<5 ) return;
        if (!obj[i]->is_character()){
            if (obj[i]->query("capacity"))  continue;
            if (undefinedp(obj_list[base_name(obj[i])]))
                destruct(obj[i]);
        }
    }
}
void reset()
{
    mapping ob_list, ob;
    string *list;
    int i,j;
    //
    // Check loaded objects to match the objects specified in "objects"
    // while query("objects") is 
    // ([ <object filename>: <amount>, ..... ])
    // and query_temp("objects") is
    // ([ <object filename>: ({ob1, ob2, ...}), .... ])
    //
    ob_list = query("objects");
    new_clean_up(ob_list);
    if( !mapp(ob_list) ) return;
    
    if( !mapp(ob = query_temp("objects")) )
        ob = allocate_mapping(sizeof(ob_list));
    list = keys(ob_list);
    for(i=0; i<sizeof(list); i++) {
        // Allocate an array if we have multiple same object specified.
        if( undefinedp(ob[list[i]])
        &&  intp(ob_list[list[i]])
        &&  ob_list[list[i]] > 1 )
            ob[list[i]] = allocate(ob_list[list[i]]);
        switch(ob_list[list[i]]) {
        case 1:
            if(!ob[list[i]] ) ob[list[i]] = make_inventory(list[i],0) ;
            if (ob[list[i]]->is_character() && !ob[list[i]]->is_corpse()){
                ob[list[i]]->return_home(this_object());
             }
            break;
        default:
            for(j=0; j<ob_list[list[i]]; j++) {
                // If the object is gone, make another one.
                if( !objectp(ob[list[i]][j]) ) { 
                    ob[list[i]][j] = make_inventory(list[i],j) ;
                }
            if (ob[list[i]][j]->is_character() && !ob[list[i]][j]->is_corpse()){
                ob[list[i]][j]->return_home(this_object());
             }
            }
        }
    }
    set_temp("objects", ob);
}

// Redirect item_desc of the door to this function in default.
string look_door(string dir)
{
	if( !mapp(doors) || undefinedp(doors[dir]) )
		return "��Ҫ��ʲô��\n";
	if( doors[dir]["status"] & DOOR_CLOSED )
		return "���" + doors[dir]["name"] + "�ǹ��ŵġ�\n";
	else
		return "���" + doors[dir]["name"] + "�ǿ��ŵġ�\n";
}

varargs int open_door(string dir, int from_other_side)
{
	mapping exits;
	object ob;

	if( !mapp(doors) || undefinedp(doors[dir]) )
		return notify_fail("�������û���š�\n");

	if( !(doors[dir]["status"] & DOOR_CLOSED) )
		return notify_fail( doors[dir]["name"] + "�Ѿ��ǿ��ŵ��ˡ�\n");

	exits = query("exits");
	if( !mapp(exits) || undefinedp(exits[dir]) )
		error("Room: open_door: attempt to open a door with out an exit.\n");

	if( from_other_side )
		message("vision", "���˴���һ�߽�" + doors[dir]["name"] + "���ˡ�\n", this_object());
	else if( objectp(ob = find_object(exits[dir])) ) {
		if( !ob->open_door(doors[dir]["other_side_dir"], 1) ) return 0;
	}

	doors[dir]["status"] &= (!DOOR_CLOSED);
	return 1;
}

varargs int close_door(string dir, int from_other_side)
{
	mapping exits;
	object ob;

	if( !mapp(doors) || undefinedp(doors[dir]) )
		return notify_fail("�������û���š�\n");

	if( (doors[dir]["status"] & DOOR_CLOSED) )
		return notify_fail( doors[dir]["name"] + "�Ѿ��ǹ��ŵ��ˡ�\n");

	exits = query("exits");
	if( !mapp(exits) || undefinedp(exits[dir]) )
		error("Room: close_door: attempt to open a door with out an exit.\n");

	if( from_other_side )
		message("vision", "���˴���һ�߽�" + doors[dir]["name"] + "�����ˡ�\n", this_object());
	else if( objectp(ob = find_object(exits[dir])) ) {
		if( !ob->close_door(doors[dir]["other_side_dir"], 1) ) return 0;
	}

	doors[dir]["status"] |= DOOR_CLOSED;
	return 1;
}

int check_door(string dir, mapping door)
{
	// If we have no responding door, assume it is correct.
	if( !mapp(doors) || undefinedp(doors[dir]) ) return 1;

	door["status"] = doors[dir]["status"];
	return 1;
}

varargs void create_door(string dir, mixed data, string other_side_dir, int status)
{
	mapping d, exits;
	object ob;

	exits = query("exits");
	if( !mapp(exits) || undefinedp(exits[dir]) )
		error("Room: create_door: attempt to create a door without exit.\n");

	// Compact mode.
	if( stringp(data) ) {
		d = allocate_mapping(4);
		d["name"] = data;
		d["id"] = ({ dir, data, "door" });
		d["other_side_dir"] = other_side_dir;
		d["status"] = status;
	} else if( mapp(data) )
		d = data;
	else
		error("Create_door: Invalid door data, string or mapping expected.\n");

	set("item_desc/" + dir, (: look_door, dir :) );

	if( objectp(ob = find_object(exits[dir])) ) {
		if( !ob->check_door(other_side_dir, d) )
			return;
	}

	if( !mapp(doors) ) doors = ([ dir: d ]);
	else doors[dir] = d;
}

mapping query_doors() { return doors; }

mixed query_door(string dir, string prop)
{
	if( !mapp(doors) || undefinedp(doors[dir]) ) return 0;
	else return doors[dir][prop];
}

int valid_leave(object t, string dir)
{
	if( mapp(doors) && !undefinedp(doors[dir]) ) {
		if( doors[dir]["status"] & DOOR_CLOSED )
			return notify_fail("������Ȱ�" + doors[dir]["name"] + "�򿪣�\n");
		// if ( door[dir]["status"] & DOOR_HAS_TRAP ) ....
	}
	return 1;
}

void setup()
{
	seteuid(getuid());
	this_object()->reset();
}
