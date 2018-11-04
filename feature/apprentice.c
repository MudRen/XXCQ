// apprentice.c
// From ES2
// Modified by Load (9/30/99)

#include <dbase.h>

int is_apprentice_of(object ob)
{
        mapping family;
        
        if( !mapp(family = query("family")) ) return 0;

        if( family["master_id"] == (string)ob->query("id")
        &&      family["master_name"] == (string)ob->query("name") )
                return 1;

        return 0;       
}

// �ж��Ƿ��Ѿ�����һ������
int is_join_of(object ob)
{
        mapping party;
        
        if( !mapp(party = query("party")) ) return 0;
        if( party["party_name"] == ob->query("party/party_name") )
                return 1;

        return 0;
}

void assign_apprentice(string title, int privs)
{
        mapping family;

        if( !mapp(family = query("family")) ) return;

        family["title"] = title;
        family["privs"] = privs;

        if( userp(this_object()) || !query("title") ) {
                if( family["generation"]==1 )
                        set("title", family["family_name"] + "��ɽ��ʦ");
                else
                        set("title", sprintf("%s��%s��%s", family["family_name"],
                                chinese_number(family["generation"]), family["title"]));
        }
}

// This is used for NPC, or start a new family for a player.
void create_family(string family_name, int generation, string title)
{
        mapping family;

        family = allocate_mapping(6);

        family["family_name"] = family_name;
        family["generation"] = generation;

        set("family", family);

        // priv = -1 for ALL privileges.
        assign_apprentice( title, -1 );
}

// �����趨NPC�İ���
void create_party(string party_name, string rank, int level)
{
        mapping party;
        party = allocate_mapping(5);
        party["party_name"] = party_name;
        party["rank"] = rank;
        party["level"] = level;
        set("party", party);
}

int recruit_apprentice(object ob)
{
        mapping my_family, family;

        if( ob->is_apprentice_of( this_object() ) )
                return 0;
        if( !mapp(my_family = query("family")) )
                return 0;

        family = allocate_mapping(sizeof(my_family));
        family["master_id"] = query("id");
        family["master_name"] = query("name");
        family["family_name"] = my_family["family_name"];
        family["generation"] = my_family["generation"] + 1;
        family["enter_time"] = time();
        ob->set("family", family);
        ob->assign_apprentice("����", 0);
        return 1;
}

// �������µİ���Ա
int recruit_party(object ob,string rank)
{
        mapping my_party, party;

        if( ob->is_join_of( this_object() ) )
                return 0;
        if( !mapp(my_party = query("party")) )
                return 0;

        party = allocate_mapping(sizeof(my_party));
        party["party_name"] = my_party["party_name"];
        party["rank"] = rank;
        party["level"] = 1;
        party["tasks"] = 0;
        party["enter_time"] = time();
        ob->set("party", party);

        return 1;
}

